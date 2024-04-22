#ifndef NEUTRINO_H
#define NEUTRINO_H

#include <iostream>
#include "lepton.h"

class Neutrino: public Lepton
{
private:
  std::string flavour{"None"};
  bool has_interacted{false};

public:
  // Default constructor
  Neutrino() {if(print_constructor_destructor) {std::cout<<"Default neutrino constructor called"<<std::endl;}}
  // Parameterised constructor
  Neutrino(double neutrino_energy, double neutrino_px, double neutrino_py, double neutrino_pz, bool antiparticle, 
           bool constructor_destructor_status, std::string flavour);
  // Destructor 
  ~Neutrino() {if(print_constructor_destructor) {std::cout<<"Neutrino destructor called"<<std::endl;}}
  // Overwritten copy constructor
  Neutrino(Neutrino& neut) : Lepton(neut), flavour(neut.flavour) {};
  // Overwritten move constructor
  Neutrino(Neutrino&&);
  // Overwritten copy assignment operator
  Neutrino& operator=(Neutrino&);
  // Overwritten move assignment operator
  Neutrino& operator=(Neutrino&&);
 
  std::string get_flavour() const {return flavour;}
  bool get_interacted_status() const {return has_interacted;}
  void set_interacted_status(bool interacted_status) {has_interacted = interacted_status;}
  void print_data();
};

#endif