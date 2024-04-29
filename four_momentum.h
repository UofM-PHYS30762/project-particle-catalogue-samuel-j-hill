#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include <iostream>
#include <cmath>
#include <vector>

class FourMomentum
{
private:
  std::vector<double> four_momentum_vector{0,0,0,0};
  bool print_constructor_destructor{false};

public:
  // Default constructor
  FourMomentum() {if(print_constructor_destructor) {std::cout<<"Default four momentum constructor called"<<std::endl;}}
  // Parameterised constructor
  FourMomentum(double energy, double p_x, double p_y, double p_z);
  // Destructor 
  ~FourMomentum() {if(print_constructor_destructor) {std::cout<<"Four momentum destructor called"<<std::endl;}}

  std::vector<double> get_four_momentum_vector() {return four_momentum_vector;}
  double get_invariant_mass() {return sqrt(std::pow(four_momentum_vector[0],2) - std::pow(four_momentum_vector[1],2)
                                            - std::pow(four_momentum_vector[2],2) - std::pow(four_momentum_vector[3],2));}
  bool get_print_constructor_destructor_status() const {return print_constructor_destructor;}
  
  void set_four_momentum_vector(double energy, double p_x, double p_y, double p_z);
  void set_print_constructor_destructor_status(bool print_constructor_destructor_status) {print_constructor_destructor = print_constructor_destructor_status;}
};

#endif