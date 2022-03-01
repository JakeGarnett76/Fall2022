#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "HW1.h"
#include "WorldGeneration.h"
#include "heap.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/time.h>
#include <assert.h>



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
/**
void dijkstra(int x, int y, struct Tile *tile){
    int dist[21][80];
    int terrValues[21][80];

    //set dist map to INT_MAX and fill out terrvalues
    int i, j;
    for(i = 0; i < 21; i++){
        for(j = 0; j < 80; j++){
            dist[i][j] = INT_MAX;
            if(tile->map[i][j] =='#'){
                terrValues[i][j] = 1;
            }
            if(tile->map[i][j] =='.'){
                terrValues[i][j] = 2;
            }
            if(tile->map[i][j] ==','){
                terrValues[i][j] = 3;
            }
        }
    }

    //set start of distance map to 0
    dist[y][x] = 0;

    //initalize priority queue
    struct heap pq;
    struct heap *pqPtr = &pq;

    //add start to priority queue
    heap_insert(pqPtr, 0);

//    src = start;

    while(pq.size != 0){
        //pop from priority queue
        int u = heap_decrease_key_no_replace();
        //neighbors[8] = neighbors of src;
        int neighbors[8];
        int a, b;
        int counter = 0;
        for(a = -1; a < 2; a++){
            for(b = -1; b < 2; b++){
                neighbors[counter] = terrValues[a][b];
                counter++;
            }
        }

        int z;
        int neighborCounter;
        for(z = 0; z < 8; z++){
            int newDist = u + neighbors[neighborCounter];
            if(newDist < dist[u][u]){
                dist[u][u] = newDist;
                heap_insert(pqPtr, newDist);
            }
        }
}
**/
//how to find pq size
//what to insert into pq

typedef struct path {
  heap_node_t *hn;
  uint8_t pos[2];
  uint8_t from[2];
  int32_t cost;
} path_t;

typedef enum dim {
  dim_x,
  dim_y,
  num_dims
} dim_t;

typedef uint8_t pair_t[num_dims];

#define MAP_X              80
#define MAP_Y              21
#define MIN_TREES          10
#define MIN_BOULDERS       10
#define TREE_PROB          95
#define BOULDER_PROB       95

#define mappair(pair) (m->map[pair[dim_y]][pair[dim_x]])
#define mapxy(x, y) (m->map[y][x])
#define heightpair(pair) (m->height[pair[dim_y]][pair[dim_x]])

#define terrValue(pair) (m->height[pair[dim_y]][pair[dim_x]])

#define heightxy(x, y) (m->height[y][x])

typedef enum __attribute__ ((__packed__)) terrain_type {
  ter_debug,
  ter_boulder,
  ter_tree,
  ter_path,
  ter_mart,
  ter_center,
  ter_grass,
  ter_clearing,
  ter_mountain,
  ter_forest
} terrain_type_t;

typedef struct map {
  terrain_type_t map[MAP_Y][MAP_X];
  uint8_t height[MAP_Y][MAP_X];
  uint8_t n, s, e, w;
} map_t;

typedef struct queue_node {
  int x, y;
  struct queue_node *next;
} queue_node_t;


static int32_t path_cmp(const void *key, const void *with) {
  return ((path_t *) key)->cost - ((path_t *) with)->cost;
}

static int32_t edge_penalty(uint8_t x, uint8_t y)
{
  return (x == 1 || y == 1 || x == MAP_X - 2 || y == MAP_Y - 2) ? 2 : 1;
}



static void dijkstra_path(map_t *m, pair_t from)
{
  static path_t path[MAP_Y][MAP_X], *p;
  static uint32_t initialized = 0;
  heap_t h;
  uint32_t x, y;

  if (!initialized) {
    for (y = 0; y < MAP_Y; y++) {
      for (x = 0; x < MAP_X; x++) {
        path[y][x].pos[dim_y] = y;
        path[y][x].pos[dim_x] = x;
      }
    }
    initialized = 1;
  }
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      path[y][x].cost = INT_MAX;
    }
  }

  path[from[dim_y]][from[dim_x]].cost = 0;

  heap_init(&h, path_cmp, NULL);

  for (y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      path[y][x].hn = heap_insert(&h, &path[y][x]);
    }
  }

  while ((p = heap_remove_min(&h))) {
    p->hn = NULL;

    
    //change heightpair to terrain value
    int terrValue(){
        if(path[p->[dim_y][dim_x]] == '#'){
            return 1;
        }
        if(path[p->[dim_y][dim_x]] == '.'){
            return 2;
        }
        if(path[p->[dim_y][dim_x]] ==','){
            return 3;
        }
    }
    
    //check north
    if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
         ((p->cost + terrValue(p->pos))))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
        ((p->cost + terrValue(p->pos)));
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x]    ].hn);
    }

    //check north west
    if ((path[p->pos[dim_y] - 1][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x] - 1].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y] - 1)))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x] - 1].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y] - 1));
      path[p->pos[dim_y] - 1][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x] - 1].hn);
    }

    //check west
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] - 1].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] - 1].hn);
    }

    //check south west
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x] - 1].hn);
    }

    //check south
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] + 1].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] + 1].hn);
    }

    //check south east
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x] + 1].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x] + 1].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x] + 1].hn);
    }

    //check east
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x]    ].hn);
    }

    //check northeast
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].cost >
         ((p->cost + terrValue(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].cost =
        ((p->cost + terrValue(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x] - 1].hn);
    }
  }
}