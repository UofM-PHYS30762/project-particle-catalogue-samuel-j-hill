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
  ParticleCatalogue catalogue_1;
  catalogue_1.add_particle(std::move(muon_1));
  catalogue_1.add_particle(std::move(muon_2));
  catalogue_1.add_particle(std::move(quark));
  catalogue_1.print_catalogue();
  FourMomentum total = catalogue_1.get_total_four_momentum();
  std::cout<<total.get_four_momentum_vector()[1];

  return 0;
}