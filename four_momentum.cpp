#include <iostream>
#include "four_momentum.h"

// Parameterised constructor
FourMomentum::FourMomentum(double energy, double p_x, double p_y, double p_z)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised four momentum constructor called. "<<std::endl;}
  if(energy < 0)
  {
    throw std::invalid_argument("Energy must be positive. ");
  }
  
  four_momentum_vector[0] = energy/speed_of_light;
  four_momentum_vector[1] = p_x;
  four_momentum_vector[2] = p_y;
  four_momentum_vector[3] = p_z;
}

void FourMomentum::set_four_momentum_vector(double energy, double p_x, double p_y, double p_z)
{
  if(energy < 0)
  {
    throw std::invalid_argument("Energy must be positive. ");
  }
  four_momentum_vector[0] = energy/speed_of_light;
  four_momentum_vector[1] = p_x;
  four_momentum_vector[2] = p_y;
  four_momentum_vector[3] = p_z;
}