//*****************
//Author: Nabin Chaudhary
//IDE Used: Visual Studio
//Program description:  My program will reverse the 
//  conents of files using dynamic stack 

#include <iostream>              // for cin and cout 
#include <iomanip>
#include <string>                // for working with variables 
#include <fstream>               // for working with files 
#include "Stack.h"               // for working with Stack.h header files 
using namespace std;

// function main 
int main()
{
    ifstream fin;                // for reading the files 
    ofstream fout;               // for creating the files 
    char words;                   
    Stack<char>stacks;           // dynamically allocating template
    
    // opening the files 
    fin.open("input.txt", ios::in);
    if (fin)
    {
    cout << "Reading the content from the file:\n";
    while(fin.get(words))
    {
        cout << words;
        stacks.push(words);
    }
    }
    else 
    {
        cout<<"ERROR...Cannot open the file!!"<<endl;
    }
    
    // creating a file 
    fout.open("output.txt", ios::out);
    
    if (fout)
    {
    cout << "\n\nWriting the content in the file:\n";
    while(!stacks.isEmpty()){
        stacks.pop(words);
        cout << words;
        fout << words;
    }
    }
    else 
    {
        cout<<"ERROR...Cannot open the file!!"<<endl;
    }
    
    fin.close();           // closing the reading file 
    fout.close();          // closing the create file

    return 0;
}
// end of the program 
