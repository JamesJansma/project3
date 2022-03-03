/*
Name: James Jansma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: P7
Description: Program illustrates using class MyString 
By doing dynamic and static testing
*/

#include "8-MyStr.h"
#include <iostream> 
#include <string> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);
 

//  //Test of myDisplay
//  cout << "***************************************" << endl;
//  cout << "*****Test 1 myDisplay*****" << endl;
//  cout << "static test" << endl;
//  cout << "output should be the command line input" << endl;
//  str1.myDisplay();
//  cout << endl;
//  cout << "*****Test 2  myDisplay*****" << endl;
//  cout << "dynamic test" << endl;
//  cout << "output should be the command line input" << endl;
//  str2->myDisplay();
//  cout << endl;
//  cout << "***************************************" << endl;
//  //Test of myStrlen
//  cout << "*****Test 3  myStrlen*****" << endl;
//  cout << "static test" << endl;
//  cout << str1.myStrlen() << endl;
//  cout << "***************************************" << endl;
//  cout << "*****Test 4  myStrlen*****" << endl;
//  cout << "dynamic test" << endl;
//  cout << "output should be length of command line input" << endl;
//  cout << str2->myStrlen() << endl;
//  cout << "***************************************" << endl;
//  //Test of myStrcpy
//  cout << "*****Test 5  myStrcpy*****" << endl;
//  cout << "Static test" << endl;
//  cout << "output should be butterfly as it is now copied as the str" << endl;
//  str1.myStrcpy("Butterfly");
//  str1.myDisplay();
//  cout << endl;
//   cout << "***************************************" << endl;
//  cout << "*****Test 6  myStrcpy*****" << endl;
//  cout << "Dynamic test" << endl;
//  cout << "output should be butterfly as it is now copied as the str" << endl;
//  str2->myStrcpy("Butterfly");
//  str2->myDisplay();
//  cout << endl;
//  //test of isEqual
//  cout << "***************************************" << endl;
//  cout << "*****Test 7  isEqual*****" << endl;
//  cout << "Static test" << endl;
//  cout << "output should be True if they are equal false otherwise" << endl;
//  bool check = str1.isEqual("Butterfly");
//  cout << check;
//  cout << endl;
//  cout << "***************************************" << endl;
//  cout << "*****Test 8  isEqual*****" << endl;
//  cout << "Dynamic test" << endl;
//  cout << "output should be True if they are equal false otherwise" << endl;
//  bool answer = str2->isEqual("JamesJansma");
//  cout << answer;
//  cout << endl;
//  cout << "***************************************" << endl;
//  //Test of concat
//  cout << "*****Test 9 concat*****" << endl;
//  cout << "Static test" << endl;
//  cout << "output should be The original string with a string concatenated" << endl;
//  str1.concat("James");
//  str1.myDisplay();
//  cout << endl;
//  cout << "***************************************" << endl;
//  cout << "*****Test 10 concat*****" << endl;
//  cout << "Dynamic test" << endl;
//  cout << "output should be The original string with a string concatenated" << endl;
//  str2->concat("James");
//  str2->myDisplay();
//  cout << endl;
//  cout << "***************************************" << endl;
//  //Test of find
//  cout << "*****Test 11 find*****" << endl;
//  cout << "Static test" << endl;
//  cout << "output should be idx of the start of the substring or -1 if it is not a substring" << endl;
//  cout << str1.find("Jam");
//  cout << endl;
//  cout << "***************************************" << endl;
//  cout << "*****Test 12 find*****" << endl;
//  cout << "Dynamic test" << endl;
//  cout << "output should be idx of the start of the substring or -1 if it is not a substring" << endl;
//  cout << str2->find("fly");
//  cout << endl;
//  cout << "***************************************" << endl;
 
 
 delete str2;
 return 0;  
}
   
  
