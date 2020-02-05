/*Author Christian Rojas
 Date:02/03/2020
 Program: Mimics the C string library functions using pointers
 PseudoCode:........................
 
 
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//String Length Function
int stringLength(const char *str)
{
    int SIZE;
    
	for (SIZE = 0; *(str + SIZE) != '\0'; SIZE++);
		
    return SIZE;
}

//String and Copy Function tricky.....overflow check?
char *StringNCopy(char *destination, const char *source, int num)
{
    for(int i = 0; i< num; i++)
    {
		cout << i;
        *(destination+i) = *(source+i);
		cout << i;
		cout << *(destination) << endl;
    }
    
    return destination;
}

//Concatention Function (strncat)
char *StringNAdd(char *destination, char *source, int num)//fix source should be const
{
    int end = stringLength(destination);//end of the word to be added

    for(int i = 0; i<num; i++)
        *(destination+(end+i)) = *(source+i);

	*(destination + (end + num)) = '\0';//add the null idenitfier to get length later
    return destination;
}


int stringNCompare(const char *str1, const char *str2, int num)
{
    int check = 0, i = 0;
    while((*(str1+i)!='\0'&&*(str2+i)!='\0')||i==num)//checks if null id is found or if count goes equals num
    {
        if(*(str1+i)!= *(str2+i))
        {
            check = -1;
            return check;
        }
        i++;
    }
    
    return check;
}

int main()
{
	int num = 0, length, i, cond;
	bool condition = true;

	char destination[100];
	char source[100];
	char finaldestination[100];
	char userInput[100];
	char str1[100], str2[100];

	char *pUserInput = &userInput[0];
	char*pDestination = &destination[0];
	char *pSource = &source[0];
	char *pfinaldestination = &finaldestination[0];
	char *pstr1 = &str1[0], *pstr2 = &str2[0];

	string useInput;
	while (condition == true)
{ 
		cout << "Please choose numbers to test function\n" << endl;
		cout << "----------MENU--------" << endl;
		cout << "1,2,3,4,5" << endl;
		cin >> num;

	switch (num)
	{
	case 1: cout << "Please enter word to get length\n" << endl;

		cin.getline(userInput,100,'\n');
		length = stringLength(pUserInput);
		cout << "The length of the word is: " << length << endl;
		break;

	case 2: cout << "Please enter orginal word:\n" << endl;//DO this at home!!!
			cin.ignore();
			
			cin.getline(destination, 100,'\n');
			//cin >> destination;
			cout << "Please enter word to copy from:" << endl;
			cin.ignore();
			cin.getline(source, 100);
			//cin >> source;
			cout << "Please enter number from where to stop copying" << endl;
			cin >> num;
			pfinaldestination = StringNCopy(pDestination, pSource, num);//pointer that points to final word
			length = stringLength(pfinaldestination);//gets the 
			cout <<'\n'<< length<<"<<<<<<<<This is the length"<<endl;
			for (i = 0; i < num; i++)
				cout << *(pfinaldestination + i);
			break;

	case 3: cout << "Please enter word to be contatetr " << endl;
		cin >> destination;//getline to be implmented
		cout << "Please enter word to copy from " << endl;
		cin >> source;
		cout << "Please enter number to stop" << endl;
		cin >> num;
		pDestination = StringNAdd(pDestination, pSource, num);
		length = stringLength(pDestination);//Fix this at home
		for (i = 0; i < length; i++)
			cout << *(pDestination + i);
		break;
	case 4:	cout << "Please enter word to compare" << endl;
		cin >> str1;
		cout << "Please second word to compare" << endl;
		cin >> str2;
		cout << "Please enter number to stop comparing " << endl;
		cin >> num;
		cond = stringNCompare(pstr1, pstr2, num);
		if (cond != 0)
		{
			if (cond == -1)
				cout << "First word is greater than";
			else
				cout << "Second Word is greater " << endl;
		}
		else
			cout << "Congrats the words matched" << endl;

		
		break;

	case 5:	cout << "GoodBye!" << endl;
		    condition = false;


	}
	
	
	}

	system("pause");
	

   // 
   ////Test Module for the strlen function
   //char test[] = "Hello World";// Test has 11 chars
   //char *pTest;
   //pTest = &test[0];
   //cout<<"Hello WO"<<endl;
   //stringLength(pTest);
   // 
   // 

   ////Test Module for StringNCopy Function
   //char test2[] = "Hello World";//Source
   //char test3[20];// Destination

   //char *pDestination;
   //pDestination = &test3[0];
   //char *pSource;
   //pSource = &test2[0];

   //StringNCopy(pDestination, pSource, 7);


   // 
   // /* Need to check bounds somewhow and do somehting about the remainder of left overs spots /0? */
   // //Test Module for StringNAdd
   //char source[50] = "Monkey ";
   //char destination[50] = "Hello ";

   //char *pSource = &source[0];
   //char *pDestination = &destination[0];
   //char *finalWord;

   //finalWord = StringNAdd(pDestination, pSource, 3);
   //for(int i = 0; i<14; i++)
   //    cout<<*(finalWord+i);
   // 
   // 
   // 
   // /* Test with more data*/
   ////Test Module for StringNCompare

   //char compare1[] = "Hello";
   //char compare2[] = "Hello";

   //char *pCompare1 = &compare1[0];
   //char *pCompare2 = &compare2[0];


   //int check = stringLength(pCompare2);
   //cout<<check<<endl;


   // 
   // 
   // /*To do list: make menu and test with more data. Amount to test should be around 50 times or more*/
   // 
    
    
   
    return 0;
}
