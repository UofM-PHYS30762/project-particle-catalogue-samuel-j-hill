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
  Tau tau_2{sqrt(1777),0,0,0,false,false,true,false};
  tau_1.print_data();
  tau_2.print_data();
  //Neutrino neutrino_1{0,0,0,0,true,false,"Electron"};
  //Muon muon_1{0,sqrt(105.7),0,0,true,false,false};
  //neutrino_1.print_data();
  //muon_1.print_data();

}