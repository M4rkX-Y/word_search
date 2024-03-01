#include "grid.h"

grid::grid(std::ifstream &f)
{
    if (f.is_open())
    {
        f >> rows >> cols;
        std::vector<std::vector<char>> m(rows, std::vector<char>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                f >> m[i][j];
            }
        }
        matrix = m;
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