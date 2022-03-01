#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "HW1.h"


//map[y][x] map[row][col]
/**
char map[21][80];
int north;
int east;
int south;
int west;
**/
double distance(double x1, double y1, double x2, double y2);


/**
int main(){
    struct Tile tile;
    struct Tile *tilePtr = &tile;
    emptyMap(tilePtr);
    addEdge(tilePtr);
    generateTerrainSeeds(tilePtr,',', 2);
    randomExits(tilePtr);
    randomRoadNS(tilePtr);
    randomRoadWE(tilePtr);
    addBuildings(tilePtr);
    displayTileMap(tilePtr);
   
}
**/

void inititateTile(struct Tile *tile){
    tile->north = 0;
    tile->east = 0;
    tile->south = 0;
    tile->west = 0;

    tile->currentX = 0;
    tile->currentY = 0;
}

void generateMap(struct Tile *tile){
    emptyMap(tile);
//    printf("%s\n", "emptyMap");

    addEdge(tile);
//    printf("%s\n", "addEdge");

    generateTerrainSeeds(tile, ',', 2);
 //   printf("%s\n", "generateTerrainSeeds");

    //last print
    randomExits(tile);
//    printf("%s\n", "randomExits");

    randomRoadNS(tile);
//    printf("%s\n", "roadNS");

    randomRoadWE(tile);
//    printf("%s\n", "roadWE");

    addBuildings(tile);
//    printf("%s\n", "addBuilngs");
}

//displays map
void displayMap(struct Tile tile){
    int i;
    int j;
    int counter = 0;
//    printf("%s", "indisplay");
    for(i = 0 ; i < 21; i++){
        for(j = 0; j < 80;j++){
//            printf("%s", "indisplay1");
            printf("%c ", tile.map[i][j]);
            counter++;
//            printf("%s", "indisplay2");
            if(counter == 80){
                printf("%s", "\n");
                counter = 0;
            }
        }
    }
}


void displayTileMap(struct Tile *tile){
    int i;
    int j;
    int counter = 0;
    for(i = 0 ; i < 21; i++){
        for(j = 0; j < 80;j++){
            printf("%c ", tile->map[i][j]);
            counter++;
            if(counter == 80){
                printf("%s", "\n");
                counter = 0;
            }
        }
    }
}

//generates an empty map
void emptyMap(struct Tile *tile){
    int y;
    int z;
    int counter = 0;
    for(y = 0 ; y < 21; y++){
        for(z = 0; z < 80;z++){
            counter++;
            tile->map[y][z] = '.';
        }
    }
}

//generates random exits and roads
void randomExits(struct Tile *tile){
 //   printf("%s", "exits0");
    srand(time(NULL));
//    printf("%s", "exits1"); //last print last print last print last print
    if(tile->north == 0){
        tile->north = rand() % 15 + 30;
    }
    
    if(tile->east == 0){
        tile->east = rand() % 15 + 2;
    }
    
//    printf("%s", "exits3");
    if(tile->south == 0){
        tile->south = rand() % 15 + 30;
    }
    
//    printf("%s", "exits4");
    if(tile->west == 0){
        tile->west = rand() % 15 + 2;
    }
    /**
    printf("%s", "north- ");
    printf("%d \n", tile->north);
    printf("%s", "east- ");
    printf("%d \n", tile->east);
    printf("%s", "south- ");
    printf("%d \n", tile->south);
    printf("%s", "west- ");
    printf("%d \n", tile->west);
    **/
/**
    printf("\nnorth: %d\n", tile->north);
    printf("east: %d\n", tile->east);
    printf("south: %d\n", tile->south);
    printf("west: %d\n", tile->west);
**/
    tile->map[0][tile->north] = '#';
    tile->map[20][tile->south] = '#';
    tile->map[tile->west][0] = '#';
    tile->map[tile->east][79] = '#';
}

//generates Road north to south
void randomRoadNS(struct Tile *tile){
    int currX = tile->north;
    int currY = 0;
    double currentCoordY;
    double currentCoordX;
    double temp = 0;
    int i;
    int j;
    int counter = 0;
    int movement;
    
    //
    while(currY != 19){
        //north to south
        for(i = -1; i < 2;i++){
//            printf("%s", "Y distance: ");
            temp = distance(currX, currY + i, tile->south, 21);
            currentCoordY = distance(currX, currY, tile->south, 21);
            if(temp < currentCoordY){
 //               printf("%s\n","updateY");
                currY = currY + i;
                tile->map[currY][currX] = '#';
            }
        }

        //check west/east
        for(j = -1; j < 2; j++){
 //           printf("%s", "X distance: ");
            temp = distance(currX + j, currY, tile->south, 21);
            currentCoordX = distance(currX, currY, tile->south, 21);
            if(temp < currentCoordX){
//               printf("%s\n","updateX");
                currX = currX + j;
//                map[currY][currX] = '2';
            }
        }
        
        
        counter++;
//        printf("%d", counter);
    }
}

//generates a road from west to east
void randomRoadWE(struct Tile *tile){
    int currX = 0;
    int currY = tile->west;
    double currentCoordY;
    double currentCoordX;
    double temp = 0;
    int i;
    int j;
    int counter = 0;
    int movement;
    
    //
    while(currX != 78){
        //west to east
        for(i = -1; i < 2;i++){
//            printf("%s", "Y distance: ");
            temp = distance(currX, currY + i, 80, tile->east);
            currentCoordY = distance(currX, currY, 80, tile->east);
            if(temp < currentCoordY){
//                printf("%s\n","updateY");
                currY = currY + i;
//                map[currY][currX] = '1';
            }
        }

        //check west/east
        for(j = -1; j < 2; j++){
 //           printf("%s", "X distance: ");
            temp = distance(currX + j, currY, 80, tile->east);
            currentCoordX = distance(currX, currY, 80, tile->east);
            if(temp < currentCoordX){
//                printf("%s\n","updateX");
                currX = currX + j;
                tile->map[currY][currX] = '#';
            }
        }
        
        
        counter++;
//        printf("%d", counter);
    }
}


