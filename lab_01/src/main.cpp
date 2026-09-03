#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "io.hpp"
#include "linearBaseSearch.hpp"
#include "binBaseSearch.hpp"
#include "binImprovedSearch.hpp"
#include "binRecursionSearch.hpp"


int* generateRandomArray(const size_t arrSize, int spanStart, int spanEnd)
{
    int *arr = new int[arrSize];

    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distrib(spanStart, spanEnd);

    for (size_t i = 0; i < arrSize; ++i)
        arr[i] = distrib(gen);

    return arr;
}


int main()
{
    size_t N = 10;  // TODO choose randomly
    int x = 67;  // TODO choose randomly
    int generationSpanStart = 0;
    int generationSpanEnd = 10000;

    bool isRunning = true;
    std::expected<size_t, ParseError> opt;

    int *arr = generateRandomArray(N, generationSpanStart, generationSpanEnd);

    while (isRunning)
    {
        PrintMainMenu(arr, N, x, generationSpanStart, generationSpanEnd);
        
        auto opt = UserInputMenuOption(MENU_OPTIONS_QUANTITY);
        while (!opt.has_value())
            opt = UserInputMenuOption(MENU_OPTIONS_QUANTITY);
        
        ssize_t index;
        switch (opt.value())
        {
            case 0:
                isRunning = false;
                break;

            case 1:
                // TODO
                std::cout << "Здесь должен быть ввод данных" << std::endl;
                break;

            case 2:
                index = LinearBaseSearch(arr, N, x);
                std::cout << "Индекс, найденный линейным алгоритмом: " << index << std::endl; 
                break;

            case 3:
                index = BinBaseSearch(arr, N, x);
                std::cout << "Индекс, найденный бинарным алгоритмом: " << index << std::endl; 
                break;

            case 4:
                index = BinImprovedSearch(arr, N, x);
                std::cout << "Индекс, найденный модифицированным бинарным алгоритмом: " << index << std::endl; 
                break;

            case 5:
                index = BinRecursionSearch(arr, N, x);
                std::cout << "Индекс, найденный рекурсивным бинарным алгоритмом: " << index << std::endl; 
                break;

            case 6:
                // TODO
                std::cout << "Здесь должен быть вывод итоговой таблички";
                break;
            
            default:
                // TODO
                break;
        }
    }

    delete[] arr;

    return 0;
}