/**
 * Lepton
 * s8 
 *
 * Created by Samvel Khalatian on Sep 28, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_LEPTON
#define S8_LEPTON

#include <utility>

#include <TLorentzVector.h>
#include <TVector3.h>

#include "interface/S8GenParticle.h"

namespace s8
{
    class Lepton
    {
        public:
            // Value and associated Error pair
            //
            typedef std::pair<double,double> ImpactParameter;

            Lepton() throw();

            ImpactParameter &impactParameter();
            const ImpactParameter &impactParameter() const;

            TLorentzVector &p4();
            const TLorentzVector &p4() const;

            TVector3 &vertex();
            const TVector3 &vertex() const;

            GenParticle &genParticle();
            const GenParticle &genParticle() const;

        private:
            ImpactParameter _impactParameter;
            TLorentzVector  _p4;
            TVector3        _vertex;

            GenParticle     _genParticle;
    };

    inline Lepton::Lepton() throw()
    {
    }

    inline Lepton::ImpactParameter &Lepton::impactParameter()
    {
        return _impactParameter;
    }

    inline const Lepton::ImpactParameter &Lepton::impactParameter() const
    {
        return _impactParameter;
    }

    inline TLorentzVector &Lepton::p4()
    {
        return _p4;
    }

    inline const TLorentzVector &Lepton::p4() const
    {
        return _p4;
    }

    inline TVector3 &Lepton::vertex()
    {
        return _vertex;
    }

    inline const TVector3 &Lepton::vertex() const
    {
        return _vertex;
    }

    inline GenParticle &Lepton::genParticle()
    {
        return _genParticle;
    }

    inline const GenParticle &Lepton::genParticle() const
    {
        return _genParticle;
    }
}

#endif
