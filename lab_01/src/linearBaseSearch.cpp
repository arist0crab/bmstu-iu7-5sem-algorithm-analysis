#include "linearBaseSearch.hpp"


ssize_t LinearBaseSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy;
    return LinearBaseSearch(arr, arrSize, elem, dummy);
}

ssize_t LinearBaseSearch(const int *arr, const size_t arrSize, const int elem, size_t &iterQuantity)
{
    for (size_t i = 0; i < arrSize; ++i)
    {
        iterQuantity++;
        if (arr[i] == elem)
            return i;
    }

    return -1;
}