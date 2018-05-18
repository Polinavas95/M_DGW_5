//
// Created by idalov on 12.05.18.
//

#include <EventAction.hh>

EventAction::EventAction(RunAction *_runAction) : runAction(_runAction) {}

EventAction::EventAction() {
    classPormes = new Pormes(this);
}
Pormes::Pormes(EventAction* cls4):Pormesclass(cls4) {
    myDir = new G4UIdirectory (" my_dir/");
    newPorVal = new G4UIcmdWithADouble (" my_dir/set_new_porog", this);
}

void Pormes::NewPorVal(G4UIcommand* cmd4, G4String nThreshold){
    if (cmd4 == newPorVal){
        Pormesclass->Porval(newPorVal -> GetNewDoubleValue(nThreshold));
    }
}
void EventAction::Porval(G4double porval){
    Threshold = porval;
}

Pormes::~Pormes(){
}
void EventAction::BeginOfEventAction(const G4Event* anEvent) {
    EnergyDep = Threshold;
}
