#ifndef TAU_H
#define TAU_H

#include <iostream>
#include <vector>
#include <memory>
#include "lepton.h"

class Tau: public Lepton
{
private:
  bool electron_decay{false};
  bool muon_decay{false};
  std::vector<std::shared_ptr<Lepton>> decay_products;

public:
  // Default constructor
  Tau() {if(print_constructor_destructor) {std::cout<<"Default tau constructor called"<<std::endl;}}
  // Parameterised constructor
  Tau(double tau_energy, double tau_px, double tau_py, double tau_pz, bool antiparticle, bool constructor_destructor_status,
      bool electron_decay, bool muon_decay);
  // Destructor 
  ~Tau() {if(print_constructor_destructor) {std::cout<<"Tau destructor called"<<std::endl;}}
  // Overwritten copy constructor
  Tau(Tau& tau) : Lepton(tau), electron_decay(tau.electron_decay), muon_decay(tau.muon_decay), decay_products(tau.decay_products) {};
  // Overwritten move constructor
  Tau(Tau&&);
  // Overwritten copy assignment operator
  Tau& operator=(Tau&);
  // Overwritten move assignment operator
  Tau& operator=(Tau&&);

  std::vector<std::shared_ptr<Lepton>> get_decay_products() {return decay_products;} 
  void print_data();
};

#endif