#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://ideone.com/l23He
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c
// https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm

const char* getfield(char* line, int num)
{
    char* tmp = strdup(line);
    const char* tok;
    for (tok = strtok(tmp, ",");       // assign tok to a function to get the next string
            tok && *tok;               // if function returned a value, call function again ???
            tok = strtok(NULL, ",\n")) // end if we overflow the line
    {
        if (!--num){
            free(tmp);
            return tok;
        }
    }
    free(tmp);
    return NULL;
}

int main(void)
{
    int count = -1;
    printf("Hello\n");
    FILE* stream = fopen("input", "r");

   if (stream == NULL) {
       printf("File cannot be opened\n");
       return 1;
   }

    int num;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if (count++ == -1) {
            continue;
        }
        printf("line %d\n",count);
        printf("Field 1 would be %s\n", getfield(line, 1));
        printf("Field 2 would be %s\n", getfield(line, 2));
        printf("Field 3 would be %s\n", getfield(line, 3));
        sscanf(getfield(line, 3),"%d",&num);
        printf("num is %d\n",num);
        
        
    }
}