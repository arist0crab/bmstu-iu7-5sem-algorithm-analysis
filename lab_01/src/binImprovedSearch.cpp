#include "binImprovedSearch.hpp"


ssize_t BinImprovedSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy;
    return BinImprovedSearch(arr, arrSize, dummy);
}


ssize_t BinImprovedSearch(const int *arr, const size_t arrSize, const int elem, size_t &iterQuantity)
{
    iterQuantity = 0;
    size_t length = arrSize;

    if (length == 0) return -1;

    size_t step = std::bit_floor(length);

    size_t beginIndex = 0;
    size_t endIndex = length - 1;

    if (step != length && arr[beginIndex + step] < elem)
    {
        length -= step + 1;

        if (length == 0) 
            return -1;

        step = std::bit_ceil(length);
        beginIndex = endIndex - step;
    }

    for (step /= 2; step != 0; step /= 2)
    {
        iterQuantity++;
        if (arr[beginIndex + step] < elem)
            beginIndex += step;
    }
    
    return beginIndex + (arr[beginIndex] < elem);
}