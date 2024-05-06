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
  std::cout<<get_number_of_entries_of_type<Electron>(false)<<" Electron(s)\n"
  <<get_number_of_entries_of_type<Electron>(true)<<" Antielectron(s)\n"
  <<get_number_of_entries_of_type<Muon>(false)<<" Muon(s)\n"
  <<get_number_of_entries_of_type<Muon>(true)<<" Antimuon(s)\n"
  <<get_number_of_entries_of_type<Tau>(false)<<" Tau(s)\n"
  <<get_number_of_entries_of_type<Tau>(true)<<" Antitau(s)\n"
  <<get_number_of_entries_of_type<Neutrino>(false)<<" Neutrino(s)\n"
  <<get_number_of_entries_of_type<Neutrino>(true)<<" Antineutrino(s)\n"
  <<get_number_of_entries_of_type<Quark>(false)<<" Quark(s)\n"
  <<get_number_of_entries_of_type<Quark>(true)<<" Antiquark(s)\n"
  <<get_number_of_entries_of_type<Photon>(false)<<" Photon(s)\n"
  <<get_number_of_entries_of_type<Gluon>(false)<<" Gluon(s)\n"
  <<get_number_of_entries_of_type<Gluon>(true)<<" Antigluon(s)\n"
  <<get_number_of_entries_of_type<WBoson>(false)<<" W+ boson(s)\n"
  <<get_number_of_entries_of_type<WBoson>(true)<<" W- boson(s)\n"
  <<get_number_of_entries_of_type<ZBoson>(false)<<" Z boson(s)\n"
  <<get_number_of_entries_of_type<HiggsBoson>(false)<<" Higgs boson(s)\n"<<std::endl;
  
  std::cout<<"Total four momentum of the particles in the catalogue = ["<<std::setprecision(3)
  <<(get_total_four_momentum()).get_four_momentum_vector()[0]<<","<<std::setprecision(3)
  <<(get_total_four_momentum()).get_four_momentum_vector()[1]<<","<<std::setprecision(3)
  <<(get_total_four_momentum()).get_four_momentum_vector()[2]<<","<<std::setprecision(3)
  <<(get_total_four_momentum()).get_four_momentum_vector()[3]<<"]"<<std::endl;
}