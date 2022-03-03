#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>
#include <string>

//Constructor function
MyString::MyString(char const* strIn)
{
 length = strlen(strIn);
 str = new char[length + 1];
 strcpy(str, strIn);

}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
 delete []str; 
}

void MyString::myDisplay()
{
 cout << str << endl;
}

 /*
   Desc: Overwrites contents of MyString.str with what strIn points to 
   To clarify: nothing of str remains. strIn replaces it entirely
   Pre: strIn is a null-terminated string 
   Post: contents of strIn replaces MyString 
   */
   void MyString::myStrcpy(char const* strIn)
   {
        int i =0;
        while(strIn[i] != '\0')
        {
            str[i] = strIn[i];
            i++;
        }
        str[i] = '\0';
        length = myStrlen();
        
        // for(int j =0;j<i;j++)
        //     str[i] = strIn[i];
   }

   /*
   Desc: Used to determine the length of MyString.str
   Pre:  An instance of MyString exists
   Post: Returns the number of characters, excluding the null character
         in MyString. 
   */
   int MyString::myStrlen()
   {
       int len = 0;
       while(str[len]!= '\0')
       {
           len++;
       }
       return len;
   }

   /*
   Desc: Determines if MyString.str is equivalent to an input C-String 
   Pre:  An instance of MyString exists. strIn is a null-terminated
         string.
   Post: Returns true if the strings are equivalent, false otherwise 
   */
   bool MyString::isEqual(char const* strIn)
   {
       int i =0;
       while(strIn[i] != '\0' || str[i] != '\0')
       {
            if(strIn[i] != str[i])
                return false;
            i++;
       }
       return true;
   }
   
   /*
   Desc: Concatenates strIn with MyString 
   Pre:  An instance of MyString exists. strIn is a null-terminated string
   Post: strIn is concatenated with MyString.str.  Ex.
         MyString.str is ABC. strIn is DEF.  MyString is still a null-terminated
	 string, but contains: ABCDEF. 
   */
   void MyString::concat(char const* strIn)
   {
        int i = length;
        int j =0;
        while(strIn[j] != '\0')
        {
            str[i] = strIn[j];
            i++;
            j++;
        }
        str[i] = '\0';
        
        length = myStrlen();
        
   }

   /*
   Desc: Searches for a substring within MyString 
   Pre:  An instance of MyString exists
   Post: If strIn is a substring of MyString.str, returns
         the index of its starting positon, -1 otherwise
   */
   int MyString::find(char const* strIn)
   {
       for(int i =0;i<length;i++)
       {
           if(str[i] == strIn[0])
                if(isSub(strIn,i))
                    return i;
       }
       return -1;
   }

   /*
   Desc: Used in conjunction with the function, find. Loops through MyString starting
         with idx looking for strIn.
   pre: idx is the first character of MyString.str that matches the substring, strIn
   post: returns true if strIn is a substring of str, false otherwise. 
         Used by find()
   */ 
   bool MyString::isSub(char const* strIn, int idx)
   {
       cout << "I am being called" << endl;
       int i=1;
       while(strIn[i] != '\0')
       {
            if(str[idx+1] != strIn[i])
            {
                return false;
            }
            i++;
            idx++;
       }
       return true;
   }

