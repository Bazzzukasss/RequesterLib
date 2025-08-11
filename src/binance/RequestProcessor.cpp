#include "src/binance/RequestProcessor.h"
#include "src/common/Utils.h"

namespace rqs
{
namespace binance
{

std::map<rqs::CurrencyPair, double> RequestProcessor::processPriceRequest(const ReplyData& data) const
{
    std::map<CurrencyPair, double> curencyPrices;
    for(const auto& dataMap : data)
    {
        auto price = dataMap.at("price");
        auto symbol = dataMap.at("symbol");

        curencyPrices.insert({utils::toCurrencyPair(symbol), std::stod(price)});
    }

    return curencyPrices;
}

} // namespace binance
} // namespace rqs
