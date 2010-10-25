/**
 * TriggerCenter
 * s8 
 *
 * Created by Samvel Khalatian on Oct 25, 2010
 * Copyright 2010, All rights reserved
 */

#include <stdexcept>

#include "interface/S8TriggerProxy.h"

#include "interface/S8TriggerCenter.h"

using std::runtime_error;

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

const TriggerProxy *TriggerCenter::proxy(const std::string &name) const
{
    for(TriggerProxies::const_iterator proxy = _proxies.begin();
        _proxies.end() != proxy;
        ++proxy)
    {
        if (name == proxy->name())
            return &*proxy;
    }

    throw runtime_error("Trigger Proxy does not exist for name: " + name);
}

const TriggerCenter::TriggerProxies &TriggerCenter::proxies() const
{
    return _proxies;
}
