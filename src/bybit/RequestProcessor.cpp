#include "src/bybit/RequestProcessor.h"
#include "src/common/Utils.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace rqs
{
namespace bybit
{

std::map<rqs::CurrencyPair, double> RequestProcessor::processPriceRequest(const ReplyData& replyData) const
{
    std::map<CurrencyPair, double> curencyPrices;

    const auto& data = processReplyData(replyData);

    for(const auto& dataMap : data)
    {
        auto price = dataMap.at("ask1Price");
        auto symbol = dataMap.at("symbol");

        curencyPrices.insert({utils::toCurrencyPair(symbol), std::stod(price)});
    }

    return curencyPrices;
}


ProcessedReplyData RequestProcessor::processReplyData(const ReplyData& replyData) const
{
    ProcessedReplyData processedReplyData;

    const auto& resultMap = replyData.object().toVariantMap();
    const auto& resultValue = resultMap.value("result").toJsonObject().toVariantMap();
    const auto& listValue = resultValue.value("list");
    const auto& list = listValue.toJsonArray();

    for (int i = 0; i < list.size(); i++)
    {
        const QJsonObject& object = list.at(i).toObject();
        processedReplyData.push_back(utils::toStringMap(object.toVariantMap()));

    }

    return processedReplyData;
}

} // namespace bybit
} // namespace rqs
