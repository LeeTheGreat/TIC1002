#include <cstdio>
#include <iostream>

using namespace std;

int COG(int weight[], int size)
{
    int mid = size/2;
    int cog = mid;
    for(int i = 0; i < mid; i++){
        if(weight[i] > weight[size-1-i]){
            cog--;
            continue;
        }
        if(weight[i] < weight[size-1-i]){
            cog++;
        }
    }
    return cog;
}

int COG2(int weight[], int size)
{
    int move = 0;
    //cout << "size: " << size << endl;
    //cout << "Comparing " << weight[0] << " with " << weight[size-1] << endl;
    if(weight[0] == weight[size-1]){
        // cout << "size: " << size << endl;
        return 0;
    }
    if(weight[0] > weight[size-1]){
        move--;
    }
    if(weight[0] < weight[size-1]){
        move++;
    }
    return move + COG2(&weight[1], size-2) + 1;
}

int main()
{
    //Sample test case 1
    int w1[] = {3, 2, 9, 5, 1};
 
    cout << "COG for w1[]: " << COG(w1, 5) << endl;
    cout << "COG2 for w1[]: " << COG2(w1,5) << endl; 

    //Sample test case 2
    int w2[] = {1, 2, 3, 4, 5, 6, 7};
 
    cout << "COG for w2[]: " << COG(w2, 7) << endl;
    cout << "COG2 for w2[]: " << COG2(w2,7) << endl;

    //Sample test case 3
    int w3[] = {2, 5, 3, 1, 2};
 
    cout << COG(w3, 5) << endl;

    return 0;
}
