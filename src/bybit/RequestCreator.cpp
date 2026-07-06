#include "src/bybit/RequestCreator.h"
#include "src/common/Utils.h"
#include "src/interface/IMarketAPI.h"

namespace rqs
{
namespace bybit
{

RequestCreator::RequestCreator(std::unique_ptr<IMarketAPI> marketAPI)
    : IRequestCreator()
    , m_marketAPI(std::move(marketAPI))
{}

Request RequestCreator::createPriceRequest(const std::vector<CurrencyPair>& currencyPairs, const RequestHandler& handler)
{
    std::string requestData;
    if (currencyPairs.size() == 1)
    {
        auto currencyPair = currencyPairs.at(0);
        auto symbol = utils::toString(currencyPair.first) + utils::toString(currencyPair.second);
        requestData = "?category=spot&symbol=" + symbol;
    }
    else
    {
        requestData = "?category=spot";
    }

    return {RequestType::Get, m_marketAPI->epPrice(), requestData, handler};
}

} // namespace bybit
} // namespace rqs
