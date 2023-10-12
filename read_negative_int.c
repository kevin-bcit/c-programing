//https://www.geeksforgeeks.org/relational-database-from-csv-files-in-c/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char *file_name = "input.txt";
    FILE *file = fopen(file_name, "r");

    char numArr[100];
    int counter = 0;

    const char s[2] = ",";
    char *token;
    
    char line[20];
    while(fgets(line, sizeof line, file) != NULL)
    {
        //printf("current line from the file: %s", line);
        token = strtok(line, s);
        while(token !=NULL){
            //printf("(char: %s, int: %d)\n", token, atoi(token));
            numArr[counter] = atoi(token);

            token = strtok(NULL, s);
            counter++;
        }           
        
    }

    //print out the items from numArr:
    for(int i=0;i < counter;i++){
        printf("%d\n", numArr[i]);
    }

    //test to add the numbers we just get
    printf("sum: %d + %d = %d\n", numArr[0], numArr[1],numArr[0] + numArr[1]);


    fclose(file);
    return 0;
}