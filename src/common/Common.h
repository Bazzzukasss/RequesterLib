#ifndef COMMON_H
#define COMMON_H

#include <map>
#include <string>
#include <functional>
#include <QJsonDocument>

namespace rqs
{

enum class RequestType
{
    Get,
    Put,
    Post,
    Patch
};

using CoinType = std::string;
using CoinPair = std::pair<CoinType, CoinType>;
using CoinSymbol = std::string;
using ReplyData = QJsonDocument;
using ProcessedReplyData = std::vector<std::map<std::string, std::string>>;;
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

struct CoinTrinity
{
    CoinTrinity(const CoinType& c1, const CoinType& c2, const CoinType& cb)
        : c1_cb(c1, cb)
        , c2_cb(c2, cb)
        , c2_c1(c2, c1)
    {}

    CoinPair c1_cb;
    CoinPair c2_cb;
    CoinPair c2_c1;
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
