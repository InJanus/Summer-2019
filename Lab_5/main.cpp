//main
#include <iostream>
#include "sort.cpp"
using namespace std;

int main(){
    int myitems[] = {1,6,8,3,4,10,2,12,7,30};
    int *mysorteditems = bubbleSort(myitems);
    printItems(mysorteditems);
}