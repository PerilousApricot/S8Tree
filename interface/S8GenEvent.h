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
            enum GluonSplitting { NONE, BB, CC };

            GenEvent() throw();

            void reset();

            GluonSplitting gluonSplitting() const;
            double ptHat() const;



            void setGluonSplitting(const GluonSplitting &);
            void setPtHat(const double &);

        private:
            GluonSplitting _gluonSplitting;
            double         _ptHat;
    };
}

#endif
