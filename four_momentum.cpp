#include <iostream>
#include "four_momentum.h"

// Parameterised constructor
FourMomentum::FourMomentum(double energy, double p_x, double p_y, double p_z)
{
  //if(print_constructor_destructor) {std::cout<<"Parameterised four momentum constructor called. "<<std::endl;}
  try
  {
    if(energy < 0)
    {
      throw std::invalid_argument("Energy must be positive. ");
    }
    four_momentum_vector[0] = energy;
    four_momentum_vector[1] = p_x;
    four_momentum_vector[2] = p_y;
    four_momentum_vector[3] = p_z;
  }
  catch(const std::invalid_argument& e)
  {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
    four_momentum_vector[0] = 0;
    four_momentum_vector[1] = p_x;
    four_momentum_vector[2] = p_y;
    four_momentum_vector[3] = p_z;
  }
}

std::vector<double> sum(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2)
{
  std::vector<double> summed_four_momentum;
  for(int i = 0; i < 4; i++)
  {
    summed_four_momentum.push_back((four_momentum_1.four_momentum_vector)[i] + (four_momentum_2.four_momentum_vector)[i]);
  }
  
  return summed_four_momentum;
}

std::vector<double> difference(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2)
{
  std::vector<double> summed_four_momentum;
  for(int i = 0; i < 4; i++)
  {
    summed_four_momentum.push_back((four_momentum_1.four_momentum_vector)[i] - (four_momentum_2.four_momentum_vector)[i]);
  }
  
  return summed_four_momentum;
}

double dot_product(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2)
{
  double dot_product = four_momentum_1.four_momentum_vector[0] * four_momentum_2.four_momentum_vector[0]
                       - four_momentum_1.four_momentum_vector[1] * four_momentum_2.four_momentum_vector[1]
                       - four_momentum_1.four_momentum_vector[2] * four_momentum_2.four_momentum_vector[2]
                       - four_momentum_1.four_momentum_vector[3] * four_momentum_2.four_momentum_vector[3];

  return dot_product;
}


void FourMomentum::set_four_momentum_vector(double energy, double p_x, double p_y, double p_z)
{
  try
  {
    if(energy < 0)
    {
      throw std::invalid_argument("Energy must be positive. ");
    }
    four_momentum_vector[0] = energy;
    four_momentum_vector[1] = p_x;
    four_momentum_vector[2] = p_y;
    four_momentum_vector[3] = p_z;
  }
  catch(const std::invalid_argument& e)
  {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
    four_momentum_vector[0] = 0;
    four_momentum_vector[1] = p_x;
    four_momentum_vector[2] = p_y;
    four_momentum_vector[3] = p_z;
  }
}

double FourMomentum::get_invariant_mass() 
{
  double invariant_mass_squared =  std::pow(four_momentum_vector[0],2) - std::pow(four_momentum_vector[1],2)
                                - std::pow(four_momentum_vector[2],2) - std::pow(four_momentum_vector[3],2);
  if(invariant_mass_squared >= 0)
  {
    return sqrt(invariant_mass_squared);
  }
  else
  {
    throw std::invalid_argument("Energy squared must be bigger than sum of squared momenta. ");
  }
}