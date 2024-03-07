#ifndef heap_H
#define heap_H
#include <vector>
#include <string>
#include <cmath>

template <typename T>
class heap
{
public:
    heap() {}
    int parent(int n);
    int left(int n);
    int right(int n);
    T getItem(int n);
    void initializeMaxHeap(std::vector<T> v) { h = v; }
    void maxHeapify(int s, int i);
    void buildMaxHeap(int s);
    void heapsort();

private:
    std::vector<T> h;
};

#endif