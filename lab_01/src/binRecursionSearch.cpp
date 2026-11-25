#include "binRecursionSearch.hpp"

ssize_t binRecursionIteration(const int *arr, const int elem, ssize_t leftIndex, ssize_t rightIndex, size_t &recursionDepth, size_t &iterQuantity);

ssize_t BinRecursionSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy1, dummy2;
    return BinRecursionSearch(arr, arrSize, elem, dummy1, dummy2);
}

ssize_t BinRecursionSearch(const int *arr, const size_t arrSize, const int elem, size_t &recursionDepth, size_t &iterQuantity)
{
    recursionDepth = 0;
    iterQuantity = 0;
    
    if (arrSize == 0)
        return -1;
    
    return binRecursionIteration(arr, elem, 0, static_cast<ssize_t>(arrSize) - 1, recursionDepth, iterQuantity);
}

ssize_t binRecursionIteration(const int *arr, const int elem, ssize_t leftIndex, ssize_t rightIndex, size_t &recursionDepth, size_t &iterQuantity)
{
    recursionDepth++;

    if (leftIndex > rightIndex)
        return -1;

    ssize_t middleIndex = leftIndex + (rightIndex - leftIndex + 1) / 2;

    iterQuantity++;
    if (arr[middleIndex] == elem)
        return middleIndex;

    iterQuantity++;
    if (arr[middleIndex] < elem)
        return binRecursionIteration(arr, elem, middleIndex + 1, rightIndex, recursionDepth, iterQuantity);
    
    return binRecursionIteration(arr, elem, leftIndex, middleIndex - 1, recursionDepth, iterQuantity);
}