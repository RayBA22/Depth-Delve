#include "Obj.h"

Obj::Obj(){

}

Obj::Obj(entier x_init, entier y_init){

    pos.x = x_init;
    pos.y = y_init;
}


type_perso Obj::get_id()const{
    return id;
}

Vect Obj::get_position()const{

    return pos;
}