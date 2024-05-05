#include <iostream>
#include <iomanip>
#include <numeric> 
#include <cmath>
#include "electron.h"
#include "lepton.h"

// Default constructor
Electron::Electron()
{
  if(print_constructor_destructor) {std::cout<<"Default electron constructor called"<<std::endl;}
  rest_mass = 0.511;
  set_four_momentum_vector(rest_mass,0,0,0);
}

// Parameterised constructor
Electron::Electron(double electron_energy, double electron_px, double electron_py, double electron_pz, bool antiparticle, 
                   bool constructor_destructor_status, std::vector<double> deposited_energies) : 
                   Lepton(electron_energy, electron_px, electron_py, electron_pz, antiparticle, constructor_destructor_status) 
                   {
                      if(print_constructor_destructor) {std::cout<<"Electron parameterised constructor called"<<std::endl;}
                      try 
                      {
                        calorimeter_deposited_energies = deposited_energies;
                        if(abs(std::accumulate(calorimeter_deposited_energies.begin(),calorimeter_deposited_energies.end(),0.0) - 
                           electron_energy) > 0.001)
                        {
                          throw std::invalid_argument("Energies deposited in calorimeter must sum to electron energy. ");
                        }
                      }
                      catch(const std::exception& e)
                      {
                        std::cerr<<e.what()<<std::endl;
                        std::cout<<"Setting all energy to be deposited in the first layer. "<<std::endl;
                        std::vector<double> replacement_deposited_energies{electron_energy,0,0,0};
                        calorimeter_deposited_energies = replacement_deposited_energies;
                      }
                      antiparticle ? charge = 1 : charge = -1;
                      rest_mass = 0.511;
                      check_four_momentum(rest_mass);
                      std::vector<double> rest_four_momentum{0.511, 0, 0, 0};
                      if(four_momentum->get_four_momentum_vector() == rest_four_momentum)  
                      {
                        set_calorimeter_deposited_energies(rest_four_momentum);
                      }

                   } 

// Overwritten move constructor
Electron::Electron(Electron&& elec) : Lepton(elec)
{
  calorimeter_deposited_energies = elec.calorimeter_deposited_energies;
  std::vector<double> empty_deposited_energies{0,0,0,0};
  elec.calorimeter_deposited_energies = empty_deposited_energies;
}

// Overwritten copy assignment operator
Electron& Electron::operator=(Electron& elec) 
{
  if(&elec != this)
  {
    Particle::operator=(elec);
  }
  calorimeter_deposited_energies = elec.calorimeter_deposited_energies;
  
  return *this;
}

// Overwritten move assignment operator
Electron& Electron::operator=(Electron&& elec)
{
  Particle::operator=(std::move(elec));
  std::swap(calorimeter_deposited_energies, elec.calorimeter_deposited_energies);

  return *this;
}

void Electron::set_calorimeter_deposited_energies(std::vector<double> deposited_energies)
{
  try
  {
    calorimeter_deposited_energies = deposited_energies;
    if(abs(std::accumulate(calorimeter_deposited_energies.begin(),calorimeter_deposited_energies.end(),0.0) - 
     (four_momentum->get_four_momentum_vector())[0]) > 0.0001)
    {
      throw std::invalid_argument("Energies deposited in calorimeter must sum to electron energy. ");
    }
  }
  catch(const std::exception& e)
  {
    std::cerr<<e.what()<<std::endl;
    std::vector<double> replacement_deposited_energies{get_four_momentum_vector()[0],0,0,0};
    calorimeter_deposited_energies = replacement_deposited_energies;
  }
}

// Overridden print function
void Electron::print_data()
{
   std::cout<<"Particle type: "<<(antiparticle ? "Antielectron" : "Electron")<<std::endl;
   Lepton::print_data();
   std::cout<<"Energy deposited in EM 1 layer = "<<std::setprecision(3)<<calorimeter_deposited_energies[0]<<std::endl;
   std::cout<<"Energy deposited in EM 2 layer = "<<std::setprecision(3)<<calorimeter_deposited_energies[1]<<std::endl;
   std::cout<<"Energy deposited in HAD 1 layer = "<<std::setprecision(3)<<calorimeter_deposited_energies[2]<<std::endl;
   std::cout<<"Energy deposited in HAD 2 layer = "<<std::setprecision(3)<<calorimeter_deposited_energies[3]<<std::endl;
}