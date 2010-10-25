/**
 * TriggerProxy
 * s8 
 *
 * Created by Samvel Khalatian on Oct 25, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TRIGGERPROXY
#define S8_TRIGGERPROXY

#include <string>

namespace s8
{
    class TriggerProxy
    {
        public:
            TriggerProxy() throw();

            operator bool() const;

            std::string name() const;

            void setName(const std::string &);

        private:
            friend class Trigger;

            Trigger     *_trigger;
            std::string  _name;
    };
}

#endif
