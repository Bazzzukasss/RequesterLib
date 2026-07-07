#ifndef REQUESTER_H
#define REQUESTER_H

#include "src/interface/IRequester.h"

#include <memory>

namespace rqs
{

class IMarketAPI;
class IClient;
class IRequestCreator;
class IRequestProcessor;

class Requester : public IRequester
{
public:
    Requester(std::unique_ptr<IClient> client,
              std::unique_ptr<IRequestCreator> reqCreator,
              std::unique_ptr<IRequestProcessor> reqProcessor);

    bool setMarketAccount(const MarketAccount& account) override;
    bool requestPrices(const std::vector<CurrencySymbol>& currencySymbols,
                       const std::function<void (const std::map<CurrencySymbol, double>&)> handler) override;

private:
    std::unique_ptr<IClient> m_client{nullptr};
    std::unique_ptr<IRequestCreator> m_requestCreator{nullptr};
    std::unique_ptr<IRequestProcessor> m_requestProcessor{nullptr};
    MarketAccount m_account;
};

} // namespace rqs

#endif // REQUESTER_H
