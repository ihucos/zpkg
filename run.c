
#define _GNU_SOURCE
#include "brtlib.h"


#define PRESET_PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
#define ROOTFS "../rootfs/"


int main(int argc, char* argv[]) {
	char *origpwd;


	if (getuid()) brt_setup_user_ns();

	brt_setup_mount_ns();

        brt_bind_mount("/dev",             brt_path(ROOTFS "dev"));
        brt_bind_mount("/home",            brt_path(ROOTFS "home"));
        brt_bind_mount("/proc",            brt_path(ROOTFS "proc"));
        brt_bind_mount("/root",            brt_path(ROOTFS "root"));
        brt_bind_mount("/sys",             brt_path(ROOTFS "sys"));
        brt_bind_mount("/tmp",             brt_path(ROOTFS "tmp"));
        brt_bind_mount("/",                brt_path(ROOTFS "host"));
        brt_bind_mount("/etc/resolv.conf", brt_path(ROOTFS "etc/resolv.conf"));

        origpwd = get_current_dir_name();
	if (!origpwd) brt_fatal("get_current_dir_name");

	chroot(brt_path(ROOTFS)
	      ) != -1 || brt_fatal("could not chroot to %s", ROOTFS);
	brt_chdir(origpwd);

	putenv("PATH=" PRESET_PATH);
	brt_whitelist_env("TERM");
	brt_whitelist_env("DISPLAY");
	brt_whitelist_env("HOME");
	brt_whitelist_env("PATH");
	brt_whitelist_env(NULL);
	brt_whitelist_envs_from_env("ZPKG_EXPORT");

	/* exec away */
	argv[0] = program_invocation_short_name;
	execvp(argv[0], argv
		) != -1 || brt_fatal("exec %s", argv[0]);
}
