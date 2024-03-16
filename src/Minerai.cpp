#include "Minerai.h"


Minerai::Minerai(){

}

Minerai::Minerai(type_Minerai idm, entier x_init, entier y_init): Obj(x_init, y_init){
    detruit = false;
    id = idm;

}


type_Minerai Minerai:: get_idMinerai()const{
    return id;
}


bool Minerai::est_detruit()const{
    return detruit;
}
