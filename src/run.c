
#define _GNU_SOURCE
#include "errno.h"
#include "stdlib.h"
#include "unistd.h"

#include "plash.h"


#define PRESET_PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
#define ROOTFS "../rootfs/"
#define HOST_ENVS_PREFIX "HOST_"

void import_env(char *env){
	char* val = getenv(pl_sprintf(HOST_ENVS_PREFIX "%s", env));
	if (val){
		putenv(pl_sprintf("%s=%s", env, val));
	}
}


int main(int argc, char* argv[]) {
	if (getuid()) pl_setup_user_ns();

	pl_setup_mount_ns();

        pl_bind_mount("/dev",             pl_path(ROOTFS "dev"));
        pl_bind_mount("/home",            pl_path(ROOTFS "home"));
        pl_bind_mount("/proc",            pl_path(ROOTFS "proc"));
        pl_bind_mount("/root",            pl_path(ROOTFS "root"));
        pl_bind_mount("/sys",             pl_path(ROOTFS "sys"));
        pl_bind_mount("/tmp",             pl_path(ROOTFS "tmp"));
        pl_bind_mount("/",                pl_path(ROOTFS "host"));
        pl_bind_mount("/etc/resolv.conf", pl_path(ROOTFS "etc/resolv.conf"));

	putenv("PATH=" PRESET_PATH);

	// add prefix to all envs
	for (size_t i = 0; environ[i]; i++) {
		environ[i] = pl_sprintf(HOST_ENVS_PREFIX "%s", environ[i]);
	}
	import_env("TERM");
	import_env("DISPLAY");
	import_env("HOME");
	import_env("PATH");

	pl_chroot(pl_path(ROOTFS));

	/* exec away */
	argv[0] = program_invocation_short_name;
	execvp(argv[0], argv);
        pl_fatal("exec %s", argv[0]);
}
