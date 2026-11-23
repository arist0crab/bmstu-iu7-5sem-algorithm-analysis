#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "data.hpp"


void PrintMainMenu(const int *arr, const int *sortedArr, const size_t arrSize, const int x, const std::pair<int, int> &generationSpan);
void PrintResultTable(const size_t *algosIterationsQuantity, const ssize_t *algosResultsIndexes);
void PrintDataInputMenu();

void PrintLinearBaseSearchResult(ssize_t index);
void PrintBinBaseSearchResult(ssize_t index);
void PrintBinImprovedSearchResult(ssize_t index);
void PrintBinRecursionSearchResult(ssize_t index);