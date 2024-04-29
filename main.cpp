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

int main()
{
  
  Tau tau_1;
  Neutrino neutrino_1;
  Muon muon_1;
  Electron electron_1;
  tau_1.print_data();
  neutrino_1.print_data();
  muon_1.print_data();
  electron_1.print_data();
  
}