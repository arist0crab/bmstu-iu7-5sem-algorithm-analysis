#include "binRecursionSearch.hpp"

ssize_t binRecursionIteration(const int *arr, const int elem, ssize_t leftIndex, ssize_t rightIndex, size_t &recursionDepth);

ssize_t BinRecursionSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy;
    return BinRecursionSearch(arr, arrSize, elem, dummy);
}

ssize_t BinRecursionSearch(const int *arr, const size_t arrSize, const int elem, size_t &recursionDepth)
{
    recursionDepth = 0;
    
    if (arrSize == 0)
        return -1;
    
    return binRecursionIteration(arr, elem, 0, static_cast<ssize_t>(arrSize) - 1, recursionDepth);
}

ssize_t binRecursionIteration(const int *arr, const int elem, ssize_t leftIndex, ssize_t rightIndex, size_t &recursionDepth)
{
    recursionDepth++;

    if (leftIndex > rightIndex)
        return -1;

    ssize_t middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

    if (arr[middleIndex] == elem)
        return middleIndex;

    if (arr[middleIndex] > elem)
        return binRecursionIteration(arr, elem, leftIndex, middleIndex - 1, recursionDepth);
    return binRecursionIteration(arr, elem, middleIndex + 1, rightIndex, recursionDepth);

}