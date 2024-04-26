#ifndef ELECTRON_H
#define ELECTRON_H

#include <iostream>
#include "lepton.h"
#include <vector>

class Electron: public Lepton
{
private:
  std::vector<double> calorimeter_deposited_energies{0,0,0,0};

public:
  // Default constructor
  Electron() {if(print_constructor_destructor) {std::cout<<"Default electron constructor called"<<std::endl;}}
  // Parameterised constructor
  Electron(double electron_energy, double electron_px, double electron_py, double electron_pz, bool antiparticle, 
           bool constructor_destructor_status, std::vector<double> deposited_energies);
  // Destructor 
  ~Electron() {if(print_constructor_destructor) {std::cout<<"Electron destructor called"<<std::endl;}}
  // Overwritten copy constructor
  Electron(Electron& elec) : Lepton(elec), calorimeter_deposited_energies(elec.calorimeter_deposited_energies) {};
  // Overwritten move constructor
  Electron(Electron&&);
  // Overwritten copy assignment operator
  Electron& operator=(Electron&);
  // Overwritten move assignment operator
  Electron& operator=(Electron&&);

  std::vector<double> get_calorimeter_deposited_energies() const {return calorimeter_deposited_energies;}
  void set_calorimeter_deposited_energies(std::vector<double> deposited_energies);
  void print_data();
};

#endif