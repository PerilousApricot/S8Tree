/**
 * Trigger
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TRIGGER
#define S8_TRIGGER

namespace s8
{
    class TriggerProxy;

    class Trigger
    {
        public:
            Trigger() throw();
            Trigger(const Trigger &trigger) throw();

            Trigger &operator=(const Trigger &);

            int version() const;

            virtual operator bool() const;

            void setVersion(const int &);
            void setIsPass(const bool &);

        private:
            TriggerProxy *_proxy;
            int           _version;
            bool          _isPass;
    };
}

#endif
