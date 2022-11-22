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
	char* id[4];
	char pwd[6];
	int win;
	int lose;
};
int failnum = 0;
int* e;
*e = &failnum;



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
int Log(int *f)
{
	//init
	int c = 0; int Re = 1;
	struct users a, b;
	char temppwd[6];
	FILE* fp;
	int i = 0;

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
		//login
		printf("-------Login-------\n");
		fp = fopen("users.txt", "rb");
		fread(&b, sizeof(struct users), 1, fp);
		printf("Please enter your ID: \n");
		scanf("%s", &a.id);
		fflush(stdin);
		//if valid username
		while (1)
		{
			if (strcmp(a.id, b.id))
			{
				//valid
				if (!feof(fp))
				{
					fread(&b, sizeof(struct users), 1, fp);
				}
				else
				{
					printf("The ID is valid! ");
					Sleep(1500);
					fclose(fp);
					return 1;
				}
			}
			break;
		}
		//password
		printf("Please enter your password:\n");
		scanf("%s", &a.pwd);
		fflush(stdin);
		if (strcmp(a.pwd, b.pwd))
		{
			if(f<3)
			{
				printf("wrong password or username!Please try again!");
				f++;
				return 1;
			}
			else
			{
				f = 0;
				while (i <= 15)
				{
					system("cls");
					printf("You've tryed too many times, please try agian after %d s\n", i);
					i++;
				}
			}
		}
		printf("login success!\n");
		return 0;

	}
	printf("Please enter according to suggestion!");
	return 1;
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
	while (Log(*e))
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