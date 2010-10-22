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

namespace s8
{
    class Trigger
    {
        public:
            Trigger() throw();

            const std::string &name() const;
            int version() const;

            virtual operator bool() const;

            void setName(const std::string &);
            void setVersion(const int &);
            void setIsPass(const bool &);

        private:
            std::string _name;
            int         _version;
            bool        _isPass;
    };
}

#endif
