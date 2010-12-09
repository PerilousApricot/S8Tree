/**
 * GenEvent
 * s8 
 *
 * Created by Samvel Khalatian on Oct 11, 2010
 * Copyright 2010, All rights reserved
 */

#include <stdexcept>

#include "interface/S8GenEvent.h"

using std::runtime_error;

using s8::GenEvent;

GenEvent::GenEvent() throw():
    _gluonSplitting(NONE),
    _ptHat(0)
{
}

void GenEvent::reset()
{
    _gluonSplitting = NONE;
    _ptHat = 0;
}

GenEvent::GluonSplitting GenEvent::gluonSplitting() const
{
    return _gluonSplitting;
}

double GenEvent::ptHat() const
{
    return _ptHat;
}

void GenEvent::setGluonSplitting(const GluonSplitting &gluonSplitting)
{
    switch(gluonSplitting)
    {
        case NONE: // Fall through
        case BB:   // Fall through
        case CC:   // Fall through
        case BBCC: _gluonSplitting = gluonSplitting;
                   break;

        default:
            throw runtime_error("[GenEvent] Unsupported Gluon Splitting value supplied");
    }
}

void GenEvent::setPtHat(const double &ptHat)
{
    if (ptHat < 0)
        throw runtime_error("[GenEvent] Negative PtHat supplied");

    _ptHat = ptHat;
}
