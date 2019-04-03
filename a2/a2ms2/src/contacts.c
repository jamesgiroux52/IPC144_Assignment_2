/*
 ============================================================================
 Name        : contacts.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 15th, 2019 - Assignment 2 - Milestone 2
 ============================================================================
 */

/*
 ============================================================================
 Description : contact system main functions
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"


// get the name information about contact
void getNameInfo(struct Name *name){
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearBuffer();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes()){
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearBuffer();
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	clearBuffer();

	return;
}


// get the address information about contact
void getAddressInfo(struct Address *address){
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	valPos(&address->streetNumber, "STREET");


	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearBuffer();

	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes()){
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		valPos(&address->apartmentNumber, "APARTMENT");
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearBuffer();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearBuffer();

	return;
}

// get the contacts numbers numbers
void getPhoneNumbers(struct Numbers *numbers){
	printf("Please enter the contact's cell phone number: ");
	scanf(" %14[^\n]", numbers->cell);
	clearBuffer();

	printf("Do you want to enter a home phone number? (y or n): ");
	if(yes()){
		printf("Please enter the contact's home phone number: ");
		scanf(" %14[^\n]", numbers->home);
		clearBuffer();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if(yes()){
		printf("Please enter the contact's business phone number: ");
		scanf(" %14[^\n]", numbers->business);
		clearBuffer();
	}

	return;
}


// function to display the contact also does not display any optional data not gathered
// and prints a message if no numbers numbers were entered
void dispContact(const struct Contact *contact){
	printf("\nContact Details\n");
	printf("===============\n");

	// display name of contact
	printf("Name Details\n");
	printf("------------\n");
	printf("First name: %s\n", contact->name.firstName);
	if (contact->name.middleInitial[0] != '\0'){
		printf("Middle initial(s): %s\n", contact->name.middleInitial);
	}
	printf("Last name: %s\n", contact->name.lastName);

	// display address details
	printf("\nAddress Details\n");
	printf("---------------\n");
	printf("Street number: %d\n", contact->address.streetNumber);
	printf("Street name: %s\n", contact->address.street);
	if (contact->address.apartmentNumber != 0){
		printf("Apartment: %d\n", contact->address.apartmentNumber);
	}
	printf("Postal code: %s\n", contact->address.postalCode);
	printf("City: %s\n", contact->address.city);

	// display numbers numbers
	printf("\nPhone Numbers\n");
	printf("-------------\n");
	printf("Cell numbers number: %s\n", contact->numbers.cell);
	if (*contact->numbers.home != '\0'){
		printf("Home numbers number: %s\n", contact->numbers.home);
	}
	if (*contact->numbers.business != '\0'){
		printf("Business numbers number: %s\n", contact->numbers.business);
	}

	return;
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+


// get a contact and store
void getContact(struct Contact *contact){
	getNameInfo(&contact->name);
	getAddressInfo(&contact->address);
	getPhoneNumbers(&contact->numbers);
}

