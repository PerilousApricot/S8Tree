/**
 * Event
 * s8
 *
 * Created by Samvel Khalatian on Sep 29, 2010
 * Copyright 2010, All rights reserved
 */

#include <TLorentzVector.h>

#include "interface/S8EventID.h"
#include "interface/S8GenEvent.h"
#include "interface/S8GenParticle.h"
#include "interface/S8Jet.h"
#include "interface/S8Lepton.h"
#include "interface/S8PrimaryVertex.h"
#include "interface/S8Trigger.h"

#include "interface/S8Event.h"

using s8::Event;

Event::Event() throw():
    _cleanUpMemory(false)
{
    _id.reset(new EventID());
    _gen.reset(new GenEvent());
}

Event::~Event() throw()
{
    cleanUpMemory();
}

Event::Event(const Event &event):
    _cleanUpMemory(true)
{
    _id.reset(new EventID(*event.id()));
    _gen.reset(new GenEvent(*event.gen()));

    cloneCollections(event);
}

Event &Event::operator =(const Event &event)
{
    cleanUpMemory();

    *_id = *event.id();
    *_gen = *event.gen();

    cloneCollections(event);

    return *this;
}

void Event::reset()
{
    _id->reset();
    _gen->reset();

    cleanUpMemory();
}

void Event::manageMemory(const bool &manageMemory)
{
    _cleanUpMemory |= manageMemory;
}

s8::EventID *Event::id()
{
    return _id.get();
}

const s8::EventID *Event::id() const
{
    return _id.get();
}

s8::GenEvent *Event::gen()
{
    return _gen.get();
}

const s8::GenEvent *Event::gen() const
{
    return _gen.get();
}



// Collections
//
Event::Jets &Event::jets()
{
    return _jets;
}

const Event::Jets &Event::jets() const
{
    return _jets;
}

Event::Leptons &Event::muons()
{
    return _muons;
}

const Event::Leptons &Event::muons() const
{
    return _muons;
}

Event::Leptons &Event::electrons()
{
    return _electrons;
}

const Event::Leptons &Event::electrons() const
{
    return _electrons;
}

Event::PrimaryVertices &Event::primaryVertices()
{
    return _primaryVertices;
}

const Event::PrimaryVertices &Event::primaryVertices() const
{
    return _primaryVertices;
}

Event::Triggers &Event::triggers()
{
    return _triggers;
}

const Event::Triggers &Event::triggers() const
{
    return _triggers;
}



void Event::cleanUpMemory()
{
    if (_cleanUpMemory)
    {
        for(Jets::const_iterator jet = _jets.begin();
            _jets.end() != jet;
            ++jet)
        {
            delete *jet;
        }

        for(Leptons::const_iterator muon = _muons.begin();
            _muons.end() != muon;
            ++muon)
        {
            delete *muon;
        }

        for(Leptons::const_iterator electron = _electrons.begin();
            _electrons.end() != electron;
            ++electron)
        {
            delete *electron;
        }

        for(PrimaryVertices::const_iterator primaryVertex =
                _primaryVertices.begin();
            _primaryVertices.end() != primaryVertex;
            ++primaryVertex)
        {
            delete *primaryVertex;
        }

        for(Triggers::const_iterator trigger = _triggers.begin();
            _triggers.end() != trigger;
            ++trigger)
        {
            delete *trigger;
        }
    }

    _jets.clear();
    _electrons.clear();
    _muons.clear();
    _primaryVertices.clear();
    _triggers.clear();
}

void Event::cloneCollections(const Event &event)
{
    for(Jets::const_iterator jet = event.jets().begin();
        event.jets().end() != jet;
        ++jet)
    {
        _jets.push_back(new Jet(**jet));
    }

    for(Leptons::const_iterator muon = event.muons().begin();
        event.muons().end() != muon;
        ++muon)
    {
        _muons.push_back(new Lepton(**muon));
    }

    for(Leptons::const_iterator electron = event.electrons().begin();
        event.electrons().end() != electron;
        ++electron)
    {
        _electrons.push_back(new Lepton(**electron));
    }

    for(PrimaryVertices::const_iterator primaryVertex =
            event.primaryVertices().begin();
        event.primaryVertices().end() != primaryVertex;
        ++primaryVertex)
    {
        _primaryVertices.push_back(new PrimaryVertex(**primaryVertex));
    }

    for(Triggers::const_iterator trigger = event.triggers().begin();
        event.triggers().end() != trigger;
        ++trigger)
    {
        _triggers.push_back(new Trigger(**trigger));
    }
}
