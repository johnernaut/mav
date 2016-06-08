#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <openssl/sha.h>

#include "file.h"

File::File(char* fileName)
{
    Name = fileName;
    generateHash();
}

void File::generateHash()
{
    unsigned char result[SHA_DIGEST_LENGTH];
    int file_descript;
    unsigned long file_size;
    char *file_buffer;
    struct stat statbuf;

    file_descript = open(Name, O_RDONLY);
    if (file_descript < 0) exit(-1);
    if (fstat(file_descript, &statbuf) < 0) exit(-1);
    file_size = statbuf.st_size;

    file_buffer = (char*)mmap(0, file_size, PROT_READ, MAP_SHARED, file_descript, 0);
    SHA1((unsigned char*)file_buffer, file_size, result);
    munmap(file_buffer, file_size);

    int i;
    for (i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        char hexed[8];
        snprintf(hexed, sizeof(hexed), "%02x", result[i]);
        Hash.append(hexed);
    }
}
