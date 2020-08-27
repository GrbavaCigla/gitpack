#include <git2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <argp.h>

#include "config.h"
#include "utils.h"
#include "argparse.h"

struct arguments arguments;

int clone(const char *url, const char *path)
{
    git_repository *repo = NULL;

    int error = 0;
    if (arguments.full_url_flag)
    {
        error = git_clone(&repo, url, path, NULL);
    }
    else
    {
        int i = 0;
        while (sources[i] != NULL)
        {
            char final_url[strlen(sources[i]) + strlen(url)];
            strcpy(final_url, sources[i]);
            strcat(final_url, url);
            error = git_clone(&repo, final_url, path, NULL);

            // If everything is fine, finish
            if (error == 0)
            {
                break;
            }

            // Repo already exists
            if (error == -4)
            {
                safe_remove(path);

                return clone(url, path);
            }
            i++;
        }
    }

    free(repo);
    return error;
}

char *get_path(const char *url)
{
    char urlc[strlen(url)];
    strcpy(urlc, url);

    char *repo_name = strtok(urlc, "/");
    while (1)
    {
        char *temp = strtok(NULL, "/");
        if (temp == NULL)
        {
            break;
        }
        repo_name = temp;
    }

    char *path = malloc(strlen(package_path) + strlen(repo_name));
    strcpy(path, package_path);
    strcat(path, repo_name);
    return path;
}

int build(const char *path)
{
    char command[strlen(path) + strlen(cmdlist_path) + strlen("PKGPATH=")];

    strcpy(command, "PKGPATH=");
    strcat(command, path);
    strcat(command, " ");
    strcat(command, cmdlist_path);
    return system(command);
}

int setup(){
    safe_mkdir(config_path);
    safe_mkdir(package_path);
    safe_mkdir(minirootfs_path);

    download_file(cmdlist_url, cmdlist_path);
    download_file(minirootfs_url, minirootfs_path);

    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char *argv[])
{
    

    arguments.full_url_flag = 0;
    arguments.clone_master = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    git_libgit2_init();

    if (strcmp(arguments.args[0], "install") == 0)
    {
        char *path = get_path(arguments.args[1]);
        if (clone(arguments.args[1], path) == 0)
        {
            build(path);
        }
    }

    if (strcmp(arguments.args[0], "setup") == 0)
    {
        setup();
    }

    if (strcmp(arguments.args[0], "remove") == 0)
    {
        char *path = get_path(arguments.args[1]);
        safe_remove(path);
        // TODO: remove installed files
    }

    git_libgit2_shutdown();

    return 0;
}
