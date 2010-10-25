/**
 * TriggerCenter
 * s8 
 *
 * Created by Samvel Khalatian on Oct 25, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TRIGGERCENTER
#define S8_TRIGGERCENTER

#include <string>
#include <vector>

#include "interface/S8TriggerProxy.h"

namespace s8
{
    class TriggerCenter
    {
        public:
            typedef std::vector<TriggerProxy> TriggerProxies;

            TriggerCenter() throw();

            TriggerProxy *proxy(const std::string &);
            const TriggerProxy *proxy(const std::string &) const;

            const TriggerProxies &proxies() const;

        private:
            TriggerProxies _proxies;
    };
}

#endif
