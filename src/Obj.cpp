#include "Obj.h"

Obj::Obj(){

}

Obj::Obj(entier x_init, entier y_init){

    pos.x = x_init;
    pos.y = y_init;
}




Vect Obj::get_position()const{

    return pos;
}

entier Obj::getHP()const{
    return HP;
}