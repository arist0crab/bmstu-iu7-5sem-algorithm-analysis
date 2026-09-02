#pragma once

#include <iostream>
#include <expected>
#include "data.hpp"


std::expected<int, ParseError> UserInputX(int spanStart, int spanEnd);
std::expected<size_t, ParseError> UserInputMenuOption(size_t menuOptionsQuantity);


void PrintMainMenu();
void PrintDataInputMenu();