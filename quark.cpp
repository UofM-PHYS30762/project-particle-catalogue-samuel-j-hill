#include<iostream>
#include "quark.h"

// Parameterised constructor
Quark::Quark(double quark_energy, double quark_px, double quark_py, double quark_pz, bool antiparticle,
             bool constructor_destructor_status, std::string quark_flavour, std::string quark_colour_charge) :
             Particle(quark_energy, quark_px, quark_py, quark_pz, antiparticle, constructor_destructor_status)
             {
               if(print_constructor_destructor) {std::cout<<"Quark parameterised constructor called"<<std::endl;}
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
                 if(!antiparticle && !(colour_charge == "Red" || colour_charge == "Blue" || colour_charge == "Green"))
                 {
                   throw std::invalid_argument("Colour charge must be one of: Red, Blue, Green for a quark. ");
                 }
                 else if(antiparticle && !(colour_charge == "Antired" || colour_charge == "Antiblue" || colour_charge == "Antigreen"))
                 {
                   throw std::invalid_argument("Colour charge must be one of: Antired, Antiblue, Antigreen for an antiquark. ");
                 }
               }
               catch(const std::exception& e)
               {
                 std::cerr<<e.what()<<std::endl;
               }              
               antiparticle ? baryon_number = -1/3 : baryon_number = 1/3;
               rest_mass = quark_masses[flavour];
               charge = quark_charges[flavour];
               Particle::check_four_momentum(rest_mass);
             }