#pragma once


#include <iostream>
#include <expected>
#include "data.hpp"
#include "colors.hpp"


size_t UserInputNForce();
int UserInputXForce(int spanStart, int spanEnd);
size_t UserInputMenuOptionForce(size_t menuOptionsQuantity);
int UserInputSpanStartInputForce();
int UserInputSpanEndInputForce();
std::pair<int, int> UserInputDiapasonForce();