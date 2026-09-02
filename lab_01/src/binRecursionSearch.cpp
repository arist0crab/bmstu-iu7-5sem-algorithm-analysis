#include "binRecursionSearch.hpp"


ssize_t binRecursionIteration(const std::vector<int> &arr, const int elem, size_t leftIndex, size_t rightIndex);


ssize_t BinRecursionSearch(const std::vector<int> &arr, const int elem)
{
    return binRecursionIteration(arr, elem, 0, arr.size());
}


ssize_t binRecursionIteration(const std::vector<int> &arr, const int elem, size_t leftIndex, size_t rightIndex)
{
    if (leftIndex > rightIndex)
        return -1;

    size_t middleIndex = (rightIndex - leftIndex) / 2;

    if (arr[middleIndex] == elem)
        return middleIndex;

    if (arr[middleIndex] > elem)
        return binRecursionIteration(arr, elem, leftIndex, middleIndex - 1);
    else
        return binRecursionIteration(arr, elem, middleIndex + 1, rightIndex);
}


