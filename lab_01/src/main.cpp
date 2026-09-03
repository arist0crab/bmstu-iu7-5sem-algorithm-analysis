#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "output.hpp"
#include "input.hpp"
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

void processDataInputOption(size_t &N, int &x, int &generationSpanStart, int &generationSpanEnd)
{
    PrintDataInputMenu();
    size_t opt = UserInputMenuOptionForce(DATA_INPUT_MENU_OPTIONS_QUANTITY);

    switch (opt)
    {
        case 1:
            N = UserInputNForce();
            break;

        case 2:
            x = UserInputXForce(generationSpanStart, generationSpanEnd);
            break;

        case 3:
        {
            std::pair<int, int> diapason = UserInputDiapasonForce();
            generationSpanStart = diapason.first;
            generationSpanEnd = diapason.second;
            break;
        }
        
        default:
            break;
    }
}


int main()
{
    bool isRunning = true;
    std::expected<size_t, ParseError> opt;

    size_t N = UserInputNForce();
    
    std::pair diapason = UserInputDiapasonForce();
    int generationSpanStart = diapason.first;
    int generationSpanEnd = diapason.second;

    int x = UserInputXForce(generationSpanStart, generationSpanEnd);

    int *arr = generateRandomArray(N, generationSpanStart, generationSpanEnd);

    while (isRunning)
    {
        PrintMainMenu(arr, N, x, generationSpanStart, generationSpanEnd);
        
        size_t opt = UserInputMenuOptionForce(MAIN_MENU_OPTIONS_QUANTITY);
        
        ssize_t index;
        switch (opt)
        {
            case 0:
                isRunning = false;
                break;

            case 1:
                processDataInputOption(N, x, generationSpanStart, generationSpanEnd);
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