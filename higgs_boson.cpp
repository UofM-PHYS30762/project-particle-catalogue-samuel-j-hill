#include<iostream>
#include <memory>
#include "w_boson.h"
#include "z_boson.h"
#include "photon.h"
#include "quark.h"
#include "higgs_boson.h"

// Parameterised constructor
HiggsBoson::HiggsBoson(double higgs_boson_energy, double higgs_boson_px, double higgs_boson_py, double higgs_boson_pz,
                       bool constructor_destructor_status, std::string decay_type) : Particle(higgs_boson_energy, higgs_boson_px,
                       higgs_boson_py, higgs_boson_pz, false, constructor_destructor_status)
{
  if(print_constructor_destructor) {std::cout<<"Parameterised Higgs boson constructor called. "<<std::endl;}
  rest_mass = 126000;
  Particle::check_four_momentum(rest_mass);
  decay_type = decay_type;

  if(decay_type == "Z boson")
  {
    std::shared_ptr<Particle> z_boson = std::make_unique<ZBoson>(91200, 0, 0, 0, constructor_destructor_status, "None", "None");
    decay_products.push_back(z_boson);
    decay_products.push_back(z_boson);
  }
  else if(decay_type == "W boson")
  {
    std::shared_ptr<Particle> w_plus = std::make_unique<WBoson>(80400, 0, 0, 0, false, constructor_destructor_status, "None", "None");
    std::shared_ptr<Particle> w_minus = std::make_unique<WBoson>(80400, 0, 0, 0, true, constructor_destructor_status, "None", "None");
    decay_products.push_back(w_plus);
    decay_products.push_back(w_minus);
  }
  else if(decay_type == "Photon")
  {
    std::shared_ptr<Particle> photon = std::make_unique<Photon>(1, 1, 0, 0, constructor_destructor_status);
    decay_products.push_back(photon);
    decay_products.push_back(photon);
  }
  else if(decay_type == "Bottom quark")
  {
    std::shared_ptr<Particle> bottom = std::make_unique<Quark>(4180, 0, 0, 0, false, constructor_destructor_status, "Bottom", "Red");
    std::shared_ptr<Particle> antibottom = std::make_unique<Quark>(4180, 0, 0, 0, true, constructor_destructor_status, "Bottom",
                                                                   "Antired");
    decay_products.push_back(bottom);
    decay_products.push_back(antibottom);   
  }
  else if(decay_type != "None")
  {
    std::cout<<"Decay type not recognised. "<<std::endl;
    decay_type = "Unrecognised";
  }
}

// Overwritten move constructor
HiggsBoson::HiggsBoson(HiggsBoson&& higgs) : Particle(higgs)
{
  decay_type = higgs.decay_type;
  decay_products = higgs.decay_products;
  higgs.decay_type = "None";
  higgs.decay_products = std::vector<std::shared_ptr<Particle>>{nullptr};
}

// Overwritten copy assignment operator
HiggsBoson& HiggsBoson::operator=(HiggsBoson& higgs) 
{
  if(&higgs != this)
  {
    Particle::operator=(higgs);
  }
  decay_type = higgs.decay_type;
  decay_products = higgs.decay_products;
  
  return *this;
}

// Overwritten move assignment operator
HiggsBoson& HiggsBoson::operator=(HiggsBoson&& higgs)
{
  Particle::operator=(std::move(higgs));
  std::swap(decay_type, higgs.decay_type);
  std::swap(decay_products, higgs.decay_products);

  return *this;
}

void HiggsBoson::print_data()
{
  std::cout<<"Particle type: Higgs boson"<<std::endl;
  std::cout<<"Charge = "<<charge<<std::endl;
  std::cout<<"Spin = "<<spin<<std::endl;
  std::cout<<"Rest mass = "<<rest_mass<<std::endl;
  std::cout<<"Four momentum = ["<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[0]<<","<<std::setprecision(3)<<
  four_momentum->get_four_momentum_vector()[1]<<","<<std::setprecision(3)<<four_momentum->get_four_momentum_vector()[2]<<","<<
  std::setprecision(3)<<four_momentum->get_four_momentum_vector()[3]<<"]"<<std::endl;
  if(decay_products.size()>0)
  {
    std::cout<<"\nPrinting data of Higgs boson decay products\n"<<std::endl;
    for(auto i=decay_products.begin(); i<decay_products.end(); i++)
    {
      (*i)->print_data();
      std::cout<<"\n"<<std::endl;
    }
  }
}