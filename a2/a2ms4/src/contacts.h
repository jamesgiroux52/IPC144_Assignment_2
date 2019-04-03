/*
 ============================================================================
 Name        : contacts.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 18th, 2019 - Assignment 2 - Milestone 4
 ============================================================================
 */

/*
 ============================================================================
 Description : Structure definitions, and main contact function prototypes
 	 	 	   for contacts.c
 ============================================================================
 */

#ifndef CONTACTS_H_
#define CONTACTS_H_


// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
struct Numbers {
	char cell[11];
	char home[11];			// I added a few more memory locations for inputs like
	char business[11];		// 905-123-1234 or (905) 123-4567
};

// Structure type Contact declaration
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------


// Get and store from standard input the values for Name
void getName(struct Name *name);

// Get and store from standard input the values for Address
void getAddress(struct Address *address);

// Get and store from standard input the values for Numbers
void getPhone(struct Numbers *numbers);

// get contact
void getContact(struct Contact contact[], int loc);




#endif /* CONTACTS_H_ */
