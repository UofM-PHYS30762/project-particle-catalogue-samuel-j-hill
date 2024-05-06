#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include <iostream>
#include <cmath>
#include <vector>

class FourMomentum
{
private:
  std::vector<double> four_momentum_vector{0,0,0,0};

public:
  // Default constructor
  FourMomentum() {};
  // Parameterised constructor
  FourMomentum(double energy, double p_x, double p_y, double p_z) {set_four_momentum_vector(energy, p_x, p_y, p_z);}
  // Destructor 
  ~FourMomentum() {};
    // Copy constructor
  FourMomentum(FourMomentum& other_four_momentum) {four_momentum_vector = other_four_momentum.four_momentum_vector;}
  // Move constructor
  FourMomentum(FourMomentum&&);
  // Copy assignment operator
  FourMomentum& operator=(FourMomentum&);
  // Move assignment operator
  FourMomentum& operator=(FourMomentum&& other_four_momentum) {std::swap(four_momentum_vector, other_four_momentum.four_momentum_vector);
                                                               return *this;}
  FourMomentum operator+(FourMomentum& other_four_momentum);
  FourMomentum operator-(FourMomentum& other_four_momentum);
  friend double dot_product(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2);

  std::vector<double> get_four_momentum_vector() {return four_momentum_vector;}
  double get_invariant_mass();
  void set_four_momentum_vector(double energy, double p_x, double p_y, double p_z);
};



#endif