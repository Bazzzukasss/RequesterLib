#include "src/Builder.h"
#include "src/Requester.h"
#include "src/Client.h"
#include "src/binance/MarketAPI.h"
#include "src/binance/RequestCreator.h"
#include "src/binance/RequestProcessor.h"
#include "src/client/ClientImpl.h"

namespace rqs
{

std::unique_ptr<IRequester> Builder::binanceRequester() const
{
    std::unique_ptr<IClientImpl> clientImpl = std::make_unique<ClientImpl>();
    std::unique_ptr<IClient> client = std::make_unique<Client>(std::move(clientImpl));

    std::unique_ptr<IMarketAPI> marketAPI = std::make_unique<binance::MarketAPI>();
    auto serverUrl = marketAPI->testServerUrl();

    std::unique_ptr<IRequestCreator> creator = std::make_unique<binance::RequestCreator>(std::move(marketAPI));
    std::unique_ptr<IRequestProcessor> processor = std::make_unique<binance::RequestProcessor>();


    auto requester = std::make_unique<Requester>(std::move(client),
                                                 std::move(creator),
                                                 std::move(processor));
    requester->connect(serverUrl);

    return std::move(requester);
}

} // namespace rqs
