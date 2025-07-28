#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

#include "IRequestFactory.h"

namespace rqs
{

class IMarketAPI;

class RequestFactory : public IRequestFactory
{
public:
    RequestFactory(IMarketAPI* marketAPI);

    Request createPriceRequest(const std::vector<CryptoPair>& cryptoPairs,
                               const RequestHandler& handler) override;

private:
    IMarketAPI* m_marketAPI{nullptr};
};

} // namespace rqs

#endif // REQUESTFACTORY_H
