#include "src/bybit/RequestProcessor.h"
#include "src/common/Utils.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace rqs
{
namespace bybit
{

std::map<rqs::CurrencyPair, double> RequestProcessor::processPriceRequest(const std::vector<CurrencyPair>& currencyPairs, const ReplyData& replyData) const
{
    std::map<CurrencyPair, double> curencyPrices;

    const auto& data = processReplyData(currencyPairs, replyData);

    for(const auto& dataMap : data)
    {
        auto price = dataMap.at("ask1Price");
        auto symbol = dataMap.at("symbol");

        curencyPrices.insert({utils::toCurrencyPair(symbol), std::stod(price)});
    }

    return curencyPrices;
}


ProcessedReplyData RequestProcessor::processReplyData(const std::vector<CurrencyPair>& currencyPairs, const ReplyData& replyData) const
{
    ProcessedReplyData processedReplyData;

    std::set<std::string> requestedSymbols;
    for(const auto& currencyPair : currencyPairs)
    {
        requestedSymbols.insert(utils::toCurrencySymbol(currencyPair));
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
        if (requestedSymbols.count(symbol))
        {
            processedReplyData.push_back(dataMap);
        }
    }

    return processedReplyData;
}

} // namespace bybit
} // namespace rqs
