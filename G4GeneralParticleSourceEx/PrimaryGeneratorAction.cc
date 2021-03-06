/*
 * Dark Photon Primary Generator Action
 * !!!History
 *    CJC 6.14.15 created
 *
 * file: Primary Generator Action
 *
 * Description
 * This class sets up the experiment, including the world volume and the 
 * particle beam.
 * Methods to update:
 * PrimaryGeneratorAction
 * {adjust energy settings of the gun and particles}
 */

#include "PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4GeneralParticleSource.hh"
#include "G4SPSPosDistribution.hh"
#include "G4SPSAngDistribution.hh"

#include "Randomize.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction()
{

  
  fParticleSource= new G4GeneralParticleSource();

G4ParticleDefinition* particleDefinition = 
  G4ParticleTable::GetParticleTable()->FindParticle("e+");

 fParticleSource->GetCurrentSource()->SetParticleDefinition(particleDefition);
 fParticleSource->GetCurrentSource()->GetPosDist()
   ->SetCentreCoords(G4ThreeVector(0,0, -5.*m));
  fParticleSource->GetCurrentSource()->GetPosDist()
    ->SetPosRot1(G4ThreeVector(1,0,0));
  fParticleSource->GetCurrentSource()->GetPosDist()
    ->SetPosRot2(G4ThreeVector(0,1,0));

  fParticleSource->GetCurrentSource()->GetPosDist()->SetPosDisType("Beam");
  fParticleSource->GetCurrentSource()->GetPosDist()->SetPosDisShape("Square");
  fParticleSource->GetCurrentSource()->GetPosDist()->SetHalfX(17*5.0*cm);
  fParticleSource->GetCurrentSource()->GetPosDist()->SetHalfY(17*5.0*cm);

  fParticleSource->GetCurrentSource()->GetAngDist()->SetAngDistType("beam1d");
  fParticleSource->GetCurrentSource()->GetAngDist()
    ->DefineAngRefAxes("angref1", G4ThreeVector(-1.,0.,0.)); 
  fParticleSource->GetCurrentSource()->GetAngDist()
    ->DefineAngeRefAxes("angref2", G4ThreeVector(0.,1.,0.));




}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleSource;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{

  G4cout << "Generating Primaries" << G4endl;
  // This function is called at the begining of event

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get world volume
  // from G4LogicalVolumeStore.

  G4double worldZHalfLength = 0;
  G4LogicalVolume* worldLV
    = G4LogicalVolumeStore::GetInstance()->GetVolume("World");
  G4Box* worldBox = NULL;
  if ( worldLV ) worldBox = dynamic_cast<G4Box*>(worldLV->GetSolid());
  if ( worldBox ) worldZHalfLength = worldBox->GetZHalfLength();
  else  {
    G4cerr << "World volume of box not found." << G4endl;
    G4cerr << "Perhaps you have changed geometry." << G4endl;
    G4cerr << "The gun will be place in the center." << G4endl;
  }



  fParticleSource->SetParticlePosition(G4ThreeVector(0., 13.*5.0*cm, worldZHalfLength));
  fParticleSource->GeneratePrimaryVertex(anEvent);


}