//addes border
void addEdge(struct Tile *tile){
    int a;
    int b;
    for(a = 0; a < 80; a++){
        tile->map[0][a] = '%%';
        tile->map[20][a] = '%%';
    }
    for(b = 0; b < 21; b++){
        tile->map[b][0] = '%%';
        tile->map[b][79] = '%%';
    }
}
//fully randomize
void generateTerrainSeeds(struct Tile *tile, char terr, int total){
    int i;
    int x;
    int y;
    int rangeMin = 1;
    int rangeMax = 30;
    srand(time(NULL));
    for(i = 0; i < total; i++){
        x = rand() % rangeMax + rangeMin;
        y = rand() % 20 + 1;
/**        
        printf("%s", "x: ");
        printf("%d\n", x);
        printf("%s", "y: ");
        printf("%d\n\n", y);
**/
        rangeMin = rangeMin + 40;
        genTerr(tile, x, y, terr);
    }
}

//not used
void generateTerrain(struct Tile *tile, int terrX, int terrY, char terr){
    int i;
    int j;
    int y;
    int z;
//    printf("%s\n", "generate0");
    for(i = -3; i < 3; i++){
        for(y = -3; y < 3; y++){
 //           printf("%s\n", "generate1");
            tile->map[terrY+i][terrX+y] = terr;
        }
    }
//    printf("%s\n", "generate2");
    for(j = -3; j < 3; j++){
        for(y = -3; y < 3; y++){
 //           printf("%s\n", "generate3");
            tile->map[terrY + j][terrX] = terr;
        }
        tile->map[terrY + j][terrX] = terr;
    }
    
}


//generates Terrain
void genTerr(struct Tile *tile, int x, int y, int terr){
    srand(time(NULL));
    int i;
    int j;
    int counterX1 = -3;
    int counterX2 = 3;

    int counterY1 = -3;
    int counterY2 = 3;

    int totalCounter = 0;
    for(i = counterX1; i < counterX2; i++){
        for(j = counterY1 - rand() % 3; j < counterY2 + rand() % 3 ; j++){
//            printf("%s\n", "genTerr-1"); //last print //last print
            if(tile->map[y + i][x + j] == '%' || tile->map[y + i][x + j] == '#'){
            }
            else {
//                printf("%s\n", "genTerr0");
                tile->map[y + i][x + j] = terr;
                int ranVar = rand() % 4;
//                printf("%d\n", ranVar);
 //               printf("%s\n", "genTerr1"); //last print
                //below here1
                if(ranVar == 1){
                    if(tile->map[y + i + 1][x + j] == '.'){
                        tile->map[y + i + 1][x + j] = terr;
                    }
                }
//                printf("%s\n", "genTerr2"); //last print
                if(ranVar == 2){
                    if(tile->map[y + i - 1][x + j] == '.'){
                        tile->map[y + i - 1][x + j] = terr;
                    }
                }
//                printf("%s\n", "genTerr3");
                if(ranVar == 3){
                    //crash here
                    if(tile->map[y + i][x + j + 1] == '.'){
                        tile->map[y + i][x + j + 1] = terr;
                    }
                }
 //               printf("%s\n", "genTerr4");
                if(ranVar == 4){
                    if(tile->map[y + i][x + j - 1] == '.'){
                        tile->map[y + i][x + j - 1] = terr;
                    }
                }
            }
        }
    }
    counterX1--;
    counterX2++;
    counterY1--;
    counterY2++;
}

//idiot proof this and make more random
void addBuildings(struct Tile *tile){
    int i;
    int j;
    srand(time(NULL));
    int cLocation = rand() % 20 + 10;
    double distanceTo = distance(199.00,199.00,tile->currentX,tile->currentY);
    double chanceD = (-45 * (distanceTo) / 200+50);
    double chanceN = (rand() % 100 + 1);

    if(chanceN > chanceD || distanceTo == 0){
        for(i = 0;i < 20;i++){
            if(tile->map[i][cLocation] == '#'){
                tile->map[i+1][cLocation] = 'C';
                tile->map[i+2][cLocation] = 'C';
                tile->map[i+2][cLocation-1] = 'C';
                tile->map[i+1][cLocation-1] = 'C';
                break;
            }
        }

        int mLocation = rand() % 20 + 50;
        for(i = 0;i < 20;i++){
            if(tile->map[i][mLocation] == '#' && tile->map[i][41] == '#'){
                tile->map[i+1][mLocation] = 'M';
                tile->map[i+2][mLocation] = 'M';
                tile->map[i+2][mLocation-1] = 'M';
                tile->map[i+1][mLocation-1] = 'M';
                break;
            }
        }
    }
}

//finds distance between points
double distance(double x1, double y1, double x2, double y2){
    double dist = pow(pow(x2-x1, 2.0) + pow(y2-y1,2.0), 0.5);
    return dist;
}

double manhattanDistance(double x1, double y1, double x2, double y2){
    double mDist = abs(x1 - x2) + abs(y2 - y2);
    return mDist;
}