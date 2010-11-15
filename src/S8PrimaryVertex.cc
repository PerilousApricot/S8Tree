/**
 * PrimaryVertex
 * s8 
 *
 * Created by Samvel Khalatian on Sep 28, 2010
 * Copyright 2010, All rights reserved
 */

#include <stdexcept>

#include <TVector3.h>

#include "interface/S8PrimaryVertex.h"

using std::runtime_error;

using s8::PrimaryVertex;

PrimaryVertex::PrimaryVertex() throw():
    _ndof(0),
    _rho(0)
{
    _vertex.reset(new TVector3());
}

PrimaryVertex::PrimaryVertex(const PrimaryVertex &vertex):
    _ndof(vertex.ndof()),
    _rho(vertex.rho())
{
    _vertex.reset(new TVector3(*vertex.vertex()));
}

PrimaryVertex &PrimaryVertex::operator =(const PrimaryVertex &vertex)
{
    _ndof = vertex.ndof();
    _rho = vertex.rho();

    *_vertex = *vertex.vertex();

    return *this;
}

void PrimaryVertex::reset()
{
    _ndof = 0;
    _rho = 0;

    _vertex->SetXYZ(0, 0, 0);
}

TVector3 *PrimaryVertex::vertex()
{
    return _vertex.get();
}

const TVector3 *PrimaryVertex::vertex() const
{
    return _vertex.get();
}

double PrimaryVertex::ndof() const
{
    return _ndof;
}

double PrimaryVertex::rho() const
{
    return _rho;
}



void PrimaryVertex::setNdof(const double &ndof)
{
    if (0 > ndof)
        throw runtime_error("[PrimaryVertex] Wrong number of NDOF supplied.");

    _ndof = ndof;
}

void PrimaryVertex::setRho(const double &rho)
{
    _rho = rho;
}
