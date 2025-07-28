#include "MarketAPI.h"

namespace rqs
{

MarketAPI::MarketAPI()
    : IMarketAPI()
{}

EndPoint MarketAPI::epPrice() const
{
    return "/api/v3/ticker/price";
}

}
