#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void DisplayCalendar(int[]);
int GetMonth();
int* TaskHandlerer();

int main(){
    do{     
        int* temp;
        
        DisplayCalendar(temp);
        temp = TaskHandlerer();

        char buffer[5];
        printf("Do you want to quit? (quit)\n");
        scanf("%s", buffer);
        if(!strcmp(buffer, "quit")) return 0;
    }while(true);
    return 0;
}

void DisplayCalendar(int daysWithTasks[]){
   //printf("\n\nTesting!!!\nDay with a task: %d\n\n\n", );

    int month = GetMonth();
    double numOfDays = 0;
    if(month <= 7){
        if(month  != (month/2) * 2){
            numOfDays = 31;
        }else{
            numOfDays = 30;
        }
    }else{
        if(month == (month/2) * 2){
            numOfDays = 31;
        }else{
            numOfDays = 30;
        }
    }
    int dayCount = 1;
    int numOfRows = ceil(numOfDays / 7);
    char nameOfMonth[12][10] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}}; 

    printf("-----------------Calendar-----------------\n");    
    printf("--------------for %s 2022------------\n", nameOfMonth[month -1]);
    printf("|Mon| |Tue| |Wed| |Thu| |Fri| |Sat| |Sun|\n");
    for(int i = 0; i < numOfRows; i++){
        for(int j=0; j < 7; j++){
            if(dayCount <= numOfDays){       
                if(daysWithTasks != 0){              
                    int i = 0;
                    while (daysWithTasks[i] != 0){
                        if(daysWithTasks[i] == dayCount){
                            printf("|%d*| ", dayCount);
                        }else{
                            if(dayCount >= 10){
                                printf("|%d | ", dayCount);
                            }else{
                                printf("|%d  | ", dayCount);
                            }
                        }
                        i++;
                        dayCount++;
                    }
                }
                //basically the first time you open the program and you don't have any tasks
                else{             
                    if(dayCount >= 10){
                                printf("|%d | ", dayCount);
                    }else{
                        printf("|%d  | ", dayCount);
                    }
                    dayCount++;
                }
            }
        }
        printf("\n");
    }
    
}
//I realised that I'm a morron and I don't need it, but I would still like to have this code
/*
void CreateCalendarDay(int dayCount, char dayString[]){
        char dayFirstDigit[3];
        char daySecondDigit[2];

        //making a string from the numbers of the days
        sprintf(dayFirstDigit, "%d", dayCount / 10);
        sprintf(daySecondDigit, "%d", dayCount % 10);
        strcat(dayFirstDigit, daySecondDigit);

        //printf("The day is %s\n", dayFirstDigit);
        //printf("The size of the dayFirstDigit variable %d\n", sizeof(dayFirstDigit));
        sprintf(dayString, dayFirstDigit);       
}
*/

int GetMonth(){
    return 7;
}

int* TaskHandlerer(){
    int* daysWithTasks = malloc(100 * sizeof(int));
    int i = 0;

    while(true){ 
        printf("\n-----------------\n");
        printf("What task do you want to add?\n");
        //weird bug where fgets() doesn't work
        char userTask[99];
        char temp[100];
        scanf("%c", &temp);
        fgets(userTask, sizeof userTask, stdin);
        strcat(temp, userTask);
        int day;
        printf("When's the deadline? (number of the day)\n");
        scanf("%d", &day);
        if(day > 31){
            printf("You pick a day that doesn't exist!");
            exit(1);
        }
        daysWithTasks[i] = day;

        int currentMonthInt = GetMonth();
        char currentMonth[10] = {0};
        switch(currentMonthInt){
            case 1:
                strcat(currentMonth, "JANUARY");
                break;
            case 2:
                strcat(currentMonth, "FEBRUARY");
                break;
            case 3:
                strcat(currentMonth, "MARCH");
                break;
            case 4:
                strcat(currentMonth, "APRIL");
                break;
            case 5:
                strcat(currentMonth, "MAY");
                break;
            case 6:
                strcat(currentMonth, "JUNE");
                break;
            case 7:
                strcat(currentMonth, "JULY");
                break;
            case 8:
                strcat(currentMonth, "AUGUST");;
                break;
            case 9:
                strcat(currentMonth, "SEPTEMBER");
                break;
            case 10:
                strcat(currentMonth, "OCTOBER");
                break;
            case 11:
                strcat(currentMonth, "NOVEMBER");
                break;
            case 12:
                strcat(currentMonth, "DECEMBER");
                break;
        }

        FILE *file = fopen("tasksList.txt", "a");
        if(!file){
            printf("Couldn't open the file %s\n", file);
            exit(1);
        }
        
        fprintf(file, "%s", userTask); 
        /*
        char line[10];
        while(fgets(line, sizeof line, file)){
            line[strcspn(line, "\n")] = 0;

            if(!strcmp(currentMonth, line)){
                //TODO: CAN'T PUT ANY MESSAGE TO THE FILE
                printf("We found the month %s\n", line);
            }   
        } 
        */
        fclose(file);

        char response[4];
        printf("Do you want to add another task? (yes, no)\n");
        scanf("%s", &response);
        if(!strcmp(response, "yes")){
            i++;
            continue;
        } 
        else{
            //printf("The array in function: %d\n", daysWithTasks[0]);
            //printf("The array in function: %d\n", daysWithTasks[1]);
            return daysWithTasks;
        } 
    }
}
