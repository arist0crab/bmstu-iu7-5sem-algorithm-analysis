#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "data.hpp"


void PrintMainMenu(const int *arr, const int *sortedArr, const size_t arrSize, const int x, const std::pair<int, int> &generationSpan);
void PrintResultTable(const size_t *algosIterationsQuantity, const ssize_t *algosResultsIndexes);
void PrintDataInputMenu();

void PrintLinearBaseSearchResult(size_t index);
void PrintBinBaseSearchResult(size_t index);
void PrintBinImprovedSearchResult(size_t index);
void PrintBinRecursionSearchResult(size_t index);