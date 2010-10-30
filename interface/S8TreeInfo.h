/**
 * TreeInfo
 * s8 
 *
 * Created by Samvel Khalatian on Oct 22, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_TREEINFO
#define S8_TREEINFO

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

    class TreeInfo
    {
        public:
            enum Input { Undefined,
                         BTau,
                         TTbar,
                         BBbar,
                         InclusiveMu5_Pt15,
                         InclusiveMu5_Pt30,
                         InclusiveMu5_Pt50,
                         InclusiveMu5_Pt150,
                         ppMuX };

            TreeInfo() throw();

            Input input() const;

            void setInput(const Input &);

        private:
            static Version _version;

            Input _input;
    };
}

#endif
