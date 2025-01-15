#include <stdio.h>
#include <raylib.h>

int main(){
    InitWindow(800,800,"Gra");
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("siema",50,50,20,LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}