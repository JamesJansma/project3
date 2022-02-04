/*
Name: James Jansma
Class: CPSC 222
Date: January 21, 2022
Assignment Name: Project 4
Description: This program take input from the command line to decide to genretate a key,
encrypt a plaintext, or decrypt an encrypted plaintext. 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int keyGen();
char encrypt(char, int);
char decrypt(char, int);
void fileOpen(fstream&, string, char);
int findIdx(char, char[]);

int main(int argc,char* argv[])
{
    char inChar,newChar;
    int key;
    fstream fin;
    fstream fkin;
    fstream fout;
    
    if(atoi(argv[1]) == 0)
    {
        fileOpen(fout,argv[2],'w');
        fout << keyGen();
        fout.close();
    }
    else if((atoi(argv[1])) == 1)
    {
        fileOpen(fin,argv[3],'r');
        fileOpen(fout,argv[4],'w');
        fileOpen(fkin,argv[2],'r');
        while (fin.peek() != EOF)
        {
            inChar = fin.get();
            //cout << inChar;
            if(inChar == ' ')
            {
                fout << inChar;
            }
            else if(isalpha(inChar))
            {
                if(islower(inChar))
                {
                    inChar = toupper(inChar);
                    fkin >> key;
                    //cout << key;
                    newChar = encrypt(inChar,key);
                    //cout << newChar;
                    fout << newChar;
                }
                else
                {
                    fkin >> key;
                    newChar = encrypt(inChar,key);
                    fout << newChar;
                }
            }
            else
                fout << inChar; 
           
        }
        fin.close();
        fkin.close();
        fout.close();
    }
    else if(atoi(argv[1]) == 2)
    {
        fileOpen(fkin,argv[2],'r');
        fileOpen(fin,argv[3],'r');
        fileOpen(fout,argv[4],'w');
        while (fin.peek() != EOF)
        {
            inChar = fin.get();
            if(inChar == ' ')
                fout << inChar;
            else
            {
                fkin >> key;
                newChar = decrypt(inChar,key);
                fout << newChar;
            }
        }
        fin.close();
        fkin.close();
        fout.close();
    }
    else
    {
        cout << "Did not enter a viable number" << endl;
        exit(EXIT_FAILURE);
    }



    
}


/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char newCh;
    int i = findIdx(ch,alpha);
    //cout << "index of letter " << ch << " is " << i << endl; check to make sure indexing was working
    newCh = alpha[(((i + key)%26))];
    return newCh;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char newCh;
    int i = findIdx(ch,alpha);
    //cout << "index of letter " << ch << " is " << i << endl; this was just a check to figure out what was wrong
    newCh = alpha[((((i - key)+26)%26))];
    return newCh;
}

/*
Description: Randomly generates an integer in the range: [1..25]
Input: none
Output: returns a randomly generated integer in the range [1..25]
*/
int keyGen()
{
    unsigned seed = time(0);
    srand(seed);
    int i = rand() % (26);
    return i;
}


/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name because 'file' is a reference variable 
*/ 
void fileOpen(fstream& file, string name, char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " " << name <<" file" << endl; 
  exit(EXIT_FAILURE);
 }
}

/*
Descryption: finds the index of the char in the array of with the alphabet.
Input: Character and an array of alphabet
Return: int that is the index of the Character in the array
*/
int findIdx(char ch, char alpha[])
{
    int i =0;
    while(ch != alpha[i])
    {
        i++;
    }
    return i;
}