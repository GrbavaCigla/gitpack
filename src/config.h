#include <stddef.h>

// When -f(ull path) disabled (default) gp will look for repos in these urls
// Example:
// $ sudo/doas gp install GrbavaCigla/gitpack
// First found is https://github.com/ so url will be https://github.com/GrbavaCigla/gitpack
char *sources[] ={
    "https://github.com/",
    "https://gitlab.com/",
    "https://bitbucket.org/",
    NULL };

// Config and packages path
char *config_path = "/etc/gitpack/";
char *package_path = "/var/cache/gitpack/packages/";

// Commandlist path
char *cmdlist_path = "/etc/gitpack/build.sh";

// Commandlist default configuration url
char *cmdlist_url = "https://raw.githubusercontent.com/GrbavaCigla/gitpack/master/res/build.sh";

// Chroot tar file
char *minirootfs_url = "http://dl-cdn.alpinelinux.org/alpine/v3.12/releases/x86_64/alpine-minirootfs-3.12.0-x86_64.tar.gz";

// minirootfs location
char *minirootfs_path = "/usr/share/gitpack/sandbox/";



// // Packages that make problems need separate package builds
// // Folder for those are here
// // (Coming Soon)
// char *custom_builds = "/etc/gitpack/builds/";