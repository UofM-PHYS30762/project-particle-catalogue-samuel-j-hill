#include<iostream>
#include "neutrino.h"

// Default constructor
Neutrino::Neutrino()
{
  if(print_constructor_destructor) {std::cout<<"Default neutrino constructor called"<<std::endl;}
  charge = 0; 
  set_four_momentum_vector(1,1,0,0);
}

// Parameterised constructor
Neutrino::Neutrino(double neutrino_energy, double neutrino_px, double neutrino_py, double neutrino_pz, bool antiparticle,
                   bool constructor_destructor_status, std::string neutrino_flavour) : 
                   Lepton(neutrino_energy, neutrino_px, neutrino_py, neutrino_pz, antiparticle, constructor_destructor_status)
          {
              if(print_constructor_destructor) {std::cout<<"Neutrino parameterised constructor called"<<std::endl;}
              try
              {
                flavour = neutrino_flavour;
                if(!(flavour == "Electron" || flavour == "Muon" || flavour == "Tau"))
                {
                  throw std::invalid_argument("Flavour must be either Electron, Muon or Tau. ");
                }
              }
              catch(const std::exception& e)
              {
                std::cerr<<e.what()<<std::endl;
                flavour = "Unrecognised";
              }
              charge = 0;
              rest_mass = 0;
              check_four_momentum(rest_mass);
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