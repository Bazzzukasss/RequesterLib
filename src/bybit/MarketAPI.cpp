#include "src/bybit/MarketAPI.h"

namespace rqs
{

namespace bybit
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

} // namespace bybit
} // namespace rqs
