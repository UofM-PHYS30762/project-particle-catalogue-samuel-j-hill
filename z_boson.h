#ifndef Z_BOSON_H
#define Z_BOSON_H

#include <iostream>
#include <vector>
#include <memory>
#include"particle.h"

class ZBoson : public Particle
{
private:
  std::string decay_type{"None"}; // Either "Hadronic", "Leptonic" or "None"
  std::string decay_flavour; // Hadronic type -> any flavour of quark or "None"
                             // Leptonic type -> "Electron", "Muon", "Tau", "Electron neutrino", "Muon neutrino", "Tau neutrino", "None"
  std::vector<std::shared_ptr<Particle>> decay_products;

public:
  // Default constructor
  ZBoson();
  // Parameterised constructor
  ZBoson(double z_boson_energy, double z_boson_px, double z_boson_py, double z_boson_pz, bool constructor_destructor_status,
         std::string decay_type, std::string decay_flavour);
  // Destructor 
  ~ZBoson() {if(print_constructor_destructor) {std::cout<<"Z boson destructor called"<<std::endl;}}
  // Overwritten copy constructor
  ZBoson(ZBoson& z) : Particle(z), decay_type(z.decay_type), decay_flavour(z.decay_flavour), decay_products(z.decay_products) {};
  // Overwritten move constructor
  ZBoson(ZBoson&&);
  // Overwritten copy assignment operator
  ZBoson& operator=(ZBoson&);
  // Overwritten move assignment operator
  ZBoson& operator=(ZBoson&&);

  std::string get_decay_type() {return decay_type;}
  std::string get_decay_flavour() {return decay_flavour;}
  std::vector<std::shared_ptr<Particle>> get_decay_products() {return decay_products;} 
  void print_data();
};

#endif