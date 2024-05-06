#include <iostream>
#include "four_momentum.h"

// Move constructor
FourMomentum::FourMomentum(FourMomentum &&other_four_momentum)
{
  four_momentum_vector = other_four_momentum.four_momentum_vector;
  other_four_momentum.set_four_momentum_vector(0,0,0,0);
}

// Copy assignment operator
FourMomentum& FourMomentum::operator=(FourMomentum &other_four_momentum)
{
  if(&other_four_momentum == this) {return *this;}
  four_momentum_vector = other_four_momentum.four_momentum_vector;
  
  return *this;
}

FourMomentum FourMomentum::operator+(FourMomentum& other_four_momentum)
{
  std::vector<double> summed_four_momentum_vector;
  for(int i = 0; i < 4; i++)
  {
    summed_four_momentum_vector.push_back(four_momentum_vector[i] + (other_four_momentum.four_momentum_vector)[i]);
  }
  FourMomentum summed_four_momentum{summed_four_momentum_vector[0], summed_four_momentum_vector[1], summed_four_momentum_vector[2],
                                    summed_four_momentum_vector[3]};
  
  return summed_four_momentum;
}

FourMomentum FourMomentum::operator-(FourMomentum& other_four_momentum)
{
  std::vector<double> subtracted_four_momentum_vector;
  for(int i = 0; i < 4; i++)
  {
    subtracted_four_momentum_vector.push_back(four_momentum_vector[i] - (other_four_momentum.four_momentum_vector)[i]);
  }
  FourMomentum subtracted_four_momentum{subtracted_four_momentum_vector[0], subtracted_four_momentum_vector[1], 
                                    subtracted_four_momentum_vector[2], subtracted_four_momentum_vector[3]};
  
  return subtracted_four_momentum;
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
    std::cerr<<e.what()<<std::endl;
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