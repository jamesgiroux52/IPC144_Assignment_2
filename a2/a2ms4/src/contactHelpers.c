/*
 ============================================================================
 Name        : contactsHelper.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 18th, 2019 - Assignment 2 - Milestone 4
 ============================================================================
 */

/*
 ============================================================================
 Description : Contact Management System - helper functions code
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

// main program functionality
void contactManagerSystem(void){
	int choice;
	int exit = 0;

	struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } },
			{
					{ "Maggie", "R.", "Greene" },
					{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
					{ "9051112222", "9052223333", "9053334444" } },
					{
							{ "Morgan", "A.", "Jones" },
							{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
							{ "7051112222", "7052223333", "7053334444" } },
							{
									{ "Sasha", {'\0'}, "Williams" },
									{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
									{ "9052223333", "9052223333", "9054445555" } },
									{
									}
	};

	// Main program execution
	do {
		choice = menu();

		switch(choice){

		case 1:
			// display contacts information
			displayContacts(contacts, MAXCONTACTS);
			pause();

			printf("\n");
			break;
		case 2:
			// add a contact if there is space in array
			printf("\n");
			addContact(contacts, MAXCONTACTS);

			pause();

			printf("\n");
			break;
		case 3:
			// update a contact
			printf("\n");
			updateContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();

			printf("\n");
			break;
		case 4:
			// delete a contact
			printf("\n");
			deleteContact(contacts, MAXCONTACTS);

			pause();

			printf("\n");
			break;
		case 5:
			// search for a contact
			printf("\n");
			searchContacts(contacts, MAXCONTACTS);
			pause();

			printf("\n");
			break;
		case 6:

			printf("\n");
			// fully functional sort algorithm based on cell number
			sortContacts(contacts, MAXCONTACTS);

			pause();

			printf("\n");
			break;
		case 0:
			// exit program
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


// pause program and wait for enter to be pressed
void pause(void){
	printf("(Press Enter to continue)");
	while (getchar() != '\n') ;
}

// clear input buffer
void clearBuffer(void){
	while (getchar() != '\n')  ;
}

// validate a positive number
void valPos(int *num, const char text[]){

	while(*num < 1){	// ensure that user has entered a positive number
		printf("*** INVALID %s NUMBER *** <must be a positive number>: ", text);
		*num = getInt();
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
		}
		if (res == -1) {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");//Invalid characters
			clearBuffer();
		}
	} while (res < 0);


	return res; // 1 true for y and Y, 0 false for n or N
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



// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------

void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i;
	int digitCount = 0;
	char telNum[11];

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearBuffer();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10){
			for (i = 0; i < 10; i++){
				if (telNum[i] >= '0' && telNum[i] <= '9'){
					digitCount += 1;
				}
			}
		}

		if (digitCount == 10){ // if all 10 characters are digits then phoneNum = valid number
			needInput = 0;
			strcpy(phoneNum, telNum); // copy telNum into parameter variable
		} else {
			digitCount = 0; // otherwise get  new input from user
			printf("Enter a 10-digit phone number: ");
		}
	}
	return;
}
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
	int res = -1;
	int i;

	for (i = 0; i < size; i++){
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0 && res == -1){
			res = i;	// finds the first instance in array that matches const cellNum[]
		}
	}
	return res;
}

// displayContactHeader
void displayContactHeader(void){
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	return;
}

// displayContactFooter
void displayContactFooter(int num){
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", num);
	return;
}


// displayContact:
void displayContact(const struct Contact contacts[]){

	// display name information
	printf(" %s", contacts->name.firstName);
	if (contacts->name.middleInitial[0] != '\0'){
		printf(" %s", contacts->name.middleInitial);
	}
	printf(" %s\n", contacts->name.lastName);

	// display phone numbers
	printf("    C: %-10s", contacts->numbers.cell);
	printf("   H: %-10s", contacts->numbers.home);
	printf("   B: %-10s", contacts->numbers.business);
	printf("\n");

	// display address details
	printf("       %d %s, ", contacts->address.streetNumber, contacts->address.street);
	if (contacts->address.apartmentNumber != 0){
		printf("Apt# %d, ", contacts->address.apartmentNumber);
	}
	printf("%s, %s\n", contacts->address.city, contacts->address.postalCode);

	return;
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size){
	int numContacts = 0;
	int i;

	displayContactHeader();

	for (i = 0; i < size; i++){ // display all records where there is a valid cell number
		if (contacts[i].numbers.cell[0] != '\0'){
			displayContact(&contacts[i]);
			numContacts += 1;
		}
	}
	displayContactFooter(numContacts);
	return;
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size){
	char phone[11];
	int num = -1;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone);

	num = findContactIndex(contacts, size, phone);

	if (num != -1){
		printf("\n");
		displayContact(&contacts[num]);
		printf("\n");
	} else {
		printf("*** Contact NOT FOUND ***\n\n");
	}

	return;
}

// addContact:
void addContact(struct Contact contacts[], int size){
	const char empty[11] = {'\0'};
	int loc = -1;

	loc = findContactIndex(contacts, size, empty);

	if (loc != -1){
		getContact(contacts, loc); // add new contact if array is not full
		printf("--- New contact added! ---\n\n");
	} else {
		printf("*** ERROR: The contact list is full! ***\n\n");
	}

	return;
}

// updateContact:
void updateContact(struct Contact contacts[], int size){
	int loc;
	char phone[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone);

	loc = findContactIndex(contacts, size, phone); // search for number entered

	if(loc == -1){ // not found
		printf("*** Contact NOT FOUND ***\n");
	} else {		// display found contact
		printf("\nContact found:\n");
		displayContact(&contacts[loc]);
		printf("\n");

		// give user options to update values
		printf("Do you want to update the name? (y or n): ");
		if (yes()){
			getName(&contacts[loc].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes()){
			getAddress(&contacts[loc].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes()){
			getPhone(&contacts[loc].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}

	return;
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size){
	int loc;
	char search[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(search);

	loc = findContactIndex(contacts, size, search);

	printf("\n");

	if (loc == -1){
		printf("*** Contact NOT FOUND ***\n");
	} else {
		printf("Contact found:\n");
		displayContact(&contacts[loc]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes()){
			// reset all values of contact to be deleted
			contacts[loc].numbers.cell[0] = '\0';
			contacts[loc].numbers.home[0] = '\0';
			contacts[loc].numbers.business[0] = '\0';
			contacts[loc].address.street[0] = '\0';
			contacts[loc].address.streetNumber = 0;
			contacts[loc].address.apartmentNumber = 0;
			contacts[loc].address.city[0] = '\0';
			contacts[loc].address.postalCode[0] = '\0';
			contacts[loc].name.firstName[0] = '\0';
			contacts[loc].name.lastName[0] = '\0';
			contacts[loc].name.middleInitial[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
	printf("\n");

	return;
}


// sortContacts:
void sortContacts(struct Contact contacts[], int size){

	int i, j;
	// temporary variables for swapping entries
	struct Name tempName;
	struct Address tempAddress;
	struct Numbers tempPhone;

	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			// compares the first and second entries in contacts array and if the first one is greater than the next one
			// they will be swapped. This continues through the array until the contact lowest cell number is first in the array
			// and the contact with the greatest cell number is in the last element of the array before any entries
			if(strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0){
				// Swap name info
				strcpy(tempName.firstName, contacts[i].name.firstName);
				strcpy(contacts[i].name.firstName, contacts[j].name.firstName);
				strcpy(contacts[j].name.firstName, tempName.firstName);
				strcpy(tempName.firstName, "");

				strcpy(tempName.lastName, contacts[i].name.lastName);
				strcpy(contacts[i].name.lastName, contacts[j].name.lastName);
				strcpy(contacts[j].name.lastName, tempName.lastName);
				strcpy(tempName.lastName, "");

				strcpy(tempName.middleInitial, contacts[i].name.middleInitial);
				strcpy(contacts[i].name.middleInitial, contacts[j].name.middleInitial);
				strcpy(contacts[j].name.middleInitial, tempName.middleInitial);
				strcpy(tempName.middleInitial, "");

				// swap Address info
				strcpy(tempAddress.city, contacts[i].address.city);
				strcpy(contacts[i].address.city, contacts[j].address.city);
				strcpy(contacts[j].address.city, tempAddress.city);
				strcpy(tempAddress.city, "");

				strcpy(tempAddress.postalCode, contacts[i].address.postalCode);
				strcpy(contacts[i].address.postalCode, contacts[j].address.postalCode);
				strcpy(contacts[j].address.postalCode, tempAddress.postalCode);
				strcpy(tempName.firstName, "");

				strcpy(tempAddress.street, contacts[i].address.street);
				strcpy(contacts[i].address.street, contacts[j].address.street);
				strcpy(contacts[j].address.street, tempAddress.street);
				strcpy(tempAddress.street, "");

				tempAddress.apartmentNumber = contacts[i].address.apartmentNumber;
				contacts[i].address.apartmentNumber = contacts[j].address.apartmentNumber;
				contacts[j].address.apartmentNumber = tempAddress.apartmentNumber;

				tempAddress.streetNumber = contacts[i].address.streetNumber;
				contacts[i].address.streetNumber = contacts[j].address.streetNumber;
				contacts[j].address.streetNumber = tempAddress.streetNumber;

				// swap numbers info
				strcpy(tempPhone.cell, contacts[i].numbers.cell);
				strcpy(contacts[i].numbers.cell, contacts[j].numbers.cell);
				strcpy(contacts[j].numbers.cell, tempPhone.cell);
				strcpy(tempPhone.cell, "");

				strcpy(tempPhone.home, contacts[i].numbers.home);
				strcpy(contacts[i].numbers.home, contacts[j].numbers.home);
				strcpy(contacts[j].numbers.home, tempPhone.home);
				strcpy(tempPhone.home, "");

				strcpy(tempPhone.business, contacts[i].numbers.business);
				strcpy(contacts[i].numbers.business, contacts[j].numbers.business);
				strcpy(contacts[j].numbers.business, tempPhone.business);
				strcpy(tempPhone.business, "");

			}
		}
	}

	printf("--- Contacts sorted! ---\n\n");

	return;
}
/*
 * contactHelpers.c
 *
 *  Created on: Mar. 26, 2019
 *      Author: JamesMac
 */


