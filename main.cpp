/*Author Christian Rojas
 Date:02/03/2020
 Program: Mimics the C string library functions using pointers
 PseudoCode:........................
 
 
 */

#include <iostream>

using namespace std;

//String Length Function
int stringLength(const char *str)
{
    int SIZE;
    
    for(SIZE = 0; *(str+SIZE)!='\0';SIZE++);
    
    return SIZE;
}

//String and Copy Function tricky.....overflow check?
char *StringNCopy(char *destination, const char *source, int num)
{
    for(int i = 0; i< num; i++)
    {
        *(destination+i) = *(source+i);
    
    }
        
    for(int i = 0; i<num; i++){
        cout<<*(destination+i);
    }
    
    return destination;
}

//Concatention Function (strncat)
char * StringNAdd(char *destination, char *source, int num)//fix source should be const
{
    int end = stringLength(destination);//end of the word to be added

    for(int i = 0; i<num; i++)
        *(destination+(end+i)) = *(source+i);
    
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

int main(int argc, const char * argv[])
{
    
   //Test Module for the strlen function
   char test[] = "Hello World";// Test has 11 chars
   char *pTest;
   pTest = &test[0];
   cout<<"Hello WO"<<endl;
   stringLength(pTest);
    
    
   This needs a little more fine tuning works but needs to check overflow
   //Test Module for StringNCopy Function
   char test2[] = "Hello World";//Source
   char test3[20];// Destination

   char *pDestination;
   pDestination = &test3[0];
   char *pSource;
   pSource = &test2[0];

   StringNCopy(pDestination, pSource, 7);


    
    /* Need to check bounds somewhow and do somehting about the remainder of left overs spots /0? */
    //Test Module for StringNAdd
   char source[50] = "Monkey ";
   char destination[50] = "Hello ";

   char *pSource = &source[0];
   char *pDestination = &destination[0];
   char *finalWord;

   finalWord = StringNAdd(pDestination, pSource, 3);
   for(int i = 0; i<14; i++)
       cout<<*(finalWord+i);
    
    
    
    /* Test with more data*/
   //Test Module for StringNCompare

   char compare1[] = "Hello";
   char compare2[] = "Hello";

   char *pCompare1 = &compare1[0];
   char *pCompare2 = &compare2[0];


   int check = stringLength(pCompare2);
   cout<<check<<endl;


    
    
    /*To do list: make menu and test with more data. Amount to test should be around 50 times or more*/
    
    
    
   
    return 0;
}
