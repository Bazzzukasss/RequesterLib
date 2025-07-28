#ifndef REQUESTER_H
#define REQUESTER_H

#include "IRequester.h"

namespace rqs
{

class IClient;
class IRequestFactory;

class Requester : public IRequester
{
public:
    Requester(IClient* client, IRequestFactory* factory);

    bool connect(const std::string& serverUrl) override;

    void requestPrices(const std::vector<CryptoPair>& cryptoPairs) override;
    void processPrices(const ReplyData& data) override;

private:
    IClient* m_client{nullptr};
    IRequestFactory* m_requestFactory{nullptr};
};

} // namespace rqs

#endif // REQUESTER_H
