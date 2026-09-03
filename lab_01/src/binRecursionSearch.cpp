#include "binRecursionSearch.hpp"


ssize_t binRecursionIteration(const int *arr, const int elem, size_t leftIndex, size_t rightIndex, size_t &recursionDepth);


ssize_t BinRecursionSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy;
    return BinRecursionSearch(arr, arrSize, elem, dummy);
}


ssize_t BinRecursionSearch(const int *arr, const size_t arrSize, const int elem, size_t &recursionDepth)
{
    recursionDepth = 0;
    return binRecursionIteration(arr, elem, 0, arrSize, recursionDepth);
}


ssize_t binRecursionIteration(const int *arr, const int elem, size_t leftIndex, size_t rightIndex, size_t &recursionDepth)
{
    recursionDepth++;

    if (leftIndex > rightIndex)
        return -1;

    size_t middleIndex = (rightIndex - leftIndex) / 2;

    if (arr[middleIndex] == elem)
        return middleIndex;

    if (arr[middleIndex] > elem)
        return binRecursionIteration(arr, elem, leftIndex, middleIndex - 1, recursionDepth);
    else
        return binRecursionIteration(arr, elem, middleIndex + 1, rightIndex, recursionDepth);
}


