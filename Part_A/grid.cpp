#include "grid.h"

grid::grid(std::ifstream &f)
{
    if (f.is_open())
    {
        f >> rows >> cols;
        for (int i = 0; i < rows; i++)
        {
            std::vector<char> r;
            for (int j = 0; j < cols; j++)
            {
                char c;
                f >> c;
                r.push_back(c);
            }
            matrix.push_back(r);
        }
    }
    f.close();
}

void grid::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}