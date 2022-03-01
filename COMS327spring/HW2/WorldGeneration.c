#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "HW1.h"
#include "WorldGeneration.h"



//199,199 center
struct Tile *world[399][399];

int locationX = 0;
int locationY = 0;

void main(){
    locationX = 199;
    locationY = 199;
    generateGrid();
    world[199][199] = malloc(sizeof(*world[locationY][locationX]));
    struct Tile center;
    struct Tile *centerPtr = &center;
    inititateTile(centerPtr);
    centerPtr->currentX = 199.0;
    centerPtr->currentY = 199.0;
    generateMap(centerPtr);
    world[199][199] = centerPtr;
    displayTileMap(centerPtr);


    char buffer[100];

    while(buffer[0] != 'q'){
        scanf("%s", &buffer);
        
        if(buffer[0] == 'n'){
            printf("%s\n", "north");
            locationY = locationY - 1;
        }
        if(buffer[0] == 'e'){
            printf("%s\n", "east");
            locationX = locationX+1;
        }
        if(buffer[0] == 's'){
            printf("%s\n", "south");
            locationY = locationY+1;
        }
        if(buffer[0] == 'w'){
            printf("%s\n", "west");
            locationX = locationX-1;
        }

        if(buffer[0] == 'f'){
            int flyY = 0;
            int flyX = 0;;
            printf("\n%s\n", "Fly");
            printf("%s\n", "Enter X:");
            scanf("%d", &flyX);
            printf("\n%s\n", "Enter Y:");
            scanf("%d", &flyY);
            locationX = flyX;
            locationY = flyY;
            printf("(%d,", locationX);
            printf("%d)", locationY);
        }

        if(buffer[0] == 'q'){
            exit(0);
        }

        if(locationX == 400){
            printf("%s", "out of bounds");
            locationX = locationX - 1;
        }
        if(locationX == -1){
            printf("%s", "out of bounds");
            locationX = locationX + 1;

        }
        if(locationY == -1){
            printf("%s", "out of bounds");
            locationY = locationY + 1;
        }
        if(locationY == 400){
            printf("%s", "out of bounds");
            locationY = locationY - 1;
        }

        if(world[locationY][locationX] != NULL){
            displayTileMap(world[locationY][locationX]);
        }

        if(world[locationY][locationX] == NULL){
            printf("%s\n", "null");
            struct Tile currentTile;
            struct Tile *currentTilePtr = &currentTile;
            inititateTile(currentTilePtr);
            currentTile.currentX = locationX;
            currentTile.currentY = locationY;
            //south
            if(world[locationY+1][locationX] != NULL){
                currentTilePtr->south = world[locationY+1][locationX]->north;
//                printf("\n%s\n", "south: ");
//                printf("%d", currentTilePtr->south);
            }
            //north
            if(world[locationY-1][locationX] != NULL){
//                printf("%s\n", "north ");
                currentTilePtr->north = world[locationY-1][locationX]->south;
//                printf("\n%s", "north: ");
//                printf("%d", currentTilePtr->north);
            }
            //east
            if(world[locationY][locationX+1] != NULL){
//                printf("%s\n", "east: ");
                currentTilePtr->east = world[locationY][locationX+1]->west;
//                printf("\n%s\n", "east: ");
//                printf("%d", currentTilePtr->east);
            }
            //west
            if(world[locationY][locationX-1] != NULL){
//                printf("%s\n", "west");
                currentTilePtr->west = world[locationY][locationX-1]->east;
//                printf("\n%s\n", "west: ");
//                printf("%d", currentTilePtr->west);
            }

            world[locationY][locationX] = malloc(sizeof(*world[locationY][locationX]));
            generateMap(currentTilePtr);
            *world[locationY][locationX] = currentTile;
            //north
            if(locationY == 0){
                currentTilePtr->map[0][currentTilePtr->north] = '%%';
            }
            //east
            if(locationX == 399){
                currentTilePtr->map[currentTilePtr->east][79] = '%%';
            }
            //south
            if(locationY == 399){
                currentTilePtr->map[20][currentTilePtr->south] = '%%';
            }
            //west
            if(locationX == 0){
                currentTilePtr->map[0][currentTilePtr->west] = '%%';
            }

            displayTileMap(currentTilePtr);
        }
    }
}

void generateGrid(){
    int i;
    int j;
    for(i = 0; i < 399; i++){
        for(j = 0; j < 399;j++){
            struct Tile *tilePtr = NULL;
            world[i][j] = tilePtr;
        }
    }
}

void dijkstra(struct Tile *tile, int x, int y){
    int i;
    int j;

    }

    while(queue.isnotempty()){
        current = queue.pop
        for(i = -1; i < 2; i++){
            for(j = -1; j < 2; j++){
                //add to proority queue
            }
        if
    }
}

void displayDijkstraMap(struct Tile *tile){
    int i;
    int j;
    int counter = 0;

    for(i = 0 ; i < 21; i++){
        for(j = 0; j < 80;j++){
            printf("%d ", tile->dijkstraMap[i][j]);
            counter++;
            if(counter == 80){
                printf("%s", "\n");
                counter = 0;
            }
        }
    }
}