#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Store all the words in the wordList array line by line
 * wordList - The list of words for the current line (pointer to array of pointers)
 * charsPerLine - The exact number of characters the line should have
 * wordCount - The number of words for the current line
 * charCount - The number of characters from the words for the current line
 */
const char *storeLine(char **wordList, int charsPerLine, int wordCount, int charCount) {
    char result[charsPerLine];
    char *ptresult = result;

    //find the spaces neeed by length of a line minus number of words
    int spaces = charsPerLine - charCount;
    
    if (wordCount == 1) {
        //case if word is single, we center it
        // spaces to the left of the word
        // If the number of spaces is odd, add one extra space here
        
        for(int i=0;i < ((spaces/2) + (spaces%2));i++){
            strcat(result, " ");
        }
        
        //printf("%s", wordList[0]);
        strcat(result, wordList[0]);
        for(int i=0;i < (spaces/2);i++){
            strcat(result, " ");
        }

        
    } else { 
        
        //divide the space equally and find out the minimum number of space between each words
        //find the reminder for case of uneven distribute, add from first position until n-1 pos
        
        int avgSpaceBetweenWords = spaces/(wordCount-1);
        int reminderSpace = spaces%(wordCount-1);

        //printf("wordcount: %d, spaces: %d, avgSpaceBetweenWords: %d, reminderSpace: %d\n", wordCount, spaces, avgSpaceBetweenWords, reminderSpace);

        for (int i = 0; i < wordCount; i++) {
            if (i > 0){
                for(int j = 0; j < avgSpaceBetweenWords;j++ ){
                    //add the minimun spaces                
                    strcat(result, " ");
                }

                if(reminderSpace > 0){
                    //add the reminding 1 space, from left to right
                    //printf("reminderSpace: %d\n", reminderSpace);
                    strcat(result, " ");
                    reminderSpace--;
                }
            }
            //printf("%s\n", wordList[i]);
            strcat(result, wordList[i]);
        }
    }
    
    return ptresult;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <characters_per_line> <input_file>\n", argv[0]);
        return 1;
    }

    int charsPerLine = atoi(argv[1]);
    char *inputFileName = argv[2];
    
    FILE *file = fopen(inputFileName, "r");
    if (file == NULL) {
        printf("Error opening input file");
        return 1;
    }

    char inputChar;
    char *inputWord = (char*)malloc(1000);
    char **wordList;
    char **finalOutput;
    int words = 2000;
    int wordCount = 0; 
    int charCount = 0;
    int currentCharCount = 0;
    int setForceNewLine = 0;
    int forceNewline = 0;
    int outputCount = 0;

    wordList = malloc(words * sizeof(char *)); 
    finalOutput = malloc(words * sizeof(char *));

    while ((inputChar = fgetc(file)) != EOF) {
        
        if (inputChar == '-') {
            // A hyphen ends the current line

            inputWord[currentCharCount++] = inputChar;
            inputWord[currentCharCount] = '\0'; // null terminator
        
            // Indicate next word should be on a new line
            setForceNewLine = 1;
        } else if (inputChar != ' ' && inputChar != '\n' && inputChar != '\r') {
            //if the word is not ending, continue the while loop until getting the whole word
            inputWord[currentCharCount++] = inputChar;
            continue;
        } else {
            // Situation of space

            inputWord[currentCharCount] = '\0'; // add the end of the string
            
        }
        // reset the current counter for each word (start by 0)
        currentCharCount = 0;
        
        int inputWordLength = strlen(inputWord);
        //printf("inputWordLength %d\n", inputWordLength);
        if ((inputWordLength > charsPerLine) || inputWordLength == 0) {
            //All error show from here
            //Error will always show before any resulting string
            //End program immidiately
            printf("Error. The word processor can't display the output\n");
            return 1;
        }

        // If the current word can't fit in the current line, or a new line is forced, 
        // Compare characters per line with the sum of:
        // - number of characters from words for the current line
        // - number of spaces for the current line (number of words - 1)
        // - the length of the new word + 1 to include its space

        //printf("forceNewline %d, charCount: %d, inputWordLength: %d, wordCount: %d\n", forceNewline, charCount,inputWordLength, wordCount); //k
        if (forceNewline || charCount + (inputWordLength+1) + (wordCount-1) > charsPerLine) {
            // Reset forceNewLine to false
            forceNewline = 0;

            finalOutput[outputCount] = malloc( 1000 * sizeof(char));    //charsPerLine
            strcpy(finalOutput[outputCount], storeLine(wordList, charsPerLine, wordCount, charCount));
            // Increase output line counter
            //printf("o: %d, output: %s\n",outputCount, finalOutput[outputCount]);
            outputCount++;
            
            // Reset character and word counts for current line
            charCount = 0;
            wordCount = 0;
        }


        
        wordList[wordCount] = malloc(inputWordLength * sizeof(char));
        // Add input word to wordList then increment the word count
        strcpy(wordList[wordCount++], inputWord);
        // Increment the character count by the length of the input word
        charCount += inputWordLength;
        
        if (setForceNewLine) {
            forceNewline = 1;
            setForceNewLine = 0;
        }
    }

    // Print out any remaining words in the word list
    finalOutput[outputCount] = malloc( 1000 * sizeof(char));
    strcpy(finalOutput[outputCount], storeLine(wordList, charsPerLine, wordCount, charCount));
    outputCount++;

    //print the final output if no error (didn't return 1) 
    for(int i=0;i<outputCount;i++){
        
        printf("%s\n", finalOutput[i]);
    }
    

    

    //free all the allocated memory
    for(int i=0; i < outputCount; i++){
        free(finalOutput[i]);
    }
    free(finalOutput); 
    
    for(int i=0;i < wordCount; i++){
        free(wordList[i]);
    }
    free(wordList); 

    free(inputWord);
     

    char *ANum = "A01346537_A01341525"; // A numbers of everyone. AXXXX_AXXXX_AXXX format.

    FILE *outputFile = fopen(ANum, "w");

    if (outputFile == NULL) {
         printf("Failed to create the output file.\n");
         return 1;
    }

    fclose(outputFile);

    return 0;
}

