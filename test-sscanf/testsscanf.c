#include<stdio.h>
#include <string.h>


int main() {
    char line[1024];
    char part1[25],part2[25],part3[25],part4[25];
    int num;
    strcpy(line,"hello how are 356\n");
    sscanf(line,"%s %s %s %s\n",part1,part2,part3,part4);
    printf("* %s\n* %s\n* %s\n* %s\n",part1,part2,part3,part4);
    sscanf(part4,"%d",&num);
    printf("%d\n",num* 2);



}