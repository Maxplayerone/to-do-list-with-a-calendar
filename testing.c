#include<stdio.h>
#include<string.h>


int main(){
   FILE *file = fopen("testing.txt", "a");
   fprintf(file, "\nHi");
   fclose(file);

    return 0;
}