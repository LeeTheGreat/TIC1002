#include <cstdio>
#include <iostream>

using namespace std;

//Sample Selection Sort from lecture
void swap(int a[], int i, int j) 
{
	int temp;

    temp = a[i] ; 
    a[i] = a[j] ; 
    a[j] = temp ;
}

void selectionSort(int a[], int n) 
{
    int i, j, maxIdx, temp;

    for (i = n-1; i >= 1; i--) {
        maxIdx = i;
        for (j = 0; j < i; j++) {
            if (a[j] > a[maxIdx]){
			    maxIdx = j;
            }
        }
        swap(a, maxIdx, i);
    }
}


//Conversion functions from number to individual digits and vice versa
void numberToArray(int number, int array[], int size)
{
    int idx = size-1;

    for (idx = size -1; idx >= 0; idx--){
        array[idx] = number % 10;
        number /= 10;
    }
}

int arrayToNumber(int array[], int size)
{
    int i, number = 0;

    for (i = 0; i < size; i++){
        number = 10*number + array[i];
    }
    return number;
}
/*****************************************************
 * You only need to write the following two functions
 * You are NOT allowed to define additional functions for this task
 ****************************************************/

void reverseSelectionSort(int a[], int n) 
//Sort the array a[] in descending ordeer (large to small)
//  using selection sort approach
{
    int i, j, max, temp;
    for (i = 0; i < n; i++) {
        max = i;
        for (j = i+1; j < n; j++) {
            if (a[j] > a[max]){
			    max = j;
            }
        }
        swap(a, max, i);
    }
}

int kNumber(int N)
//Count how many rounds do we need to perform the k-operation to reach 6174
{
    if(N == 6174){
        return 0;
    }
    int arr[4] = {};
    numberToArray(N, arr, 4);
    reverseSelectionSort(arr, 4);
    int B = arrayToNumber(arr, 4);
    selectionSort(arr, 4);
    int S = arrayToNumber(arr, 4);
    return 1 + kNumber(B - S);
    
}


int main()
{
    int digits[4];

    //The code below show the usage of the number to array conversion funtions.
    //You can commment them off when you start to work on the solution.

    //convert the number 1234 to an array of four individual digits, i.e. {1, 2, 3, 4}
    // numberToArray(1234, digits, 4);

    // for (int i = 0; i < 4; i++){
    //     cout << digits[i] << endl;
    // }

    //convert the digit array, e.g. {1, 2, 3, 4} into a single number, e.g. 1234
    // 1234 is returned as a result of the function
    // cout << arrayToNumber( digits, 4) << endl;


    //Uncomment the following to test your kNumber() function when ready
    cout << kNumber(6174) << endl;
    cout << kNumber(8352) << endl;
    cout << kNumber(9189) << endl;
    cout << kNumber(36) << endl;   
    cout << kNumber(2357) << endl;  //should be 7 rounds

    return 0;
}