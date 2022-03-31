/*Juan Alvarez
Console Apps Solution Project
Program that will give 3 options
Option 1: to generate a personal username
Option 2: To calculate a numb's factorial
Option 3: To exit from the application
Saved as EPOSPROJ.cpp
09/11/2017*/

//First we reference libraries
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>

// function prototypes
void menu();
void getName();
void displayUserName(char[]);
void createPassword(char[],char[]);
void factorial();

/*creates character arrays to hold name, surname
and username once they are joined, in this case
we comment them out as we are using local arrays.
They are here just as an example of how they would be
if we had made them global.*/
//char name[20];
//char surname[20];
//char username[21];
//long num;
//long userNum;
//long fact;

/* function where it displays the first menu where user chooses
if he wants to create a user name, calculate a factorial of a number
or exit the program*/
void menu()
{
	int choice;
	do
	{
	clrscr();

	cout << "\t\t\tWelcome to the EPOS Options ltd." << endl;
	cout << "\t\tNetwork Administration & Statistics Department's" << endl;
	cout << "\t\t\tPilot 'One Stop Shop' interface" << endl;

	cout << "\n\t1.\tOption 1: Generate a personal username";
	cout << "\n\t2.\tOption 2: Calculate a number's factorial";
	cout << "\n\t3.\tOption 3: Exit";

	cout << "\n\n\tPlease choose one of the options above:";
	cin >> choice;

	switch(choice)
	{
		case 1:
			//will include the function to ask for the user input
			getName();
			getch();
			break;

		case 2:
			//will call the program to calculate number's factorial
			factorial();
			getch();
			break;
		case 3:
			//will exit the application
			break;

		default: cout << "\n\n\tYou entered an invalid menu choice, only the numbers '1', '2' and '3' are allowed, please press return and try again.";
			 getch();
			 break;
	}

	}while (choice !=3);

	cout << "\n\n\tPlease press enter to exit the program";
	getch();
}

//function that asks user to introduce full name
void getName()
{
	char name[20];
	char surname[20];
	cout << "\n\tPlease enter your first name: " << endl;
	cin >> name;
	cout << "\n\tPlease enter your surname: " << endl;
	cin >> surname;
	createPassword(name, surname);
}

/*function that uses strcpy to copy just the first letter of the
name into username, then adds the surname uses strcat to
join surname into username and strlwr to make it lower case*/
void createPassword(char name[20],char surname[20])
{
	char username[21];
	memset(username, '\0', 21);
	strncpy(username, name, 1);
	strcat(username, surname);
	strlwr(username);
	displayUserName(username);
}

//function to display the username
void displayUserName(char username[21])
{
	cout << "\n\tYour username is: " << username << endl;
	cout << "\n\n\tPress any key to go back to the main menu\n";
	getch();
}

//function created to produce and display a factorial
void factorial()
{
	long num, userNum, fact=1;
	clrscr();

	cout << "\n\tEnter a positive number: ";
	cin >> userNum;

	for(num = userNum; num > 0; num--)

	fact = fact * num;

	cout << "\n\tFactorial of " << userNum << " = " << fact;
	cout << "\n\n\tPress any key to return to the menu";
	getch();
}

//main function
void main()
{
	menu();
	getch();
}