/*
 ============================================================================
 Name        : contacts.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 18th, 2019 - Assignment 2 - Milestone 4
 ============================================================================
 */

/*
 ============================================================================
 Description : Contact Management System - modify/add contact functions code
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"


// get the name information about contact
void getName(struct Name *name){

	name->firstName[0] = '\0';
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearBuffer();


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes()){
		name->middleInitial[0] = '\0';
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearBuffer();
	} else {
		name->middleInitial[0] = '\0';
	}
	name->lastName[0] = '\0';
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	clearBuffer();

	return;
}


// get the address information about contact
void getAddress(struct Address *address){
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	valPos(&address->streetNumber, "STREET");

	address->street[0] = '\0';
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearBuffer();

	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes()){
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		valPos(&address->apartmentNumber, "APARTMENT");
	} else {
		address->apartmentNumber = 0;
	}

	address->postalCode[0] = '\0';
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearBuffer();

	address->city[0] = '\0';
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearBuffer();

	return;
}

// get the contacts phone numbers
void getPhone(struct Numbers *phone){
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(phone->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	if(yes()){
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(phone->home);
	} else {
		phone->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if(yes()){
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(phone->business);
	} else {
		phone->business[0] = '\0';
	}

	return;
}

// get a contact and store
void getContact(struct Contact contact[], int loc){
	getName(&contact[loc].name);
	getAddress(&contact[loc].address);
	getPhone(&contact[loc].numbers);
}

