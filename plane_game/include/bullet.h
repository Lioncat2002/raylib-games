#ifndef RAYLIB_H
#include "raylib.h"
#endif

typedef struct
{
   Rectangle hitbox;
    Vector2 pos;
}Bullet;


float bulletUpdate(float posY){
    return posY-1;
}
