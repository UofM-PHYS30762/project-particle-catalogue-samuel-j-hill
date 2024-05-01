#include <iostream>
#include "gluon.h"

// Parameterised constructor
Gluon::Gluon(double gluon_energy, double gluon_px, double gluon_py, double gluon_pz, bool antiparticle_status,
             bool constructor_destructor_status) : Particle(gluon_energy, gluon_px, gluon_py, gluon_pz, antiparticle_status,
                                                            constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised gluon constructor called"<<std::endl;}
  spin = 1;
  Particle::check_four_momentum(rest_mass);
};