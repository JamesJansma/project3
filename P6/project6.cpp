/*
Name: James Jansma
Class: CPSC 222 Section 1
Date: February 18, 2022
Assignment Name: Project 6
Description: This program take input from the command line to decide to generate a key,
encrypt a plaintext, or decrypt an encrypted plaintext. It uses the transposition cipher which has
a key space of 26!-1
*/
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

//This is the constant P that is used for the size of the alphabet
const int P = 26;

char encrypt (char, int, int);
char decrypt (char, int, int, int[]);
void fileOpen(fstream&, string, char);
void fileControl (string,string,string,int);
void mysterySort(int k[P][2]);
bool sink(int k[P][2],int);
void swap(int k[P][2],int);
char transform(char ch, int encDec[]);
void keyGen (string keyFile);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);


int main(int argc,char* argv[])
{
    int mode = atoi(argv[1]);
    if(mode == 0)
        keyGen(argv[2]);
    else if(mode == 1 || mode == 2)
    {
        fileControl(argv[2],argv[3],argv[4],mode);
    }
    else
        cout<<"error";

}
/*
Description: Algorithm to sort the key array. Invoked within keyGen
Input: 26 position 2-D array, K, of integers with columns 0 and 1
Output: an array k’, where col 0 is the sorted version of col 1.
*/
void mysterySort(int k[][2])
{
    int bottom = P-1;
    bool shift = true;
    while(shift)
    {
        shift = sink(k,bottom);
        bottom--;
    }
    
}
/*
Description: Called by mystery sort.Moves item as far down the array as possible and invokes the swap function
Input: 26 position 2d array that is full of integers. Bot which has the bottom of the array
Output: a bool releases true if there is still more to be sorted.
*/
bool sink(int k[][2],int bot)
{
    bool shift = false;
    int cur = 0;
    while(cur< bot)
    {
        if(k[cur][1]> k[cur+1][1])
        {
            swap(k,cur);
        }
        shift = true;
        cur++;
    }
    return shift;
    
}
/*
Description: swaps the current item with the next item in line
Input:26 position 2d Array full of intergeres, and an int cur containing the index of the item being swapped
output:No output it is void.
*/
void swap(int k[][2],int cur)
{
    int tmp0 = k[cur][0];
    int tmp1 = k[cur][1];
    k[cur][0] = k[cur+1][0];
    k[cur][1] = k[cur+1][1];
    k[cur+1][0] = tmp0;
    k[cur+1][1] = tmp1;
}
/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[])
{
    int newLoc;
    char newCh;
    if(ch == '\n' || ch == ' ' || !isalpha(ch))
    {
            return ch;
    }
    else if(islower(ch))
        ch = toupper(ch);
    
    int loc = ch - 'A';
    newLoc = encDec[loc];
    newCh = newLoc + 'A';
    return newCh;
}
/*
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs  arrays for encryption and decryption.  The decryption array is sorted as explained above.  Use the function, MysterySort, described below to do the sorting.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5.  Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
    fstream fkin;
    fstream fin;
    fstream fout;
    fileOpen(fkin,keyFile,'r');
    fileOpen(fin,fileIn,'r');
    fileOpen(fout,fileOut,'w');

    string temp;
    int enc[P],dec[P][2],dec1D[P];
    char ch;
    for(int i=0;i<P;i++)
    {
        getline(fkin,temp);
        enc[i] = stoi(temp);
        dec[i][1] = stoi(temp);
        //cout << enc[i];
    }
    for(int i=0;i<P;i++)
    {
        dec[i][0] = i;
    }
    mysterySort(dec);
    for(int i =0;i<P;i++)
    {
        dec1D[i] = dec[i][0];
    }
    if(mode ==1)
    {
        while(fin.peek() != EOF)
        {
            ch = transform(fin.get(),enc);
            fout<<ch;
        }
    }
    else if(mode == 2)
    {
        while(fin.peek() != EOF)
        {
            ch = transform(fin.get(),dec1D);
            fout<<ch;
        }
    }
    

}

/*
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/
void keyGen (string keyFile)
{
    fstream fout;
    
    fileOpen(fout,keyFile,'w');
    int key[P];
    bool validate[P];
    int pos = 0;
    unsigned seed = time(0);
    srand(seed);
    for(int i=0;i<P;i++)
        validate[i] = false;
    while(pos<P)
    {
        while(true)
        {
            int k = ((rand() % P));
            // cout << k;
            if(!validate[k])
            {
                key[pos] = k;
                validate[k] = true;
                pos++;
                break;
            }
        }
    }
    for(int i=0;i<P;i++)
        fout << key[i] << endl;
    
    fout.close();
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
