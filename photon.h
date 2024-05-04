#ifndef PHOTON_H
#define PHOTON_H

#include<iostream>
#include "particle.h"

class Photon: public Particle
{
public:
  // Default constructor
  Photon() : Particle() {spin = 1; if(print_constructor_destructor) {std::cout<<"Default photon constructor called"<<std::endl;}};
  // Parameterised constructor
  Photon(double photon_energy, double photon_px, double photon_py, double photon_pz, bool constructor_destructor_status);
  // Destructor
  ~Photon() {if(print_constructor_destructor) {std::cout<<"Photon destructor called"<<std::endl;}}

  void print_data();
};

#endif