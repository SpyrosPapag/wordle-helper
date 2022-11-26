#include <iostream>
#include <vector>
#include <string>

#include "findwords.h"
#include "fio.h"
#include "chance.h"
//#include "wordgaps.h"

using namespace std;
void displaywords(vector<string>);

int main(){
    //makefile();
    cout<<"*********************Program started!*********************"<<endl<<endl;
    char quitflag;
    vector<string> words = readfile("gaps.txt");
    /*findchance(words,1);
    int j = (int)words.size();
    words = mergesort(words,0,j-1);
    writetofile(words);*/
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

void displaywords(vector<string> words){
    char dispflag;
    do{
        cout<<"Do you want to display the words found?(y or n): ";
        cin>>dispflag;
    }while(dispflag!='y'&&dispflag!='n');

    if(dispflag=='y'){
    for(int i=0;i<(int)words.size();i++)
        cout<<words[i]<<endl;}
}
