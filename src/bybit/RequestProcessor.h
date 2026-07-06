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
    std::map<CurrencyPair, double> processPriceRequest(const std::vector<CurrencyPair>& currencyPairs, const ReplyData& replyData) const override;

private:
    ProcessedReplyData processReplyData(const std::vector<CurrencyPair>& currencyPairs, const ReplyData& replyData) const;
};

} // namespace bybit
} // namespace rqs

#endif // BYBIT_REQUESTPROCESSOR_H
