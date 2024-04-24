#include<iostream>
#include "quark.h"

// Parameterised constructor
Quark::Quark(double quark_energy, double quark_px, double quark_py, double quark_pz, bool antiparticle_status,
             bool constructor_destructor_status, std::string quark_flavour, std::string quark_colour_charge) :
             Particle(quark_energy, quark_px, quark_py, quark_pz, antiparticle_status, constructor_destructor_status)
             {
               if(print_constructor_destructor) {std::cout<<"Quark parameterised constructor called"<<std::endl;}
               antiparticle_status ? baryon_number = -0.333 : baryon_number = 0.333;
               antiparticle_status ? spin = -0.5 : spin = 0.5;
               try
               {
                 flavour = quark_flavour;
                 auto i = quark_masses.find(flavour);
                 if(i == quark_masses.end())
                 {
                   throw std::invalid_argument("Flavour must be one of: Up, Down, Charm, Strange, Top or Bottom. ");
                 }
               }
               catch(const std::exception& e)
               {
                 std::cerr<<e.what()<<std::endl;
               }

               try
               {
                 colour_charge = quark_colour_charge;
                 if(!antiparticle_status && !(colour_charge == "Red" || colour_charge == "Blue" || colour_charge == "Green"))
                 {
                   throw std::invalid_argument("Colour charge must be one of: Red, Blue, Green for a quark. ");
                 }
                 else if(antiparticle_status && !(colour_charge == "Antired" || colour_charge == "Antiblue" || colour_charge == "Antigreen"))
                 {
                   throw std::invalid_argument("Colour charge must be one of: Antired, Antiblue, Antigreen for an antiquark. ");
                 }
               }
               catch(const std::exception& e)
               {
                 std::cerr<<e.what()<<std::endl;
               }              
               rest_mass = quark_masses[flavour];
               charge = quark_charges[flavour];
               Particle::check_four_momentum(rest_mass);
             }

// Overwritten print function
void Quark::print_data()
{
  std::cout<<"Particle type: "<<flavour<<(antiparticle ? " antiquark" : " quark")<<std::endl;
  std::cout<<"Baryon number = "<<baryon_number<<std::endl;
  std::cout<<"Colour charge = "<<colour_charge<<std::endl;
  Particle::print_data();  
}