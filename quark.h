#ifndef QUARK_H
#define QUARK_H

#include<iostream>
#include<string>
#include<map>
#include "particle.h"

class Quark: public Particle
{
protected:
  double baryon_number{1/3};
  std::string colour_charge{"None"};
  std::string flavour{"None"};
  std::map<std::string,double> quark_masses = {{"Up", 2.3}, {"Down", 4.8}, {"Charm", 1275},{"Strange", 95},{"Top", 173070},
                                               {"Bottom", 4180}};
  std::map<std::string,double> quark_charges = {{"Up", 2/3}, {"Down", -1/3}, {"Charm", 2/3},{"Strange", -1/3},{"Top", 2/3},
                                                {"Bottom", -1/3}};
                                                    
public: 
  // Default constructor
  Quark() {if(print_constructor_destructor) {std::cout<<"Default quark constructor called"<<std::endl;}};
  // Parameterised constructor
  Quark(double quark_energy, double quark_px, double quark_py, double quark_pz, bool antiparticle, bool constructor_destructor_status,
        std::string quark_flavour, std::string quark_colour_charge);
  // Destructor
  virtual ~Quark() {if(print_constructor_destructor) {std::cout<<"Quark destructor called"<<std::endl;}}

  double get_quark_number() {return baryon_number;}
  std::string get_colour_charge() {return colour_charge;}
  std::string get_flavour() {return flavour;}
  //void print_data();
};

#endif