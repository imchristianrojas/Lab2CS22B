/*
CIS 22B
Lab 2: Made my own functions that has some functionality as C string functions.
Author: Christian Rojas
Date:02/03/2020
Professor Goel

Program Description: Mimics the C string library functions using pointers.

PseudoCode:
Initialize neccessary char arrays with max size of 1024,pointers,ints,and a boolean.
Prompt menu with 5 options
User chooses which function to test or input 5 to exit program
When user chooses option they will be prompted with necessary arguments for paramenters
Function returns either int or pointer depends on what funciton is called
Gives the User option to try another function until they are done.
If user inputs 5 in option menu,program exits with message.
*/

#include <iostream>

using namespace std;

//String Length Function
int stringLength(const char *str)//original function has type size_t. I am too fimilair with this type so I changed it to a int data type.
{
	int SIZE;
	//Size increments until element of pointer at the address is == null ID.
	for (SIZE = 0; *(str + SIZE) != '\0'; SIZE++);

	return SIZE;
}

//String Copy Function
char *StringNCopy(char *destination, const char *source, int num)//Changed the 3rd parameter of type size_t to int.Not too fimiliar with size_t.
{
	for (int i = 0; i< num; i++)
		//Elements at destination address are set equal to elemment of the address of source.
		*(destination + i) = *(source + i);

	*(destination + num) = '\0';//Add null ID at last element

	return destination;
}

//Concatenate Function (strncat)
char *StringNAdd(char *destination, const char *source, int num)//Changed the 3rd parameter of type size_t to int.Not too fimiliar with size_t.
{
	int end = stringLength(destination);//Gets the last index of the orginal string to add to it

	for (int i = 0; i<num; i++)
		//starts at the last element of what destination points to and adds elements from source until num is reached.
		*(destination + (end + i)) = *(source + i);

	*(destination + (end + num)) = '\0';//Add the null idenitfier
	return destination;
}

//Comparing strings
int stringNCompare(const char *str1, const char *str2, int num)//Changed the 3rd parameter of type size_t to int.Not too fimiliar with size_t.
{
	int check = 0, i;

	for (i = 0; i<num; i++)
	{	//Checks to see if elements do not matched.
		if (*(str1 + i) != *(str2 + i))//Checks which one is greater than.
			check = (*(str1)<*(str2)) ? -1 : 1;//if str2 is greater than str1 return 1,else return 1
	}

	return check;//Either returns 0 if they are equal or one of the two values from the ternary condition.
}

int main()
{
	const int SIZE = 1024;//maximum size of char arrays
	int num = 0, length, i, cond;
	bool condition = true; 

	//Char Arrays for User Input
	char destination[SIZE];
	char source[SIZE];
	//Pointers to Char Arrays
	char *pSource = &source[0];
	char *pDestination = &destination[0];

	//Menu and User Interactivity
	while (condition)
	{
		cout << "\nPlease choose numbers to test function\n" << endl;
		cout << "-------------------------------------MENU---------------------------------------" << endl;
		cout << "1:String Length, 2:StringNCopy, 3:StringNAdd, 4:StringNCompare,5:To Quit Program" << endl;
		cin >> num;

		switch (num)
		{
		case 1: cout << "Please enter string to get length: ";//String Length Function
			cin.ignore();
			cin.getline(destination, SIZE);
			length = stringLength(pDestination);
			cout << "The length of the string is: " << length << endl;
			break;

		case 2: cout << "Please enter orginal string: "; //String Copy Function
			cin.ignore();
			cin.getline(destination, SIZE);

			cout << "Please enter string to copy from:";
			cin.getline(source, SIZE);

			cout << "Please enter number from where to stop copying" << endl;
			cin >> num;

			pDestination = StringNCopy(pDestination, pSource, num);//pointer that points to final string
			cout << "This is your new string!: ";
			for (int i = 0; *(pDestination + i) != '\0'; i++)
				cout << *(pDestination + i);
			break;

		case 3: cout << "Please enter string to be added: ";//Concatenation Function
			cin.ignore();
			cin.getline(destination, SIZE);

			cout << "Please enter string to copy from: ";
			cin.ignore(0);
			cin.getline(pSource, SIZE);

			cout << "Please enter number to stop" << endl;
			cin >> num;
			pDestination = StringNAdd(pDestination, pSource, num);
			cout << "This is your new string: ";
			for (i = 0; *(pDestination + i) != '\0'; i++)
				cout << *(pDestination + i);
			break;

		case 4: cout << "Please enter string to compare: ";//String Compare Function
			cin.ignore();
			cin.getline(destination, SIZE);

			cout << "Please second string to compare: ";
			cin.ignore(0);
			cin.getline(source, SIZE);

			cout << "Please enter number to stop comparing: ";
			cin >> num;
			cond = stringNCompare(pDestination, pSource, num);

			if (cond != 0)//Checks return value of function and prompts message accordingly.
				(cond == -1) ? cout << "The string don't match! But the first string is greater than the second. " << endl : cout 
				<< "The strings don't match! But the second string is greater than the first." << endl;
			else
				cout << "The strings matched! " << endl;

			break;

		case 5: cout << "GoodBye!" << endl;//Exits program.
			condition = false;

		}


	}
	
	system("pause");

	return 0;
}