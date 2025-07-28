#include "Utils.h"

namespace rqs
{

std::string toString(const CurrencyType& currency)
{
    switch(currency)
    {
    case CurrencyType::USDT: return "USDT"; break;
        case CurrencyType::BTC: return "BTC"; break;
        case CurrencyType::ETH: return "ETH"; break;
        case CurrencyType::SOL: return "SOL"; break;
    }
    return "";
}

} // namespace rqs
