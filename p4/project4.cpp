/*
Name: James Jansma
Class: CPSC 222 Section 1
Date: Febraury 4, 2022
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
int keyGenCtr(int,string);
int findIdx(char, char[]);

int main(int argc,char* argv[])
{
    char inChar,newChar;
    int key;
    fstream fin;
    fstream fkin;
    fstream fout;

    key = keyGenCtr(atoi(argv[1]),argv[2]);
    if((atoi(argv[1])) == 1)
    {
        fileOpen(fin,argv[3],'r');
        fileOpen(fout,argv[4],'w');
        while (fin.peek() != EOF)
        {
            if(islower(inChar))
                inChar = toupper(inChar);
            newChar = encrypt(inChar,key);
            fout << newChar;
        }
    }
    else if(atoi(argv[1]) == 2)
    {
        fileOpen(fin,argv[3],'r');
        fileOpen(fout,argv[4],'w');
        while (fin.peek() != EOF)
        {
            inChar = fin.get();
            newChar = decrypt(inChar,key);
            fout << newChar;
        }
    }
    fin.close();
    fkin.close();
    fout.close();
}


/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
    if(ch == '\n' || ch == ' ' || !isalpha(ch))
    {
        return ch;
    }
        
    int pos = ch - 'A';
    pos = (((pos + key)%26));
    return (pos + 'A');
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
    if(ch == '\n' || ch == ' ' || !isalpha(ch))
    {
        return ch;
    }
    int pos = ch - 'A';
    pos = ((((pos - key) + 26)% 26));
    return (pos + 'A');
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


int keyGenCtr(int num,string name)
{
    fstream fkin;
    int key;
    if(num == 0){
        fileOpen(fkin,name,'w');
        key =  keyGen();
        fkin << key;
        return key;
    }
    else if(num == 1 || num == 2)
    {
        fileOpen(fkin,name,'r');
        fkin >> key;
        return key;
    }
    else
    {
        cout << "Did not enter a viable number" << endl;
        exit(EXIT_FAILURE);
        return 0;
    }

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
// int findIdx(char ch, char alpha[])
// {
//     int i =0;
//     while(ch != alpha[i])
//     {
//         i++;
//     }
//     return i;
// }