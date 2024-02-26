#include <iostream>
#include <string>
#include <list>
#include "findwords.h"
#include "fio.h"

using namespace std;
void displaywords(list<string>);

int main(){
    cout<<"*********************Program started!*********************"<<endl<<endl;
    char quitflag;
    list<string> words = readfile("gaps.txt");
    
    do{
       words = findwords(words);
       writetofile(words);
       displaywords(words);

        do{
            cout<<"Do you want to continue?(y or q to quit): ";
            cin>>quitflag;
        }while(quitflag!='y'&&quitflag!='q');
        
        rcount++;
    }while(quitflag!='q');

    cout<<endl<<"**********************Program ended!**********************"<<endl;
    return 0;
}

void displaywords(list<string> words){
    char dispflag = ' ';
    do{
        cout<<"Do you want to display the words found?(y or n): ";
        cin>>dispflag;
    }while(dispflag!='y'&&dispflag!='n');

    if(dispflag=='y'){
        for (auto iterator = words.begin(); iterator != words.end(); iterator++)
            cout << *iterator << endl;   
    }
}