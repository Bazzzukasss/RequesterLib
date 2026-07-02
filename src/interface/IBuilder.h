#ifndef IBUILDER_H
#define IBUILDER_H

#include <memory>

namespace rqs
{

class IRequester;

class IBuilder
{
public:
    virtual ~IBuilder() = default;

    virtual std::shared_ptr<IRequester> binanceRequester() const = 0;
};

} // namespace rqs

#endif // IBUILDER_H
