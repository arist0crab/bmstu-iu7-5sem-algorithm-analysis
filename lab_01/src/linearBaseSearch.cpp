#include "linearBaseSearch.hpp"


ssize_t LinearBaseSearch(const std::vector<int> &arr, const int elem)
{
    for (size_t i = 0; i < arr.size(); ++i)
        if (arr[i] == elem)
            return i;

    return -1;
}