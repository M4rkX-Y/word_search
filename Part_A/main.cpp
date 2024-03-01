#include "grid.h"
#include "dictionary.h"

void findMatches();

int main()
{
    std::ifstream f("input 30-3");
    grid g(f);
    g.print();
    return 0;
}

void findMatches()
{
    dictionary d;
    std::ifstream f("dictionary-2");
    d.readFile(f);
    d.sort();
    d.print();
    std::cout << d.search("deafly");
}