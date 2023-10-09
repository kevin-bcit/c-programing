/**
Assignment 1
Names, BCIT-IDs
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
Validate whether the word can put in a line. Return:
    integer: Number of word we can put into a line
    0: even the first word cannot fulfill the requirement. Case of error

consideration:
- Case of words in 10th spot is continue (regular case) 
- Case of words exactly end in 10th spot
- Case of a word is longer than 10th spot 
*/
int validateCharPerLine(char **wordArr, int wordPerLine){

    return 0;
}

/**
Use the word to create a line of sentence. Put into the result array (by pointer?)
Add more space to justified the line by round robin:

- Mechanism to calculate total spaces in a line 
- Know how many spaces need to add 
- Add space evenly after each word to make every line exactly 10 characters (if character per line is much longer, e.g. 50, we need to add space until a line is 50 character long) 
*/
void addWordsToLineJustified(char *words){

}

/**
Also create a line of sentence but with single word only. Require
- Centralize a word if it is single: 
- Calculate space need to add in left or right margin 
- Function to add space to left and right side 
*/
void addSingleWordCentered(char word){

}

int main(int argc, char *argv[])
{
    //1. read the argument of number per line
    //2. read txt file (assume one line only) 
    //3. Split sentence input into words-array by space or after hypen
    //4. Create a temporary array to hold the result (10 characters per line) 

    //loop if there is word in words-array
    //validateCharPerLine();

    //Either return "number of word" per line or error. If error, break the loop, show msg and stop
    
    //remove the number of words from the words-array and:
    
    //call addWordsToLineJustified() if return is > 1

    //call addSingleWordCentered if return = 1
    //end loop


    //handle error
    

    return 0;

}