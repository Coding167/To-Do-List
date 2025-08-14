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
        int lines;
    public:
        File(): File("") {}
        File(string path) {setPath(path);}

        void addLine(const string& line);

        void setPath(const string& path);

        vector<string> read();

        void replaceLine(int lineNum, const string& line);

        void removeLine(int lineNum);

        void writeLines(vector<string> lines);
};

#endif
