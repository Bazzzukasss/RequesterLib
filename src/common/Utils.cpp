#include "src/common/Utils.h"

namespace rqs
{
namespace utils
{

const std::map<CurrencyType, std::string> CurrencyMap {
    {CurrencyType::USDT, "USDT"},
    {CurrencyType::BTC, "BTC"},
    {CurrencyType::ETH, "ETH"},
    {CurrencyType::SOL, "SOL"},
    {CurrencyType::LINK, "LINK"},
};

std::string toString(const CurrencyType& currency)
{
    auto itr = CurrencyMap.find(currency);
    return itr != CurrencyMap.end() ? itr->second : "";
}

CurrencyType toCurrencyType(const std::string& str)
{
    auto itr =
        std::find_if(CurrencyMap.begin(),
                     CurrencyMap.end(),
                     [&](const std::pair<CurrencyType, std::string> item) {
                                return item.second == str;
                            });
    return itr != CurrencyMap.end() ? itr->first : CurrencyType::UNKNOWN;
}

CurrencyPair toCurrencyPair(const std::string& str)
{
    for(const auto& item : CurrencyMap)
    {
        auto pos = str.find(item.second);
        if (pos != std::string::npos)
        {
            CurrencyType currency1;
            CurrencyType currency2;
            if (pos == 0)
            {
                currency1 = item.first;
                currency2 = toCurrencyType(str.substr(strlen(item.second.c_str())));
            }
            else
            {
                currency2 = item.first;
                currency1 = toCurrencyType(str.substr(0, pos));
            }

            return CurrencyPair(currency1, currency2);
        }
    }

    return {CurrencyType::UNKNOWN, CurrencyType::UNKNOWN};
}

} // namespace utils
} // namespace rqs
