#include "binImprovedSearch.hpp"


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