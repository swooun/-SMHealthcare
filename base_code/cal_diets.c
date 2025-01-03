//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) 
{
    char str[50];
    int n = 50;
    	
    FILE *file = fopen(DIETFILEPATH, "r");  
    if (file == NULL) 
	{
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", &diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake)) 
	{
    	diet_list_size++;
    	//loadexercises랑 동일한 오류 수정  
        if (diet_list_size >= MAX_DIETS || fgets(str, n, file) == NULL)
		{
        	break;
		}
    }
    
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) 
{
    int choice, i;
	
    // ToCode: to enter the selected diet in the health data
    printf("The list of diets:\n");
    printf("0. exit\n");            //exit 옵션 
	for(i=0;i<diet_list_size;i++)
	{
		printf("%d. %s - %d\n", i+1, diet_list[i].food_name, diet_list[i].calories_intake);
	}
	printf("choose(0-%d): ", diet_list_size);
	scanf("%d", &choice); 
	
	// ToCode: to enter the diet to be chosen with exit option
	if (choice == 0)
	{
		return;
	}
	
	// 식단 번호 이외의 choice 예외 처리  
    if (choice < 1 || choice > diet_list_size)
    {
    	printf("[Error] Invalid option. \n");
        printf("Please try again! \n");
        
        return;
    }
	
    //exercise 와 동일
	strcpy(health_data->diet[health_data->diet_count].food_name, diet_list[choice-1].food_name); 
	health_data->diet[health_data->diet_count].calories_intake = diet_list[choice-1].calories_intake;

    health_data->diet_count++;
    // ToCode: to enter the total calories intake in the health data
    health_data->total_calories_intake += diet_list[choice-1].calories_intake;


}

