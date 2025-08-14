#include "file.h"

void File::setPath(const string& path) {
    this->path = path;
    this->lines = read().size();
}

void File::addLine(const string& line) {
    this->lines++;
    ofstream file(path, ios::app);
    file << line << "\n";
    file.close();
}

vector<string> File::read() {
    vector<string> lines;
    ifstream file(path);
    string line;
    while (getline(file,line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

void File::replaceLine(int lineNum, const string& line) {
    if (lineNum > lines || lineNum <= 0) {
        return;
    }
    vector<string> lines = read();
    lines.at(lineNum - 1) = line;
    writeLines(lines);
}

void File::removeLine(int lineNum) {
    if (lineNum > lines || lineNum <= 0) {
        return;
    }
    this->lines--;
    vector<string> lines = read();
    lines.erase(lines.begin() + (lineNum - 1));
    writeLines(lines);
}

void File::writeLines(vector<string> lines) {
    this->lines += lines.size();
    ofstream file(path);
    for (const string& line: lines) {
        file << line << "\n";
    }
    file.close();
}