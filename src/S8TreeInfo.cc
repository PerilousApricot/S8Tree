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

using std::ostream;
using std::runtime_error;

using boost::lexical_cast;

using s8::TreeInfo;
using s8::Version;

Version TreeInfo::_version(5, 0);

Version::Version(const int &major, const int &minor) throw():
    _major(major),
    _minor(minor)
{
}

Version::operator double() const
{
    std::ostringstream version;
    version << *this;

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

ostream &s8::operator<<(ostream &out, const Version &version)
{
    return out << version.major() << "." << version.minor();
}



TreeInfo::TreeInfo() throw()
{
}
