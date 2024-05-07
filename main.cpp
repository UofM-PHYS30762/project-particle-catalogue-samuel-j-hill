// PHYS 30762 Programming in C++
// Samuel Hill, Final project, 07/05/2024
// Creates a catalogue containing one of each particle in the standard model

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

  std::vector<double> deposited_energies{0.511, 0, 0, 0};
  std::unique_ptr<Particle> electron = std::make_unique<Electron>(0.511, 0, 0, 0, false, false, deposited_energies);
  catalogue.add_particle(std::move(electron));
  std::unique_ptr<Particle> antielectron = std::make_unique<Electron>(0.511, 0, 0, 0, true, false, deposited_energies);
  catalogue.add_particle(std::move(antielectron));
  std::unique_ptr<Particle> gluon = std::make_unique<Gluon>(1, 1, 0, 0, false, false, "Blue", "Antired");
  catalogue.add_particle(std::move(gluon));
  std::unique_ptr<Particle> antigluon = std::make_unique<Gluon>(1, 1, 0, 0, true, false, "Antigreen", "Blue");
  catalogue.add_particle(std::move(antigluon));
  std::unique_ptr<Particle> higgs = std::make_unique<HiggsBoson>(126000, 0, 0, 0, false, "W boson");
  catalogue.add_particle(std::move(higgs));
  std::unique_ptr<Particle> muon = std::make_unique<Muon>(105.7, 0, 0, 0, false, false, false);
  catalogue.add_particle(std::move(muon));
  std::unique_ptr<Particle> antimuon = std::make_unique<Muon>(105.7, 0, 0, 0, true, false, false);
  catalogue.add_particle(std::move(antimuon));
  std::unique_ptr<Particle> electron_neutrino = std::make_unique<Neutrino>(1, 1, 0, 0, false, false, "Electron");
  catalogue.add_particle(std::move(electron_neutrino));
  std::unique_ptr<Particle> electron_antineutrino = std::make_unique<Neutrino>(1, 1, 0, 0, true, false, "Electron");
  catalogue.add_particle(std::move(electron_antineutrino));
  std::unique_ptr<Particle> muon_neutrino = std::make_unique<Neutrino>(1, 1, 0, 0, false, false, "Muon");
  catalogue.add_particle(std::move(muon_neutrino));
  std::unique_ptr<Particle> muon_antineutrino = std::make_unique<Neutrino>(1, 1, 0, 0, true, false, "Muon");
  catalogue.add_particle(std::move(muon_antineutrino));
  std::unique_ptr<Particle> tau_neutrino = std::make_unique<Neutrino>(1, 1, 0, 0, false, false, "Tau");
  catalogue.add_particle(std::move(tau_neutrino));
  std::unique_ptr<Particle> tau_antineutrino = std::make_unique<Neutrino>(1, 1, 0, 0, true, false, "Tau");
  catalogue.add_particle(std::move(tau_antineutrino));
  std::unique_ptr<Particle> photon = std::make_unique<Photon>(1, 1, 0, 0, false);
  catalogue.add_particle(std::move(photon));
  std::unique_ptr<Particle> up_quark = std::make_unique<Quark>(2.3, 0, 0, 0, false, false, "Up", "Red");
  catalogue.add_particle(std::move(up_quark));
  std::unique_ptr<Particle> up_antiquark = std::make_unique<Quark>(2.3, 0, 0, 0, true, false, "Up", "Antired");
  catalogue.add_particle(std::move(up_antiquark));
  std::unique_ptr<Particle> down_quark = std::make_unique<Quark>(4.8, 0, 0, 0, false, false, "Down", "Red");
  catalogue.add_particle(std::move(down_quark));
  std::unique_ptr<Particle> down_antiquark = std::make_unique<Quark>(4.8, 0, 0, 0, true, false, "Down", "Antired");
  catalogue.add_particle(std::move(down_antiquark));
  std::unique_ptr<Particle> charm_quark = std::make_unique<Quark>(1275, 0, 0, 0, false, false, "Charm", "Blue");
  catalogue.add_particle(std::move(charm_quark));
  std::unique_ptr<Particle> charm_antiquark = std::make_unique<Quark>(1275, 0, 0, 0, true, false, "Charm", "Antiblue");
  catalogue.add_particle(std::move(charm_antiquark));
  std::unique_ptr<Particle> strange_quark = std::make_unique<Quark>(95, 0, 0, 0, false, false, "Strange", "Blue");
  catalogue.add_particle(std::move(strange_quark));
  std::unique_ptr<Particle> strange_antiquark = std::make_unique<Quark>(95, 0, 0, 0, true, false, "Strange", "Antiblue");
  catalogue.add_particle(std::move(strange_antiquark));
  std::unique_ptr<Particle> top_quark = std::make_unique<Quark>(173070, 0, 0, 0, false, false, "Top", "Green");
  catalogue.add_particle(std::move(top_quark));
  std::unique_ptr<Particle> top_antiquark = std::make_unique<Quark>(173070, 0, 0, 0, true, false, "Top", "Antigreen");
  catalogue.add_particle(std::move(top_antiquark));
  std::unique_ptr<Particle> bottom_quark = std::make_unique<Quark>(4180, 0, 0, 0, false, false, "Bottom", "Green");
  catalogue.add_particle(std::move(bottom_quark));
  std::unique_ptr<Particle> bottom_antiquark = std::make_unique<Quark>(4180, 0, 0, 0, true, false, "Bottom", "Antigreen");
  catalogue.add_particle(std::move(bottom_antiquark));
  std::unique_ptr<Particle> tau = std::make_unique<Tau>(1777, 0, 0, 0, false, false, "Electron");
  catalogue.add_particle(std::move(tau));
  std::unique_ptr<Particle> antitau = std::make_unique<Tau>(1777, 0, 0, 0, true, false, "Electron");
  catalogue.add_particle(std::move(antitau));
  std::unique_ptr<Particle> w_plus_boson = std::make_unique<WBoson>(80400, 0, 0, 0, false, false, "Leptonic", "Muon");
  catalogue.add_particle(std::move(w_plus_boson));
  std::unique_ptr<Particle> w_minus_boson = std::make_unique<WBoson>(80400, 0, 0, 0, true, false, "Leptonic", "Muon");
  catalogue.add_particle(std::move(w_minus_boson));
  std::unique_ptr<Particle> z_boson = std::make_unique<ZBoson>(-100, 0, 0, 0, false, "Hadronic", "Top"); // Invalid inputs
  catalogue.add_particle(std::move(z_boson));

  catalogue.print_catalogue();

  return 0;
}