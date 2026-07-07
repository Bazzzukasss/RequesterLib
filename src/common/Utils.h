#ifndef UTILS_H
#define UTILS_H

#include "src/common/Common.h"

namespace rqs
{
namespace utils
{

std::string toCurrencySymbol(const CurrencyPair& currencyPair);
//std::string toString(const CurrencyType& currency);
//CurrencyType toCurrencyType(const std::string& str);
//CurrencyPair toCurrencyPair(const std::string& str);
std::map<std::string, std::string> toStringMap(const QVariantMap& varMap);

} //namspace utils
} //namspace rqs

#endif // UTILS_H
