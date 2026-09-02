#include "binBaseSearch.hpp"


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
