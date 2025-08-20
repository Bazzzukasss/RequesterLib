#ifndef COMMON_H
#define COMMON_H

#include <map>
#include <string>
#include <functional>

namespace rqs
{

enum class CurrencyType
{
    UNKNOWN,
    USDT,
    BTC,
    ETH,
    SOL,
    LINK
};

enum class RequestType
{
    Get,
    Put,
    Post,
    Patch
};

using CurrencyPair = std::pair<CurrencyType, CurrencyType>;
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

struct CurrencyTrinity
{
    CurrencyPair c1_cb;
    CurrencyPair c2_cb;
    CurrencyPair c2_c1;
};

struct MarketAccount
{
    std::string serverUrl;
    std::string user;
    std::string password;
    double commision_prs;
};

} // namespace rqs

#endif // COMMON_H
