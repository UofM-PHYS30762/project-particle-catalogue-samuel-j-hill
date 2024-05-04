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
  
  std::vector<double> energies{0.511/2,0.511/2,0,0};
  std::vector<double> energies_2{0.511/2,0.511/2,9,0};
  Electron electron_1{0.511,0,0,0,false,false,energies};
  electron_1.set_calorimeter_deposited_energies(energies_2);
  std::cout<<electron_1.get_calorimeter_deposited_energies()[2];

  return 0;
}