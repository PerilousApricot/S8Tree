/**
 * Trigger
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#include <iostream>
#include <stdexcept>

#include "interface/S8Trigger.h"

using std::runtime_error;

using s8::Trigger;

Trigger::Trigger() throw():
    _hlt(Undefined),
    _version(1),
    _prescale(1),
    _isPass(false)
{
}

Trigger::HLT Trigger::hlt() const
{
    return _hlt;
}

int Trigger::version() const
{
    return _version;
}

int Trigger::prescale() const
{
    return _prescale;
}

Trigger::operator bool() const
{
    return _isPass;
}

void Trigger::setHLT(const HLT &hlt)
{
    switch(hlt)
    {
        case Undefined:       // Fall through
        case BTagMu_Jet10U:   // Fall through
        case BTagMu_Jet20U:   // Fall through
        case BTagMu_DiJet20U: break;
        default: throw runtime_error("Unsupported Trigger");
    }

    _hlt = hlt;
}

void Trigger::setVersion(const int &version)
{
    if (Undefined == _hlt)
        throw runtime_error("Trigger is undefined");

    if (1 > version)
        throw runtime_error("Version can not be negative");

    _version = version;
}

void Trigger::setPrescale(const int &prescale)
{
    if (0 > prescale)
        throw runtime_error("Negative Prescale supplied");

    _prescale = prescale;
}

void Trigger::setIsPass(const bool &isPass)
{
    if (Undefined == _hlt)
        throw runtime_error("Trigger is undefined");

    _isPass = isPass;
}
