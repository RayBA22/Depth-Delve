#include "Minerai.h"


Minerai::Minerai(){

}

Minerai::Minerai(type_Minerai idm, int x_init, int y_init): Obj(x_init, y_init){
    detruit = false;
    id = idm;
    HP = 2*(id+1); //changer en parabole ou une autre fonction
    
}



type_Minerai Minerai:: get_idMinerai()const{
    return id;
}





void Minerai::se_detruit(int deg){
    HP = HP - deg;      
    if (HP <= 0) detruit=true;
    
}




bool Minerai::est_detruit()const{
    return detruit;
}



