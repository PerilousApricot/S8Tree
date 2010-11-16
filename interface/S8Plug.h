/**
 * Plug (do not use it)
 * s8 
 *
 * Created by Samvel Khalatian on Nov 15, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_PLUG
#define S8_PLUG

#include <memory>

#include <TLorentzVector.h>

#include "interface/S8GenParticle.h"

namespace s8
{
    class Plug
    {
        private:
            Plug();

            std::auto_ptr<TLorentzVector> _1;
            std::auto_ptr<GenParticle>    _2;
    };
}

#endif
