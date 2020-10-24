#include "PARTICLETYPE.HPP"
#include <iostream>

ParticleType::ParticleType( const char* n,  const double m, const char q) :  m_name{n}, m_mass{m},  m_charge{q} {};
double ParticleType::GetMass() const { return m_mass;}
const char* ParticleType::GetName() const {return m_name;}
char ParticleType::GetCharge() const {return m_charge;}
void ParticleType::Print() 
{
	std::cout << "Particle's name: " << m_name << "\n Mass: " << m_mass << " eV/c^2 \n Charge: " << m_charge << '\n'; 
}
