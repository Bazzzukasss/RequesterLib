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
    std::map<CurrencySymbol, double> processPriceRequest(const std::vector<CurrencySymbol>& requestedSymbols, const ReplyData& replyData) const override;

private:
    ProcessedReplyData processReplyData(const std::vector<CurrencySymbol>& requestedSymbols, const ReplyData& replyData) const;
};

} // namespace bybit
} // namespace rqs

#endif // BYBIT_REQUESTPROCESSOR_H
