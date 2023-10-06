#include <stdio.h>
#include <string.h>

int main(){
    char myStr[] = "This is my computer!";

    int strLength = strlen(myStr);

    printf("length of string: %d\n", strLength);


    //split
    char strSet[10][50];    //just random assign some space first
    int wordCounter = 0;
    int charPos = 0;        //reset position to 0 for next word
    for(int i=0;i<strLength;i++){
        //printf("char: %c, T/F? %d\n", myStr[i], myStr[i] != ' ');
        if(myStr[i] != ' ' && myStr[i] != '\0')
        {               
            strSet[wordCounter][charPos] = myStr[i];    
            charPos++; 
        }else{
            //printf("see: %d", myStr[i]);
            strSet[wordCounter][i] = '\0';
            wordCounter++;
            charPos = 0;
            
        }
    }

    for(int i=0;i<=wordCounter;i++){
        
        printf("word[%d]: %s,length: %ld\n", i, strSet[i], strlen(strSet[i]));
    }
    

    return 0;
}