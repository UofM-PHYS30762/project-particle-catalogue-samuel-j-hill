#include<iostream>
#include <memory>
#include "electron.h"
#include "muon.h"
#include "neutrino.h"
#include "tau.h"
#include "quark.h"

// Default constructor
Tau::Tau()
{
  rest_mass = 1777;
  set_four_momentum_vector(rest_mass,0,0,0);
  if(print_constructor_destructor) {std::cout<<"Default tau constructor called"<<std::endl;}
}

// Parameterised constructor
Tau::Tau(double tau_energy, double tau_px, double tau_py, double tau_pz, bool antiparticle, bool constructor_destructor_status,
         std::string decay_type) : Lepton(tau_energy, tau_px, tau_py, tau_pz, antiparticle, constructor_destructor_status)
         {
           if(print_constructor_destructor) {std::cout<<"Parameterised Tau constructor called. "<<std::endl;}
           antiparticle ? charge = 1 : charge = -1;
           rest_mass = 1777;
           Particle::check_four_momentum(rest_mass);

           std::shared_ptr<Particle> tau_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                               constructor_destructor_status, "Tau");
           decay_products.push_back(tau_neutrino);
           if(decay_type == "Electron")
           {
             std::vector<double> calorimeter_energies{tau_energy/3,0,0,0};
             std::shared_ptr<Particle> electron = std::make_shared<Electron>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                           constructor_destructor_status, calorimeter_energies);
             std::shared_ptr<Particle> electron_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3,
                                                                                    !antiparticle, constructor_destructor_status, 
                                                                                    "Electron");
             decay_products.push_back(electron);
             decay_products.push_back(electron_neutrino);
           }
           else if(decay_type == "Muon")
           {
             std::shared_ptr<Particle> muon = std::make_shared<Muon>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                     constructor_destructor_status, false);
             std::shared_ptr<Particle> muon_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3,
                                                                                  !antiparticle, constructor_destructor_status, "Muon");
             decay_products.push_back(muon);
             decay_products.push_back(muon_neutrino);
           }
           else if(decay_type == "Pion")
           {
             std::shared_ptr<Particle> up_quark = std::make_shared<Quark>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, !antiparticle, 
                                                                          constructor_destructor_status, "Up", "Red");
             std::shared_ptr<Particle> down_quark = std::make_shared<Quark>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                            constructor_destructor_status, "Down", "Antired");
             decay_products.push_back(up_quark);
             decay_products.push_back(down_quark);                                                                              
           }
           else if(decay_type == "Kaon")
           {
             std::shared_ptr<Particle> up_quark = std::make_shared<Quark>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, !antiparticle, 
                                                                          constructor_destructor_status, "Up", "Red");
             std::shared_ptr<Particle> strange_quark = std::make_shared<Quark>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                            constructor_destructor_status, "Strange", "Antired");
             decay_products.push_back(up_quark);
             decay_products.push_back(strange_quark);                                                                              
           }
           else
           {
             std::cout<<"Decay type not recognised: must be either Electron, Muon, Pion or Kaon "<<std::endl;
             decay_products.pop_back(); // Other decay products cannot be created so tau neutrino is removed so that the vector is empty
           }
         }

// Overwritten move constructor
Tau::Tau(Tau&& tau) : Lepton(tau)
{
  decay_type = tau.decay_type;
  decay_products = tau.decay_products;
  tau.decay_type = "None";
  tau.decay_products = std::vector<std::shared_ptr<Particle>>{nullptr};
}

// Overwritten copy assignment operator
Tau& Tau::operator=(Tau& tau) 
{
  if(&tau != this)
  {
    Lepton::operator=(tau);
  }
  decay_type = tau.decay_type;
  decay_products = tau.decay_products;
  
  return *this;
}

// Overwritten move assignment operator
Tau& Tau::operator=(Tau&& tau)
{
  Particle::operator=(std::move(tau));
  std::swap(decay_type, tau.decay_type);
  std::swap(decay_products, tau.decay_products);

  return *this;
}

void Tau::print_data()
{
   std::cout<<"Particle type: "<<(antiparticle ? "Antitau" : "Tau")<<std::endl;
   Lepton::print_data();
   if(decay_products.size()>0)
   {
     std::cout<<"\nPrinting data of tau decay products\n"<<std::endl;
     for(auto i=decay_products.begin(); i<decay_products.end(); i++)
     {
       (*i)->print_data();
       std::cout<<"\n"<<std::endl;
     }
   }
}