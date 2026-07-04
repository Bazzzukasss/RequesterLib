#ifndef BYBIT_REQUESTCREATOR_H
#define BYBIT_REQUESTCREATOR_H

#include "src/interface/IRequestCreator.h"
#include <memory>

namespace rqs
{

class IMarketAPI;

namespace bybit
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

} // namespace bybit
} // namespace rqs

#endif // BYBIT_REQUESTCREATOR_H
