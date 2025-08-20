#include "src/Requester.h"
#include "src/interface/IRequestCreator.h"
#include "src/interface/IRequestProcessor.h"
#include "src/interface/IClient.h"

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

bool Requester::setServerUrl(const std::string& serverUrl)
{
    return m_client->connect(serverUrl);
}

bool Requester::requestPrices(const std::vector<CurrencyPair>& currencyPairs,
                              const std::function<void (const std::map<CurrencyPair, double>&)> handler)
{
    auto request =
        m_requestCreator->createPriceRequest(currencyPairs, [handler, this](const ReplyData& data) {

        const auto& curencyPrices = m_requestProcessor->processPriceRequest(data);

        handler(curencyPrices);
    });

    return m_client->request(request);
}

} // namespace rqs
