#ifndef REQUESTCREATOR_H
#define REQUESTCREATOR_H

#include "src/interface/IRequestCreator.h"
#include <memory>

namespace rqs
{

class IMarketAPI;

namespace binance
{

class RequestCreator : public IRequestCreator
{
public:
    RequestCreator(std::unique_ptr<IMarketAPI> marketAPI);

    Request createPriceRequest(const std::vector<CurrencyPair>& currencyPairs,
                               const RequestHandler& handler) override;

private:
    std::unique_ptr<IMarketAPI> m_marketAPI{nullptr};
};

} // namespace binance
} // namespace rqs

#endif // REQUESTCREATOR_H
