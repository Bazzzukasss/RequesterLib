#ifndef ICLIENTIMPL_H
#define ICLIENTIMPL_H

#include "src/common/Common.h"

namespace rqs
{

class IClientImpl
{
public:
    virtual ~IClientImpl() = default;

    virtual bool connect(const std::string& serverUrl) = 0;
    virtual bool request(const RequestType& type,
                         const EndPoint& endpoint,
                         const RequestData& data,
                         const RequestHandler& handler) = 0;
};

} //namespace rqs

#endif // ICLIENTIMPL_H
