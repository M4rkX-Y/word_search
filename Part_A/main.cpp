#include "grid.h"
#include "dictionary.h"

void findMatches(std::string grid_name);

int main()
{
    std::string grid_name = "input15-2";
    findMatches(grid_name);
    return 0;
}

void findMatches(std::string grid_name)
{
    std::ifstream df("dictionary-2");
    std::ifstream gf(grid_name);
    grid g(gf);
    std::cout << "The Word Grid: " << std::endl;
    g.print();
    dictionary d;
    d.readFile(df);
    d.sort();
    for (int i = 0; i < g.rows; i++)
    {
        for (int j = 0; j < g.cols; j++)
        {
            for (int k = 5; k < g.cols + 1; k++)
            {
                std::string word_right, word_left, word_up, word_down, word_upleft, word_upright, word_downleft, word_downright;
                for (int p = 0; p < k; p++)
                {
                    word_right.push_back(g.getValue(i, (j + p) % g.cols));
                    word_left.push_back(g.getValue(i, (j - p + g.cols) % g.cols));
                    word_down.push_back(g.getValue((i + p) % g.rows, j));
                    word_up.push_back(g.getValue((i - p + g.cols) % g.cols, j));
                    word_upleft.push_back(g.getValue((i - p + g.cols) % g.cols, (j - p + g.cols) % g.cols));
                    word_upright.push_back(g.getValue((i - p + g.cols) % g.cols, (j + p) % g.cols));
                    word_downleft.push_back(g.getValue((i + p) % g.rows, (j - p + g.cols) % g.cols));
                    word_downright.push_back(g.getValue((i + p) % g.rows, (j + p) % g.cols));
                }
                if (d.search(word_right))
                {
                    std::cout << "Find word: " << word_right << std::endl;
                }
                if (d.search(word_left))
                {
                    std::cout << "Find word: " << word_left << std::endl;
                }
                if (d.search(word_up))
                {
                    std::cout << "Find word: " << word_up << std::endl;
                }
                if (d.search(word_down))
                {
                    std::cout << "Find word: " << word_down << std::endl;
                }
                if (d.search(word_upleft))
                {
                    std::cout << "Find word: " << word_upleft << std::endl;
                }
                if (d.search(word_upright))
                {
                    std::cout << "Find word: " << word_upright << std::endl;
                }
                if (d.search(word_downleft))
                {
                    std::cout << "Find word: " << word_downleft << std::endl;
                }
                if (d.search(word_downright))
                {
                    std::cout << "Find word: " << word_downright << std::endl;
                }
            }
        }
    }
}