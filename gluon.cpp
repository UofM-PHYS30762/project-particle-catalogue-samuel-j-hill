#include <iostream>
#include "gluon.h"

// Parameterised constructor
Gluon::Gluon(double gluon_energy, double gluon_px, double gluon_py, double gluon_pz, bool antiparticle_status,
             bool constructor_destructor_status) : Particle(gluon_energy, gluon_px, gluon_py, gluon_pz, antiparticle_status,
                                                            constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised gluon constructor called"<<std::endl;}
  spin = 1;
  check_four_momentum(rest_mass);
};

void Gluon::print_data()
{
  std::cout<<"Particle type: "<<(antiparticle ? "Antigluon" : "Gluon")<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
}