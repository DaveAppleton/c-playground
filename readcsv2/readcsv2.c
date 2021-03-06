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

int getInt(char * line, int pos) {
    int num;
    sscanf(getfield(line, pos),"%d",&num);
    return num;
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
        char name[15];
        char position[15];
        if (count++ == -1) { // ignore headers
            continue;
        }
        printf("line %d\n",count);
        strcpy(name, getfield(line, 1));
        strcpy(position, getfield(line, 2));
        printf("Field 3 would be %s\n", getfield(line, 3));
        num = getInt(line,3);
        printf("num is %d\n",num*3);

        // use above to define a CSV file with employee_name + required data for payroll calc.
        
        
    }
}