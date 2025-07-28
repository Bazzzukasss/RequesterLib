#ifndef IREQUESTER_H
#define IREQUESTER_H

#include "Common.h"

namespace rqs
{

class IRequester
{
public:
    virtual ~IRequester() = default;

    virtual bool connect(const std::string& serverUrl) = 0;
    virtual void requestPrices(const std::vector<CryptoPair>& cryptoPairs) = 0;
    virtual void processPrices(const ReplyData& data) = 0;
};

} // namespace rqs

#endif // IREQUESTER_H
