/*
Name: James Jansma
Class: CPSC 222
Date: January 21, 2022
Assignment Name: Project 1
Description: This program takes a number of columns and a number of prime numbers
from the command line and then prints out the amount a list of prime numbers in 
columns
Effecient isPrime algorithm goes from 2 to the square root of the number that is in question.
If a factor is found in that range it is obviously not prime. 
No need to go further than the square root.
*/


#include <iostream>
using namespace std;

void display(int,int);
bool isPrime(int);
void error(int);

int main(int argc, char* argv[])
{
    int columns, amountPrime;

    columns = atoi(argv[1]);
    if(columns < 1)
        error(1);

    amountPrime = atoi(argv[2]);
    if(amountPrime < 1)
        error(2);

    display(amountPrime, columns);



}

bool isNumPrime(int num)
{

    if (num == 1) 
    {
        return false;
    }

    int i = 2;
   
    while (i*i <= num) {
       
        if (num % i == 0) 
        {
            
            return false;
        }

        i += 1;
    }
    
    return true;



}
//displays prime numbers in columns
//input: amount of prime numbers wanted and the amount of columns
void display(int amount, int cols){
    int count = 1;
    int value = 1;

    while(count <= amount)
    {
        if(isNumPrime(value))
        {
            cout << value << '\t';
            
            if(count % cols == 0)
            {
            cout << endl;
            }
            count++;
        }
    value++;
    }

}



void error(int code){
    if (code == 1)
    {
        cout << "Columns must be <= 1" << endl;
        exit(EXIT_FAILURE);
    }
    if (code == 2)
    {
        cout << "Amount of prime numbers must be <= 1" << endl;
        exit(EXIT_FAILURE);
    }
}