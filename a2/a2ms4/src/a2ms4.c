/*
 ============================================================================
 Name        : a2ms4.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : March 18th, 2019 - Assignment 2 - Milestone 4
 ============================================================================
 */

/*
 ============================================================================
 Description : Fully functional contact management system.  Our max contacts
 	 	 	   are set at 5 but this is easily changeable by defining MAXCONTACTS
 	 	 	   to a higher value.  functions are error proof and foolproof.
 	 	 	   Options to display, add, delete, modify by cell phone number search,
 	 	 	   search for a contact by cell phone number, and sort contact array.
 ============================================================================
 */
/*
+--------------------------------------------------------*
|           2  0  1  9  ~  W  I  N  T  E  R
|                 I  P  C  :  B  T  P
|                 1  4  4  :  1  0  0
|                 ASSIGNMENT #2 MS# 4
|
|   S  E  N  E  C  A               C  O  L  L  E  G  E
|   ========  =======  =====  ========  ======  ======
|      ==     ==      ==        ==     ==      ==   ==
|     ==     ====     ====     ==     ====    ======
|    ==     ==          ==    ==     ==      == ==
|   ==     ======  =====     ==     ======  ==   ==
|
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
|  !!!   DO NOT ALTER THE CONTENTS OF THIS FILE   !!!
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
+--------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"



// Section header
void printSectionHeader(const char *testName);



int main(void){

	printSectionHeader("Final A#2-Milestone #4 (sort)"); // included sort algorithm

    contactManagerSystem();

    return 0;
}

// Display specified test section header
void printSectionHeader(const char *testName){
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}

