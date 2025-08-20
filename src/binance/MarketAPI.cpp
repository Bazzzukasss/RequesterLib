#include "src/binance/MarketAPI.h"

namespace rqs
{

namespace binance
{

MarketAPI::MarketAPI()
    : IMarketAPI()
{}

EndPoint MarketAPI::epPrice() const
{
    return "/api/v3/ticker/price";
}

std::string MarketAPI::testServerUrl() const
{
    return "https://testnet.binance.vision";
}

} // namespace binance
} // namespace rqs
