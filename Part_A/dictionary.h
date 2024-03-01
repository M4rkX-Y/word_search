#ifndef dictionary_H
#define dictionary_H
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

class dictionary
{
public:
    dictionary() {}
    dictionary(std::ifstream &f);
    void readFile(std::ifstream &f);
    void print();
    void sort();
    bool search(std::string w);

private:
    std::vector<std::string> words;
};

#endif