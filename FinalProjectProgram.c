/* This project was only debugged, tested and documented by me, but not coded by me as a part of a pair work for a final project, credits to the original author.

Abstract:
This program is used to calculate the actual efficiency of an assembly line compared to its ideal efficiency. The first part is a sign in screen that is 
for organizing each assembly line. The usernames, passwords, and assembly line details will be stored in txt files (if we can make it work). 
After the user either signs in or creates a new account, they will be prompted to input the details of the assembly line 
(number of processes and ideal time for each process), these will be saved to the txt file (if possible). Next, the user is prompted to input 
the data for the actual current assembly line (amount of items, amount of failed items, and actual time for each process). 
The efficiency percent and failed/successful percent are then outputted for each process and as a whole along with a ranking of each process's efficiency, 
fail percent, and overall time taken.
●	Prompts the user to sign in
●	Collects the ideal processing time for each stage
●	Collects the actual data about the assembly line
●	Calculates what stages are inefficient compared to the ideal conditions 

Introduction:
This program is designed to aid students, especially engineering students to help them calculate the efficiency of an assembly line. 
By also having them to sign-in is a convenient way to add security to the program that we are about to create. 
It will ensure the program that the ones who will use it is an engineer who will compute for their assembly line. 
By just having the user to input their data for the assembly line, they can calculate and predict their progress and efficiency on their project in an instant.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 100

void registerUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char filename[MAX_LENGTH];
    int i = 0, temp;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    
    while (i < MAX_LENGTH) {
		
		temp = getch();
		if(temp == 13){
			
			break;
		} else if (temp == 8 && i > 0) {
			i--;
			printf("\b \b");
		} else if (temp > 31 && temp < 127) {
			printf("*");
			password[i] = temp;
			i++;
		}
	}
	password[i] = '\0';


    sprintf(filename, "%s.txt", username);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\n\nError opening file!\n\n");
        exit(1);
    }

    fprintf(file, "%s\n", password);
    fclose(file);

    printf("\n\nUser registered successfully!\n\n");
}

void enterSavedData(int assemblyLineNum, char username[MAX_LENGTH]) {
	int processes, i, processNum, check2 = 1;
	char filename[MAX_LENGTH];
	float processtime[MAX_LENGTH];
	while (check2 == 1){
		printf("\nNumber of Processes for Assembly Line No.%d (100 or less):\t", assemblyLineNum);
		scanf("%d", &processes);
		if (processes > 100) {
			printf("Number of Processes is Too High");
		} else {
			check2 = 0;
		}
	}
	
	for(i = 0; i < processes; i++) {
		processNum = i + 1;
		printf("\nIdeal Time taken (in seconds) per Item for process No.%d:\t", processNum);
		scanf("%f", &processtime[i]);
	}
	
	sprintf(filename, "%s AL No%d.txt", username, assemblyLineNum);
	
	FILE *file = fopen(filename, "w");
	
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d\n", processes);
    for(i = 0; i < processes; i++) {
    	fprintf(file, "%f\n", processtime[i]);
	}
	fclose(file);
}

void actualTest (int processes, int itemNum, int failedItemNum, float processtime[], float actualTime[]){
	int i, j, temp2;
	float actualTimePerItem[MAX_LENGTH], processEfficiency[MAX_LENGTH], totalEfficiency, totalTime = 0, actualTotalTime = 0, failedPercent;
	float actualTimePerItemTemp[MAX_LENGTH], processEfficiencyTemp[MAX_LENGTH], temp;
	
	for(i = 0; i < processes; i++){
		actualTimePerItem[i] = actualTime[i] / (float)itemNum;
		
		processEfficiency[i] = processtime[i] / actualTimePerItem[i];	
		
		totalTime += processtime[i];
		actualTotalTime += actualTimePerItem[i];
		
		actualTimePerItemTemp[i] = actualTimePerItem[i];
		processEfficiencyTemp[i] = processEfficiency[i];
			
	}
	
	for(i = 0; i < processes-1; i++){
		for(j = 0; j < processes-i-1; j++){
			if(actualTimePerItemTemp[j] > actualTimePerItemTemp[j+1]){
				temp = actualTimePerItemTemp[j];
				actualTimePerItemTemp[j] = actualTimePerItemTemp[j+1];
				actualTimePerItemTemp[j+1] = temp;
			}
		}
	}
	
	for(i = 0; i < processes; i++){
		for(j = 0; j < processes-i-1; j++){
			if(processEfficiencyTemp[j] < processEfficiencyTemp[j+1]){
				temp = processEfficiencyTemp[j];
				processEfficiencyTemp[j] = processEfficiencyTemp[j+1];
				processEfficiencyTemp[j+1] = temp;
			}
		}
	}
	
	temp = 0;
	
	
	
	totalEfficiency = totalTime / actualTotalTime;
	
	failedPercent = (float) failedItemNum / (float)itemNum;
	
	printf("\nThe Total Efficiency Percent is %f%%", totalEfficiency*100);
	printf("\nThe Total Failed Item Percent is %f%%", failedPercent*100);
	printf("\n\nThe Actual Time Taken per Item (in Seconds) Ranked are:\t");
	
	for(i = 0; i < processes; i++) {
		for(j = 0; j < processes; j++) {
			if (actualTimePerItemTemp[i] == actualTimePerItem[j]){
				temp2 = j + 1;
				actualTimePerItem[j] = -1;		//To prevent errors when there are multiple processEfficiencies with the same time
				break;
			}
		}
		printf("\nRank %d: Process No. %d at %f seconds per Item", i+1, temp2, actualTimePerItemTemp[i]);
	}
	
	printf("\n\nThe Efficiency per Item Ranked are:\t");
	for(i = 0; i < processes; i++) {
		for(j = 0; j < processes; j++) {
			if (processEfficiencyTemp[i] == processEfficiency[j]){
				temp2 = j + 1;
				processEfficiency[j] = -1;		//To prevent errors when there are multiple processEfficiencies with the same time
				break;
				
			}
		}
		printf("\nRank %d: Process No. %d at %f%%", i+1, temp2, processEfficiencyTemp[i] * 100);
	}
}

int main() {
    int n, check, i = 0, temp;
    int cont = 1;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char storedPassword[MAX_LENGTH];
    char filename[MAX_LENGTH];

    while (cont == 1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                registerUser();
                break;
            case 2:
	
	    		printf("Enter username: ");
	    		scanf("%s", username);
	    		printf("Enter password: ");
	    		
	    		while (i < MAX_LENGTH) {
		
					temp = getch();
					if(temp == 13){
			
						break;
					} else if (temp == 8 && i > 0) {
						i--;
						printf("\b \b");
					} else if (temp > 31 && temp < 127) {
						printf("*");
						password[i] = temp;
						i++;
					}
				}
				password[i] = '\0';
			
	    		sprintf(filename, "%s.txt", username);
		
    			FILE *file = fopen(filename, "r");
    			if (file == NULL) {
    			    printf("Invalid username or password.\n");
    			    return 0;
    			}
	
	    		fscanf(file, "%s", storedPassword);
	    		fclose(file);

	    		if (strcmp(password, storedPassword) == 0) {
	    		    check = 1;  // Login successful
	    		} else {
	    		    check = 0;  // Login failed
	    		}
                
				
				if (check == 1) {
                    printf("\nLogin successful!\n");
                    cont = 2;
                } else {
                    printf("\nInvalid username or password.\n");
                }
                
                break;
            case 3:
                exit(0);
            default:
                printf("Please Enter a Valid Input\n");
                getchar();
                getchar();
        }
    }
    
    int assemblyLineNum;
    
    float processtime[MAX_LENGTH], actualTime[MAX_LENGTH];
    int processes, j, itemNum, failedItemNum;
    
    
    cont = 1;
    
    while (cont == 1) {
    	printf("\n1. Alter or Create a new Assembly line's Ideal Conditions");
    	printf("\n2. Test Ideal Conditions of an Assembly Line against Actual Conditions\n");
    	scanf("%d", &n);
    
    	switch(n){
    		case 1:
    			printf("\nWhat assembly line do you want to create or alter? (has to be an integer)\t");
				scanf("%d", &assemblyLineNum);
    			enterSavedData(assemblyLineNum, username);
    			break;
    		case 2:
    			printf("\nWhat assembly line do you want to compare the ideal conditions of to?\t");
    			scanf("%d", &assemblyLineNum);
    			
    			sprintf(filename, "%s AL No%d.txt", username, assemblyLineNum);
		
    			FILE *file = fopen(filename, "r");
    			
    			if (file == NULL) {
    			    printf("Invalid Assembly Line\n");
    			    break;
    			}
    			
    			fscanf(file, "%d", &processes);
    			printf("Ideal Process Amount:	%d\n", processes);
    			
    			for (j = 0; j < processes; j++) {
                    fscanf(file, "%f", &processtime[j]);
                    printf("The Ideal Speed of Process No. %d is:    %f\n", j + 1, processtime[j]);
                }
    			
				fclose(file);
				
				printf("Enter the Current Data you want to test\nEnter The Number of Items Entering the Assembly Line:\t");
				scanf("%d", &itemNum);
				printf("\nEnter The Total Number of Failed Items:\t");
				scanf("%d", &failedItemNum);
				
				printf("test");
				
				for(j = 0; j < processes; j++){
					printf("\nEnter The Total Time Taken for Process %d:\t", j+1);
					scanf("%f", &actualTime[j]);
				}
				
				
				getchar();
				
				actualTest (processes, itemNum, failedItemNum, processtime, actualTime);
    			break;
		}
	}
    
    
    
    

    return 0;
}
