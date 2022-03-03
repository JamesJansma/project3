/*
Name: James Jansma
Class: CPSC 222 Section 1
Date: Febraury 11, 2022
Assignment Name: Project 5
Description: This program take input from the command line to decide to genretate a key,
encrypt a plaintext, or decrypt an encrypted plaintext. It does it using the affine cipher
which has a bigger key space than the substitution cypher. 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

void keyGen(string);
char encrypt (char, int, int);
char decrypt (char, int, int, int[]);
void fileOpen(fstream&, string, char);
void fileControl (string,string,string,int);

int p = 27;

int main(int argc,char* argv[])
{
    if(atoi(argv[1]) == 0)
        keyGen(argv[2]);
    else if(atoi(argv[1]) == 1)
        fileControl (argv[2],argv[3],argv[4], 1);
    else if(atoi(argv[1]) == 2)
        fileControl (argv[2],argv[3],argv[4], 2);
    else
    {
        cout << "Did not enter a viable number" << endl;
        exit(EXIT_FAILURE);
        return 0;
    }

}


/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
	*/

char encrypt (char ch, int alpha, int beta)
{
    
        
    int pos = ch - 'A';
    pos = (((pos*alpha) + beta)%26);
    return (pos + 'A');
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt (char ch, int alpha, int beta, int MI[])
{
    
    int pos = ch - 'A';
    pos = ((MI[alpha]*pos) - (MI[alpha]*beta) + p * 26) % 26;
    return (pos + 'A');
}

/*
Description: Randomly generates an integer in the range: [1..25]
Input: none
Output: returns a randomly generated integer in the range [1..25]
*/
void keyGen(string keyFile)
{
    int alpha[] = {1,3,5,7,11,17,19,25};
    fstream fout;
    fileOpen(fout,keyFile,'w');
    unsigned seed = time(0);
    srand(seed);
    int i = rand() % (26);
    fout << i;
    fout << "\n";
    int j = (rand() % (8)) -1;
    fout << alpha[j];
    fout.close();

}
/*
Description: invokes fileOpen (../B-Files/7-openFileError.cpp in my GitHub repo) on all files.  Closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt. If the action is encrypt, alphabetic characters are transformed to upper case.   Writes the result of encrypt or decrypt to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
	*/
	void fileControl (string keyFile, string fileIn, string fileOut, int mode)
    {
        fstream fin;
        fstream fout;
        fstream fkin;
        fstream foutD;
        char inChar,newChar;
        string a,b;
        int alpha,beta;
        int mi[] = {0,1,0,9,0,21,0,15,0,0,0,19,0,0,0,0,0,23,0,11,0,0,0,0,0,25};

        fileOpen(fin,fileIn,'r');
        fileOpen(fout,fileOut,'w');
        fileOpen(fkin,keyFile,'r');
        
        getline(fkin,b);
        getline(fkin,a);
        alpha = stoi(a);
        beta = stoi(b);
        if(mode == 1)
        {
            
            while (fin.peek() != EOF)
            {   
                inChar = fin.get();
                    if(inChar == '\n' || inChar == ' ' || !isalpha(inChar))
                    {
                        fout << inChar;
                    }
                    else if(islower(inChar))
                    {
                        inChar = toupper(inChar);
                        newChar = encrypt(inChar,alpha,beta);
                        fout << newChar;
                    }
                    else
                    {
                        newChar = encrypt(inChar,alpha,beta);
                        fout << newChar;
                    }
            }
        }
        else if(mode == 2)
        {
            while (fin.peek() != EOF)
            {   
                inChar = fin.get();
                    if(inChar == '\n' || inChar == ' ' || !isalpha(inChar))
                    {
                        fout << inChar;
                    }
                    else
                    {
                        newChar = decrypt(inChar,alpha,beta,mi);
                        fout << newChar;
                    }
            }
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
