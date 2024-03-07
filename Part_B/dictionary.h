#ifndef dictionary_H
#define dictionary_H
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "heap.h"

class dictionary
{
public:
    dictionary() {}
    dictionary(std::ifstream &f);
    void readFile(std::ifstream &f);
    void print();
    void sort();
    void quicksort(int left, int right);
    void heapsort();
    bool search(std::string w);
    int size();

private:
    std::vector<std::string> words;
    int partition(int p, int r);
};

#endif