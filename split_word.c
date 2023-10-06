//reference:
//https://www.w3resource.com/c-programming-exercises/string/c-string-exercise-31.php

#include <stdio.h>
#include <string.h>

int main(){
    char myStr[] = "This is my computer!";

    int strLength = strlen(myStr);

    printf("length of string: %d\n", strLength);


    //split
    char strSet[10][50];    //an array of 10 slots for each 50 char length string. just randomly assign some space
    int wordCounter = 0;    //go to next word after finish reading all characters of one word
    int charPos = 0;        //As each new word start by char 0 in new position. We need to reset to 0 for each word
    for(int i=0;i<strLength;i++){
        //printf("char: %c, T/F? %d\n", myStr[i], myStr[i] != ' ');
        if(myStr[i] != ' ' && myStr[i] != '\0')
        {
            //reading a word normally, char by char               
            strSet[wordCounter][charPos] = myStr[i];    
            charPos++; 
        }else{
            //if we deal with a space or an ending char \0, we finish the slot and incease the counter 
            //and reset position to 0 in next slot
            //printf("see: %d", myStr[i]);
            strSet[wordCounter][i] = '\0'; //SUPER IMPORTANT: MUST NEED TO ADD '\0' TO EVERY ENDING OF A STRING!!!!
            wordCounter++;
            charPos = 0;
            
        }
    }

    for(int i=0;i<=wordCounter;i++){
        
        printf("word[%d]: %s,length: %ld\n", i, strSet[i], strlen(strSet[i]));
    }
    

    return 0;
}