#ifndef TAU_H
#define TAU_H

#include <iostream>
#include <vector>
#include <memory>
#include "lepton.h"

class Tau: public Lepton
{
private:
  std::string decay_type;
  std::vector<std::shared_ptr<Particle>> decay_products;

public:
  // Default constructor
  Tau();
  // Parameterised constructor
  Tau(double tau_energy, double tau_px, double tau_py, double tau_pz, bool antiparticle, bool constructor_destructor_status,
      std::string decay_type);
  // Destructor 
  ~Tau() {if(print_constructor_destructor) {std::cout<<"Tau destructor called"<<std::endl;}}
  // Overwritten copy constructor
  Tau(Tau& tau) : Lepton(tau), decay_type(tau.decay_type), decay_products(tau.decay_products) {};
  // Overwritten move constructor
  Tau(Tau&&);
  // Overwritten copy assignment operator
  Tau& operator=(Tau&);
  // Overwritten move assignment operator
  Tau& operator=(Tau&&);

  std::vector<std::shared_ptr<Particle>> get_decay_products() {return decay_products;} 
  void print_data();
};

#endif