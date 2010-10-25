/**
 * TriggerProxy
 * s8 
 *
 * Created by Samvel Khalatian on Oct 25, 2010
 * Copyright 2010, All rights reserved
 */

#include "interface/S8Trigger.h"
#include "interface/S8TriggerProxy.h"

using s8::TriggerProxy;

TriggerProxy::TriggerProxy() throw()
{
}

TriggerProxy::operator bool() const
{
    return _trigger ? *_trigger : false;
}

std::string TriggerProxy::name() const
{
    return _name;
}

void TriggerProxy::setName(const std::string &name)
{
    _name = name;
}
