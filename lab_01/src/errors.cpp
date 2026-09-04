#include "errors.hpp"


void HandleParseError(ParseError error)
{
    switch (error)
    {
        case ParseError::InvalidInputValue:
            std::cout << RED << "Введено неверное значение, попробуйте еще раз." << RESET << std::endl;
            break;

        case ParseError::InvalidInputDiapason:
            std::cout << RED << "Введенное значение не принадлежит требуемому диапазону. Попробуйте еще раз." << RESET << std::endl;
            break;
        
        default:
            break;
    }
}


void HandleUnknownError()
{
    std::cout << RED << "Произошла неизвестная ошибка. Я не знаю что делать. Попробуйте выключить и включить." << RESET << std::endl;
}