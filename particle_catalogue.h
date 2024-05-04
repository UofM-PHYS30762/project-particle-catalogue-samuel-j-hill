#ifndef PARTICLE_CATALOGUE_H
#define PARTICLE_CATALOGUE_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include "four_momentum.h"
#include "particle.h"
#include "lepton.h"
#include "electron.h"
#include "muon.h"
#include "tau.h"
#include "neutrino.h"
#include "quark.h"
#include "photon.h"
#include "gluon.h"
#include "z_boson.h"
#include "w_boson.h"
#include "higgs_boson.h"

class ParticleCatalogue
{
private:
  typedef std::unordered_set<std::shared_ptr<Particle>> particle_catalogue;
  particle_catalogue catalogue;

public: 
  ParticleCatalogue() {std::cout<<"Particle catalogue default constructor called"<<std::endl;}
  ParticleCatalogue(std::vector<std::shared_ptr<Particle>>& particle_pointers_vector);
  ~ParticleCatalogue() {std::cout<<"Particle catalogue destructor called"<<std::endl;}

  particle_catalogue get_particle_catalogue() {return catalogue;}
  template <class c_type> ParticleCatalogue get_subcatalogue();
  int get_number_of_entries() {return catalogue.size();}
  template <class c_type> int get_number_of_entries_of_type();
  //std::vector<double> get_total_four_momentum();
  void add_particle(std::shared_ptr<Particle> particle) {catalogue.insert(std::move(particle));}
  void print_catalogue();
};

template <class c_type> int ParticleCatalogue::get_number_of_entries_of_type()
{
  int counter = 0;
  for(auto i = catalogue.begin(); i != catalogue.end(); i++)
  {
    std::shared_ptr<c_type> derived_ptr = std::dynamic_pointer_cast<c_type>(*i);
    if(derived_ptr != nullptr)
    {
      counter += 1;
    }
  }

  return counter;
}

template <class c_type> ParticleCatalogue ParticleCatalogue::get_subcatalogue()
{
  ParticleCatalogue subcatalogue;
  for(auto i = catalogue.begin(); i != catalogue.end(); i++)
  {
    std::shared_ptr<c_type> derived_ptr = std::dynamic_pointer_cast<c_type>(*i);
    if(derived_ptr != nullptr)
    {
      subcatalogue.add_particle(*i);
    }
  }

  return subcatalogue; 
}

#endif