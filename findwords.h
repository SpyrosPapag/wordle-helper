#include <iostream>
#include <list>
#include <string>

#include <time.h>

using namespace std;

static int rcount = 1;


list<string> greenwords(list<string> words,char ch,int p){
        
    for(auto iterator = words.begin(); iterator != words.end(); iterator++)
    {
        const string& word = *iterator;

        if(word.at(p) != ch) // If word doesn`t have the green character(ch) in the right position(p) it gets deleted
            words.erase(iterator);
    }
    cout<<"Words with the character '"<<ch<<"' at position "<<p<<": "<<words.size()<<endl<<endl;
    return words;
}

list<string> greencheck(list<string> words){
    int greenflag = 0;
    char ch = ' ';
    int p = 0;

    do{
        cout<<"Give number of green characters in row "<<rcount<<": ";
        cin>>greenflag;
    }while(greenflag<0 || greenflag>4);


    if(greenflag!=0){
        for(int i=0;i<greenflag;i++){
            cout<<"Give green character "<<i+1<<": ";
            cin>>ch;
            
            do{
                cout<<"Give character position(1-5): ";
                cin>>p;
            }while(p<1 || p>5);
            
            words = greenwords(words,ch,p);
        }
        return words;
    }
    return words;
}

list<string> graywords(list<string> words,char ch){
    for(auto iterator = words.begin(); iterator != words.end(); iterator++){

        const string& word = *iterator;
        
        if(word.at(1)==ch||word.at(2)==ch||word.at(3)==ch||word.at(4)==ch||word.at(5)==ch) // If word has the gray character(ch) it gets deleted
            words.erase(iterator);
        
    }

    cout<<"Words w/o the character '"<<ch<<"': "<<words.size()<<endl<<endl;
    return words;
}

list<string> graycheck(list<string> words){
    int grayflag = 0;
    char ch = ' ';
    do{
        do{
            cout<<"Give number of gray characters in row "<<rcount<<": ";
            cin>>grayflag;
        }while(grayflag<0||grayflag>5);

        
        for(int i=0;i<grayflag;i++){
            cout<<"Give gray character "<<i+1<<": ";
            cin>>ch;
            words = graywords(words,ch);
        }

        if(grayflag == 5)
            rcount++;

    }while(grayflag==5);

    return words;
}

list<string> yellowwords(list<string> words,char ch,int p){
    
    for(auto iterator = words.begin(); iterator != words.end(); iterator++){
        
        const string& word = *iterator;
        
        if(word.at(p)==ch || (word.at(1)!=ch && word.at(2)!=ch && word.at(3)!=ch && word.at(4)!=ch && word.at(5)!=ch)) 
            words.erase(iterator); // If word doesn`t have the yellow character(ch) in any position or it has it in the position p it gets deleted
    }

    cout<<"Words w/o the character '"<<ch<<"' at position "<<p<<": "<<words.size()<<endl<<endl;
    return words;
}

list<string> yellowcheck(list<string> words){
    int yellowflag = 0;
    char ch = ' ';
    int p = 0;
    do{
        do{
            cout<<"Give number of yellow characters in row "<<rcount<<": ";
            cin>>yellowflag;
        }while(yellowflag<0||yellowflag>5);

        
        for(int i=0;i<yellowflag;i++){
            cout<<"Give yellow character "<<i+1<<": ";
            cin>>ch;

            do{
                cout<<"Give character position(1-5): ";
                cin>>p;
            }while(p<1 || p>5);

            words = yellowwords(words,ch,p);
        }

        if(yellowflag == 5)
            rcount++;   
    
    }while(yellowflag==5);

    return words;
}

list<string> findwords(list<string> words){
    words = graycheck(words);
    words = yellowcheck(words);
    words = greencheck(words);
    return words;
}