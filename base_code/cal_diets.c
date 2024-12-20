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
    FILE *file = fopen(DIETFILEPATH, "r");  
    if (file == NULL) 
	{
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while () 
	{
    	diet_list_size++;
        if (diet_list_size >= MAX_DIETS)
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
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n"); 
    loadDiets("DIETFILEPATH");                         //����� ��� �ĺ� ���  
    printf("Enter the food you ate: ");      
    scanf("%s", &choice);                           //�Ļ� �ɼǿ��� ������ �Ĵ���  choice�� �Ҵ� 
    
	// ToCode: to enter the diet to be chosen with exit option
	
    

    // ToCode: to enter the selected diet in the health data
    printf("Enter the number you ate: ");
    scanf("%d", &choice);
    

    // ToCode: to enter the total calories intake in the health data
    health_data->total_calories_intake += diet_list[choice-1].calories_intake;


}
