#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define COL 3



//menu
int menu()
{
	printf("###########################\n");
	printf("##   1.Play	2.Exit   ##\n");
	printf("###########################\n");
	return 0;
}

//display gameboard
int ShowBroad(char chess[][COL])
{
	system("cls");		//Ë¢ÐÂ½çÃæ
	printf(" %c | %c |%c          Player:   X\n", chess[0][0], chess[0][1], chess[0][2]);
	printf(" ----------        Computer: O\n");
	printf(" %c | %c |%c \n", chess[1][0], chess[1][1], chess[1][2]);
	printf(" ----------\n");
	printf(" %c | %c |%c \n", chess[2][0], chess[2][1], chess[2][2]);

}


int main()
{
	//determain if there's already a file created
	//establish the file for user behavior and account storage
	//display user interface
	//register or login
	// if register
	//input user name and password
	//storage
	// then login or again
	// start the game, choose to go first or second
	// determain victory
	// three in a line
	//choose if to delete the user data

	return 0;
}