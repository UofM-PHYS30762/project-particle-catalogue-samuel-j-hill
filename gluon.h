#ifndef GLUON_H
#define GLUON_H

#include<iostream>
#include "particle.h"

class Gluon: public Particle
{
private:
  std::string first_colour_charge{"Default"};
  std::string second_colour_charge{"Default"};
public:
  // Default constructor
  Gluon();
  // Parameterised constructor
  Gluon(double gluon_energy, double gluon_px, double gluon_py, double gluon_pz, bool antiparticle_status,
        bool constructor_destructor_status, std::string first_colour_charge, std::string second_colour_charge);
  // Destructor
  ~Gluon() {if(print_constructor_destructor) {std::cout<<"Gluon destructor called"<<std::endl;}}

  void print_data();
};

#endif