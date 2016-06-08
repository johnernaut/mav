#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_manager.h"
#include "file.h"

int main(int argc, char **argv)
{
//    if (argc == 1)
//    {
//        printf("Must provide at least 1 argument to mav.");
//        return 1;
//    }

    for (int i = 0; i < 0; i++)
    {
        if (argv[i] == NULL)
            break;
    }

    FileManager* fm = new FileManager();
    fm->addFileStructure();
    for (std::vector<File*>::iterator f = fm->Files.begin(); f != fm->Files.end(); ++f)
    {
        printf("\tName: %s\t Hash: %s\n", (*f)->Name, (*f)->Hash.c_str());
    }

    return 0;
}
