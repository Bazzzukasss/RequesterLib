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

Request RequestCreator::createPriceRequest(const std::vector<CoinSymbol>& currencySymbols, const RequestHandler& handler)
{
    std::string requestData;

    if (!currencySymbols.empty())
    {
        requestData = "?symbols=[";
        int i{0};
        for(const auto& currencySymbol : currencySymbols)
        {
            requestData += "\"" + currencySymbol + "\"";
            i++;
            if (i != currencySymbols.size())
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
