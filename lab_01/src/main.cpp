#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

#include "io.hpp"


std::vector<int> generateRandomIntVector(const size_t arrSize, int spanStart = 0, int spanEnd = 10000)
{
    std::vector<int> arr;

    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distrib(spanStart, spanEnd);

    for (size_t i = 0; i < arrSize; ++i)
        arr.push_back(distrib(gen));

    return arr;
}


int main()
{

    PrintMainMenu();
    auto opt = UserInputX(0, 7);

    if (opt.has_value())
        std::cout << "Введено: " << opt.value() << std::endl;
    else
        std::cout << "Ошибка: " << opt.error() << std::endl;
    

    return 0;
}