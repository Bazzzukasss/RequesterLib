#include "src/binance/RequestCreator.h"
#include "src/common/Utils.h"
#include "src/interface/IMarketAPI.h"

namespace rqs
{
namespace binance
{

RequestCreator::RequestCreator(std::unique_ptr<IMarketAPI> marketAPI)
    : IRequestCreator()
    , m_marketAPI(std::move(marketAPI))
{}

Request RequestCreator::createPriceRequest(const std::vector<CurrencyPair>& currencyPairs, const RequestHandler& handler)
{
    std::string requestData;

    if (!currencyPairs.empty())
    {
        requestData = "?symbols=[";
        int i{0};
        for(const auto& currencyPair : currencyPairs)
        {
            const auto symbol = utils::toString(currencyPair.first) + utils::toString(currencyPair.second);
            requestData += "\"" + symbol + "\"";
            i++;
            if (i != currencyPairs.size())
            {
                requestData += ",";
            }
        }
        requestData += "]";
    }

    return {RequestType::Get, m_marketAPI->epPrice(), requestData, handler};
}

} // namespace binance
} // namespace rqs
