#include "error.h"
#include <string>
#include <iostream>


namespace Error {
    int errorCount = 0;
    double reportError(const std::string& message) {
        errorCount++;
        std::cerr << "Error: " << message << '\n';
        return 1;
    }

}//namespace Error