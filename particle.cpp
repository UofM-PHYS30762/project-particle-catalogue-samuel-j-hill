#include <iostream>
#include <format>
#include "particle.h"
#include "four_momentum.h"

// Parameterised constructor
Particle::Particle(double particle_energy, double particle_px, double particle_py,
                   double particle_pz, bool antiparticle_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised particle constructor called"<<std::endl;}
  four_momentum = std::make_unique<FourMomentum>(particle_energy, particle_px, particle_py, particle_pz);
  if(abs((*four_momentum).get_invariant_mass() - rest_mass) > 0.001)
  {
    throw std::invalid_argument("Four momentum invariant mass must be equal to the rest mass. ");
  }
  antiparticle = antiparticle_status;
}

// Copy constructor
Particle::Particle(Particle &part)
{
  if(print_constructor_destructor) {std::cout<<"Copy constructor called"<<std::endl;}
  charge = part.charge;
  spin = part.spin; 
  four_momentum = std::make_unique<FourMomentum>(part.get_four_momentum_vector()[0], part.get_four_momentum_vector()[1], 
                                                 part.get_four_momentum_vector()[2], part.get_four_momentum_vector()[3]);
  antiparticle = part.antiparticle; 
}

// Move constructor
Particle::Particle(Particle &&part)
{
  if(print_constructor_destructor) {std::cout<<"Move constructor called"<<std::endl;}
  charge = part.charge;
  spin = part.spin;
  four_momentum = std::make_unique<FourMomentum>(part.get_four_momentum_vector()[0], part.get_four_momentum_vector()[1], 
                                                 part.get_four_momentum_vector()[2], part.get_four_momentum_vector()[3]); 
  antiparticle = part.antiparticle;

  part.charge = 0;
  part.spin = 0;
  part.four_momentum = std::make_unique<FourMomentum>(0,0,0,0);
  part.antiparticle = false;
}

// Copy assignment operator
Particle& Particle::operator=(Particle &part)
{
  if(print_constructor_destructor) {std::cout<<"Copy assignment operator called"<<std::endl;}
  if(&part == this) return *this;
  charge = part.charge;
  spin = part.spin;
  four_momentum = std::make_unique<FourMomentum>(part.get_four_momentum_vector()[0], part.get_four_momentum_vector()[1], 
                                                 part.get_four_momentum_vector()[2], part.get_four_momentum_vector()[3]); 
  antiparticle = part.antiparticle;
  
  return *this;
}

// Move assignment operator
Particle& Particle::operator=(Particle&& part)
{
  if(print_constructor_destructor) {std::cout<<"Move assignment operator called"<<std::endl;}
  std::swap(charge,part.charge);
  std::swap(spin,part.spin);
  std::swap(four_momentum,part.four_momentum);
  std::swap(antiparticle,part.antiparticle);

  return *this;
}

void Particle::set_four_momentum_vector(double particle_energy, double particle_px, double particle_py, double particle_pz)
{
  four_momentum->set_four_momentum_vector(particle_energy, particle_px, particle_py, particle_pz);
  if(abs((*four_momentum).get_invariant_mass() - rest_mass) < 0.001)
  {
    throw std::invalid_argument("Four momentum invariant mass must be equal to the rest mass. ");
  }
}

void Particle::print_data()
{
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<four_momentum->get_four_momentum_vector()[0]<<","<<four_momentum->get_four_momentum_vector()[1]<<","
  <<four_momentum->get_four_momentum_vector()[2]<<","<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
}

