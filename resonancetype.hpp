#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP
#include "particletype.hpp"

class ResonanceType : public  ParticleType
{
public:
   ResonanceType(const char* name, double mass, char charge, double w);
   double GetWidth() const;
  void Print();
private:
	 const double m_Width;
};

#endif
