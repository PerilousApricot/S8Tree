/**
 * GenEvent
 * s8 
 *
 * Created by Samvel Khalatian on Oct 11, 2010
 * Copyright 2010, All rights reserved
 */

#include <algorithm>
#include <stdexcept>

#include "interface/S8GenEvent.h"

using std::find;
using std::runtime_error;

using s8::GenEvent;

GenEvent::GenEvent() throw():
    _ptHat(0)
{
}

void GenEvent::reset()
{
    _gluonSplittings.clear();
    _ptHat = 0;
}

bool GenEvent::isGluonSplitting(const GluonSplitting &gluonSplitting) const
{
    if (NONE == gluonSplitting)
        return _gluonSplittings.empty();

    return _gluonSplittings.end() != find(_gluonSplittings.begin(),
                                          _gluonSplittings.end(),
                                          gluonSplitting);
}

double GenEvent::ptHat() const
{
    return _ptHat;
}

void GenEvent::setGluonSplitting(const GluonSplitting &gluonSplitting)
{
    switch(gluonSplitting)
    {
        case BB:   // Fall through
        case CC:   if (_gluonSplittings.end() == find(_gluonSplittings.begin(),
                                                      _gluonSplittings.end(),
                                                      gluonSplitting))
                       _gluonSplittings.push_back(gluonSplitting);

                   // Fall through

        case NONE: break;

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
