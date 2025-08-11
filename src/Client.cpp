#include "src/Client.h"
#include "src/interface/IClientImpl.h"

namespace rqs
{

Client::Client(std::unique_ptr<IClientImpl> impl)
    : IClient()
    , m_impl(std::move(impl))
{}

bool Client::connect(const std::string& serverUrl)
{
    return m_impl->connect(serverUrl);
}

bool Client::request(const Request& request)
{
    return m_impl->request(request.type,
                           request.endpoint,
                           request.data,
                           request.handler);
}

} //namespace rqs
