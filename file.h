#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class File {
    private:
        string path;
    public:
        File(): File("") {}
        File(string path): path(path) {}

        void addLine(const string& line);

        vector<string> read();

        void replaceLine(int lineNum, const string& line);

        void removeLine(int lineNum);
};

#endif
