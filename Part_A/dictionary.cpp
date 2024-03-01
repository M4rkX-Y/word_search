#include "dictionary.h"

dictionary::dictionary(std::ifstream &f)
{
    if (f.is_open())
    {
        while (f)
        {
            std::string word;
            f >> word;
            words.push_back(word);
        }
    }
    f.close();
}

void dictionary::readFile(std::ifstream &f)
{
    if (f.is_open())
    {
        while (f)
        {
            std::string word;
            f >> word;
            words.push_back(word);
        }
    }
    f.close();
}

void dictionary::print()
{
    for (auto it = begin(words); it != end(words); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void dictionary::sort()
{
    for (int i = 0; i < words.size(); i++)
    {
        std::string min = words[i];
        int minIndex = i;
        for (int j = i; j < words.size(); j++)
        {
            if (words[j].compare(min) < 0)
            {
                min = words[j];
                minIndex = j;
            }
        }
        std::swap(words[i], words[minIndex]);
    }
}

bool dictionary::search(std::string w)
{
    int first = 0;
    int last = words.size();
    int mid;
    std::string midValue;
    while (first <= last)
    {
        mid = std::floor((first + last) / 2);
        midValue = words[mid];
        if (midValue.compare(w) == 0)
        {
            return true;
        }
        else if (midValue.compare(w) > 0)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return false;
}
