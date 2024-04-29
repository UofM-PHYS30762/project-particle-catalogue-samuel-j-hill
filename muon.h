#ifndef MUON_H
#define MUON_H

#include <iostream>
#include "lepton.h"

class Muon: public Lepton
{
private:
  bool isolated{true};

public:
  // Default constructor
  Muon();
  // Parameterised constructor
  Muon(double muon_energy, double muon_px, double muon_py, double muon_pz, bool antiparticle, bool constructor_destructor_status, 
       bool isolated);
  // Destructor 
  ~Muon() {if(print_constructor_destructor) {std::cout<<"Muon destructor called"<<std::endl;}}
  // Overwritten copy constructor
  Muon(Muon& mu) : Lepton(mu), isolated(mu.isolated) {};
  // Overwritten move constructor
  Muon(Muon&&);
  // Overwritten copy assignment operator
  Muon& operator=(Muon&);
  // Overwritten move assignment operator
  Muon& operator=(Muon&&);

  bool get_isolated_status() const {return isolated;}
  void set_isolated_status(bool isolated_status) {isolated = isolated_status;}
  void print_data();
};

#endif