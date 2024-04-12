#include "Pioche.h"


Pioche::Pioche(){

}


Pioche::Pioche(idPioche idp){
    id = idp;
    dmg = idp;
    
}



idPioche Pioche::get_idPioche()const{
    return id;
}
    

int Pioche::get_dmgPioche()const{

    return dmg;
}