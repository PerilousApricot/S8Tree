/**
 * TriggerCenter
 * s8 
 *
 * Created by Samvel Khalatian on Oct 25, 2010
 * Copyright 2010, All rights reserved
 */

#include "interface/S8TriggerProxy.h"

#include "interface/S8TriggerCenter.h"

using s8::TriggerCenter;
using s8::TriggerProxy;

TriggerCenter::TriggerCenter() throw()
{
}

TriggerProxy *TriggerCenter::proxy(const std::string &name)
{
    for(TriggerProxies::iterator proxy = _proxies.begin();
        _proxies.end() != proxy;
        ++proxy)
    {
        if (name == proxy->name())
            return &*proxy;
    }

    TriggerProxy proxy;
    proxy.setName(name);

    return &*_proxies.insert(_proxies.end(), proxy);
}
