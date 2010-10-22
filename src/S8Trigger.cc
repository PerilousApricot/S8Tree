/**
 * Trigger
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#include "interface/S8Trigger.h"

using s8::Trigger;
using s8::TriggerGroup;

Trigger::Trigger() throw():
    _isPass(false)
{
}

Trigger::~Trigger() throw()
{
}

Trigger::operator bool() const
{
    return _isPass;
}



TriggerGroup::TriggerGroup() throw():
    _name("undefined")
{
}

TriggerGroup::~TriggerGroup() throw()
{
}

TriggerGroup::operator bool() const
{
    // OR trigger versions
    //
    bool result = false;

    for(Triggers::const_iterator version = _versions.begin();
        _versions.end() != version;
        ++version)
    {
        result |= *version;

        if (result)
            break;
    }

    return result;
}

const std::string & TriggerGroup::name() const
{
    return _name;
}
