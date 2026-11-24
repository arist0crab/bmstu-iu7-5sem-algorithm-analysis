#include "binImprovedSearch.hpp"
#include <bit>

ssize_t BinImprovedSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy;
    return BinImprovedSearch(arr, arrSize, elem, dummy);
}

ssize_t BinImprovedSearch(const int *arr, const size_t arrSize, const int elem, size_t &iterQuantity)
{
    iterQuantity = 0;

    if (arr == nullptr || arrSize == 0)
        return -1;

    size_t beginIndex = 0;
    size_t step = std::bit_ceil(arrSize) / 2;

    for (; step != 0; step /= 2)
    {
        if (beginIndex + step < arrSize)
        {
            iterQuantity++;
            if (arr[beginIndex + step] < elem)
                beginIndex += step;
        }
    }

    iterQuantity++;
    const size_t pos = beginIndex + (arr[beginIndex] < elem ? 1 : 0);

    if (pos < arrSize)
    {
        iterQuantity++;
        if (arr[pos] == elem)
            return static_cast<ssize_t>(pos);
    }

    return -1;
}