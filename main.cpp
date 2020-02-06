/*Author Christian Rojas
 Date:02/03/2020
 Program: Mimics the C string library functions using pointers
 PseudoCode:........................
 
 
 */

#include <iostream>
#include <cstdlib>


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
       
        *(destination+i) = *(source+i);
       
    }
    *(destination+num) = '\0';//Add null ID at last element
    
    return destination;
}

//Concatention Function (strncat)
char *StringNAdd(char *destination, char *source, int num)//fix source should be const
{
    int end = stringLength(destination);//Gets the last index of the orginal word to add to it

    for(int i = 0; i<num; i++)
        *(destination+(end+i)) = *(source+i);

    *(destination + (end + num)) = '\0';//Add the null idenitfier
    return destination;
}

//Comparing strings
int stringNCompare(const char *str1, const char *str2, int num)
{
    int check = 0,i;
    
    for(i = 0; i<num; i++)
    {
        if(*(str1+i)!= *(str2+i))
        check =  (*(str1)<*(str2))? -1 : 1;//if str2 is greater than str1 return 1,else return 1
    }

    return check;//Either returns 0 if they are equal or one of the two values from the ternary condition.
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

    
    //Menu and User Interactivity
    while (condition)
{
        cout << "\nPlease choose numbers to test function\n" << endl;
        cout << "----------MENU--------" << endl;
        cout << "1:String Length, 2:StringNCopy, 3:StringNAdd, 4:StringNCompare, 5:To Quit Program" << endl;
        cin >> num;

    switch (num)
    {
    case 1: cout << "Please enter word to get length: ";//String Length Function
            cin.ignore();
            cin.getline(userInput,100);
            length = stringLength(pUserInput);
            cout << "The length of the word is: " << length << endl;
            break;

    case 2: cout << "Please enter orginal word: "; //String Copy Function
            cin.ignore(1);
            cin.getline(destination, 100);
            
            cout << "Please enter word to copy from:" ;
            cin.getline(source, 100);
        
            cout << "Please enter number from where to stop copying" << endl;
            cin >> num;

            pfinaldestination = StringNCopy(pDestination, pSource, num);//pointer that points to final word
            cout<<"This is your new word!: ";
            for(int i = 0; *(pfinaldestination+i)!='\0';i++)
                cout<<*(pfinaldestination+i);
            break;

    case 3: cout << "Please enter word to be added: ";
            cin.ignore(1);
            cin.getline(destination, 100);
        
            cout << "Please enter word to copy from: ";
            cin.ignore(0);
            cin.getline(pSource,100);
        
            cout << "Please enter number to stop" << endl;
            cin >> num;
            pDestination = StringNAdd(pDestination, pSource, num);
            cout<<"This is your new word: ";
            for (i = 0; *(pDestination+i)!='\0'; i++)
                cout << *(pDestination + i);
        break;
            
            
    case 4: cout << "Please enter word to compare: ";
            cin.ignore();
            cin.getline(str1, 100);
        
            cout << "Please second word to compare: ";
            cin.ignore(0);
            cin.getline(str2, 100);
       
            cout << "Please enter number to stop comparing: ";
            cin >> num;
            cond = stringNCompare(pstr1, pstr2, num);
           
            if(cond!=0)
                (cond==-1) ? cout<<"The words don't match! But the first word is greater than the second! "<<endl : cout<<"The words don't match but the second words is greater than the first"<<endl;
            else
                cout<<"The words matched! "<<endl;
            
            break;

    case 5: cout << "GoodBye!" << endl;
            condition = false;

    }
    
    
    }
    /*
     To do:
     1. Check for Null ID in all functions overflow check
     2. Find out wierd infinite loop bug somewhere after testing numerous sets of data.(In while loop of switch case)
     3. Psuedocode
     4. Comment a little more
     5. Delete extranous pointers
     6. Test more.
     */
    system("pause");
    
    return 0;
}
