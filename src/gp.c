#include <git2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int safeMkdir(char *path) {
    if (stat(path, NULL) == -1) {
        return mkdir(path, 0755);
    }
    return 0;
}

int clone(const char *url, const char *path) {
    git_repository *repo = NULL;

    int error = git_clone(&repo, url, path, NULL);

    free(repo);
    return error;
}

char *get_path(const char *url) {
    char urlc[strlen(url)];
    strcpy(urlc, url);

    char *repo_name = strtok(urlc, "/");
    while (1) {
        char *temp = strtok(NULL, "/");
        if (temp == NULL) {
            break;
        }
        repo_name = temp;
    }
    char *path = malloc(strlen(url) + strlen(repo_name) + 2);
    strcpy(path, CACHE_DIR);
    strcat(path, repo_name);
    return path;
}

int build(const char *path) {
    char *command =
        malloc(strlen(path) + strlen(COMMAND_FILE) + strlen("PKGPATH="));
    strcpy(command, "PKGPATH=");
    strcat(command, path);
    strcat(command, " ");
    strcat(command, COMMAND_FILE);
    return system(command);
}

int main(int argc, char *argv[]) {
    safeMkdir(CONFIG_DIR);
    safeMkdir(CACHE_DIR);

    git_libgit2_init();

    if (strcmp(argv[1], "install") == 0) {
        for (int i = 2; i < argc; i++) {
            char *path = get_path(argv[i]);
            clone(argv[i], path);
            build(path);
        }
    }

    git_libgit2_shutdown();

    return 0;
}
