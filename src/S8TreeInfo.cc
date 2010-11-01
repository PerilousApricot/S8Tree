/**
 * TreeInfo
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#include <sstream>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

#include "interface/S8TreeInfo.h"

using std::runtime_error;

using boost::lexical_cast;

using s8::TreeInfo;
using s8::Version;

Version TreeInfo::_version(4, 3);

Version::Version(const int &major, const int &minor) throw():
    _major(major),
    _minor(minor)
{
}

Version::operator double() const
{
    std::ostringstream version;
    version << _major << '.' << _minor;

    return lexical_cast<double>(version.str());
}

int Version::major() const
{
    return _major;
}

int Version::minor() const
{
    return _minor;
}



TreeInfo::TreeInfo() throw():
    _input(Undefined)
{
}

TreeInfo::Input TreeInfo::input() const
{
    return _input;
}

void TreeInfo::setInput(const Input &input)
{
    switch(input)
    {
        case Undefined:          // Fall through
        case BTau:               // Fall through
        case TTbar:              // Fall through
        case BBbar:              // Fall through
        case InclusiveMu5_Pt30:  // Fall through
        case InclusiveMu5_Pt50:  // Fall through
        case InclusiveMu5_Pt150: // Fall through
        case ppMuX:              break;

        default:
            throw runtime_error("Unsupported Input type specified");
    }
    _input = input;
}
