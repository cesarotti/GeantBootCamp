//
/*
 Physics list for positron-electron annihilation events
 Background specific
 Dark Photon group
 
 !!!History
    CJC 6.11.14 Created
    cJC 6.18.14 Modified likelihood of collision

 */

#include "PositronPhysicsList1.hh"


#include "G4ProcessManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Positron.hh"
#include "G4Electron.hh"
#include "G4Proton.hh"
#include "G4Gamma.hh"

#include "G4VUserPhysicsList.hh"

#include "G4hIonisation.hh"
#include "G4eIonisation.hh"

#include "G4hBremsstrahlung.hh"
#include "G4eBremsstrahlung.hh"

#include "G4eplusAnnihilation.hh"

#include "G4VEmProcess.hh"


PositronPhysicsList1::PositronPhysicsList1()
{
  defaultCutValue = 1.0*mm;
  SetVerboseLevel(0);
}

PositronPhysicsList1::~PositronPhysicsList1()
{}

void PositronPhysicsList1::ConstructParticle()
{
  G4Gamma::GammaDefinition();
  G4Positron::PositronDefinition();
  G4Electron::ElectronDefinition();
  G4Proton::ProtonDefinition();
}

void PositronPhysicsList1::ConstructProcess()
{
  AddTransportation();
  ConstructEM();

}

void PositronPhysicsList1::ConstructEM()
{
  G4ParticleDefinition* positron = G4Positron::PositronDefinition();
  G4ProcessManager* pman = positron->GetProcessManager();
  


  G4VEmProcess* eplusProc = new G4eplusAnnihilation();
  eplusProc->SetCrossSectionBiasingFactor(1e+01, true);
  pman->AddProcess(eplusProc, 0, -1, 4); //Look up process for these arguments
 
  
}


void PositronPhysicsList1::SetCuts()
{
  SetCutValue(defaultCutValue, "gamma");
  SetCutValue(defaultCutValue, "e-");
  SetCutValue(defaultCutValue, "e+");
  SetCutValue(defaultCutValue, "proton");
}




