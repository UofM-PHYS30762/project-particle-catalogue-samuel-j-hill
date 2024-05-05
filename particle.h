#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<cmath>
#include <iomanip>
#include<vector>
#include<memory>
#include "four_momentum.h"

class Particle
{
protected:
  double charge{0}; // Units of elementary charge
  double spin{0};  // Units of hbar
  double rest_mass{0}; // Units of MeV (natural units)
  std::unique_ptr<FourMomentum> four_momentum = std::make_unique<FourMomentum>(0,0,0,0);
  bool antiparticle{false};
  bool print_constructor_destructor{false}; // Constructor and destructor print statements are only called if true
  void check_four_momentum(double particle_rest_mass); // Checks and fixes invariant mass (user cannot set reference rest mass)

public:
  // Default constructor
  Particle() {if(print_constructor_destructor) {std::cout<<"Default particle constructor called"<<std::endl;}}
  // Parameterised constructor
  Particle(double particle_energy, double particle_px, double particle_py, double particle_pz, bool antiparticle_status,
           bool constructor_destructor_status);
  // Destructor
  virtual ~Particle() {if(print_constructor_destructor) {std::cout<<"Particle destructor called"<<std::endl;}}
  // Copy constructor
  Particle(Particle&);
  // Move constructor
  Particle(Particle&&);
  // Copy assignment operator
  Particle& operator=(Particle&);
  // Move assignment operator
  Particle& operator=(Particle&&);

  double get_charge() const {return charge;}
  double get_spin() const {return spin;}
  double get_rest_mass() const {return rest_mass;}
  FourMomentum get_four_momentum() const {return *four_momentum;}
  std::vector<double> get_four_momentum_vector() {return four_momentum->get_four_momentum_vector();}
  bool get_antiparticle_status() const {return antiparticle;}
  bool get_print_constructor_destructor_status() const {return print_constructor_destructor;}
                        
  void set_four_momentum_vector(double particle_energy, double particle_px, double particle_py, double particle_pz);
  void set_print_constructor_destructor_status(bool print_constructor_destructor_status) {print_constructor_destructor = print_constructor_destructor_status;}
  
  virtual void print_data()=0;
};

#endif 