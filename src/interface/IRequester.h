#ifndef IREQUESTER_H
#define IREQUESTER_H

#include "src/common/Common.h"

namespace rqs
{

class IRequester
{
public:
    virtual ~IRequester() = default;

    virtual bool connect(const std::string& serverUrl) = 0;
    virtual bool requestPrices(const std::vector<CurrencyPair>& currencyPairs,
                               const std::function<void(const std::map<CurrencyPair, double>&)> handler) = 0;
};

} // namespace rqs

#endif // IREQUESTER_H
