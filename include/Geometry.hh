//
// Created by student on 08.05.18.
//

#ifndef TEMPLATE_GEOMETRY_HH
#define TEMPLATE_GEOMETRY_HH

#include <G4VUserDetectorConstruction.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithADouble.hh>

class Matmes;
class Sizemes;

class Geometry: public G4VUserDetectorConstruction{

public:
    G4VPhysicalVolume *Construct() override;
    Matmes *classMatmes;
    Sizemes *classSizemes;
    void MatVal(G4String matval);
    void SizeVal(G4double sizeval);
    Geometry();

private:
    G4double box_size;
    G4String mName;
};
class Sizemes : public G4UImessenger{
private:
    Geometry* Sizemesclass;
    G4UIdirectory* myDir;
    G4UIcmdWithADouble* newSizeVal;
public:
    Sizemes(Geometry* cls1);
    ~Sizemes();
    void SetNewValue(G4UIcommand* cmd1, G4String nbox_size);
};
class Matmes : public G4UImessenger{
private:
    Geometry* Matmesclass;
    G4UIdirectory* myDir;
    G4UIcommand* newMatVal;
public:
    Matmes(Geometry* cls2);
    ~Matmes();
    void SetNewValue(G4UIcommand* cmd2, G4String nmName);

};
#endif //TEMPLATE_GEOMETRY_HH
