#include<stdio.h>

    int board[5][5];
    int numBoard[5][5];
    int i;
    int j;
    int counter = 1;
    int counter2 = 0;
    int total = 0;
    int pos;


int main(){

    initBoard();
    initNumBoard();
    showBoard();

   int l;
   int p;
   for(l = 0; l < 5; l++){
       for(p = 0; p < 5; p++){
           pos = 1;
           knightsTour(l,p,pos);
       }
   }
    printf("\n%s", "total: ");
    printf("%d", total);
}

int validMove(int x, int y){
    if(((x < 0) || (x > 4)) || ((y < 0) || (y > 4)) || board[x][y] != 0){
        return 0;
    }
    else{
        return 1;
    }
}

int knightsTour(int x, int y, int pos){
    int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int yMove[8] = {1, 2,  2,  1, -1, -2, -2, -1};

    board[x][y] = pos;

    if(pos >= 25){
//        showBoard();
        showSequence();
        board[x][y] = 0;
        return 1;
    }

    int a;
    for(a = 0; a < 8; a++){
        int currX = x + xMove[a];
        int currY = y + yMove[a];

        if(validMove(currX, currY) == 1){
            knightsTour(currX, currY, pos + 1);
        }
    }
    board[x][y] = 0;
    
}

void initBoard(){
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5;j++){
            board[i][j] = 0;
        }
    }
}

void showBoard(){
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5;j++){

            printf("%3d ", board[i][j]);
            counter2++;

            if(counter2 == 5){
                printf("\n");
                counter2 = 0;
            }
        }
    }
    printf("\n");
//    total++;
}

void showSequence(){
    int p;
    int q;
    int counter = 1;
    int otherCounter = 1;
    int commaCounter = 0;
    while(counter < 26){
        for(p = 0; p < 5; p++){
            for(q = 0; q < 5; q++){
                
                if(board[p][q] == counter){
                    if(otherCounter == 26){
                        printf("1");
                    }
                    else{
                        printf("%d", otherCounter);
                    }
                    
                    if(commaCounter < 24){
                        printf(", ");
                    }
                    commaCounter++;
                    counter++;
                    otherCounter = 1;
                    p = 0;
                    q = 0;
                }
            otherCounter++;
            }
        }
    }
    printf("\n");
    total++;
}

void initNumBoard(){
    int temp = 1;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5;j++){
            numBoard[i][j] = temp;
            temp++;
        }
    }
}

