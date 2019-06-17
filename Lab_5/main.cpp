//main
#include <iostream>
#include ".\\sort\sort.h"
using namespace std;

int main(){
    int myitems[100];
    randomGenerate(myitems);
    // int *mysorteditems = bubbleSort(myitems);
    cout << mysize(myitems) << endl;
    printItems(myitems);
}