#include "resonancetype.hpp"
#include "particletype.hpp"
#include <iostream>


ResonanceType::ResonanceType( const char* name, double mass, char charge,  double w) : ParticleType(name, mass, charge), m_Width(w) {};
double ResonanceType::GetWidth() const {return m_Width;}
void ResonanceType::Print() 
{
	ParticleType::Print();
	std::cout << "Resonance width: " << m_Width << '\n';
}
