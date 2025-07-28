#ifndef MARKETAPI_H
#define MARKETAPI_H

#include "IMarketAPI.h"

namespace rqs
{

class MarketAPI : public IMarketAPI
{
public:
    MarketAPI();

    EndPoint epPrice() const override;
};

} // namespace rqs

#endif // MARKETAPI_H
