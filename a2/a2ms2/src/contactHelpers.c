/*
 ============================================================================
 Name        : contactsHelper.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 15th, 2019 - Assignment 2 - Milestone 2
 ============================================================================
 */

/*
 ============================================================================
 Description : contact system helper functions
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"


// pause program and wait for enter to be pressed
void pause(void){
	printf("(Press Enter to Continue)");
	while (getchar() != '\n') ;
}

// clear input buffer
void clearBuffer(void){
	while (getchar() != '\n')  ;
}

// validate a positive number
void valPos(int *num, char text[]){
	while(*num < 1){	// ensure that user has entered a positive number
		printf("*** INVALID %s NUMBER *** <must be a positive number>: ", text);
		scanf("%d", num);
	}
	return;
}

// get a valid integer without characters or any other garbage input
int getInt(void){
	int res;
	int valid = -1;
	int num;
	char nl;

	do{
		scanf(" %d%c", &num, &nl);
		if (nl == '\n'){
			res = num;
			valid = 1;
		} else {
			clearBuffer();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (valid < 0);

	//printf ("%d", res);

	return res;
}

// return an integer within the range of the parameters min and max
int getIntInRange(int min, int max){
	int res;
	int valid = -1;

	do {
		int num = getInt();

		if (num >= min && num <= max){
			res = num;
			valid = 1;
		} else {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (valid < 0);

	return res;  // return integer within range min - max
}

// returns 1 when user enters y & Y or return 0 for n & N validates entry
int yes(void){
	int res = -1;
	char choice;
	char nl;

	do {   		// validate that user enters (y or n) or (Y or N)
		scanf("%c%c", &choice, &nl);
		if (nl == '\n') {
			if (choice == 'n' || choice == 'N'){
				res = 0;
			} else if (choice == 'y' || choice == 'Y'){
				res = 1;
			}
		} else {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");//Invalid characters
			clearBuffer();
		}
	} while (res < 0);


	return res; // 1 for true/yY 0 for false/Nn
}

// main menu of application
int menu(void){

	int res;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");

	printf("Select an option:> ");
	res = getIntInRange(0, 6);

	return res;
}

// main program functionality
void contactManagerSystem(void){
	int choice;
	int exit = 0;
	do {
		choice = menu();
		switch(choice){

		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();

			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();

			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();

			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();

			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();

			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();

			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			if (yes()){
				exit = 1;
				printf("\nContact Management System: terminated\n");
			} else {
				printf("\n");
			}

			break;
		}
	} while (exit == 0);

	return;
}
