
#include "Echo.h"


#include <iostream>
#include <ostream>

bool echoOn = false;

void echo(const std::string& message) {
    if (echoOn) {
        std::cout << message << std::endl;
    }
}