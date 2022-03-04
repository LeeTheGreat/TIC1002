#include <cstdio>
#include <iostream>

using namespace std;


#define MAXCOL 15
#define MAXROW 20

#define LEFT '<'
#define RIGHT '>'
#define UP '^'
#define DOWN 'v'
#define CROSS 'X'
#define EMPTY '-'

struct Plane{
    int row;
    int col;
    char direction;
};


void print_trail(char region[MAXROW][MAXCOL], int nRow, int nCol)
{
    int i, j;

    for (i = 0; i < nRow; i++){
        for (j = 0; j < nCol; j++){
            printf("%c", region[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void findEdgePlanes(char region[MAXROW][MAXCOL], Plane edgePlanes[], int &count){
    int index = 0;
    for(int i = 0; i < MAXROW; i++){
        if(region[i][0] == RIGHT){ //left edge
            edgePlanes[index] = {i, 0, RIGHT};
            index++;
        }
        if(region[i][MAXCOL-1] == LEFT){ // right edge
            edgePlanes[index] = {i, MAXCOL-1, LEFT};
            index++;
        }
    }
    for(int i = 0; i < MAXCOL; i++){
        if(region[0][i] == DOWN){ //top edge
            edgePlanes[index] = {0, i, DOWN};
            index++;
        }
        if(region[MAXROW-1][i] == UP){ //bottom edge
            edgePlanes[index] = {MAXROW-1, i, UP};
            index++;
        }
    }
    count = index;
}

bool hasObstacle(int row, int col, char region[MAXROW][MAXCOL]){
    if(region[row][col] == EMPTY){
        return false;
    }
    return true;
}

void updateMap(Plane plane, char region[MAXROW][MAXCOL]){
    if(plane.direction == UP){
        for(int i = MAXROW-2; i > -1; i--){
            if(hasObstacle(i, plane.col, region)){
                region[i][plane.col] = CROSS;
                continue;
            }
            region[i][plane.col] = UP;
        }
    }
    if(plane.direction == DOWN){
        for(int i = 1; i < MAXROW; i++){
            if(hasObstacle(i, plane.col, region)){
                region[i][plane.col] = CROSS;
                continue;
            }  
            region[i][plane.col] = DOWN;
        }
    }
    if(plane.direction == LEFT){
        for(int i = MAXCOL-2; i > -1; i--){
            if(hasObstacle(plane.row, i, region)){
                region[plane.row][i] = CROSS;
                continue;
            }  
            region[plane.row][i] = LEFT;
        }
    }
    if(plane.direction == RIGHT){
        for(int i = 1; i < MAXCOL; i++){
            if(hasObstacle(plane.row, i, region)){
                region[plane.row][i] = CROSS;
                continue;
            }  
            region[plane.row][i] = RIGHT;
        }
    }
}

void plot_trail(char region[MAXROW][MAXCOL])
{
    int count = 0;
    int max = MAXROW * 2 + MAXCOL * 2;
    Plane edgePlanes[max] = { };
    findEdgePlanes(region, edgePlanes, count);
    for(int i = 0; i < count; i++){
        updateMap(edgePlanes[i], region);
    }
}

int main()
{
    char region[MAXROW][MAXCOL] = {
        '-','-','-','-','v','-','-','^','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','P','P','E','1','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '>','-','-','-','-','-','1','-','N','O','T','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','h','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','a','-','-','-',
        '<','-','-','-','-','-','-','-','-','-','-','r','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','d','-','-','-',
        '-','-','-','-','-','-','-','@','-','-','-','!','-','-','-',
        '-','-','-','-','-','-','$','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','*','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','^','-','-','-','-','-','>',
        '-','-','-','-','-','-','-','<','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','>','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','v','-','-','-','-','-','-','-','<',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','v','-','-','-','-','-','-','-','^','-','-','-','-'
    };

    //Before trail is plotted
    //print_trail(region, MAXROW, MAXCOL); 

    plot_trail(region);

    //After trail is plotted
    print_trail(region, MAXROW, MAXCOL); 

    return 0;
}
