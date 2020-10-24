#include<iostream>
#include "particle.hpp"
#include "resonancetype.hpp"
#include "particletype.hpp"

int main() 
{
   Particle::AddParticle("pippo", 1., '-', 3.);
   ParticleType p("pi", 238, '-');
   ResonanceType pp("pi", 238, '-', 5);
   pp.Print(); 
   Particle pr("pippo");
   pr.setMomentum(1.,2.,3.);
   pr.printParticle();
   
}
