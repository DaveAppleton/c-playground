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
    printf("What is your file name : ");
    char filename[40];
    scanf("%s",filename);
    FILE* stream = fopen(filename, "r"); //"final_input.csv", "r");

   if (stream == NULL) {
       printf("File cannot be opened\n");
       return 1;
   }

    
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char name[15];
        char position[15];
        int n_rate,we_rate,ph_rate, n_hours,we_hours,ph_hours; // for calculations
        if (count++ == -1) { // ignore headers
            continue;
        }
        strcpy(name, getfield(line, 1));
        strcpy(position, getfield(line, 2));
        n_rate = getInt(line,3);
        we_rate = getInt(line,4);
        ph_rate = getInt(line,5);
        n_hours = getInt(line,6);
        we_hours = getInt(line,6);
        ph_hours = getInt(line,7);

        int pay = n_rate * n_hours + we_rate * we_hours + ph_rate * ph_hours;

        printf("%s (%s) earned %d\n",name,position,pay);
        // use above to define a CSV file with employee_name + required data for payroll calc.
        
        
    }
}