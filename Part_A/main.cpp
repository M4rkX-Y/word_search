#include "grid.h"
#include "dictionary.h"

void findMatches(std::string grid_name);

int main()
{
    std::string grid_name = "input30-3";
    findMatches(grid_name);
    return 0;
}

void findMatches(std::string grid_name)
{
    dictionary d;
    std::ifstream df("dictionary-2");
    d.readFile(df);
    d.sort();
    std::ifstream gf(grid_name);
    grid g(gf);
    g.print();
    std::cout << d.search("deafly");
}