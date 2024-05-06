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


FourMomentum ParticleCatalogue::get_total_four_momentum()
{
  FourMomentum total_four_momentum{0,0,0,0};
  for(auto i = catalogue.begin(); i != catalogue.end(); i++)
  {
    total_four_momentum = (*i)->get_four_momentum() + total_four_momentum;
  }

  return total_four_momentum;
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
  std::cout<<"Summarising number of particles of each type: \n"<<std::endl;
  std::cout<<get_number_of_entries_of_type<Electron>()<<" Electron(s)\n"<<get_number_of_entries_of_type<Muon>()<<" Muon(s)\n"<<
  get_number_of_entries_of_type<Tau>()<<" Tau(s)\n"<<get_number_of_entries_of_type<Neutrino>()<<" Neutrino(s)\n"<<
  get_number_of_entries_of_type<Quark>()<<" Quark(s)\n"<<get_number_of_entries_of_type<Photon>()<<" Photon(s)\n"<<
  get_number_of_entries_of_type<Gluon>()<<" Gluon(s)\n"<<get_number_of_entries_of_type<WBoson>()<<" W boson(s)\n"<<
  get_number_of_entries_of_type<ZBoson>()<<" Z boson(s)\n"<<get_number_of_entries_of_type<HiggsBoson>()<<" Higgs boson(s)\n"<<std::endl;
}