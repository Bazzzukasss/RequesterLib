#ifndef IREQUESTER_H
#define IREQUESTER_H

#include "src/common/Common.h"

namespace rqs
{

class IRequester
{
public:
    virtual ~IRequester() = default;

    virtual bool setMarketAccount(const MarketAccount& account) = 0;
    virtual bool requestPrices(const std::vector<CurrencySymbol>& currencyPairs,
                               const std::function<void(const std::map<CurrencySymbol, double>&)> handler) = 0;
};

} // namespace rqs

#endif // IREQUESTER_H
