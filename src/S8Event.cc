/**
 * Event
 * s8
 *
 * Created by Samvel Khalatian on Sep 29, 2010
 * Copyright 2010, All rights reserved
 */

#include "interface/S8EventID.h"
#include "interface/S8GenEvent.h"

#include "interface/S8Event.h"

using s8::Event;

Event::Event() throw()
{
    _id = new EventID();
    _gen = new GenEvent();
}

Event::~Event() throw()
{
    delete _gen;
    delete _id;
}

void Event::reset()
{
    _id->reset();
    _gen->reset();

    _jets.clear();
    _muons.clear();
    _electrons.clear();
    _primaryVertices.clear();
    _triggers.clear();
}

s8::EventID *Event::id()
{
    return _id;
}

const s8::EventID *Event::id() const
{
    return _id;
}

s8::GenEvent *Event::gen()
{
    return _gen;
}

const s8::GenEvent *Event::gen() const
{
    return _gen;
}

