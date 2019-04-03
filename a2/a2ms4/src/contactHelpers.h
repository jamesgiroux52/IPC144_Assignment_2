/*
 ============================================================================
 Name        : contactsHelpers.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 18th, 2019 - Assignment 2 - Milestone 4
 ============================================================================
 */

/*
 ============================================================================
 Description : contactHelper.c helper function prototypes
 ============================================================================
 */

#ifndef CONTACTHELPERS_H_
#define CONTACTHELPERS_H_

#include "contacts.h"


// main program functionality run through this function
void contactManagerSystem(void);
// pause and wait for enter key
void pause(void);
// clearKeyboard in MS instructions
void clearBuffer(void);
// validate that a number is positive
// this function was not in the assignment but
// I added it to validate Street # and Apt. #
void valPos(int *num, const char text[]);
// gets a valid integer value with error checking
int getInt(void);
// gets and integer within min and max
int getIntInRange(int min, int max);
// boolean function that only accepts Y,y,N,n with error checking
int yes(void);
// main menu
int menu(void);
// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);
// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);
// displayContactHeader
void displayContactHeader(void);
// displayContactFooter:
void displayContactFooter(int num);
// displayContact:
void displayContact(const struct Contact *contact);
// displayContacts:
void displayContacts(const struct Contact contacts[], int size);
// searchContacts:
void searchContacts(const struct Contact contacts[], int size);
// addContact:
void addContact(struct Contact contacts[], int size);
// updateContact:
void updateContact(struct Contact contacts[], int size);
// deleteContact:
void deleteContact(struct Contact contacts[], int size);
// sortContacts:
void sortContacts(struct Contact contacts[], int size);


#endif
