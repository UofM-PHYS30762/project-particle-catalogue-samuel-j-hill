#include<iostream>
#include <memory>
#include "w_boson.h"
#include "electron.h"
#include "muon.h"
#include "neutrino.h"
#include "tau.h"
#include "quark.h"

// Default constructor
WBoson::WBoson()
{
  spin = 1;
  rest_mass = 80400;
  antiparticle ? charge = -1 : charge = 1;
  set_four_momentum_vector(rest_mass,0,0,0);
  if(print_constructor_destructor) {std::cout<<"Default W boson constructor called"<<std::endl;}
}

// Parameterised constructor
WBoson::WBoson(double w_boson_energy, double w_boson_px, double w_boson_py, double w_boson_pz, bool antiparticle,
               bool constructor_destructor_status, std::string decay_type, std::string decay_flavour) : 
               Particle(w_boson_energy, w_boson_px, w_boson_py, w_boson_pz, antiparticle, constructor_destructor_status)
               {
                 if(print_constructor_destructor) {std::cout<<"Parameterised W boson constructor called. "<<std::endl;}
                 spin = 1;
                 rest_mass = 80400;
                 antiparticle ? charge = -1 : charge = 1;
                 check_four_momentum(rest_mass);
                 decay_type = decay_type;
                 decay_flavour = decay_flavour;

                 if(decay_type == "Hadronic")
                 {
                   if(decay_flavour.substr(0,2) == "Up")
                   {
                     std::string other_flavour = decay_flavour.substr(3, decay_flavour.size()-3);
                     if(other_flavour == "Down" || other_flavour == "Strange" || other_flavour == "Bottom")
                     {
                       std::shared_ptr<Particle> up_quark = std::make_unique<Quark>(2.3, 0, 0, 0, antiparticle, 
                                                                                    constructor_destructor_status, "Up",
                                                                                    (antiparticle ? "Antired" : "Red"));
                       std::shared_ptr<Particle> other_quark = std::make_unique<Quark>(Quark::quark_masses[other_flavour], 0, 0, 0,
                                                                                       !antiparticle, constructor_destructor_status,
                                                                                       other_flavour, (antiparticle ? "Red" : "Antired"));   
                       decay_products.push_back(up_quark);
                       decay_products.push_back(other_quark);
                     }
                     else
                     {
                       std::cout<<"Second decay flavour not recognised. "<<std::endl;
                       decay_flavour = "Unrecognised";
                     }
                   }
                   else if(decay_flavour.substr(0,5) == "Charm")
                   {
                     std::string other_flavour = decay_flavour.substr(6, decay_flavour.size()-6);
                     if(other_flavour == "Down" || other_flavour == "Strange" || other_flavour == "Bottom")
                     {
                       std::shared_ptr<Particle> charm_quark = std::make_unique<Quark>(1275, 0, 0, 0, antiparticle, 
                                                                                       constructor_destructor_status, "Charm", 
                                                                                       (antiparticle ? "Antired" : "Red"));
                       std::shared_ptr<Particle> other_quark = std::make_unique<Quark>(Quark::quark_masses[other_flavour], 0, 0, 0,
                                                                                       !antiparticle, constructor_destructor_status,
                                                                                       other_flavour, (antiparticle ? "Red" : "Antired"));   
                       decay_products.push_back(charm_quark);
                       decay_products.push_back(other_quark);
                     }
                     else
                     {
                       std::cout<<"Second decay flavour not recognised. "<<std::endl;
                       decay_flavour = "Unrecognised";
                     }
                   }
                   else if(decay_flavour != "None")
                   {
                     std::cout<<"Decay flavour not valid: must be either Up Down, Up Strange, Up Bottom, Charm Down, Charm Strange, Charm Bottom or None. "<<std::endl;
                     decay_type = "Unrecognised";
                   }
                 }

                 else if(decay_type == "Leptonic")
                 {
                   std::shared_ptr<Particle> neutrino = std::make_unique<Neutrino>(1, 1, 0, 0, antiparticle, 
                                                                                     constructor_destructor_status, decay_flavour);
                   decay_products.push_back(neutrino);
                   if(decay_flavour == "None") {decay_products.pop_back();}
                   if(decay_flavour == "Electron")
                   {
                     std::vector<double> energies_deposited{0.511,0,0,0};
                     std::shared_ptr<Particle> electron = std::make_unique<Electron>(0.511, 0, 0, 0, !antiparticle, 
                                                                                     constructor_destructor_status, energies_deposited);
                     decay_products.push_back(electron);                                                                                     
                   }
                   else if(decay_flavour == "Muon")
                   {
                     std::shared_ptr<Particle> muon = std::make_unique<Muon>(105.7, 0, 0, 0, !antiparticle,
                                                                             constructor_destructor_status, false);
                     decay_products.push_back(muon);                                                                                     
                   } 
                   else if(decay_flavour == "Tau")
                   {
                     std::shared_ptr<Particle> tau = std::make_unique<Tau>(1777, 0, 0, 0, !antiparticle, constructor_destructor_status,
                                                                           "None");
                     decay_products.push_back(tau);                                                                                     
                   } 
                   else
                   {
                     decay_type = "Unrecognised";
                     decay_products.pop_back();
                   }                                    
                 }
                 else if(decay_type != "None")
                 {
                   std::cout<<"Decay type not recognised"<<std::endl;
                   decay_type = "Unrecognised";
                 }
               }

// Overwritten move constructor
WBoson::WBoson(WBoson&& w) : Particle(w)
{
  decay_type = w.decay_type;
  decay_flavour = w.decay_flavour;
  decay_products = w.decay_products;
  w.decay_type = "None";
  w.decay_flavour = "None";
  w.decay_products = std::vector<std::shared_ptr<Particle>>{nullptr};
}

// Overwritten copy assignment operator
WBoson& WBoson::operator=(WBoson& w) 
{
  if(&w != this)
  {
    Particle::operator=(w);
  }
  decay_type = w.decay_type;
  decay_flavour = w.decay_flavour;
  decay_products = w.decay_products;
  
  return *this;
}

// Overwritten move assignment operator
WBoson& WBoson::operator=(WBoson&& w)
{
  Particle::operator=(std::move(w));
  std::swap(decay_type, w.decay_type);
  std::swap(decay_flavour, w.decay_flavour);
  std::swap(decay_products, w.decay_products);

  return *this;
}

void WBoson::print_data()
{
  std::cout<<"Particle type: "<<(antiparticle ? "W- boson" : "W+ boson")<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
  if(decay_products.size()>0)
  {
    std::cout<<"\nPrinting data of W boson decay products\n"<<std::endl;
    for(auto i=decay_products.begin(); i<decay_products.end(); i++)
    {
      (*i)->print_data();
      std::cout<<"\n"<<std::endl;
    }
  }
}