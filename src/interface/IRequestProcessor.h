#ifndef IREQUESTPROCESSOR_H
#define IREQUESTPROCESSOR_H

#include "src/common/Common.h"

namespace rqs
{

class IRequestProcessor
{
public:
    virtual ~IRequestProcessor() = default;

    virtual std::map<CurrencyPair, double> processPriceRequest(const ReplyData& replyData) const = 0;
};

} // namespace rqs

#endif // IREQUESTPROCESSOR_H
