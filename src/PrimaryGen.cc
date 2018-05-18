//
// Created by student on 08.05.18.
//

#include <G4Event.hh>
#include <PrimaryGen.hh>
#include <G4Gamma.hh>
#include "G4SystemOfUnits.hh"
void PrimaryGen::GeneratePrimaries(G4Event *anEvent) {
    gun->GeneratePrimaryVertex(anEvent);
}

PrimaryGen::PrimaryGen() {
    classVectormes=new Vectormes(this);
    pos_vect.set(0,0,-10*cm);
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    gun->SetParticlePosition(pos_vect);
    gun->SetParticleEnergy(661*keV);
}
Vectormes::Vectormes(PrimaryGen* cls5):Vectormesclass(cls5) {
    myDir = new G4UIdirectory (" my_dir/");
    newVectorVal= new G4UIcommand (" my_dir/set_new_vector", this);
}
void Vectormes::SetNewVector(G4UIcommand* cmd5, G4String npos_vect){
    if (cmd5 == newVectorVal){
        Vectormesclass->NewVector(newVectorVal->ConvertTo3Vector(npos_vect));
    }
}
void PrimaryGen::NewVector(G4ThreeVector nvector){
    pos_vect = nvector;
}
PrimaryGen::~PrimaryGen() {
    delete gun;
}
