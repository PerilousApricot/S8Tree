/**
 * Trigger
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TRIGGER
#define S8_TRIGGER

#include <cstddef>

namespace s8
{
    class Trigger
    {
        public:
            typedef std::size_t Hash;

            Trigger() throw();

            std::size_t hash() const;
            int version() const;
            int prescale() const;

            virtual operator bool() const;

            void setHash(const std::size_t &);
            void setVersion(const int &);
            void setPrescale(const int &);
            void setIsPass(const bool &);

        private:
            std::size_t _hash;
            char        _version;
            int         _prescale;
            bool        _isPass;
    };
}

#endif
