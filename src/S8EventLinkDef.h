#include <utility>
#include <vector>

#include "interface/S8EventID.h"
#include "interface/S8GenParticle.h"
#include "interface/S8Jet.h"
#include "interface/S8Muon.h"
#include "interface/S8PrimaryVertex.h"
#include "interface/S8Event.h"

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace s8;

#pragma link C++ class s8::EventID+;
#pragma link C++ class s8::GenParticle+;
#pragma link C++ class s8::Jet+;
#pragma link C++ class s8::Muon+;
#pragma link C++ class s8::PrimaryVertex+;

#pragma link C++ class std::vector<s8::Muon>;
#pragma link C++ class std::vector<s8::Jet>;
#pragma link C++ class std::vector<s8::PrimaryVertex>;

#pragma link C++ class s8::Event+;

#endif
