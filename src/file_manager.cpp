#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <openssl/md5.h>

#include "file_manager.h"
#include "file.h"

FileManager::FileManager() 
{
    char currentPath[FILENAME_MAX];
    if (!getcwd(currentPath, sizeof(currentPath)))
    {
        printf("Could not get the current executable path.");
    }

    _rootDir = currentPath;
    printf("Current path: %s\n", _rootDir);
}

void FileManager::addFileStructure()
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(_rootDir)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;

            if (ent->d_type == DT_DIR)
            {
                printf("Dir: \t%s\n", ent->d_name);
            }
            else
            {
                File* file = new File(ent->d_name);
                Files.push_back(file);
            }
        }

        closedir(dir);
    }
    else
    {
        printf("Could not find any files in this directory.");
    }
}
