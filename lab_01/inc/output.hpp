#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "data.hpp"


void PrintMainMenu(const int *arr, const size_t arrSize, const int x, const std::pair<int, int> &generationSpan);
void PrintDataInputMenu();

void PrintLinearBaseSearchResult(size_t index);
void PrintBinBaseSearchResult(size_t index);
void PrintBinImprovedSearchResult(size_t index);
void PrintBinRecursionSearchResult(size_t index);