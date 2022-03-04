#include <cstdio>
#include <iostream>

using namespace std;

#define MAXCOL 10
#define MAXROW 10

void print_map(bool map[][MAXCOL], int nRow, int nCol)
{
    int i, j;

    for (i = 0; i < nRow; i++){
        for (j = 0; j < nCol; j++){
            if (map[i][j]){ // Occupied
                cout << '@';
            } else {
                cout << '.';  //Not occupied
            }
        }
        cout << endl;
    }
    cout << endl;
}

/*****************************************************
 * You are ALLOWED to define additional functions for this task
 * Remember to paste all _additional_ functions for the task during submission
 ****************************************************/

bool validCell(int row, int col){
    if(row >= MAXROW || row < 0){
        return false;
    }
    if(col >= MAXCOL || col < 0){
        return false;
    }
    return true;
}

int violateSD(bool map[][MAXCOL], int row, int col)
//Purpose: check whether the person at [row][col] violates social distancing
//Return:
//     if [row][col] is not occupied, return 0
//     Otherwise, count the number of occupied locaions around [row][col] in 
//        the "Fat-Cross" shape as described in question sheet
{
    int rowBorder[5] = {-2,-1,0,1,2};
    int colBorder[5] = {-2,-1,0,1,2};
    int count = 0;
    if(!map[row][col]){
        return 0;
    }
    for(int loopRow = 0; loopRow < 5; loopRow++){
        for(int loopCol = 0; loopCol < 5; loopCol++){
            int rowAdd = rowBorder[loopRow];
            int colAdd = colBorder[loopCol];
            int rowFnl= row + rowAdd;
            int colFnl = col + colAdd;
            // cout << "(rowFnl,colFnl): " << "(" << rowFnl << "," << colFnl << ")" << endl;
            if(!validCell(rowFnl, colFnl)){
                // cout << "invalid cell. Ignore" << endl;
                continue;
            }            
            if(abs(rowAdd) == 2 && abs(colAdd) == 2){
                // cout << "abs(2),abs(2). Ignore" << endl;
                continue;
            }
            if(rowAdd == 0 && colAdd == 0){
                // cout << "self position. Ignore" << endl;
                continue;
            }
            if(map[rowFnl][colFnl]){
                // cout << "ok. add count" << endl;
                count++;
            }
        }
    }
    return count;
}


int main()
{
    //Boolean 2D array. Note that 0 = false, 1 = true
    // true means the space is occupied, false means empty
    bool map[MAXROW][MAXCOL] = {
        { 1, 1, 0, 0, 0, 1, 0, 0, 1, 1 },   //row 0
        { 1, 0, 1, 0, 0, 1, 0, 0, 0, 1 },   //row 1
        { 0, 1, 1, 0, 0, 0, 1, 1, 0, 1 },   //row 2
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },   //row 3
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 4
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 5
        { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 6
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 7
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 8
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }    //row 9
    };

    print_map(map, MAXROW, MAXCOL);

    cout << violateSD(map, 4, 0) << endl; //Is anyone there?
    cout << violateSD(map, 6, 5) << endl; //Wow, looks like a full gathering there!
    cout << violateSD(map, 0, 0) << endl; //the person at upper left
    cout << violateSD(map, 0, 8) << endl; //the person near upper right
    cout << violateSD(map, 6, 1) << endl;

    return 0;
}