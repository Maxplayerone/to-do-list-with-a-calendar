#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void DisplayCalendar();
void CreateCalendarDay(int, char[]);
int GetMonth();
void TaskHandlerer();

int main(){
    DisplayCalendar();
    TaskHandlerer();
    return 0;
}

void DisplayCalendar(){
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
                char currentDay[3];
                CreateCalendarDay(dayCount, currentDay);      
                printf("|%s | ", currentDay);
                dayCount++;
            }
        }
        printf("\n");
    }
    
}

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

int GetMonth(){

    return 7;

}

void TaskHandlerer(){
    printf("\n-----------------\n");
    printf("What task do you want to add?\n");
    char userTask[100];
    fgets(userTask, sizeof userTask, stdin);
    //printf("Your task is: \n %s", userTask);
    char day[3];
    printf("When's the deadline? (number of the day)\n");
    scanf("%s", &day);
    //printf("The deadline is on day %s\n", day);

    //TODO: CREATE A FILE THAT CONTAINS TASKS SEPARATED BY MONTHS AND DAYS
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
    //printf("The current month is %s\n", currentMonth); //works fine

    FILE *file = fopen("tasksList.txt", "r");
    if(!file){
        printf("Couldn't open the file %s\n", file);
        exit(1);
    }
    char line[100];
    //TODO: THE PROGRAM READS ONLY ONE LINE
    while(fscanf(file, "%[^\n]", line)){
        printf("%s\n", line);  
        if(!strcmp(currentMonth, line)){
            printf("We found the month %s\n", line);
            break;
        } 
    } 
    
    //TODO: RETURN THE DEADLINE AND CHANGE THE ICON IN THE CALENDAR
}