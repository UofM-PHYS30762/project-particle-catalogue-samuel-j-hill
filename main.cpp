#include<iostream>
#include "four_momentum.h"
#include "particle.h"
#include "lepton.h"
#include "muon.h"
#include "neutrino.h"
#include "quark.h"

int main()
{
  /*
  Neutrino neutrino_1{0,0,0,0,true,false,"Electron"};
  Muon muon_1{0,sqrt(105.7),0,0,false,false,false};
  neutrino_1.print_data();
  muon_1.print_data();
  */
  Quark quark_1(sqrt(2.3),0,0,0,false,false,"Down","Red");
}