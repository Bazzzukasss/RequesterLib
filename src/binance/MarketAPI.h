#ifndef MARKETAPI_H
#define MARKETAPI_H

#include "src/interface/IMarketAPI.h"

namespace rqs
{

namespace binance
{

class MarketAPI : public IMarketAPI
{
public:
    MarketAPI();

    EndPoint epPrice() const override;
};

} // namespace binance
} // namespace rqs

#endif // MARKETAPI_H
