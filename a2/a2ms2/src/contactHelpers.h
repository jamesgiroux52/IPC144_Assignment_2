/*
 ============================================================================
 Name        : contactsHelper.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 15th, 2019 - Assignment 2 - Milestone 2
 ============================================================================
 */

/*
 ============================================================================
 Description : contactHelper.c function prototypes
 ============================================================================
 */

#ifndef CONTACTHELPERS_H_
#define CONTACTHELPERS_H_


// pause and wait for enter key
void pause(void);
// clearKeyboard in MS instructions
void clearBuffer(void);
// validate that the use has entered a positive number
void valPos(int *num, char text[]);
// gets a valid integer value with error checking
int getInt(void);
// gets and integer within min and max
int getIntInRange(int min, int max);
// boolean function that only accepts Y,y,N,n with error checking
int yes(void);
// main menu
int menu(void);
// main program functionality run through this function
void contactManagerSystem(void);


#endif
