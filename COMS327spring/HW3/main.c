#include "HW1.h"
#include "WorldGeneration.h"
#include "heap.h"


void main(){
    struct Tile tile;
    struct Tile *tilePtr = &tile;
    emptyMap(tilePtr);
    addEdge(tilePtr);
    generateTerrainSeeds(tilePtr,',', 2);
    randomExits(tilePtr);
    randomRoadNS(tilePtr);
    randomRoadWE(tilePtr);
    addBuildings(tilePtr);

    dijkstra_path(map_t *m, pair_t from);


}