#pragma once

#include <iostream>

namespace Error {

/**
 * @brief Global counter tracking the number of errors encountered.
 *
 * This variable is declared here with `extern`, indicating that it is
 * only a declaration. The actual definition resides in the corresponding
 * implementation file. The counter is incremented whenever an error is
 * reported through reportError().
 */
 extern int errorCount;

/**
 * @brief Reports an error and returns a fallback value.
 *
 * This function handles malformed or incomplete expressions encountered
 * during parsing or evaluation. It increments Error::errorCount, prints
 * or logs the provided message, and returns a default numeric value so
 * that the calculator can continue operating even after an error occurs.
 *
 * @param message Description of the error condition.
 * @return A numeric fallback value used when evaluation cannot proceed
 *         normally due to the error.
 */
double reportError(const std::string& message);

} // namespace Error
