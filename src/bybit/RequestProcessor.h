#ifndef BYBIT_REQUESTPROCESSOR_H
#define BYBIT_REQUESTPROCESSOR_H

#include "src/interface/IRequestProcessor.h"

namespace rqs
{

namespace bybit
{

class RequestProcessor : public IRequestProcessor
{
public:
    std::map<CurrencyPair, double> processPriceRequest(const ReplyData& data) const override;
};

} // namespace bybit
} // namespace rqs

#endif // BYBIT_REQUESTPROCESSOR_H
