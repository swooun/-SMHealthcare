//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH)
   {
   	char str[50];
   	int n = 50;
   	
    FILE *file = fopen(EXERCISEFILEPATH, "r");  
    if (file == NULL) 
	{
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s %d", &exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned_per_minute)) 
	{
    	exercise_list_size++;
    	// exercise 목록이 없어도 출력되는 오류 수정 (week11참고) 
        if (exercise_list_size >= MAX_EXERCISES || fgets(str, n, file) == NULL)
		{
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i, calories_burned;
  
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    printf("0. exit\n");
    for(i=0;i<exercise_list_size;i++)
    {
    	printf("%d. %s - %d\n", i+1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);
	}

    // ToCode: to enter the exercise to be chosen with exit option
    printf("choose(0-%d): ", exercise_list_size);
    scanf("%d", &choice);        //입력받은 값을 choice에 할당  
    
    //운동 번호가 아닌 값 예외 처리  
    	if (choice == 0)
	{
		return;
	}
    if (choice < 1 || choice > exercise_list_size)
    {
    	printf("[Error] Invalid option. \n");
        printf("Please try again! \n");
        
        return;
	}
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    calories_burned = exercise_list[choice - 1].calories_burned_per_minute * duration;
    //history에 출력되지 않는 오류 수정, 문자열이라 그런지 =으로 안되길래 strcpy 처리 (week11) 
    strcpy(health_data->exercises[health_data->exercise_count].exercise_name, exercise_list[choice-1].exercise_name);
    health_data->exercises[health_data->exercise_count].calories_burned_per_minute = exercise_list[choice-1].calories_burned_per_minute;
    health_data->total_calories_burned += calories_burned;
    health_data->exercise_count++; 
   

}
