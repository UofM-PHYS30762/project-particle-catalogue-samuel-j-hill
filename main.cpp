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

int main()
{  
  Tau tau_1{1777,0,0,0,false,false,"None"};
  ZBoson z_boson_1{91200,0,0,0,false,"Leptonic","Tau"};
  tau_1.print_data();
  z_boson_1.print_data();
}