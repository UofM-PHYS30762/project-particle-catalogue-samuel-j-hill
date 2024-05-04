#include <iostream>
#include "lepton.h"

// Parameterised constructor
Lepton::Lepton(double lepton_energy, double lepton_px, double lepton_py, double lepton_pz, bool antiparticle_status,
               bool constructor_destructor_status) : Particle(lepton_energy, lepton_px, lepton_py, lepton_pz, antiparticle_status,
                                                              constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised lepton constructor called"<<std::endl;}
  spin = 0.5;
  antiparticle ? lepton_number = -1 : lepton_number = 1;
};

void Lepton::print_data()
{
  std::cout<<"Lepton number = "<<lepton_number<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
}