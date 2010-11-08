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
#include <utility>

#include <Rtypes.h>

namespace s8
{
    // Currently TreeInfo is not used.
    //
    class Version
    {
        public:
            typedef std::pair<int, int> VersionPair; // <major, minor>

            Version() throw();

            operator double() const;

            VersionPair operator()() const;

            void set(const VersionPair &);

        private:
            std::pair<int, int> _version;
    };

    // Default Logical operators on Versions should work b/c version can be
    // converted to the double

    class TreeInfo
    {
        public:
            TreeInfo() throw();

            void merge(const TreeInfo &);

            Version version() const;

        private:
            Version _version;

            ClassDef(TreeInfo, 1);
    };
}

#endif
