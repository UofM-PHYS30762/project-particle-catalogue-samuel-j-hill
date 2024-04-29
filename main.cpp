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
  Tau tau_1{1777,0,0,0,true,false,"Kaon"};
  tau_1.print_data();  
}