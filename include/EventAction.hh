//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_EVENTACTION_HH
#define TEMPLATE_EVENTACTION_HH

#include <G4UserEventAction.hh>
#include <pwdefs.hh>
#include <G4UImessenger.hh>
#include <G4UIcmdWithADouble.hh>

class RunAction;
class Pormes;

class EventAction: public G4UserEventAction{
private:
    RunAction* runAction;
    G4double Threshold;

public:
    explicit EventAction(RunAction *runAction);
    void BeginOfEventAction(const G4Event* anEvent);
    G4double EnergyDep;
    Pormes* classPormes;
    void Porval(G4double porval);
    EventAction();
};
class Pormes : public G4UImessenger{
private:
    EventAction* Pormesclass;
    G4UIdirectory* myDir;
    G4UIcmdWithADouble* newPorVal;

public:
    Pormes(EventAction* cls4);
    ~Pormes();
    void SetNewValue(G4UIcommand* cmd4, G4String nThreshold);
};



#endif //TEMPLATE_EVENTACTION_HH
