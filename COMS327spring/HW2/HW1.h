#ifndef HW1_H_
#define HW1_H_

struct Tile {
   char map[21][80];
   int dijkstraMap[21][80];
   int north;
   int east;
   int south;
   int west;
   double currentX;
   double currentY;
};

void inititateTile(struct Tile *tile);
void generateMap(struct Tile *);
void displayMap(struct Tile);
void displayTileMap(struct Tile *);
void emptyMap(struct Tile *);
void randomExits(struct Tile *);
void randomRoadNS(struct Tile *);
void randomRoadWE(struct Tile *);
void addEdge(struct Tile *);
void generateTerrainSeeds(struct Tile *, char terr, int total);
void generateTerrain(struct Tile *, int terrX, int terrY, char terr);
void genTerr(struct Tile *, int x, int y, int terr);
void addBuildings(struct Tile *);
double distance(double x1, double y1, double x2, double y2);
double manhattanDistance(double x1, double y1, double x2, double y2);



#endif