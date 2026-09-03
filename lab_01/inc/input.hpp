#pragma once


#include <iostream>
#include <expected>
#include "data.hpp"
#include "colors.hpp"


void UserInputMenuOptionForce(const size_t menuOptionsQuantity, size_t &result);
void UserInputXForce(int &X, const std::pair<int, int> &generationSpan);
void UserInputDiapasonForce(std::pair<int, int> &generationSpan);
void UserInputNForce(size_t &N);