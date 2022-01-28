/*
 Name: James Jansma
 Class: CPSC 122, Section 1
 Date Submitted: January 29, 2022
 Assignment: Project 3                                                                     
 Description: This program takes two digit strings and a filename
 from the command line. It converts those two digit strings to ints using
 atoiMy. It then multiples the two together and prints it in the file
 that was named in the commandline

*/

#include <fstream>
#include<math.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int atoiMy(char []);

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        cout << "Incorrect number of command line arguments" << endl;
        exit(EXIT_FAILURE);
    }
    ofstream outf;
    outf.open(argv[3]);

    int num1 = 0, num2 = 0;
    double mult = 0;

    num1 = atoiMy(argv[1]);
    num2 = atoiMy(argv[2]);

    mult = num1 * num2;

    outf << mult << endl;

    outf.close();

}


/*
Description: Transforms a digit string stored as a c-string to an int. 
Input: c-string containing  digits
Returns: integer value of the digit string
*/
int atoiMy(char str[])
{
    
    int i = 0, count = 0,value = 0;
    char out;
    while((str[count]) != '\0')
    {
        count++;
    }
    
    while(true)
    {
        if(str[i] == '\0')
            break;
        out = (str[i]);
        value += ((int)(out - '0')) * pow(10,(count - 1));
        i++;
        count--;
    }
    return value;
}