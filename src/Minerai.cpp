#include "Minerai.h"


Minerai::Minerai(){

}

Minerai::Minerai(type_Minerai idm, entier x_init, entier y_init): Obj(x_init, y_init){
    detruit = false;
    id = idm;
    // pv du min depend de son type

}


type_Minerai Minerai:: get_idMinerai()const{
    return id;
}





void Minerai::se_detruit(entier deg){
    HP -= deg;      
    if (HP <= 0) detruit=true;
    
}




bool Minerai::est_detruit()const{
    return detruit;
}



