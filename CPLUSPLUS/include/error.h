#pragma once

#include <iostream>

namespace Error {
    extern int errorCount;
    double reportError(const std::string& message);       
}