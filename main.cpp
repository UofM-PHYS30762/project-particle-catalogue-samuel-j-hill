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
  ZBoson test{91200,0,0,0,false,"Leptonic","Electron neutrino"};
  test.print_data();
}