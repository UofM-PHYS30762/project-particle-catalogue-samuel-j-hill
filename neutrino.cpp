#include<iostream>
#include "neutrino.h"

// Parameterised constructor
Neutrino::Neutrino(double neutrino_energy, double neutrino_px, double neutrino_py, double neutrino_pz, bool antiparticle,
                   bool constructor_destructor_status, std::string flavour) : 
                   Lepton(neutrino_energy, neutrino_px, neutrino_py, neutrino_pz, antiparticle, constructor_destructor_status), 
                   flavour{flavour} 
          {
              if(print_constructor_destructor) {std::cout<<"Neutrino parameterised constructor called"<<std::endl;}
              if(!(flavour == "Electron" || flavour == "electron" || flavour == "Muon" || flavour == "muon" || flavour == "Tau" || flavour == "tau"))
              {
                throw std::invalid_argument("Flavour must be either Electron/electron, Muon/muon or Tau/tau. ");
              }
              rest_mass = 0;
              Particle::check_four_momentum();
              charge = 0;
          }  

// Overwritten move constructor
Neutrino::Neutrino(Neutrino&& neut) : Lepton(neut)
{
  flavour = neut.flavour;
  neut.flavour = "None";
}

// Overwritten copy assignment operator
Neutrino& Neutrino::operator=(Neutrino& neut) 
{
  if(&neut != this)
  {
    Particle::operator=(neut);
  }
  flavour = neut.flavour;
  
  return *this;
}

// Overwritten move assignment operator
Neutrino& Neutrino::operator=(Neutrino&& neut)
{
  Particle::operator=(std::move(neut));
  std::swap(flavour, neut.flavour);

  return *this;
}

// Overridden print function
void Neutrino::print_data()
{
    std::cout<<"Particle type: "<<flavour<<(antiparticle ? " antineutrino" : " neutrino")<<std::endl;
    Lepton::print_data();
    std::cout<<(has_interacted ? "Has interacted" : "Has not interacted")<<std::endl;
}