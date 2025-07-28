#ifndef COMMON_H
#define COMMON_H

#include <map>
#include <string>
#include <functional>

namespace rqs
{

enum class CurrencyType
{
    USDT,
    BTC,
    ETH,
    SOL
};

enum class RequestType
{
    Get,
    Put,
    Post,
    Patch
};

using CryptoPair = std::pair<CurrencyType, CurrencyType>;
using ReplyData = std::vector<std::map<std::string, std::string>>;
using RequestData = std::string;
using EndPoint = std::string;
using RequestHandler = std::function<void(ReplyData)>;

struct Request
{
    rqs::RequestType type;
    rqs::EndPoint endpoint;
    rqs::RequestData data;
    rqs::RequestHandler handler;
};

} // namespace rqs

#endif // COMMON_H
