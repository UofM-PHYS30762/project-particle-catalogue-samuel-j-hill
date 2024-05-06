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
  ParticleCatalogue catalogue;

  std::unique_ptr<Particle> electron = std::make_unique<Electron>();
  catalogue.add_particle(std::move(electron));
  std::unique_ptr<Particle> gluon = std::make_unique<Gluon>();
  catalogue.add_particle(std::move(gluon));
  std::unique_ptr<Particle> higgs = std::make_unique<HiggsBoson>();
  catalogue.add_particle(std::move(higgs));
  std::unique_ptr<Particle> muon = std::make_unique<Muon>();
  catalogue.add_particle(std::move(muon));
  std::unique_ptr<Particle> neutrino = std::make_unique<Neutrino>();
  catalogue.add_particle(std::move(neutrino));
  std::unique_ptr<Particle> photon = std::make_unique<Photon>();
  catalogue.add_particle(std::move(photon));
  std::unique_ptr<Particle> quark = std::make_unique<Quark>();
  catalogue.add_particle(std::move(quark));
  std::unique_ptr<Particle> tau = std::make_unique<Tau>();
  catalogue.add_particle(std::move(tau));
  std::unique_ptr<Particle> w_boson = std::make_unique<WBoson>();
  catalogue.add_particle(std::move(w_boson));
  std::unique_ptr<Particle> z_boson = std::make_unique<ZBoson>();
  catalogue.add_particle(std::move(z_boson));

  catalogue.print_catalogue();

  return 0;
}