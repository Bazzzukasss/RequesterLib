#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

#include "src/interface/IRequestProcessor.h"

namespace rqs
{

namespace binance
{

class RequestProcessor : public IRequestProcessor
{
public:
    std::map<CurrencyPair, double> processPriceRequest(const ReplyData& data) const override;
};

} // namespace binance
} // namespace rqs

#endif // REQUESTPROCESSOR_H
