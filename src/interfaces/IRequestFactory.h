#ifndef IREQUESTFACTORY_H
#define IREQUESTFACTORY_H

#include "Common.h"

namespace rqs
{

class IRequestFactory
{
public:
    virtual ~IRequestFactory() = default;

    virtual Request createPriceRequest(const std::vector<CryptoPair>& cryptoPairs,
                                       const RequestHandler& handler) = 0;
};

} // namespace rqs


#endif // IREQUESTFACTORY_H
