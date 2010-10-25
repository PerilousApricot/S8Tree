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

namespace s8
{
    class TriggerProxy;

    class TriggerCenter
    {
        public:
            TriggerCenter() throw();

            /*
            const TriggerProxy *proxy(const std::string &) const;
            */

            TriggerProxy *proxy(const std::string &);

        private:
            typedef std::vector<TriggerProxy> TriggerProxies;

            TriggerProxies _proxies;
    };
}

#endif
