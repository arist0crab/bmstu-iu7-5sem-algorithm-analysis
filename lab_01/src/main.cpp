#include <iostream>
#include <random>
#include <algorithm>

#include "output.hpp"
#include "input.hpp"
#include "linearBaseSearch.hpp"
#include "binBaseSearch.hpp"
#include "binImprovedSearch.hpp"
#include "binRecursionSearch.hpp"

void processDataInputOption(int*& arr, int*& sortedArr, size_t &N, int &x, std::pair<int, int> &generationSpan);
void processResultTableOutput(const int *arr, const int* sortedArr, const size_t N, const int x);
void processMenuOption(bool &isRunning, size_t &N, int*& arr, int*& sortedArr, int &x, std::pair<int, int> &generationSpan, const size_t opt);
void generateRandomArray(int*& arr, int*& sortedArr, const size_t arrSize, const std::pair<int, int> &generationSpan, const int x);


int main()
{
    bool isRunning = true;

    int x;
    size_t N;
    size_t menuOpt;
    std::pair<int, int> generationSpan;

    int *arr = nullptr;
    int *sortedArr = nullptr;
    
    UserInputNForce(N);
    UserInputDiapasonForce(generationSpan);
    UserInputXForce(x, generationSpan);
    generateRandomArray(arr, sortedArr, N, generationSpan, x);

    while (isRunning)
    {
        PrintMainMenu(arr, sortedArr, N, x, generationSpan);
        UserInputMenuOptionForce(MAIN_MENU_OPTIONS_QUANTITY, menuOpt);
        processMenuOption(isRunning, N, arr, sortedArr, x, generationSpan, menuOpt);
    }

    delete[] arr;
    delete[] sortedArr;

    return 0;
}


void processMenuOption(bool &isRunning, size_t &N, int*& arr, int*& sortedArr, int &x, std::pair<int, int> &generationSpan, const size_t opt)
{
    ssize_t index;
    switch (opt)
    {
        case 0:
            isRunning = false;
            break;

        case 1:
            processDataInputOption(arr, sortedArr, N, x, generationSpan);
            break;

        case 2:
            generateRandomArray(arr, sortedArr, N, generationSpan, x);
            break;

        case 3:
            index = LinearBaseSearch(arr, N, x);
            PrintLinearBaseSearchResult(index);
            break;

        case 4:
            index = BinBaseSearch(sortedArr, N, x);
            PrintBinBaseSearchResult(index);
            break;

        case 5:
            index = BinImprovedSearch(sortedArr, N, x);
            PrintBinImprovedSearchResult(index);
            break;

        case 6:
            index = BinRecursionSearch(sortedArr, N, x);
            PrintBinRecursionSearchResult(index);
            break;

        case 7:
            processResultTableOutput(arr, sortedArr, N, x);
            break;
        
        default:
            HandleUnknownError();
            break;
    }
}


void processResultTableOutput(const int *arr, const int* sortedArr, const size_t N, const int x)
{
    size_t linearBaseIterationsQuantity = 0;
    size_t binBaseIterationsQuantity = 0;
    size_t binImprovedIterationsQuantity = 0;
    size_t binRecursionIterationsQuantity = 0;

    ssize_t linearBaseIndex = LinearBaseSearch(arr, N, x, linearBaseIterationsQuantity);
    ssize_t binBaseIndex = BinBaseSearch(sortedArr, N, x, binBaseIterationsQuantity);
    ssize_t binImprovedIndex = BinImprovedSearch(sortedArr, N, x, binImprovedIterationsQuantity);
    ssize_t binRecursionIndex = BinRecursionSearch(sortedArr, N, x, binRecursionIterationsQuantity);

    size_t algosIterationsQuantity[] = { linearBaseIterationsQuantity, binBaseIterationsQuantity, binImprovedIterationsQuantity, binRecursionIterationsQuantity };
    ssize_t algosResultsIndexes[] = { linearBaseIndex, binBaseIndex, binImprovedIndex, binRecursionIndex };

    PrintResultTable(algosIterationsQuantity, algosResultsIndexes);
}


void processDataInputOption(int*& arr, int*& sortedArr, size_t &N, int &x, std::pair<int, int> &generationSpan)
{
    size_t opt;
    PrintDataInputMenu();
    UserInputMenuOptionForce(DATA_INPUT_MENU_OPTIONS_QUANTITY, opt);

    switch (opt)
    {
        case 1:
            UserInputNForce(N);
            generateRandomArray(arr, sortedArr, N, generationSpan, x);
            break;

        case 2:
            UserInputXForce(x, generationSpan);
            break;

        case 3:
            UserInputDiapasonForce(generationSpan);
            generateRandomArray(arr, sortedArr, N, generationSpan, x);
            break;
        
        default:
            HandleUnknownError();
            break;
    }
}


void generateRandomArray(int*& arr, int*& sortedArr, const size_t arrSize, const std::pair<int, int> &generationSpan, const int x)
{
    delete[] arr;
    delete[] sortedArr;

    arr = new int[arrSize];
    sortedArr = new int[arrSize];

    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<size_t> distribIndexes(0, arrSize - 1);
    std::uniform_int_distribution<int> distribElems(generationSpan.first, generationSpan.second);

    size_t randomIndex = distribIndexes(gen);

    for (size_t i = 0; i < arrSize; ++i)
        if (i != randomIndex)
            arr[i] = distribElems(gen);
    arr[randomIndex] = x;

    std::copy(arr, arr + arrSize, sortedArr);
    std::sort(sortedArr, sortedArr + arrSize);
}