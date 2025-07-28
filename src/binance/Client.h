#ifndef CLIENT_H
#define CLIENT_H

#include "IClient.h"

namespace rqs
{

class IClientImpl;

class Client : public IClient
{
public:
    Client(IClientImpl* impl);

    bool connect(const std::string& serverUrl) override;
    bool request(const Request& request) override;

private:
    IClientImpl* m_impl{nullptr};
};

} //namespace rqs

#endif // CLIENT_H
