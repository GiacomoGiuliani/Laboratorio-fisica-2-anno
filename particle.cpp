#include "particle.hpp"
#include "particletype.hpp"
#include "resonancetype.hpp"

#include <iostream>
#include <cmath>

ParticleType* Particle::particleArray [Particle::fMaxNumParticleType];
int Particle::fNParticleType = 0;

Particle::Particle(const char* name)
{
	m_px = 0;
	m_py = 0;
	m_pz = 0;
	m_indexP = FindParticle(name);
	
};
int Particle::FindParticle(const char* name) 
{
	for(int i = 0; i <  fNParticleType; ++i)
	{
		if(particleArray[i] -> GetName() == name)
		{
			return i;
		} 
	}
	std::cout << "No particle found" << '\n';
	return -1;
};

int Particle::GetIndex() const { return m_indexP;}
float Particle::GetPx() const { return m_px; }
float Particle::GetPy() const { return m_py; }
float Particle::GetPz() const { return m_pz; }

void Particle::AddParticle(const char* Name, double m, char q, double w) // only for particletype
{
	auto i = FindParticle(Name);
	if(i == -1 && fNParticleType < fMaxNumParticleType) 
	{
		particleArray[fNParticleType] = new ResonanceType(Name, m, q, w);
		++fNParticleType;
		std::cout << "Number of particles in the array now: " << fNParticleType << std::endl;
		std::cout << "There are " << fMaxNumParticleType - fNParticleType << " spots left." << '\n';
	} else {
		std::cout << Name << "is already in the array." << '\n';
	}
}; 

void Particle::setAttribute(int i) {
	if(i > fNParticleType) {
	m_indexP = i;
	}
};

void Particle::setAttribute(const char* name) {
	auto i = FindParticle(name);
	if(i > fNParticleType) 
	{
		m_indexP = i;
		std::cout << name << "'s code is now: " << m_indexP << '\n';
	}
};

void Particle::printArray()
{
	for(int i = 0; i < fNParticleType; i++)
	{
		 particleArray[i] ->Print();
	}
};

void Particle::printParticle()const
{
	std::cout << "Particle's name: " << particleArray[m_indexP] -> GetName() << '\n' << "index: " << GetIndex() << '\n' << "members of momentum: " << '\n' << GetPx() << '\n' << GetPy() << '\n' << GetPz() << '\n';
};

double Particle::getMass() const 
{
    double mass = particleArray[m_indexP] -> GetMass();	
	return mass;
};
const char* Particle::GetName() const 
{
    const char* name = particleArray[m_indexP] -> GetName();	
	return name;
};

double Particle::getPNorm() const
{
	double norm = std::sqrt(std::pow(GetPx(), 2) + std::pow(GetPy(), 2) + std::pow(GetPz(), 2));
	return norm;
};
double Particle::getEnergy() const 
{
	double m = getMass();
	double np = getPNorm();
	double Energy = std::sqrt(std::pow(m, 2) + std::pow(np, 2));  
	return Energy;
};
double Particle::getInvMass(Particle & p)
{
	double totE = std::pow(getEnergy() + p.getEnergy(),2);
	double totP = std::pow(GetPx()+p.GetPx(), 2) + std::pow(GetPy()+p.GetPy(), 2) + std::pow(GetPz()+p.GetPz(), 2);
	double invMass = std::sqrt(totE - totP);
	return invMass;
	
}; 
void Particle::setMomentum(float x, float y, float z)
{
	m_px = x;
	m_py = y;
	m_pz = z;
};

