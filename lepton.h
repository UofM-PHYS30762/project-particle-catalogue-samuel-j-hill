#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<memory>
#include "four_momentum.h"

class Lepton
{
protected:
  int lepton_number{1};

public:
  // Default constructor
  Lepton() {std::cout<<"Default lepton constructor called"<<std::endl;};
  // Parameterised constructor
  Lepton(int lepton_charge, double lepton_spin, double lepton_rest_mass, double lepton_px,
           double lepton_py, double lepton_pz, bool antiparticle);
  // Destructor
  virtual ~Lepton() {std::cout<<"Lepton destructor called"<<std::endl;}
  // Copy constructor
  Lepton(Lepton&);
  // Move constructor
  Lepton(Lepton&&);
  // Copy assignment operator
  Lepton& operator=(Lepton&);
  // Move assignment operator
  Lepton& operator=(Lepton&&);

  int get_lepton_number() {return lepton_number;}  
  virtual void print_data();
};

#endif