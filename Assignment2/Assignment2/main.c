#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//#include"testsource.h"

#define COL 3
#define ROW 3
//window size
void WindowSize(unsigned uCol, unsigned uLine)
{
	char cmd[64];
	sprintf(cmd, "mode con cols=%d lines=%d", uCol, uLine);
	system(cmd);
}

//create file for login
void Init_file()
{
	FILE *fp;
	if ((fp = fopen("users.txt", "rb")) == NULL)
	{
		if ((fp = fopen("users.txt", "wb+")) == NULL)
		{
			printf("faild to create user data file!\n");
			exit(0);
		}
	}
}
//menu


//display gameboard


//init
int a, count = 0;
char chess[ROW][COL] = {'\0'};

int main()
{
	WindowSize(50, 15);
	//determain if there's already a file created
	//establish the file for user behavior and account storage
	// 
	Init_file();
	//set cursor
	
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