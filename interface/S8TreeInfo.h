/**
 * TreeInfo
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TREEINFO
#define S8_TREEINFO

#include <ostream>

namespace s8
{
    // Currently TreeInfo is not used.
    //
    class Version
    {
        public:
            Version(const int &major, const int &minor) throw();

            operator double() const;

            int major() const;
            int minor() const;

        private:
            int _major;
            int _minor;
    };

    std::ostream &operator<<(std::ostream &, const Version &);

    class TreeInfo
    {
        public:
            TreeInfo() throw();

        private:
            static Version _version;
    };
}

#endif
