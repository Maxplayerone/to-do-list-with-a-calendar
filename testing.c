#include<stdio.h>
#include<string.h>

void Add(int count, char localVariable[]){
    localVariable[0] = 'W';
    localVariable[1] = 'W';

}


int main(){
    char localVariable[4];
    for(int i = 0; i < 20; i++){
        Add(i, localVariable);
    }
    printf("Local variable is %s", localVariable);

    return 0;
}