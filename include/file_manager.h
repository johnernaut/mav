#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <vector>

#include "file.h"

class FileManager
{
    private:
        std::string _rootDir;
    public:
        FileManager();
        std::vector<File*> Files;
        void addFileStructure();
};
#endif
