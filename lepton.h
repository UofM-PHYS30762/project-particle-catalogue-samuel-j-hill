#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<memory>
#include "four_momentum.h"
#include "particle.h"

class Lepton: public Particle
{
protected:
  int lepton_number{1};

public:
  // Default constructor
  Lepton() {if(print_constructor_destructor) {std::cout<<"Default lepton constructor called"<<std::endl;}};
  // Parameterised constructor
  Lepton(double lepton_energy, double lepton_px, double lepton_py, double lepton_pz, bool antiparticle, 
         bool constructor_destructor_status);
  // Destructor
  virtual ~Lepton() {if(print_constructor_destructor) {std::cout<<"Lepton destructor called"<<std::endl;}}

  int get_lepton_number() {return lepton_number;} 
  void print_data() {std::cout<<"Lepton number = "<<lepton_number<<std::endl; Particle::print_data();}
};

#endif