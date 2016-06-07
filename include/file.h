#ifndef FILE_H
#define FILE_H
#include <string>

class File
{
    public:
        File(char *Name);
        std::string Hash;
        char *Name;
    private:
        void generateHash();
};
#endif
