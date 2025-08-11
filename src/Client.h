#ifndef CLIENT_H
#define CLIENT_H

#include "src/interface/IClient.h"
#include <memory>

namespace rqs
{

class IClientImpl;

class Client : public IClient
{
public:
    Client(std::unique_ptr<IClientImpl> impl);

    bool connect(const std::string& serverUrl) override;
    bool request(const Request& request) override;

private:
    std::unique_ptr<IClientImpl> m_impl{nullptr};
};

} //namespace rqs

#endif // CLIENT_H
