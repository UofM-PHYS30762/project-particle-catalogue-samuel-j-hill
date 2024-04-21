#include<iostream>
#include "four_momentum.h"
#include "particle.h"
#include "lepton.h"

int main()
{
  Lepton lepton_1{0,0,0,0,false};
  lepton_1.print_data();
  Lepton lepton_2 = lepton_1;
  lepton_1.print_data();
  lepton_2.print_data();

  return 0;
}