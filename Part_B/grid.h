#ifndef grid_H
#define grid_H
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

class grid
{
public:
    int rows;
    int cols;
    grid() {}
    grid(std::ifstream &f);
    void print();
    char getValue(int r, int c);

private:
    std::vector<std::vector<char>> matrix;
};

#endif