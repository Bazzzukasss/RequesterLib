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
    return "/v5/market/tickers";
}

std::string MarketAPI::testServerUrl() const
{
    return "https://testnet.binance.vision";
}

} // namespace bybit
} // namespace rqs
