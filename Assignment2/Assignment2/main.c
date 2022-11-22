#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


//#include"testsource.h"

//init
int a, count = 0;
typedef struct users
{
	char* id[10];
	char pwd[6];
	int win;
	int lose;
};


//color setting
VOID setcolor(UINT uFore, UINT uBack)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}
//shape

//window size
void WindowSize(unsigned uCol, unsigned uLine)
{
	char cmd[64];
	sprintf(cmd, "mode con cols=%d lines=%d", uCol, uLine);
	system(cmd);
}

//create file for login
int Init_file()
{
	FILE *fp;
	if ((fp = fopen("userdata.txt", "rb")) == NULL)
	{
		if ((fp = fopen("userdata.txt", "wb+")) == NULL)
		{
			printf("faild to create user data file!\n");
			exit(0);
		}
	}
	return 1;
}
//menu
int menu()
{
	setcolor(9, 0);
	printf("##############################\n");
	setcolor(7, 0);
	printf("##   1.Login	2.Register   ##\n");
	setcolor(9, 0);
	printf("##############################\n");
	return 0;
}
//login or register
int Log()
{
	//init
	int c = 0;int Re = 1;
	struct users a, b;
	char temppwd[6];
	FILE* fp;

	printf("\nPlease enter your decision(1 or 2):");
	scanf("%d", &c);
	fflush(stdin);
	if (c == 2)
	{
		fp = fopen("userdata.txt", "r");
		system("cls");
		printf("-------Register-------\n");
		fread(&b, sizeof(struct users), 1, fp);// open space from begin to "b" component
		//ID
		printf("Please enter your ID(10 characters):\n");
		scanf("%s", &a.id);
		fflush(stdin);
		//check for same ID
		while (1)
		{
			if (strcmp(a.id, b.id))
			{
				if (!feof(fp))
				{
					fread(&b, sizeof(struct users), 1, fp);
				}
				else
				{
					break;
				}
			}
			else
			{
				printf("\r\033[k");
				
				printf("This ID had been occupied, please change one\n");
				Sleep(3000);
				fclose(fp);
				
				system("cls");
				return 1;
			}
		}
		//Password
		while (Re)
		{
			printf("\r\033[k");
			printf("Please enter your password(6 numbers):\n");
			scanf("%s", &a.pwd);
			fflush(stdin);
			printf("\r\033[k");
			printf("Please enter your password again:\n");
			scanf("%s", &temppwd);
			fflush(stdin);
			if (strcmp(a.pwd, temppwd))
			{
				printf("\r\033[k");
				printf("The passwords you've entered are not the same, please try again!");
				Re = 1;
			}
			else
			{
				fp = fopen("userdata.txt", "a");
				fwrite(&a, sizeof(struct users), 1, fp);
				printf("You've succesfully registered, please login!");
				Sleep(500);
				fclose(fp);
				return 1;
			}
		}
	}
	else if (c == 1)
	{

	}
	return 0;
}

//display gameboard

int main()
{
	WindowSize(50, 15);
	printf("Loading");
	for (a = 0;a<4;a++)
	{
		Sleep(500);
		printf(".");
		a++;
	}
	//determain if there's already a file created
	//establish the file for user behavior and account storage
	Init_file();
	system("cls");
	//set cursor
	
	//display user interface
	menu();
	//register or login
	while (Log())
	{
		Sleep(500);
	}
	// if register
	//input user name and password
	//storage
	// then login or again
	// start the game, choose to go first or second
	// determain victory
	// three in a line
	//choose if to delete the user data
	setcolor(7,0);
	return 0;
}