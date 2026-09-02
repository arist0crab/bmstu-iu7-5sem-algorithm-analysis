#include "algos.hpp"


ssize_t binRecursionIteration(const std::vector<int> &arr, const int elem, size_t leftIndex, size_t rightIndex);


ssize_t LinearBaseSearch(const std::vector<int> &arr, const int elem)
{
    for (size_t i = 0; i < arr.size(); ++i)
        if (arr[i] == elem)
            return i;

    return -1;
}


ssize_t BinBaseSearch(const std::vector<int> &arr, const int elem)
{
    ssize_t start_ind = 0;
    ssize_t end_ind = arr.size() - 1;

    while (start_ind <= end_ind)
    {
        ssize_t cur_ind = (end_ind - start_ind) / 2 + start_ind;

        if (arr[cur_ind] < elem)
            start_ind = cur_ind + 1;
        else if (arr[cur_ind] > elem)
            end_ind = cur_ind - 1;
        else
            return cur_ind;
    }
    
    return -1;
}


ssize_t BinImprovedSearch(const std::vector<int> &arr, const int elem)
{
    size_t length = arr.size();

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
        if (arr[beginIndex + step] < elem)
            beginIndex += step;
    
    return beginIndex + (arr[beginIndex] < elem);
}

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


