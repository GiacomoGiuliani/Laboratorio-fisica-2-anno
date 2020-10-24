#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include "particletype.hpp"

class Particle 
{
public:
	Particle(const char* name);
	int GetIndex() const;
	float GetPx()const;
	float GetPy()const;
	float GetPz() const;
	static void AddParticle(const char* Name, double m, char q, double w);
	void setAttribute(int i);
	void setAttribute(const char* name);
	void printArray();
	void printParticle() const;
	double getMass() const;
	double getPNorm() const;
	double getEnergy() const;
	double getInvMass(Particle & p);
	void setMomentum(float x, float y, float z);
	const char* GetName() const;
	
private:
	static const int fMaxNumParticleType = 10;
	static ParticleType* particleArray [fMaxNumParticleType];
	static int fNParticleType;	
	//struct Momentum {
	float m_px;
	float m_py;
	float m_pz;
	//};
	int m_indexP;
	
	static int FindParticle(const char* name);
};


#endif
