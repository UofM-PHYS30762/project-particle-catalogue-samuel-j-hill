#include <iostream>
#include "lepton.h"

// Parameterised constructor
Lepton::Lepton(double lepton_energy, double lepton_px, double lepton_py, double lepton_pz,
               bool antiparticle_status) : Particle(lepton_energy, lepton_px, lepton_py, lepton_pz, antiparticle_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised lepton constructor called"<<std::endl;}
};