//
// Created by student on 08.05.18.
//

#include <G4VPhysicalVolume.hh>
#include <Geometry.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include "G4SystemOfUnits.hh"
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4GeometryManager.hh>
#include <G4LogicalVolumeStore.hh>
#include <G4SolidStore.hh>
#include <G4PhysicalVolumeStore.hh>
#include <G4RunManager.hh>


G4VPhysicalVolume *Geometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();


    G4double world_size = 5*m;
    auto world = new G4Box("world", world_size/2.,world_size/2.,world_size/2.);
    auto world_log = new G4LogicalVolume(world,G4NistManager::Instance()->FindOrBuildMaterial(mName),"world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);


    auto box = new G4Box("box",box_size/2.,box_size/2., box_size/2.);
    auto box_log = new G4LogicalVolume(box,G4NistManager::Instance()->FindOrBuildMaterial(mName),"box_log");
    new G4PVPlacement(nullptr,G4ThreeVector(),box_log,"box_pvp",world_log,false,0);
    return new G4PVPlacement(nullptr,G4ThreeVector(),world_log,"world_pvp", nullptr,false,0);
}

Geometry::Geometry() {
    classMatmes=new Matmes(this);
    classSizemes=new Sizemes(this);
    box_size = 10*cm;
    mName = "G4_BGO";
}
Sizemes::Sizemes(Geometry* cls1):Sizemesclass(cls1) {
    myDir = new G4UIdirectory (" my_dir/");
    newSizeVal = new G4UIcmdWithADouble (" my_dir/set_new_size", this);
}
void Sizemes::SetNewSizeValue(G4UIcommand* cmd1, G4String nbox_size){
    if (cmd1 == newSizeVal){
        Sizemesclass->SizeVal(newSizeVal -> GetNewDoubleValue(nbox_size));
    }
}

void Geometry::SizeVal(G4double sizeval){
    box_size = sizeval;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}
Sizemes::~Sizemes(){}
Matmes::Matmes(Geometry* cls2):Matmesclass(cls2) {
    myDir = new G4UIdirectory (" my_dir/");
    newMatVal = new G4UIcommand (" my_dir/set_new_material", this);
}

void Matmes::SetNewMatValue(G4UIcommand* cmd2, G4String nmName){
    if (cmd2 == newMatVal){
        Matmesclass->MatVal(newMatVal ->CategoryOf(nmName));
    }
}
void Geometry::MatVal(G4String matval){
    mName = matval;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

Matmes::~Matmes(){
}
