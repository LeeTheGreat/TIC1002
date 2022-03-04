#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


//You are not allowed to modify the structure definition
struct Point3D {
    int X, Y, Z;
};

/**************** Combined ********************************/

void bubbleSort2 (Point3D a[], int N, Point3D ship);

double calculate_distance(Point3D pointA, Point3D pointB){
    return sqrt(pow(pointA.X - pointB.X, 2) + pow(pointA.Y - pointB.Y, 2) + pow(pointA.Z - pointB.Z, 2));
}

//You are not allowed to modify the function header
int rank_reachable( Point3D planets[], int size, Point3D* starship, double maxDistance, Point3D reachable[])
{
    int count = 0;
    for(int i = 0; i < size; i++){
        double distanceShipToPlanets = calculate_distance(planets[i], *starship);
        if(distanceShipToPlanets <= maxDistance){
            reachable[count] = planets[i];
            count++;
        }
        bubbleSort2(reachable, count, *starship);
    }
    return count;
}

/************* Integer Bubble Sort ***************/
void bubbleSort2 (Point3D a[], int N, Point3D ship)
{
    bool is_sorted;
    int i, j;
    Point3D temp;
    for (i = 0; i < N; ++i) {
        is_sorted = true;
        for (j = 1; j < N - i; ++j) {
            if (calculate_distance(a[j-1], ship) > calculate_distance(a[j], ship)){
                temp = a[j-1] ; 
                a[j-1] = a[j] ; 
                a[j] = temp ;
                is_sorted = false;
                continue;
            }
            if (abs(a[j-1].X) > abs(a[j].X)) {
                temp = a[j-1] ; 
                a[j-1] = a[j] ; 
                a[j] = temp ;
                is_sorted = false;
                continue;
            }
            if(abs(a[j-1].Y) > abs(a[j].Y)) {
                temp = a[j-1] ; 
                a[j-1] = a[j] ; 
                a[j] = temp ;
                is_sorted = false;
                continue;
            }
            if(abs(a[j-1].Z > a[j].Z)) {
                temp = a[j-1] ; 
                a[j-1] = a[j] ; 
                a[j] = temp ;
                is_sorted = false;
                continue;
            }    
        } 
        if (is_sorted) return;
    } 
}


int main()
{
    Point3D planets[10] = {
                                   {-9, 1, 0 },
                                   {9, 10, 10},
                                   {8, -3, -6},
                                   {3, 3, 3},
                                   {-4, -9, 5},
                                   {5, 3, 3},
                                   {-4, 3, -3},
                                   {3, 5, 3},
                                   {10, -3, -9},
                                   {-3, -5, 8 }
                                };

    Point3D starship = {4, 4, 4};

    Point3D nearbyPlanets[10] = {{0}};
    int numNearby, i;

    //Task 2. Sample output
    numNearby = rank_reachable( planets, 10, &starship, 12, nearbyPlanets);
    for (i = 0; i < numNearby; i++){
        printf("(%d, %d, %d)\n", nearbyPlanets[i].X, 
                nearbyPlanets[i].Y, nearbyPlanets[i].Z);
    }

    return 0;
}
