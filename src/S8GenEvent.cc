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
    _isGluonSplitting(false),
    _ptHat(0)
{
}

void GenEvent::reset()
{
    _isGluonSplitting = false;
    _ptHat = 0;
}

bool GenEvent::isGluonSplitting() const
{
    return _isGluonSplitting;
}

double GenEvent::ptHat() const
{
    return _ptHat;
}

void GenEvent::setGluonSplitting(const bool &value)
{
    _isGluonSplitting = value;
}

void GenEvent::setPtHat(const double &ptHat)
{
    if (ptHat < 0)
        throw runtime_error("[GenEvent] Negative PtHat supplied.");

    _ptHat = ptHat;
}
