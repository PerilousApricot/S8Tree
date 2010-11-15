/**
 * GenParticle
 * s8 
 *
 * Created by Samvel Khalatian on Sep 28, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_GENPARTICLE
#define S8_GENPARTICLE

#include <memory>

class TLorentzVector;
class TVector3;

namespace s8
{
    class GenParticle
    {
        public:
            GenParticle() throw();

            // Take care of copying b/c of pointers
            //
            GenParticle(const GenParticle &);
            GenParticle &operator =(const GenParticle &);

            void reset();

            int id() const;
            int parentId() const;

            TLorentzVector *p4();
            const TLorentzVector *p4() const;

            TVector3 *vertex();
            const TVector3 *vertex() const;



            void setId(const int &);
            void setParentId(const int &);

        private:
            int _id;
            int _parentId;

            std::auto_ptr<TLorentzVector> _p4;
            std::auto_ptr<TVector3>       _vertex;
    };
}

#endif
