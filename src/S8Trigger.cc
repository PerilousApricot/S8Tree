/**
 * Trigger
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#include <stdexcept>

#include "interface/S8Trigger.h"

using std::runtime_error;

using s8::Trigger;

Trigger::Trigger() throw():
    _name("undefined"),
    _version(1),
    _isPass(false)
{
}

const std::string &Trigger::name() const
{
    return _name;
}

int Trigger::version() const
{
    return _version;
}

Trigger::operator bool() const
{
    return _isPass;
}

void Trigger::setName(const std::string &name)
{
    _name = name;
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
