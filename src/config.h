#include <stddef.h>

// When full_url_flag disabled (default) gp will look for repos in these urls
// Example:
// $ gp install GrbavaCigla/gitpack
// First found is https://github.com/ so url will be https://github.com/GrbavaCigla/gitpack
char *sources[] ={
    "https://github.com/",
    "https://gitlab.com/",
    "https://bitbucket.org/",
    // "https://codeberg.com/",
    NULL };

// Makefile tries to parse paths so it can create them for you
// If it doesn't work, create everything by yourself and copy res/build.s
// to path you specified

// Dont forget to create this directories!
char *config_path = "/etc/gitpack/";
char *cache_path = "/etc/gitpack/packages/";

// Commandlist path
char *cmdlist_path = "/etc/gitpack/build.sh";