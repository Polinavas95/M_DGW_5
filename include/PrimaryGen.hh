//
// Created by student on 08.05.18.
//

#ifndef TEMPLATE_PRIMARYGEN_HH
#define TEMPLATE_PRIMARYGEN_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4UImessenger.hh>

class Vectormes;
class PrimaryGen: public G4VUserPrimaryGeneratorAction{
private:
    G4ParticleGun* gun;
    G4ThreeVector pos_vect;
public:
    PrimaryGen();
    Vectormes* classVectormes;
    void NewVector(G4ThreeVector nvector);
    virtual ~PrimaryGen();

    void GeneratePrimaries(G4Event *anEvent) override;
};
class Vectormes : public G4UImessenger{
private:
    PrimaryGen* Vectormesclass;
    G4UIdirectory* myDir;
    G4UIcommand* newVectorVal;
public:
    Vectormes(PrimaryGen* cls5);
    ~Vectormes();
    void SetNewValue(G4UIcommand* cmd5, G4String npos_vect);
};

#endif //TEMPLATE_PRIMARYGEN_HH
