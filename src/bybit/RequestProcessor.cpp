#include "src/bybit/RequestProcessor.h"
#include "src/common/Utils.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace rqs
{
namespace bybit
{

std::map<rqs::CurrencySymbol, double> RequestProcessor::processPriceRequest(const std::vector<CurrencySymbol>& requestedSymbols, const ReplyData& replyData) const
{
    std::map<CurrencySymbol, double> curencyPrices;

    const auto& data = processReplyData(requestedSymbols, replyData);

    for(const auto& dataMap : data)
    {
        auto price = dataMap.at("ask1Price");
        auto symbol = dataMap.at("symbol");

        if (price != "")
        {
            curencyPrices.insert({symbol, std::stod(price)});
        }
    }

    return curencyPrices;
}


ProcessedReplyData RequestProcessor::processReplyData(const std::vector<CurrencySymbol>& requestedSymbols, const ReplyData& replyData) const
{
    ProcessedReplyData processedReplyData;

    std::set<CurrencySymbol> requestedSymbolsSet;
    for(const auto& requestedSymbol : requestedSymbols)
    {
        requestedSymbolsSet.insert(requestedSymbol);
    }

    const auto& resultMap = replyData.object().toVariantMap();
    const auto& resultValue = resultMap.value("result").toJsonObject().toVariantMap();
    const auto& listValue = resultValue.value("list");
    const auto& list = listValue.toJsonArray();

    for (int i = 0; i < list.size(); i++)
    {
        const QJsonObject& object = list.at(i).toObject();
        const auto& dataMap = utils::toStringMap(object.toVariantMap());
        const auto& symbol = dataMap.at("symbol");
        if (requestedSymbolsSet.count(symbol) || requestedSymbolsSet.empty())
        {
            processedReplyData.push_back(dataMap);
        }
    }

    return processedReplyData;
}

} // namespace bybit
} // namespace rqs
