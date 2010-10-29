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
    class Trigger
    {
        public:
            enum HLT
            {
                Undefined,
                BTagMu_Jet10U,
                BTagMu_Jet20U,
                BTagMu_DiJet20U
            };

            Trigger() throw();

            HLT hlt() const;
            int version() const;
            int prescale() const;

            virtual operator bool() const;

            void setHLT(const HLT &);
            void setVersion(const int &);
            void setPrescale(const int &);
            void setIsPass(const bool &);

        private:
            HLT  _hlt;
            int  _version;
            int  _prescale;
            bool _isPass;
    };
}

#endif
