#include "RequestFactory.h"
#include "IMarketAPI.h"
#include "Utils.h"

namespace rqs
{

RequestFactory::RequestFactory(IMarketAPI* marketAPI)
    : IRequestFactory()
    , m_marketAPI(marketAPI)
{}

Request RequestFactory::createPriceRequest(const std::vector<CryptoPair>& cryptoPairs, const RequestHandler &handler)
{
    std::string requestData = "?symbols=[";
    int i{0};
    for(const auto& cryptoPair : cryptoPairs)
    {
        requestData += "\"" + toString(cryptoPair.first) + toString(cryptoPair.second) + "\"";
        i++;
        if (i != cryptoPairs.size())
        {
            requestData += ",";
        }
    }
    requestData += "]";

    return {RequestType::Get, m_marketAPI->epPrice(), requestData, handler};
}

} // namespace rqs
