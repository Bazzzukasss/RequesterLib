#ifndef BYBIT_MARKETAPI_H
#define BYBIT_MARKETAPI_H

#include "src/interface/IMarketAPI.h"

namespace rqs
{

namespace bybit
{

class MarketAPI : public IMarketAPI
{
public:
    MarketAPI();

    EndPoint epPrice() const override;
    std::string testServerUrl() const override;
};

} // namespace bybit
} // namespace rqs

#endif // BYBIT_MARKETAPI_H
