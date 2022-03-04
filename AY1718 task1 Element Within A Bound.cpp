#include <cstdio>
#include <iostream>

using namespace std;

// int within(int a[], int N, int lower, int upper, int result[]){
//     int count = 0;
//     for(int i = 0; i < N; i++){
//         if(a[i] >= lower && a[i] <= upper){
//             result[count] = a[i];
//             count++;
//         }
//     }
//     return count;
// }

int within(int a[], int N, int lower, int upper, int result[])
{
    int count = 0;
    if(N-1 < 0){
        return 0;
    }
    count = count + within(a, N-1, lower, upper, result);
    if(a[N-1] >= lower && a[N-1] <= upper){
        result[count] = a[N-1];
        count++;
    }
    return count;
}


int main()
{
    int a[] = {4, 1, 3, 1, 3, 2};
    int result[6] = {0};
    int i, nResult;

    //Try out different bounds

    nResult = within(a, 6, 2, 3, result);
    //nResult = within(a, 6, 1, 4, result);
    //nResult = within(a, 6, 5, 10, result);

    cout << nResult << " data passed the bounds\n";
    for (i = 0; i < nResult; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
