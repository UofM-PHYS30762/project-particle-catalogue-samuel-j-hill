#ifndef HIGGS_BOSON_H
#define HIGGS_BOSON_H

#include <iostream>
#include <vector>
#include <memory>
#include"particle.h"

class HiggsBoson : public Particle
{
private: 
  std::string decay_type{"None"}; // Either "Z boson", "W boson", "Photon", "Bottom quark" or "None"
  std::vector<std::shared_ptr<Particle>> decay_products;

public:
  // Default constructor
  HiggsBoson() {rest_mass = 126000; set_four_momentum_vector(rest_mass,0,0,0); if(print_constructor_destructor) {std::cout<<"Default Higgs boson constructor called"<<std::endl;}};
  // Parameterised constructor
  HiggsBoson(double higgs_boson_energy, double higgs_boson_px, double higgs_boson_py, double higgs_boson_pz,
             bool constructor_destructor_status, std::string decay_type);
  // Destructor 
  ~HiggsBoson() {if(print_constructor_destructor) {std::cout<<"Higgs boson destructor called"<<std::endl;}}
  // Overwritten copy constructor
  HiggsBoson(HiggsBoson& higgs) : Particle(higgs), decay_type(higgs.decay_type), decay_products(higgs.decay_products) {};
  // Overwritten move constructor
  HiggsBoson(HiggsBoson&&);
  // Overwritten copy assignment operator
  HiggsBoson& operator=(HiggsBoson&);
  // Overwritten move assignment operator
  HiggsBoson& operator=(HiggsBoson&&);

  std::string get_decay_type() {return decay_type;}
  std::vector<std::shared_ptr<Particle>> get_decay_products() {return decay_products;} 
  void print_data();
};

#endif