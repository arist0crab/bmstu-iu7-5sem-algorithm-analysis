#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <expected>
#include <algorithm>

#include "errors.hpp"

void UserInputNForce(size_t &N);
void UserInputXForce(int &X);
void UserInputMenuOptionForce(const size_t menuOptionsQuantity, size_t &result);
void UserInputDiapasonForce(std::pair<int, int> &generationSpan);
void UserInputArrayForce(int*& arr, int*& sortedArr, const size_t arrSize);