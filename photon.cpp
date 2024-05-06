#include <iostream>
#include "photon.h"

// Default constructor
Photon::Photon() : Particle() 
{
  if(print_constructor_destructor) {std::cout<<"Default photon constructor called"<<std::endl;}
  spin = 1; 
  set_four_momentum_vector(1,1,0,0);  
};

// Parameterised constructor
Photon::Photon(double photon_energy, double photon_px, double photon_py, double photon_pz, bool constructor_destructor_status) : 
               Particle(photon_energy, photon_px, photon_py, photon_pz, false, constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised photon constructor called"<<std::endl;}
  spin = 1;
  check_four_momentum(rest_mass);
};

void Photon::print_data()
{
  std::cout<<"Particle type: Photon"<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
}