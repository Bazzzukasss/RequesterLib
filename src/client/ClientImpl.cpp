#include "src/client/ClientImpl.h"

#include <QtNetwork/QNetworkRequestFactory>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QRestAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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
    //qDebug()<<"Request:" << endpoint << data;
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

    ReplyData replyData;

    //Turn the data into a json document
    auto doc = reply.readJson().value();

    //Turn document into json array: Have to read the value from an std::optional object returned from doc.
    if (doc.isArray())
    {
        QJsonArray array = doc.array();

        for ( int i = 0; i < array.size(); i++)
        {
            QJsonObject object = array.at(i).toObject();
            replyData.push_back(toStringMap(object.toVariantMap()));
        }
        //qDebug() << "Array response:" << replyData;
    }
    else if(doc.isObject())
    {
        replyData.push_back(toStringMap(doc.object().toVariantMap()));
        //qDebug() << "Object responce:" << replyData;
    }
    else
    {
        qCritical() << "Unknown responce format!";
    }

    return replyData;
}

std::map<std::string, std::string> ClientImpl::toStringMap(const QVariantMap& varMap) const
{
    std::map<std::string, std::string> data;

    for(const auto& key : varMap.keys())
    {
        data.insert({key.toStdString(), varMap.value(key).toString().toStdString()});
    }

    return data;
}
} //namespace rqs
