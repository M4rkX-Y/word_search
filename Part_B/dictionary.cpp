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

void dictionary::quicksort(int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int s = partition(left, right);
    quicksort(left, s - 1);
    quicksort(s + 1, right);
}

int dictionary::partition(int p, int r)
{
    std::string pivot = words[r];
    int pivotIndex = p;
    for (int j = p; j < r; j++)
    {
        if (words[j].compare(pivot) <= 0)
        {
            pivotIndex++;
        }
    }
    std::swap(words[pivotIndex], words[r]);

    int i = p, j = r;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (words[i].compare(pivot) <= 0)
        {
            i++;
        }

        while (words[j].compare(pivot) > 0)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            std::swap(words[i++], words[j--]);
        }
    }
    return pivotIndex;
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
        if (midValue == w)
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

int dictionary::size()
{
    return words.size();
}