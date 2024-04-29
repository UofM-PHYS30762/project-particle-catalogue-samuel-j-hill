#include<iostream>
#include <memory>
#include "electron.h"
#include "muon.h"
#include "neutrino.h"
#include "tau.h"

// Default constructor
Tau::Tau()
{
  rest_mass = 1777;
  set_four_momentum_vector(rest_mass,0,0,0);
  if(print_constructor_destructor) {std::cout<<"Default tau constructor called"<<std::endl;}
}

// Parameterised constructor
Tau::Tau(double tau_energy, double tau_px, double tau_py, double tau_pz, bool antiparticle, bool constructor_destructor_status,
         bool electron_decay, bool muon_decay) : Lepton(tau_energy, tau_px, tau_py, tau_pz, antiparticle, constructor_destructor_status)
         {
           if(print_constructor_destructor) {std::cout<<"Parameterised Tau constructor called. "<<std::endl;}
           antiparticle ? charge = 1 : charge = -1;
           rest_mass = 1777;
           Particle::check_four_momentum(rest_mass);
 
           if(electron_decay && muon_decay)
           {
             throw std::invalid_argument("Tau cannot undergo both electron and muon decay. ");
           }
           
           else if(electron_decay)
           {
             std::vector<double> calorimeter_energies{tau_energy/3,0,0,0};
             std::shared_ptr<Lepton> electron = std::make_shared<Electron>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                           constructor_destructor_status, calorimeter_energies);
             std::shared_ptr<Lepton> electron_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3,
                                                                                    !antiparticle, constructor_destructor_status, 
                                                                                    "Electron");
             std::shared_ptr<Lepton> tau_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                               constructor_destructor_status, "Tau");
             decay_products.push_back(electron);
             decay_products.push_back(electron_neutrino);
             decay_products.push_back(tau_neutrino);
           }
           else if(muon_decay)
           {
             std::shared_ptr<Lepton> muon = std::make_shared<Muon>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                   constructor_destructor_status, false);
             std::shared_ptr<Lepton> muon_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3,
                                                                                !antiparticle, constructor_destructor_status, "Muon");
             std::shared_ptr<Lepton> tau_neutrino = std::make_shared<Neutrino>(tau_energy/3, tau_px/3, tau_py/3, tau_pz/3, antiparticle, 
                                                                               constructor_destructor_status, "Tau");
             decay_products.push_back(muon);
             decay_products.push_back(muon_neutrino);
             decay_products.push_back(tau_neutrino);
           } 
           else
           {
             std::cout<<"Tau decayed into a hadron and a tau neutrino"<<std::endl;
           }
         }

// Overwritten move constructor
Tau::Tau(Tau&& tau) : Lepton(tau)
{
  electron_decay = tau.electron_decay;
  muon_decay = tau.muon_decay;
  decay_products = tau.decay_products;
  tau.electron_decay = false;
  tau.muon_decay = false;
  tau.decay_products = std::vector<std::shared_ptr<Lepton>>{nullptr};
}

// Overwritten copy assignment operator
Tau& Tau::operator=(Tau& tau) 
{
  if(&tau != this)
  {
    Lepton::operator=(tau);
  }
  electron_decay = tau.electron_decay;
  muon_decay = tau.muon_decay;
  decay_products = tau.decay_products;
  
  return *this;
}

// Overwritten move assignment operator
Tau& Tau::operator=(Tau&& tau)
{
  Particle::operator=(std::move(tau));
  std::swap(electron_decay, tau.electron_decay);
  std::swap(muon_decay, tau.muon_decay);
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