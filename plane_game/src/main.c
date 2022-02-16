#include "raylib.h"
#include "keyboard_inputs.h"
#include "bullet.h"
#include "stdio.h"
#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512


void MapUpdate(Vector2 mapPos[]){
for(int j=0;j<3;j++){
            if(mapPos[j].y<WINDOW_HEIGHT){
                    mapPos[j].y++;
            }
            else{
                mapPos[j].y=-512-1024*2;
                
            }
            
        }
}


int main()
{
    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Plane game");
    Bullet bullets[200];
    
    int i=0;
    int count=0;
    Texture2D bulletSprite=LoadTexture("assets\\Tiles\\bullet.png");

    Texture2D map=LoadTexture("assets\\map.png");
    Vector2 mapPos[]={{0,-512},{0,-512-1024},{0,-512-1024*2}};
    Texture2D player=LoadTexture("assets\\Ships\\ship_0000.png");
    Vector2 pos={WINDOW_WIDTH/2,WINDOW_HEIGHT-50};
    

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        pos=input(pos,4);

        MapUpdate(mapPos);
        
        if(IsKeyDown(KEY_ENTER)){
        
            if(i<200){
                if(count>=15){
                    bullets[i].pos=pos;
                    i+=1;
                    count=0;

                }
                else {
                    count++;
                }
                
            }
            else{
                i=0;
            }
            
        }
        for(int j=0;j<200;j++){
            bullets[j].pos.y=bulletUpdate(bullets[j].pos.y);
        }
        
        BeginDrawing();
        
        for(int j=0;j<3;j++){
            DrawTexture(map,mapPos[j].x,mapPos[j].y,WHITE);
        }
        
        DrawTexture(player,pos.x,pos.y,WHITE);
        
        for(int j=1;j<200;j++){
            DrawTexture( bulletSprite,bullets[j].pos.x,bullets[j].pos.y,WHITE);
        }
        EndDrawing();
    }
    
    
    return 0;
}
