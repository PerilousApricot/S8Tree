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
    struct HLT
    {
        enum{
            BTagMu_Jet10U,
            BTagMu_Jet20U,
            BTagMu_DiJet20U
        };
    };

    class Trigger
    {
        public:
            Trigger() throw();

            int version() const;

            virtual operator bool() const;

            void setVersion(const int &);
            void setIsPass(const bool &);

        private:
            int           _version;
            bool          _isPass;
    };
}

#endif
