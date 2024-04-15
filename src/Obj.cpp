#include "Obj.h"

Obj::Obj(){

}

Obj::Obj(int x_init, int y_init){

    pos.x = x_init;
    pos.y = y_init;
}




Vect Obj::get_position()const{

    return pos;
}

int Obj::get_HP()const{
    return HP;
}