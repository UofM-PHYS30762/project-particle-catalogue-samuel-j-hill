#include <iostream>
#include "gluon.h"

// Default constructor
Gluon::Gluon() : Particle() 
{
  if(print_constructor_destructor){std::cout<<"Default gluon constructor called"<<std::endl;}
  spin = 1; 
  set_four_momentum_vector(1,1,0,0);
}

// Parameterised constructor
Gluon::Gluon(double gluon_energy, double gluon_px, double gluon_py, double gluon_pz, bool antiparticle_status,
             bool constructor_destructor_status, std::string colour_charge_1, std::string colour_charge_2)
             : Particle(gluon_energy, gluon_px, gluon_py, gluon_pz, antiparticle_status,
                                                            constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised gluon constructor called"<<std::endl;}
  try
  {
    first_colour_charge = colour_charge_1;
    second_colour_charge = colour_charge_2;
    if(first_colour_charge == "Red" || first_colour_charge == "Blue" || first_colour_charge == "Green")
    {
      if(!(second_colour_charge == "Antired" || second_colour_charge == "Antiblue" || second_colour_charge == "Antigreen"))
      {
        throw std::invalid_argument("Colour charges should be a colour and anticolour, not necessarily of the same colour");
      }
    }
    else if(first_colour_charge == "Antired" || first_colour_charge == "Antiblue" || first_colour_charge == "Antigreen")
    {
      if(!(second_colour_charge == "Red" || second_colour_charge == "Blue" || second_colour_charge == "Green"))
      {
        throw std::invalid_argument("Colour charges should be a colour and anticolour, not necessarily of the same colour");
      }
    }
    else
    {
      throw std::invalid_argument("Colour charges should be a colour and anticolour, not necessarily of the same colour");
    }
  }
  catch(const std::exception& e)
  {
    std::cerr<<e.what()<<std::endl;
    first_colour_charge = "Unrecognised";
    second_colour_charge = "Unrecognised";
  }
  
  spin = 1;
  check_four_momentum(rest_mass);
};

void Gluon::print_data()
{
  std::cout<<"Particle type: "<<(antiparticle ? "Antigluon" : "Gluon")<<std::endl;
  std::cout<<"First colour charge = "<<first_colour_charge<<std::endl;
  std::cout<<"Second colour charge = "<<second_colour_charge<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
}