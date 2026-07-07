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

Request RequestCreator::createPriceRequest(const std::vector<CurrencySymbol>& currencySymbols, const RequestHandler& handler)
{
    std::string requestData;
    if (currencySymbols.size() == 1)
    {
        auto currencySymbol = currencySymbols.at(0);
        requestData = "?category=spot&symbol=" + currencySymbol;
    }
    else
    {
        requestData = "?category=spot";
    }

    return {RequestType::Get, m_marketAPI->epPrice(), requestData, handler};
}

} // namespace bybit
} // namespace rqs
