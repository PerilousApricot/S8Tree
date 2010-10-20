/**
 * Event
 * s8
 *
 * Created by Samvel Khalatian on Sep 29, 2010
 * Copyright 2010, All rights reserved
 */

#include "interface/S8EventID.h"

#include "interface/S8Event.h"

using s8::Event;

void Event::reset()
{
    _id = EventID();

    _jets.clear();
    _muons.clear();
    _electrons.clear();
    _primaryVertices.clear();
}
