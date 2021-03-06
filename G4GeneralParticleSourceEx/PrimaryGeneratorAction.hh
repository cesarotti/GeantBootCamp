/*
 * Dark Photon Generator Action
 * !!!History
 *    CJC 6.15.14 created
 */

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

//!!!
//May have to change depending on nature of final beam
class G4GeneralParticleSource;
class G4Event; 

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  PrimaryGeneratorAction();
  virtual ~PrimaryGeneratorAction();

  virtual void GeneratePrimaries(G4Event* );

  G4GeneralParticleSource* GetParticleGun() {return fParticleSource;}

  //Set methods
  void SetRandomFlag(G4bool );

private :
  G4GeneralParticleSource * fParticleSource; //General Particle source
};


#endif
