/**
 * Trigger
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TRIGGER
#define S8_TRIGGER

#include <string>
#include <vector>

namespace s8
{
    class Trigger
    {
        public:
            Trigger() throw();
            virtual ~Trigger() throw();

            virtual operator bool() const;

        private:
            bool _isPass;
    };

    class TriggerGroup: public Trigger
    {
        public:
            TriggerGroup() throw();
            virtual ~TriggerGroup() throw();

            virtual operator bool() const;

            std::string &name() const;

        private:
            typedef std::vector<Trigger> Triggers;

            std::string _name;
            Triggers    _versions;
    };
}

#endif
