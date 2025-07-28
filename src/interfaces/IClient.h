#ifndef ICLIENT_H
#define ICLIENT_H

#include "Common.h"

namespace rqs
{

class IClient
{
public:
    virtual ~IClient() = default;

    virtual bool connect(const std::string& serverUrl) = 0;
    virtual bool request(const Request& request) = 0;
};

} //namespace rqs

#endif // ICLIENT_H
