#include<iostream>
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
#include "particle_catalogue.h"

int main()
{  
  std::unique_ptr<Particle> muon_1 = std::make_unique<Muon>(105.7,0,0,0,true,false,false);
  std::unique_ptr<Particle> muon_2 = std::make_unique<Muon>(105.7,0,0,0,false,false,false);
  std::unique_ptr<Particle> quark = std::make_unique<Quark>(2.3,0,0,0,false,false,"Up","Red");
  ParticleCatalogue catalogue;
  catalogue.add_particle(std::move(muon_1));
  catalogue.add_particle(std::move(muon_2));
  catalogue.add_particle(std::move(quark));
  catalogue.print_catalogue();
  ParticleCatalogue subcatalogue = catalogue.get_subcatalogue<Muon>();
  std::cout<<"Print subcatalogue"<<std::endl;
  subcatalogue.print_catalogue();

  return 0;
}