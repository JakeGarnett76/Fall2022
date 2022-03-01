#include<stdlib.h>
#include<time.h>
#include<math.h>


//map[y][x] map[row][col]
char map[21][80];
int north;
int east;
int south;
int west;
double distance(double x1, double y1, double x2, double y2);

int main(){
    
    emptyMap();
    addEdge();
    generateTerrainSeeds(',', 2);
    randomExits();
    randomRoadNS();
    randomRoadWE();
    addBuildings();
    displayMap();
   
}

//displays map
void displayMap(){
    int i;
    int j;
    int counter = 0;
    for(i = 0 ; i < 21; i++){
        for(j = 0; j < 80;j++){
            printf("%c ", map[i][j]);
            counter++;
            if(counter == 80){
                printf("\n");
                counter = 0;
            }
        }
    }
}

//generates an empty map
void emptyMap(){
    int y;
    int z;
    int counter = 0;
    for(y = 0 ; y < 21; y++){
        for(z = 0; z < 80;z++){
            counter++;
            map[y][z] = '.';
        }
    }
}

//generates random exits and roads
void randomExits(){
    srand(time(NULL));
 //   srand(1);
    north = rand() % 15 + 30;
    east = rand() % 15 + 2;
    south = rand() % 15 + 30;
    west = rand() % 15 + 2;
/**
    printf("%d\n", north);
    printf("%d\n", east);
    printf("%d\n", south);
    printf("%d\n", west);
**/
    map[0][north] = '#';
    map[20][south] = '#';
    map[west][0] = '#';
    map[east][79] = '#';
}

//generates Road north to south
void randomRoadNS(){
    int currX = north;
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
            temp = distance(currX, currY + i, south, 21);
            currentCoordY = distance(currX, currY, south, 21);
            if(temp < currentCoordY){
 //               printf("%s\n","updateY");
                currY = currY + i;
                map[currY][currX] = '#';
            }
        }

        //check west/east
        for(j = -1; j < 2; j++){
 //           printf("%s", "X distance: ");
            temp = distance(currX + j, currY, south, 21);
            currentCoordX = distance(currX, currY, south, 21);
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
void randomRoadWE(){
    int currX = 0;
    int currY = west;
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
            temp = distance(currX, currY + i, 80, east);
            currentCoordY = distance(currX, currY, 80, east);
            if(temp < currentCoordY){
//                printf("%s\n","updateY");
                currY = currY + i;
//                map[currY][currX] = '1';
            }
        }

        //check west/east
        for(j = -1; j < 2; j++){
 //           printf("%s", "X distance: ");
            temp = distance(currX + j, currY, 80, east);
            currentCoordX = distance(currX, currY, 80, east);
            if(temp < currentCoordX){
//                printf("%s\n","updateX");
                currX = currX + j;
                map[currY][currX] = '#';
            }
        }
        
        
        counter++;
//        printf("%d", counter);
    }
}


//addes border
void addEdge(){
    int a;
    int b;
    for(a = 0; a < 80; a++){
        map[0][a] = '%%';
        map[20][a] = '%%';
    }
    for(b = 0; b < 21; b++){
        map[b][0] = '%%';
        map[b][79] = '%%';
    }
}
//fully randomize
void generateTerrainSeeds(char terr, int total){
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
        genTerr(x, y, terr);
    }
}

//not used
void generateTerrain(int terrX, int terrY, char terr){
    int i;
    int j;
    int y;
    int z;
    for(i = -3; i < 3; i++){
        for(y = -3; y < 3; y++){
            map[terrY+i][terrX+y] = terr;
        }
    }

    for(j = -3; j < 3; j++){
        for(y = -3; y < 3; y++){
            map[terrY + j][terrX] = terr;
        }
        map[terrY + j][terrX] = terr;
    }
    
}


//generates Terrain
void genTerr(int x, int y, int terr){
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
            if(map[y + i][x + j] == '%' || map[y + i][x + j] == '-'){
                
            }
            else {
                map[y + i][x + j] = terr;

                int ranVar = rand() % 4;
//                printf("%d\n", ranVar);
                if(ranVar == 1){
                    if(map[y + i + 1][x + j] == '.'){
                        map[y + i + 1][x + j] = terr;
                    }
                }
                if(ranVar == 2){
                    if(map[y + i - 1][x + j] == '.'){
                        map[y + i - 1][x + j] = terr;
                    }
                }
                if(ranVar == 3){
                    if(map[y + i][x + j + 1] == '.'){
                        map[y + i][x + j + 1] = terr;
                    }
                }
                if(ranVar == 4){
                    if(map[y + i][x + j - 1] == '.'){
                        map[y + i][x + j - 1] = terr;
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
void addBuildings(){
    int i;
    int j;
    srand(time(NULL));
    int cLocation = rand() % 20 + 10;
    for(i = 0;i < 20;i++){
        if(map[i][cLocation] == '#'){
            map[i-1][cLocation] = 'C';
            map[i-2][cLocation] = 'C';
            map[i-2][cLocation-1] = 'C';
            map[i-1][cLocation-1] = 'C';
            break;
        }
    }

    int mLocation = rand() % 20 + 50;
    for(i = 0;i < 20;i++){
        if(map[i][mLocation] == '#' && map[i][41] == '#'){
            map[i+1][mLocation] = 'M';
            map[i+2][mLocation] = 'M';
            map[i+2][mLocation-1] = 'M';
            map[i+1][mLocation-1] = 'M';
            break;
        }
    }
}

//finds distance between points
double distance(double x1, double y1, double x2, double y2){
    double dist = pow(pow(x2-x1, 2.0) + pow(y2-y1,2.0), 0.5);
//    printf("%f\n", dist);
    return dist;
}