//example of how to move pointer to point another position in an array
//https://stackoverflow.com/questions/64218020/move-pointer-in-arrays-with-c
#include <stdio.h>

int main(){
    
    int LENGTH = 50;
    int arr[LENGTH];

    for(int i=0;i<LENGTH;i++){arr[i]=i;}    //just put numbers 1 to 50 into the array

    int*p;
    p = &arr[0];    //initially point to zero
    printf("pointing b4: %d\n",*p);
    

    p+=25;  //try to point different position by increase

    printf("pointing new pos: %d\n",*p);

    p-=15;  //try to point different position

    printf("pointing another new pos: %d\n",*p);
    return 0;
}