#pragma once

#include <iostream>
#include <expected>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "data.hpp"

#define MENU_OPTIONS_QUANTITY 7


size_t UserInputNForce();
int UserInputXForce(int spanStart, int spanEnd);
size_t UserInputMenuOptionForce();
std::pair<int, int> UserInputDiapasonForce();


void PrintMainMenu(const int *arr, const size_t arrSize, const int x, const int generationSpanStart, const int generationSpanEnd);
void PrintDataInputMenu();