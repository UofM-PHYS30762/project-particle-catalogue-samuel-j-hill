#ifndef W_BOSON_H
#define W_BOSON_H

#include <iostream>
#include <vector>
#include <memory>
#include"particle.h"

class WBoson : public Particle
{
private:
  std::string decay_type{"None"};
  std::string decay_flavour;
  std::vector<std::shared_ptr<Particle>> decay_products;

public:
  // Default constructor
  WBoson();
  // Parameterised constructor
  WBoson(double w_boson_energy, double w_boson_px, double w_boson_py, double w_boson_pz, bool antiparticle,
         bool constructor_destructor_status, std::string decay_type, std::string decay_flavour);
  // Destructor 
  ~WBoson() {if(print_constructor_destructor) {std::cout<<"W boson destructor called"<<std::endl;}}
  // Overwritten copy constructor
  WBoson(WBoson& w) : Particle(w), decay_type(w.decay_type), decay_flavour(w.decay_flavour), decay_products(w.decay_products) {};
  // Overwritten move constructor
  WBoson(WBoson&&);
  // Overwritten copy assignment operator
  WBoson& operator=(WBoson&);
  // Overwritten move assignment operator
  WBoson& operator=(WBoson&&);

  std::string get_decay_type() {return decay_type;}
  std::string get_decay_flavour() {return decay_flavour;}
  std::vector<std::shared_ptr<Particle>> get_decay_products() {return decay_products;} 
  void print_data();
};

#endif