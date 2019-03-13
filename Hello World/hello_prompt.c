/*
**   Assignment:  Laboratory Assignment 01 "Hello World"
**
**     Filename:  hello.c
**
**       Author:  Christopher Paolini
**        REDID:  807456566
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  This program prints the string "hello, world" with a newline character.  The intent
**  			  of this program is to introduce beginning programmers to the C programming language.
**
**        Input:  None.
**
**       Output:  The string "hello, world" with a newline character.
**
**    Algorithm:  Output a string to stdout (the console) using the standard I/O printf() function.
**
**      Caveats:  Describe any known program bugs or limitations.
**      Version:  1.0
**
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("hello, world\n");
	return EXIT_SUCCESS;
}
