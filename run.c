
#define _GNU_SOURCE
#include "brtlib.h"


#define PRESET_PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"


int main(int argc, char* argv[]) {
	char 
	     *token,
	     *str,
	     *progpath = realpath("/proc/self/exe", NULL),
	     *origpwd = get_current_dir_name(),
	     *rootfs = dirname(dirname(strdup(progpath))); // FIXME: check for no memory error

	if (!progpath) brt_fatal("realpath");
	if (!origpwd)  brt_fatal("get_current_dir_name");

	chdir(rootfs
	     ) != -1 || brt_fatal("cd %s", rootfs);
	chdir("./rootfs"
	     ) != -1 || brt_fatal("cd %s/rootfs", rootfs);

	/* give us "fake root" */
	if (getuid()) brt_setup_user_ns();

	brt_setup_mount_ns();

        brt_bind_mount("/dev", "./dev");
        brt_bind_mount("/home", "./home");
        brt_bind_mount("/proc", "./proc");
        brt_bind_mount("/root", "./root");
        brt_bind_mount("/sys", "./sys");
        brt_bind_mount("/tmp", "./tmp");
        brt_bind_mount("/", "./host");
        brt_bind_mount("/etc/resolv.conf", "./etc/resolv.conf");

	chroot("."
	      ) != -1 || brt_fatal("could not chroot to %s/rootfs",
	                           get_current_dir_name());

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
		) != -1 || brt_fatal("chroot %s/rootfs %s", rootfs, argv[0]);
}
