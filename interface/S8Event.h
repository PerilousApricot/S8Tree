/**
 * Event 
 * s8 
 *
 * Created by Samvel Khalatian on Sep 28, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_EVENT
#define S8_EVENT

#include <vector>

#include "interface/S8Jet.h"
#include "interface/S8Lepton.h"
#include "interface/S8PrimaryVertex.h"
#include "interface/S8Trigger.h"

namespace s8
{
    typedef std::vector<Jet>           JetCollection;
    typedef std::vector<Lepton>        LeptonCollection;
    typedef std::vector<PrimaryVertex> PrimaryVertexCollection;
    typedef std::vector<Trigger>       TriggerCollection;

    class EventID;
    class GenEvent;

    class Event
    {
        public:
            Event() throw();
            ~Event() throw();

            void reset();

            EventID *id();
            const EventID *id() const;

            GenEvent *gen();
            const GenEvent *gen() const;

            JetCollection &jets();
            const JetCollection &jets() const;

            LeptonCollection &muons();
            const LeptonCollection &muons() const;

            LeptonCollection &electrons();
            const LeptonCollection &electrons() const;

            PrimaryVertexCollection &primaryVertices();
            const PrimaryVertexCollection &primaryVertices() const;

            TriggerCollection &triggers();
            const TriggerCollection &triggers() const;

        private:
            EventID  *_id;
            GenEvent *_gen;

            JetCollection           _jets;
            LeptonCollection        _muons;
            LeptonCollection        _electrons;
            PrimaryVertexCollection _primaryVertices;
            TriggerCollection       _triggers;
    };

    inline JetCollection &Event::jets()
    {
        return _jets;
    }

    inline const JetCollection &Event::jets() const
    {
        return _jets;
    }

    inline LeptonCollection &Event::muons()
    {
        return _muons;
    }

    inline const LeptonCollection &Event::muons() const
    {
        return _muons;
    }

    inline LeptonCollection &Event::electrons()
    {
        return _electrons;
    }

    inline const LeptonCollection &Event::electrons() const
    {
        return _electrons;
    }

    inline PrimaryVertexCollection &Event::primaryVertices()
    {
        return _primaryVertices;
    }

    inline const PrimaryVertexCollection &Event::primaryVertices() const
    {
        return _primaryVertices;
    }

    inline TriggerCollection &Event::triggers()
    {
        return _triggers;
    }

    inline const TriggerCollection &Event::triggers() const
    {
        return _triggers;
    }
}

#endif
