#include<iostream>
#include "quark.h"

std::map<std::string,double> Quark::quark_masses = {{"Up", 2.3}, {"Down", 4.8}, {"Charm", 1275},{"Strange", 95},{"Top", 173070},
                                                    {"Bottom", 4180}};

std::map<std::string,double> Quark::quark_charges = {{"Up", 0.666}, {"Down", -0.333}, {"Charm", 0.666},{"Strange", -0.333},{"Top", 0.666},
                                                     {"Bottom", -0.333}};

// Default constructor
Quark::Quark()
{
  charge = 0.666; // Defaults to up quark
  spin = 0.5;
  rest_mass = 2.3;
  set_four_momentum_vector(rest_mass,0,0,0);
  if(print_constructor_destructor) {std::cout<<"Default quark constructor called"<<std::endl;}
}

// Parameterised constructor
Quark::Quark(double quark_energy, double quark_px, double quark_py, double quark_pz, bool antiparticle_status,
             bool constructor_destructor_status, std::string quark_flavour, std::string quark_colour_charge) :
             Particle(quark_energy, quark_px, quark_py, quark_pz, antiparticle_status, constructor_destructor_status)
             {
               if(print_constructor_destructor) {std::cout<<"Quark parameterised constructor called"<<std::endl;}
               antiparticle_status ? baryon_number = -0.333 : baryon_number = 0.333;
               spin = 0.5;
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
                 flavour = "Unspecified";
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
                 colour_charge = "Unspecified";
               }              
               antiparticle ? charge = -quark_charges[flavour] : charge = quark_charges[flavour];
               if(flavour != "Unspecified") {rest_mass = quark_masses[flavour]; check_four_momentum(rest_mass);}
             }

// Overwritten move constructor
Quark::Quark(Quark&& qu) : Particle(qu)
{
  baryon_number = qu.baryon_number;
  colour_charge = qu.colour_charge;
  flavour = qu.flavour;
  baryon_number = 0.333;
  colour_charge = "None";
  flavour = "None";
}

// Overwritten copy assignment operator
Quark& Quark::operator=(Quark& qu) 
{
  if(&qu != this)
  {
    Particle::operator=(qu);
  }
  baryon_number = qu.baryon_number;
  colour_charge = qu.colour_charge;
  flavour = qu.flavour;
  
  return *this;
}

// Overwritten move assignment operator
Quark& Quark::operator=(Quark&& qu)
{
  Particle::operator=(std::move(qu));
  std::swap(baryon_number, qu.baryon_number);
  std::swap(colour_charge, qu.colour_charge);
  std::swap(flavour, qu.flavour);

  return *this;
}

// Overwritten print function
void Quark::print_data()
{
  std::cout<<"Particle type: "<<flavour<<(antiparticle ? " antiquark" : " quark")<<std::endl;
  std::cout<<"Baryon number = "<<baryon_number<<std::endl;
  std::cout<<"Colour charge = "<<colour_charge<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;  
}