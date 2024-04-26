#include <iostream>
#include "photon.h"

// Parameterised constructor
Photon::Photon(double photon_energy, double photon_px, double photon_py, double photon_pz, bool constructor_destructor_status) : 
               Particle(photon_energy, photon_px, photon_py, photon_pz, false, constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised photon constructor called"<<std::endl;}
  spin = 1;
  Particle::check_four_momentum(rest_mass);
};