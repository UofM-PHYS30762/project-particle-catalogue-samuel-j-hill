#include "particle_catalogue.h"

// Parameterised constructor
ParticleCatalogue::ParticleCatalogue(std::vector<std::shared_ptr<Particle>>& particle_pointers_vector)
{
  std::cout<<"Particle catalogue parameterised constructor called"<<std::endl;
  for(int i = 0; i < particle_pointers_vector.size(); i++)
  {
    catalogue.insert(std::move(particle_pointers_vector[i]));
  }
}

void ParticleCatalogue::print_catalogue()
{
  std::cout<<"Printing data of all "<<catalogue.size()<<" particles in the catalogue.\n"<<std::endl;
  for(auto i = catalogue.begin(); i != catalogue.end(); i++)
  {
    (*i)->print_data();
    std::cout<<"-------------------------------------"<<std::endl;
  }
  std::cout<<"\nPrinting of all particles in catalogue complete."<<std::endl;
}