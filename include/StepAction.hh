//
// Created by idalov on 12.05.18.
//

#ifndef TEMPLATE_STEPACTION_HH
#define TEMPLATE_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <G4String.hh>
#include <G4UImessenger.hh>



class EventAction;
class Namemes;

class StepAction : public G4UserSteppingAction{
private:
    G4String pName;
public:
    explicit StepAction(EventAction *event);
    void UserSteppingAction(const G4Step *step) override;
    Namemes* classNamemes;
    void Nameval(G4String nameval);
    StepAction();
    EventAction* event;
};
class Namemes : public G4UImessenger{
private:
    StepAction* Namemesclass;
    G4UIdirectory* myDir;
    G4UIcommand* newNameVal;
public:
    Namemes(StepAction* cls3);
    ~Namemes();
    void SetNewValue(G4UIcommand* cmd3, G4String npName);
};


#endif //TEMPLATE_STEPACTION_HH
