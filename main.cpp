#include<iostream>
#include "four_momentum.h"
#include "particle.h"

int main()
{
  Particle test{1, 0.5, 0, 0, 0, 0, false};
  test.print_data();
  return 0;
}