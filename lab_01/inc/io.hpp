#pragma once

#include <iostream>
#include <expected>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "data.hpp"

#define MENU_OPTIONS_QUANTITY 7


std::expected<int, ParseError> UserInputX(int spanStart, int spanEnd);
std::expected<size_t, ParseError> UserInputMenuOption(size_t menuOptionsQuantity);


void PrintMainMenu(const int *arr, const size_t arrSize, const int x, const int generationSpanStart, const int generationSpanEnd);
void PrintDataInputMenu();