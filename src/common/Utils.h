#ifndef UTILS_H
#define UTILS_H

#include "src/common/Common.h"

#include <string>

namespace rqs
{
namespace utils
{

std::string toString(const CurrencyType& currency);
CurrencyType toCurrencyType(const std::string& str);
CurrencyPair toCurrencyPair(const std::string& str);

} //namspace utils
} //namspace rqs

#endif // UTILS_H
