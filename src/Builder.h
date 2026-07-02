#ifndef BUILDER_H
#define BUILDER_H

#include "src/interface/IBuilder.h"

namespace rqs
{

class IRequester;

class Builder : public IBuilder
{
public:
    std::shared_ptr<IRequester> binanceRequester() const override;
};

} //namespace rqs

#endif // BUILDER_H
