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

std::vector<double> ParticleCatalogue::get_total_four_momentum()
{
  FourMomentum total_four_momentum{0,0,0,0};
  std::vector<double> total_four_momentum_vector{0,0,0,0};
  for(auto i = catalogue.begin(); i != catalogue.end(); i++)
  {
    Particle iterator_particle{*(*i)};
    total_four_momentum_vector = iterator_particle.get_four_momentum() + total_four_momentum;
    total_four_momentum.set_four_momentum_vector(total_four_momentum_vector[0], total_four_momentum_vector[1],
                                                 total_four_momentum_vector[2], total_four_momentum_vector[3]);
  }

  return total_four_momentum_vector;
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