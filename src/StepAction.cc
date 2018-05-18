//
// Created by idalov on 12.05.18.
//

#include <StepAction.hh>


StepAction::StepAction(){
    classNamemes=new Namemes(this);
}
Namemes::Namemes(StepAction* cls3){
    myDir = new G4UIdirectory (" my_dir/");
    newNameVal = new G4UIcommand (" my_dir/set_new_name", this);
}

void Namemes::SetNewName(G4UIcommand* cmd3, G4String npName){
    if (cmd3 == newNameVal){
        Namemesclass->Nameval(newNameVal ->CategoryOf(npName));
    }
}
void StepAction::Nameval(G4String nameval){
    pName = nameval;
}

Namemes::~Namemes(){}

StepAction::StepAction(EventAction *_event) : event(_event) {}

void StepAction::UserSteppingAction(const G4Step *step) {
    step=pName;

}

