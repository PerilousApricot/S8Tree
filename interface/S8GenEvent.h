/**
 * GenEvent
 * s8 
 *
 * Created by Samvel Khalatian on Oct 11, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_GENEVENT
#define S8_GENEVENT

#include <vector>

namespace s8
{
    class GenEvent
    {
        public:
            enum GluonSplitting { NONE, BB, CC};

            GenEvent() throw();

            void reset();

            bool isGluonSplitting(const GluonSplitting &) const;
            double ptHat() const;



            void setGluonSplitting(const GluonSplitting &);
            void setPtHat(const double &);

        private:
            // The same event may have several gluon splittings: bbbar, ccbar,
            // etc. Such events are supported even though they are highly
            // suppressed.
            //
            std::vector<GluonSplitting> _gluonSplittings;
            double                      _ptHat;
    };
}

#endif
