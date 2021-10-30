/* 
 * Quicksort.cpp
 * Implementation of quicksort on integer arrays in C++
 * Author: Rob Pitkin, 2021
 * Implementation inspired by Introduction to Algorithms, Chapter 8
 */
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int partition(int* array, int p, int r)
{
    int x = array[p];
    int i = p - 1;
    int j = r + 1;
    while (true)
    {
        do 
        {
            j = j - 1;
        } 
        while(array[j] > x);
        
        do 
        {
            i += 1;
        } 
        while(array[i] < x);
        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j]; 
            array[j] = temp;
        }
        else
        {
            return j;
        }
    }
}

void quicksort(int* array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quicksort(array, p, q);
        quicksort(array, q+1, r);
    }
}

int main(int argc, char const *argv[]) {
    int* arr = new int[10];
    arr[0] = 9;
    arr[1] = 2;
    arr[2] = 13;
    arr[3] = 5;
    arr[4] = 6;
    arr[5] = 4;
    arr[6] = 29;
    arr[7] = 74;
    arr[8] = 3;
    arr[9] = 1;
    cout << "array: [";
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "]" << endl;
    quicksort(arr, 0, 9);
    cout << "array: [";
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "]" << endl;
    delete[] arr;
    return 0;
}