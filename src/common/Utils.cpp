#include "src/common/Utils.h"
#include <QMap>
#include <QVariant>
#include <string>

namespace rqs
{
namespace utils
{

std::string toCurrencySymbol(const CoinPair& currencyPair)
{
    return currencyPair.first + currencyPair.second;
}

std::map<std::string, std::string> toStringMap(const QVariantMap& varMap)
{
    std::map<std::string, std::string> data;

    for(const auto& key : varMap.keys())
    {
        data.insert({key.toStdString(), varMap.value(key).toString().toStdString()});
    }

    return data;
}

} // namespace utils
} // namespace rqs
