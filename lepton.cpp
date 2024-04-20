#include <iostream>
#include "lepton.h"

// Parameterised constructor
Lepton::Lepton(int lepton_charge, double lepton_energy, double lepton_px,
         double lepton_py, double lepton_pz, bool antiparticle_status) 
{
  std::cout<<"Parameterised Lepton constructor called"<<std::endl;
  charge = lepton_charge;
  energy = lepton_energy;
  four_momentum = std::make_unique<FourMomentum>(lepton_energy, lepton_px, lepton_py, lepton_pz);
  antiparticle = antiparticle_status;
};

// Copy constructor
Lepton::Lepton(Lepton &lept)
{
  std::cout<<"Copy constructor called"<<std::endl;
  charge = lept.charge;
  energy = lept.energy; 
  four_momentum = std::make_unique<FourMomentum>(lept.get_four_momentum_vector()[0], lept.get_four_momentum_vector()[1], 
                                                 lept.get_four_momentum_vector()[2], lept.get_four_momentum_vector()[3]);
  antiparticle = lept.antiparticle; 
}

// Move constructor
Lepton::Lepton(Lepton &&lept)
{
  std::cout<<"Move constructor called"<<std::endl;
  charge = lept.charge;
  energy = lept.energy;
  four_momentum = std::make_unique<FourMomentum>(lept.get_four_momentum_vector()[0], lept.get_four_momentum_vector()[1], 
                                                 lept.get_four_momentum_vector()[2], lept.get_four_momentum_vector()[3]); 
  antiparticle = lept.antiparticle;

  lept.charge = 0;
  lept.energy = 0;
  lept.four_momentum = std::make_unique<FourMomentum>(0,0,0,0);
  lept.antiparticle = false;
}

// Copy assignment operator
Lepton& Lepton::operator=(Lepton &lept)
{
  std::cout<<"Copy assignment operator called"<<std::endl;
  if(&lept == this) return *this;
  charge = lept.charge;
  energy = lept.energy;
  four_momentum = std::make_unique<FourMomentum>(lept.get_four_momentum_vector()[0], lept.get_four_momentum_vector()[1], 
                                                 lept.get_four_momentum_vector()[2], lept.get_four_momentum_vector()[3]); 
  antiparticle = lept.antiparticle;
  
  return *this;
}

// Move assignment operator
Lepton& Lepton::operator=(Lepton&& lept)
{
  std::cout<<"Move assignment operator called"<<std::endl;
  std::swap(charge,lept.charge);
  std::swap(energy,lept.energy);
  std::swap(four_momentum,lept.four_momentum);
  std::swap(antiparticle,lept.antiparticle);

  return *this;
}

void Lepton::set_energy(const double lepton_energy)
{
  if(energy < 0)
  {
    throw std::invalid_argument("Energy must be positive. ");
  }
  energy = lepton_energy;
}

void Lepton::set_four_momentum_vector(double lepton_energy, double lepton_px, double lepton_py, double lepton_pz)
{
  four_momentum->set_four_momentum_vector(lepton_energy, lepton_px, lepton_py, lepton_pz);
}

void Lepton::print_data()
{  
   std::cout<<"Charge = "<<charge<<std::endl;
   std::cout<<"Energy = "<<energy<<std::endl;
   std::cout<<"P_x = "<<four_momentum->get_four_momentum_vector()[1]<<std::endl;
   std::cout<<"P_y = "<<four_momentum->get_four_momentum_vector()[2]<<std::endl;
   std::cout<<"P_z = "<<four_momentum->get_four_momentum_vector()[3]<<std::endl;
}

std::vector<double> sum(Lepton& lepton_1, Lepton& lepton_2)
{
  std::vector<double> summed_four_momentum;
  std::vector<double> lepton_1_four_momentum = lepton_1.get_four_momentum_vector();
  std::vector<double> lepton_2_four_momentum = lepton_2.get_four_momentum_vector();
  summed_four_momentum.push_back(lepton_1_four_momentum[0]+lepton_2_four_momentum[0]);
  summed_four_momentum.push_back(lepton_1_four_momentum[1]+lepton_2_four_momentum[1]);
  summed_four_momentum.push_back(lepton_1_four_momentum[2]+lepton_2_four_momentum[2]);
  summed_four_momentum.push_back(lepton_1_four_momentum[3]+lepton_2_four_momentum[3]);
  
  return summed_four_momentum;
}

double dot_product(Lepton& lepton_1, Lepton& lepton_2)
{
  std::vector<double> lepton_1_four_momentum = lepton_1.get_four_momentum_vector();
  std::vector<double> lepton_2_four_momentum = lepton_2.get_four_momentum_vector(); 
  double dot_product = lepton_1_four_momentum[0]*lepton_2_four_momentum[0] - lepton_1_four_momentum[1]*lepton_2_four_momentum[1]
                       - lepton_1_four_momentum[2]*lepton_2_four_momentum[2] - lepton_1_four_momentum[3]*lepton_2_four_momentum[3];

  return dot_product;
}