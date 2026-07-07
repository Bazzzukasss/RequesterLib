#ifndef BINANCE_REQUESTPROCESSOR_H
#define BINANCE_REQUESTPROCESSOR_H

#include "src/interface/IRequestProcessor.h"

namespace rqs
{

namespace binance
{

class RequestProcessor : public IRequestProcessor
{
public:
    std::map<CurrencySymbol, double> processPriceRequest(const std::vector<CurrencySymbol>& requestedSymbols, const ReplyData& data) const override;

private:
    ProcessedReplyData processReplyData(const std::vector<CurrencySymbol>& requestedSymbols, const ReplyData& replyData) const;
};

} // namespace binance
} // namespace rqs

#endif // BINANCE_REQUESTPROCESSOR_H
