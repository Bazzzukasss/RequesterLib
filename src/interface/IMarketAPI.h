#ifndef IMARKETAPI_H
#define IMARKETAPI_H

#include "src/common/Common.h"

namespace rqs
{

class IMarketAPI
{
public:
    virtual ~IMarketAPI() = default;

    virtual EndPoint epPrice() const = 0;
};

} // namespace rqs

#endif // IMARKETAPI_H
