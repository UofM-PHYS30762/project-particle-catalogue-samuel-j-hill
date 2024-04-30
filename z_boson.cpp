#include<iostream>
#include <memory>
#include "z_boson.h"
#include "electron.h"
#include "muon.h"
#include "neutrino.h"
#include "tau.h"
#include "quark.h"

// Default constructor
ZBoson::ZBoson()
{
  spin = 1;
  rest_mass = 91200;
  set_four_momentum_vector(rest_mass,0,0,0);
  if(print_constructor_destructor) {std::cout<<"Default Z boson constructor called"<<std::endl;}
}

// Parameterised constructor
ZBoson::ZBoson(double z_boson_energy, double z_boson_px, double z_boson_py, double z_boson_pz, bool constructor_destructor_status,
               std::string decay_type, std::string decay_flavour) : Particle(z_boson_energy, z_boson_px, z_boson_py, z_boson_pz, false,
                                                                             constructor_destructor_status)
               {
                 if(print_constructor_destructor) {std::cout<<"Parameterised Z boson constructor called. "<<std::endl;}
                 spin = 1;
                 rest_mass = 91200;
                 Particle::check_four_momentum(rest_mass);
                 decay_type = decay_type;
                 decay_flavour = decay_flavour;

                 if(decay_type == "Hadronic")
                 {
                    std::shared_ptr<Particle> quark = std::make_unique<Quark>(z_boson_energy/2, z_boson_px/2, z_boson_py/2, z_boson_pz/2,
                                                                              false, constructor_destructor_status, decay_flavour, "Red");
                    std::shared_ptr<Particle> antiquark = std::make_unique<Quark>(z_boson_energy/2, z_boson_px/2, z_boson_py/2, z_boson_pz/2,
                                                                              true, constructor_destructor_status, decay_flavour,
                                                                              "Antired");   
                    decay_products.push_back(quark);
                    decay_products.push_back(antiquark);                                                                        
                 }  
                 else if(decay_type == "Leptonic")
                 {
                   if(decay_flavour == "Electron")
                   {
                     std::vector<double> energies_deposited{z_boson_energy/2,0,0,0};
                     std::shared_ptr<Particle> electron = std::make_unique<Electron>(z_boson_energy/2, z_boson_px/2, z_boson_py/2,
                                                                                     z_boson_pz/2, false, constructor_destructor_status,
                                                                                     energies_deposited);
                     std::shared_ptr<Particle> antielectron = std::make_unique<Electron>(z_boson_energy/2, z_boson_px/2, z_boson_py/2,
                                                                                     z_boson_pz/2, true, constructor_destructor_status,
                                                                                     energies_deposited);  
                    decay_products.push_back(electron);
                    decay_products.push_back(antielectron);                                                                                  
                   }
                   else if(decay_flavour == "Muon")
                   {
                     std::shared_ptr<Particle> muon = std::make_unique<Muon>(z_boson_energy/2, z_boson_px/2, z_boson_py/2, z_boson_pz/2,
                                                                            false, constructor_destructor_status, false);
                     std::shared_ptr<Particle> antimuon = std::make_unique<Muon>(z_boson_energy/2, z_boson_px/2, z_boson_py/2, 
                                                                                 z_boson_pz/2, true, constructor_destructor_status,
                                                                                 false);
                    decay_products.push_back(muon);
                    decay_products.push_back(antimuon);  
                   }
                   else if(decay_flavour == "Electron neutrino" || decay_flavour == "Muon neutrino" || decay_flavour == "Tau neutrino")
                   {
                     std::string neutrino_flavour = decay_flavour.substr(0,decay_flavour.size()-9);
                     std::shared_ptr<Particle> neutrino = std::make_unique<Neutrino>(z_boson_energy/2, z_boson_px/2, z_boson_py/2, 
                                                                                     z_boson_pz/2, false, constructor_destructor_status,
                                                                                     neutrino_flavour);
                     std::shared_ptr<Particle> antineutrino = std::make_unique<Neutrino>(z_boson_energy/2, z_boson_px/2, z_boson_py/2, 
                                                                                         z_boson_pz/2, true, constructor_destructor_status,
                                                                                         neutrino_flavour);
                    decay_products.push_back(neutrino);
                    decay_products.push_back(antineutrino);
                   }
                   else
                   {
                     std::cout<<"Decay flavour not recognised"<<std::endl;
                   }
                 } 
                 else
                 {
                   std::cout<<"Decay type not recognised"<<std::endl;
                 }
               }

// Overwritten move constructor
ZBoson::ZBoson(ZBoson&& z) : Particle(z)
{
  decay_type = z.decay_type;
  decay_flavour = z.decay_flavour;
  decay_products = z.decay_products;
  z.decay_type = "None";
  z.decay_flavour = "None";
  z.decay_products = std::vector<std::shared_ptr<Particle>>{nullptr};
}

// Overwritten copy assignment operator
ZBoson& ZBoson::operator=(ZBoson& z) 
{
  if(&z != this)
  {
    Particle::operator=(z);
  }
  decay_type = z.decay_type;
  decay_flavour = z.decay_flavour;
  decay_products = z.decay_products;
  
  return *this;
}

// Overwritten move assignment operator
ZBoson& ZBoson::operator=(ZBoson&& z)
{
  Particle::operator=(std::move(z));
  std::swap(decay_type, z.decay_type);
  std::swap(decay_flavour, z.decay_flavour);
  std::swap(decay_products, z.decay_products);

  return *this;
}

void ZBoson::print_data()
{
   std::cout<<"Particle type: Z boson"<<std::endl;
   Particle::print_data();
   if(decay_products.size()>0)
   {
     std::cout<<"\nPrinting data of Z boson decay products\n"<<std::endl;
     for(auto i=decay_products.begin(); i<decay_products.end(); i++)
     {
       (*i)->print_data();
       std::cout<<"\n"<<std::endl;
     }
   }
}