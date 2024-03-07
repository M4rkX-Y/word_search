#include "heap.h"

template <class T>
int heap<T>::parent(int n)
{
    return std::floor((n - 1) / 2);
}

template <class T>
int heap<T>::left(int n)
{
    return 2 * n + 1;
}

template <class T>
int heap<T>::right(int n)
{
    return 2 * n + 2;
}

template <class T>
T heap<T>::getItem(int n)
{
    return h[n];
}

template <class T>
void heap<T>::maxHeapify(int s, int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < s && h[l] > h[largest])
    {
        largest = l;
    }
    if (r < s && h[r] > h[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        std::swap(h[i], h[largest]);
        maxHeapify(s, largest);
    }
}

template <class T>
void heap<T>::buildMaxHeap(int s)
{
    for (int i = (s / 2) - 1; i >= 0; i--)
        maxHeapify(s, i);
}

template <class T>
void heap<T>::heapsort()
{
    int heap_size = h.size();
    buildMaxHeap(heap_size);
    for (int i = heap_size - 1; i > 0; i--)
    {
        std::swap(h[0], h[i]);
        maxHeapify(i, 0);
    }
}

template class heap<std::string>;