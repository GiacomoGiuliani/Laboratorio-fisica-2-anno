#ifndef PARTICLETYPE_HPP
#define PARTICLETYPE_HPP


class ParticleType 
{
public:
	ParticleType( const char* n, double m, char q);
	double GetMass() const;
	const char* GetName() const;
	char GetCharge() const;
	virtual void Print();
	
private:
	
	 const char* m_name;
	 const double m_mass;
     const char m_charge;
	
};
#endif
