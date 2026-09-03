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

void processDataInputOption(int *arr, size_t &N, int &x, std::pair<int, int> &generationSpan);
void processMenuOption(bool &isRunning, size_t &N, int *arr, int &x, std::pair<int, int> &generationSpan, const size_t opt);
void generateRandomArray(int*& arr, const size_t arrSize, const std::pair<int, int> &generationSpan);


int main()
{
    bool isRunning = true;

    int x;
    size_t N;
    size_t menuOpt;
    std::pair<int, int> generationSpan;

    int *arr = nullptr;
    
    UserInputNForce(N);
    UserInputDiapasonForce(generationSpan);
    UserInputXForce(x, generationSpan);
    generateRandomArray(arr, N, generationSpan);

    while (isRunning)
    {
        PrintMainMenu(arr, N, x, generationSpan);
        UserInputMenuOptionForce(MAIN_MENU_OPTIONS_QUANTITY, menuOpt);
        processMenuOption(isRunning, N, arr, x, generationSpan, menuOpt);
    }

    delete[] arr;

    return 0;
}


void processMenuOption(bool &isRunning, size_t &N, int *arr, int &x, std::pair<int, int> &generationSpan, const size_t opt)
{
    ssize_t index;
    switch (opt)
    {
        case 0:
            isRunning = false;
            break;

        case 1:
            processDataInputOption(arr, N, x, generationSpan);
            break;

        case 2:
            index = LinearBaseSearch(arr, N, x);
            PrintLinearBaseSearchResult(index);
            break;

        case 3:
            index = BinBaseSearch(arr, N, x);
            PrintBinBaseSearchResult(index);
            break;

        case 4:
            index = BinImprovedSearch(arr, N, x);
            PrintBinImprovedSearchResult(index);
            break;

        case 5:
            index = BinRecursionSearch(arr, N, x);
            PrintBinRecursionSearchResult(index);
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

void processDataInputOption(int *arr, size_t &N, int &x, std::pair<int, int> &generationSpan)
{
    size_t opt;
    PrintDataInputMenu();
    UserInputMenuOptionForce(DATA_INPUT_MENU_OPTIONS_QUANTITY, opt);

    switch (opt)
    {
        case 1:
            UserInputNForce(N);
            generateRandomArray(arr, N, generationSpan);
            break;

        case 2:
            UserInputXForce(x, generationSpan);
            break;

        case 3:
            UserInputDiapasonForce(generationSpan);
            generateRandomArray(arr, N, generationSpan);
            break;
        
        default:
            break;
    }
}


void generateRandomArray(int*& arr, const size_t arrSize, const std::pair<int, int> &generationSpan)
{
    delete[] arr;
    arr = new int[arrSize];

    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distrib(generationSpan.first, generationSpan.second);

    for (size_t i = 0; i < arrSize; ++i)
        arr[i] = distrib(gen);
}