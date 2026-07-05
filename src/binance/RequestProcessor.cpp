#include "src/binance/RequestProcessor.h"
#include "src/common/Utils.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace rqs
{
namespace binance
{

std::map<rqs::CurrencyPair, double> RequestProcessor::processPriceRequest(const ReplyData& replyData) const
{
    std::map<CurrencyPair, double> curencyPrices;

    const auto& data = processReplyData(replyData);

    for(const auto& dataMap : data)
    {
        const auto& price = dataMap.at("price");
        const auto& symbol = dataMap.at("symbol");

        curencyPrices.insert({utils::toCurrencyPair(symbol), std::stod(price)});
    }

    return curencyPrices;
}

ProcessedReplyData RequestProcessor::processReplyData(const ReplyData& replyData) const
{
    ProcessedReplyData processedReplyData;
    //Turn document into json array: Have to read the value from an std::optional object returned from doc.
    if (replyData.isArray())
    {
        QJsonArray array = replyData.array();

        for ( int i = 0; i < array.size(); i++)
        {
            const QJsonObject& object = array.at(i).toObject();
            processedReplyData.push_back(utils::toStringMap(object.toVariantMap()));
        }
        //qDebug() << "Array response:" << replyData;
    }
    else if(replyData.isObject())
    {
        processedReplyData.push_back(utils::toStringMap(replyData.object().toVariantMap()));
        //qDebug() << "Object responce:" << replyData;
    }
    else
    {
        qCritical() << "Unknown responce format!";
    }

    return processedReplyData;
}

} // namespace binance
} // namespace rqs
