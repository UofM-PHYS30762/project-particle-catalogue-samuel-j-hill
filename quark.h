#ifndef QUARK_H
#define QUARK_H

#include<iostream>
#include<string>
#include<map>
#include "particle.h"

class Quark: public Particle
{
  friend class ZBoson;
protected:
  double baryon_number{0.333};
  std::string colour_charge{"Default"};
  std::string flavour{"Default"};
  static std::map<std::string,double> quark_masses;
  static std::map<std::string,double> quark_charges;
                                                    
public: 
  // Default constructor
  Quark();
  // Parameterised constructor
  Quark(double quark_energy, double quark_px, double quark_py, double quark_pz, bool antiparticle_status,
        bool constructor_destructor_status, std::string quark_flavour, std::string quark_colour_charge);
  // Destructor
  virtual ~Quark() {if(print_constructor_destructor) {std::cout<<"Quark destructor called"<<std::endl;}}
  // Overwritten copy constructor
  Quark(Quark& qu) : Particle(qu), baryon_number(qu.baryon_number), colour_charge(qu.colour_charge), flavour(qu.flavour) {};
  // Overwritten move constructor
  Quark(Quark&&);
  // Overwritten copy assignment operator
  Quark& operator=(Quark&);
  // Overwritten move assignment operator
  Quark& operator=(Quark&&);

  double get_quark_number() {return baryon_number;}
  std::string get_colour_charge() {return colour_charge;}
  std::string get_flavour() {return flavour;}
  void print_data();
};

#endif