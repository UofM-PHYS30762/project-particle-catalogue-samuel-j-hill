#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include <iostream>
#include <cmath>
#include <vector>

class FourMomentum
{
private:
  std::vector<double> four_momentum_vector{0,0,0,0};
  //bool print_constructor_destructor{false};

public:
  // Default constructor
  FourMomentum() {};
  // Parameterised constructor
  FourMomentum(double energy, double p_x, double p_y, double p_z);
  // Destructor 
  ~FourMomentum() {};
  friend std::vector<double> sum(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2);
  friend std::vector<double> difference(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2);
  friend double dot_product(FourMomentum& four_momentum_1, FourMomentum& four_momentum_2);

  std::vector<double> get_four_momentum_vector() {return four_momentum_vector;}
  double get_invariant_mass();
  //bool get_print_constructor_destructor_status() const {return print_constructor_destructor;}
  
  void set_four_momentum_vector(double energy, double p_x, double p_y, double p_z);
  //void set_print_constructor_destructor_status(bool print_constructor_destructor_status) {print_constructor_destructor = print_constructor_destructor_status;}
};



#endif