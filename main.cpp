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
  Gluon gluon_1;
  Quark quark_1;
  Photon photon_1;
  gluon_1.print_data();
  quark_1.print_data();
  photon_1.print_data();  
}