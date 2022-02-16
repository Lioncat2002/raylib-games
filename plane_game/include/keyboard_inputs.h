#ifndef RAYLIB_H
#include "raylib.h"
#endif

Vector2 input(Vector2 pos,float speed){

    if(IsKeyDown(KEY_W)||IsKeyDown(KEY_UP)){
        if(pos.y>0)
        pos.y-=speed;
    }
    if(IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN)){
        if(pos.y<480)
        pos.y+=speed;
    }
    if(IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT)){
        if(pos.x>0)
        pos.x-=speed;
    }
    if(IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT)){
        if(pos.x<480)
        pos.x+=speed;
    }
    return pos;
}