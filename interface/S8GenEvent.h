/**
 * GenEvent
 * s8 
 *
 * Created by Samvel Khalatian on Oct 11, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_GENEVENT
#define S8_GENEVENT

namespace s8
{
    class GenEvent
    {
        public:
            GenEvent() throw();

            void reset();

            double ptHat() const;



            void setPtHat(const double &);

        private:
            double _ptHat;
    };
}

#endif
