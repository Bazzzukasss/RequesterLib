#include "Requester.h"
#include "IRequestFactory.h"
#include "IClient.h"

#include <QDebug>

namespace rqs
{

Requester::Requester(IClient* client, IRequestFactory* factory)
    : m_client(client)
    , m_requestFactory(factory)
{}

bool Requester::connect(const std::string& serverUrl)
{
    return m_client->connect(serverUrl);
}

void Requester::requestPrices(const std::vector<CryptoPair>& cryptoPairs)
{
    auto request =
        m_requestFactory->createPriceRequest(cryptoPairs, [this](const ReplyData& data) {
        processPrices(data);
    });

    m_client->request(request);
}

void Requester::processPrices(const ReplyData& data)
{
    qDebug()<<"processPrices:" << data;
}

} // namespace rqs
