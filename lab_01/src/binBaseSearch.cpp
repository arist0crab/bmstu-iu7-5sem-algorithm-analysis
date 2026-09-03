#include "binBaseSearch.hpp"


ssize_t BinBaseSearch(const int *arr, const size_t arrSize, const int elem)
{
    size_t dummy;
    return BinBaseSearch(arr, arrSize, elem, dummy);
}


ssize_t BinBaseSearch(const int *arr, const size_t arrSize, const int elem, size_t &iterQuantity)
{
    iterQuantity = 0;
    ssize_t start_ind = 0;
    ssize_t end_ind = arrSize - 1;

    while (start_ind <= end_ind)
    {
        iterQuantity++;
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
