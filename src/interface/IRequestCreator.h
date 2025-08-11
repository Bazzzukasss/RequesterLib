#ifndef IREQUESTCREATOR_H
#define IREQUESTCREATOR_H

#include "src/common/Common.h"

namespace rqs
{

class IRequestCreator
{
public:
    virtual ~IRequestCreator() = default;

    virtual Request createPriceRequest(const std::vector<CurrencyPair>& currencyPairs,
                                       const RequestHandler& handler) = 0;
};

} // namespace rqs


#endif // IREQUESTCREATOR_H
