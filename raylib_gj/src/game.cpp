#include <raylib.h>
#include <stdio.h>
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400 
#define SPEED 2

typedef struct
{
    Vector2 position;
}Blaster;

typedef struct
{
    Texture2D enemyTex;
    Vector2 position;
    int hit=0;

}Enemy;

float bulletUpdate(float pos){

    return pos-SPEED;

}
float enemyUpdate(float pos){
    return pos+SPEED;
}

int main(){
    

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Alien Shooter");

    //Load content
    //Player Region
    int moving=0;
    int time_between_bullets=0;
   
    int i=0;
    Blaster blaster[30];
    Texture2D planeTex=LoadTexture("assets/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png");
    Texture2D blasters=LoadTexture("assets/Mini Pixel Pack 3/Projectiles/Player_beam (16 x 16).png");

    Texture2D boosters=LoadTexture("assets/Mini Pixel Pack 3/Player ship/Boosters (16 x 16).png");

    Vector2 pos={SCREEN_WIDTH/2,SCREEN_HEIGHT-50};
    Rectangle plane={16,0,(float)planeTex.width/3,(float)planeTex.height};
    //Player Region End

    //Enemy Region
    int time_between_enemy_spawn=200;
    int enemy_spawn_tick=0;
    int enemy_count=0;
    Enemy enemy[50];
    Texture2D bon_bon=LoadTexture("assets/Mini Pixel Pack 3/Enemies/Bon_Bon (16 x 16).png");
    Rectangle enemy_rect={16,0,(float)bon_bon.width/4,(float)bon_bon.height};

    //Enemy Region end
    //End load content

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        plane.x=16;
        moving=0;
        
        //Update
        if(IsKeyDown(KEY_ENTER)){
            if(i<30){
                time_between_bullets++;
                if(time_between_bullets>8){
                    i++;
                    blaster[i].position=pos;
                    time_between_bullets=0;

                }
            
            }
            else
            i=0;
        }
        if(IsKeyDown(KEY_W)){
            pos.y-=SPEED;
            moving=1;
        }
        if(IsKeyDown(KEY_S)){
            pos.y+=SPEED;
            moving=1;
        }
        if(IsKeyDown(KEY_A)){

            pos.x-=SPEED;
            plane.x=0;
            moving=1;
        }
        if(IsKeyDown(KEY_D)){

            pos.x+=SPEED;
            plane.x=32;
            moving=1;
        }
        for (size_t j = 0; j < 30; j++)
            {
                blaster[j].position.y=bulletUpdate(blaster[j].position.y);
            }

        
        if(enemy_spawn_tick>time_between_enemy_spawn){

            if(enemy_count<50){
                enemy[enemy_count].position={SCREEN_WIDTH/2,0};
            }
            else{
                enemy_count=0;
            }
            enemy_spawn_tick=0;
            
        }
        else{
            enemy_spawn_tick++;
        }
        for (size_t j = 0; j < 50; j++)
            {
               enemy[j].position.y=enemyUpdate(enemy[j].position.y);
            }
            

        //End Update

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTextureRec(planeTex,plane,pos,WHITE);
            if(moving){
                DrawTextureRec(boosters,plane,{pos.x,pos.y+16},WHITE);
            }
            for (size_t j = 0; j < 30; j++)
            {
                DrawTexture(blasters,blaster[j].position.x,blaster[j].position.y,WHITE);
            }
            for (size_t j = 0; j < 50; j++)
            {
                DrawTextureRec(bon_bon,enemy_rect,{enemy[j].position.x,enemy[j].position.y},WHITE);
                
            }
            
        EndDrawing();


    }
    UnloadTexture(planeTex);
    UnloadTexture(boosters);
    UnloadTexture(bon_bon);
    CloseWindow();
    return 0;

}