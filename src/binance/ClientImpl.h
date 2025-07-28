#ifndef CLIENTIMPL_H
#define CLIENTIMPL_H

#include "IClientImpl.h"

#include <QtNetwork/QRestReply>

class QNetworkAccessManager;
class QRestAccessManager;

namespace rqs
{

class ClientImpl : public QObject, public IClientImpl
{
    Q_OBJECT
public:
    ClientImpl(QObject* parent = nullptr);
    virtual ~ClientImpl() = default;

    bool connect(const std::string& serverUrl) override;
    bool request(const RequestType& type,
                 const EndPoint& endpoint,
                 const RequestData& data,
                 const RequestHandler& handler) override;
private:
    ReplyData processReply(QRestReply& reply) const;
    std::map<std::string, std::string> toStringMap(const QVariantMap& varMap) const;

private:
    std::string m_serverUrl;
    QNetworkAccessManager* m_netManager{nullptr};
    QRestAccessManager* m_restManager{nullptr};
};

} //namespace rqs

#endif // CLIENTIMPL_H
