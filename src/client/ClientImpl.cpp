#include "src/client/ClientImpl.h"

#include <QtNetwork/QNetworkRequestFactory>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QRestAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <map>

namespace rqs
{

ClientImpl::ClientImpl(QObject* parent)
    : QObject(parent)
{
    m_netManager = new QNetworkAccessManager(this);
    m_restManager = new QRestAccessManager(m_netManager);
}

bool ClientImpl::connect(const std::string& serverUrl)
{
    m_serverUrl = serverUrl;
    return true;
}

bool ClientImpl::request(const RequestType& type, const EndPoint& endpoint,
                         const RequestData& data, const RequestHandler& handler)
{
    qDebug()<<"Request:" << endpoint << data;
    QNetworkRequestFactory factory(QString::fromStdString(m_serverUrl + endpoint));
    QNetworkRequest request = factory.createRequest(QString::fromStdString(data));

    switch(type)
    {
        case RequestType::Get:
            m_restManager->get(request, this, [=](QRestReply& reply) {
                const auto& replyData = processReply(reply);
                handler(replyData);
            });
            break;
        case RequestType::Put:
            break;
        case RequestType::Post:
            break;
        case RequestType::Patch:
            break;
    }

    return true;
}

ReplyData ClientImpl::processReply(QRestReply& reply) const
{
    if(!reply.isSuccess())
    {
        qCritical() << "Reqest is not success!";
        return {};
    }

    //Turn the data into a json document
    ReplyData replyData = reply.readJson().value();
    //qDebug()<<replyData;

    return replyData;
}

} //namespace rqs
