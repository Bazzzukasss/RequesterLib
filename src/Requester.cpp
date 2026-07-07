#include "src/Requester.h"
#include "src/interface/IRequestCreator.h"
#include "src/interface/IRequestProcessor.h"
#include "src/interface/IClient.h"
#include "src/common/Common.h"

#include <QDebug>

namespace rqs
{

Requester::Requester(std::unique_ptr<IClient> client,
                     std::unique_ptr<IRequestCreator> reqCreator,
                     std::unique_ptr<IRequestProcessor> reqProcessor)
    : m_client(std::move(client))
    , m_requestCreator(std::move(reqCreator))
    , m_requestProcessor(std::move(reqProcessor))
{}

bool Requester::setMarketAccount(const MarketAccount& account)
{
    m_account = account;
    return m_client->connect(account.serverUrl);
}

bool Requester::requestPrices(const std::vector<CoinSymbol>& currencySymbols,
                              const std::function<void (const std::map<CoinSymbol, double>&)> handler)
{
    auto request =
        m_requestCreator->createPriceRequest(currencySymbols, [handler, currencySymbols, this](const ReplyData& data) {

        const auto& curencyPrices = m_requestProcessor->processPriceRequest(currencySymbols, data);

        handler(curencyPrices);
    });

    return m_client->request(request);
}

} // namespace rqs
