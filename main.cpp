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
  HiggsBoson higgs_boson_1{126000, 0, 0, 0, false, "None"};
  higgs_boson_1.print_data();

  return 0;
}