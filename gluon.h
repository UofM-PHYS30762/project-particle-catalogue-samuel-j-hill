#ifndef GLUON_H
#define GLUON_H

#include<iostream>
#include "particle.h"

class Gluon: public Particle
{
public:
  // Default constructor
  Gluon() : Particle() {spin = 1; if(print_constructor_destructor){std::cout<<"Default gluon constructor called"<<std::endl;}}
  // Parameterised constructor
  Gluon(double gluon_energy, double gluon_px, double gluon_py, double gluon_pz, bool antiparticle_status,
        bool constructor_destructor_status);
  // Destructor
  ~Gluon() {if(print_constructor_destructor) {std::cout<<"Gluon destructor called"<<std::endl;}}

  void print_data();
};

#endif