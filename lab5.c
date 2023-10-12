/**
 * Lab4
 * Name: Oy Kwan Kevin Ng
 * BCIT-id: A01341525
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int WORD_SIZE = 200;

void reverseString(char **words, int wordCounter){
    //do reverse for each character
    for(int i = 0;i< wordCounter;i++){
        printf("%s", *(words + i));
        
    }
}


int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s <input_file> <out_putfile>\n", argv[0]);
        return 1;
    }

    //get inputfile, output file and the require sec
    char *inputFile = argv[1];
    char *outputFile = argv[2];
    //int numSec = atoi(argv[3]);


    char **words = (char **)malloc(WORD_SIZE * sizeof(char *));
    for(int i = 0; i < WORD_SIZE; i++){
        *(words + i) = (char *)malloc(WORD_SIZE * sizeof(char));
    }

    //char *words = (char *)malloc(WORD_SIZE * sizeof(char));


    //open input file
    FILE *file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    char inputLine[1000];
    int wordCounter = 0;

    while((fgets(inputLine, sizeof inputLine, file) != NULL)){
        //printf("%d: %s\n",wordCounter, inputLine);

        strcpy(*(words + wordCounter), inputLine);
        //printf("%d: %s\n",wordCounter, *(words + wordCounter)); 
        wordCounter++;
    }


    // printf("%d\n",wordCounter);
    // for(int i = 0;i< wordCounter;i++){
    //     //printf("%s", *(words + i));
    //     reverseString(&(words[i]));
    // }

    reverseString(words, wordCounter);
}