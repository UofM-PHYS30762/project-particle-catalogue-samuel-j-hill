#include<iostream>
#include "muon.h"

// Parameterised constructor
Muon::Muon(double muon_energy, double muon_px, double muon_py, double muon_pz, bool antiparticle, bool isolated_status,
           bool constructor_destructor_status) : Lepton(muon_energy, muon_px, muon_py, muon_pz, antiparticle, 
                                                        constructor_destructor_status), isolated{isolated_status}
          {
              if(print_constructor_destructor) {std::cout<<"Muon parameterised constructor called"<<std::endl;}
              rest_mass = 105.7;
              Particle::check_four_momentum();
              antiparticle ? charge = 1 : charge = -1;
              antiparticle ? spin = -0.5 : spin = 0.5;
          }  

// Overwritten move constructor
Muon::Muon(Muon&& mu) : Lepton(mu)
{
  isolated = mu.isolated;
  mu.isolated = false;
}

// Overwritten copy assignment operator
Muon& Muon::operator=(Muon& mu) 
{
  if(&mu != this)
  {
    Particle::operator=(mu);
  }
  isolated = mu.isolated;
  
  return *this;
}

// Overwritten move assignment operator
Muon& Muon::operator=(Muon&& mu)
{
  Particle::operator=(std::move(mu));
  std::swap(isolated, mu.isolated);

  return *this;
}

// Overridden print function
void Muon::print_data()
{
   std::cout<<"Particle type: "<<(antiparticle ? "Antimuon" : "Muon")<<std::endl;
   Lepton::print_data();
   std::cout<<(isolated ? "Isolated" : "Not isolated")<<std::endl;
}