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

using std::clog;
using std::endl;
using std::runtime_error;

using s8::Trigger;

Trigger::Trigger() throw():
    _version(1),
    _isPass(false)
{
    _proxy = 0;
}

Trigger::Trigger(const Trigger &trigger) throw():
    _version(trigger.version()),
    _isPass(trigger)
{
    clog << "Trigger::Trigger(const Trigger &)" << endl;
    _proxy = trigger._proxy;

    if (_proxy)
        _proxy._trigger = this;
}

Trigger &Trigger::operator=(const Trigger &trigger)
{
    clog << "Trigger::operator=" << endl;

    _proxy = trigger._proxy;
    if (_proxy)
        _proxy._trigger = this;

    _version = trigger.version();
    _isPass = trigger;

    return *this;
}

int Trigger::version() const
{
    return _version;
}

Trigger::operator bool() const
{
    return _isPass;
}

void Trigger::setProxy(const TriggerProxy *proxy)
{
    if (_proxy)
        _proxy._filter = 0;

    _proxy = proxy;
}

void Trigger::setVersion(const int &version)
{
    if(1 > version)
        throw runtime_error("Version can not be negative");

    _version = version;
}

void Trigger::setIsPass(const bool &isPass)
{
    _isPass = isPass;
}
