#include "Pioche.h"


Pioche::Pioche(){

}


Pioche::Pioche(idPioche idp){
    id = idp;
    dmg = 3*idp;
}



idPioche Pioche::get_idPioche()const{
    return id;
}
    

float Pioche::get_dmgPioche()const{

    return dmg;
}