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
    grid() {}
    grid(std::ifstream &f);
    void print();

private:
    std::vector<std::vector<char>> matrix;
    int rows;
    int cols;
};

#endif