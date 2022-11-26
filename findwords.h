#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int rcount=1;


vector<string> greenwords(vector<string> words,char ch,int p){
        int j = (int)words.size();
        for(int i=0;i<j;i++){
            if(words[i].at(p)!=ch){
                words.erase(words.begin()+i);
                i-=1;
                j = (int)words.size();
                }
        }
        cout<<"Words with the character '"<<ch<<"' at position "<<p<<": "<<words.size()<<endl<<endl;
        return words;
}

vector<string> greencheck(vector<string> words){
    int greenflag;
            do{
            cout<<"Give number of green characters in row "<<rcount<<": ";
            cin>>greenflag;
            }while(greenflag<0||greenflag>4);


        if(greenflag!=0){
            for(int i=0;i<greenflag;i++){
                        cout<<"Give green character "<<i+1<<": ";
                        char ch;
                        cin>>ch;
                        int p;
                        do{
                            cout<<"Give character position(1-5): ";
                            cin>>p;
                        }while(p!=1&&p!=2&&p!=3&&p!=4&&p!=5);
                        words = greenwords(words,ch,p);
                     }
                     return words;
            }
            return words;
}

vector<string> graywords(vector<string> words,char ch){
      int j = (int)words.size();
        for(int i=0;i<j;i++){
            if(words[i].at(1)==ch||words[i].at(2)==ch||words[i].at(3)==ch||words[i].at(4)==ch||words[i].at(5)==ch){
                words.erase(words.begin()+i);
                i-=1;
                j = (int)words.size();
                }
        }
        cout<<"Words w/o the character '"<<ch<<"': "<<words.size()<<endl<<endl;
        return words;
}

vector<string> graycheck(vector<string> words){
    int grayflag;
        do{
            do{
            cout<<"Give number of gray characters in row "<<rcount<<": ";
            cin>>grayflag;
            }while(grayflag<0||grayflag>5);

            switch(grayflag){
                case 0: break;

                case 5:{for(int i=0;i<grayflag;i++){
                            cout<<"Give gray character "<<i+1<<": ";
                            char ch;
                            cin>>ch;
                            words = graywords(words,ch);
                            }
                        rcount++;
                        }break;

                default:{for(int i=0;i<grayflag;i++){
                            cout<<"Give gray character "<<i+1<<": ";
                            char ch;
                            cin>>ch;
                            words = graywords(words,ch);
                            }
                        }break;
            }
        }while(grayflag==5);
        return words;
}

vector<string> yellowwords(vector<string> words,char ch,int p){
    int j = (int)words.size();
        for(int i=0;i<j;i++){
            if(words[i].at(p)==ch){
                words.erase(words.begin()+i);
                i-=1;
                j = (int)words.size();
                }
        }
        for(int i=0;i<j;i++){
                    if(words[i].at(1)!=ch&&words[i].at(2)!=ch&&words[i].at(3)!=ch&&words[i].at(4)!=ch&&words[i].at(5)!=ch){
                        //cout<<words[i]<<"   "<<k<<"     "<<words[i].at(k)<<endl;
                        words.erase(words.begin()+i);
                        i-=1;
                        j = (int)words.size();
                    }
        }
        cout<<"Words w/o the character '"<<ch<<"' at position "<<p<<": "<<words.size()<<endl<<endl;
        return words;
}

vector<string> yellowcheck(vector<string> words){
    int yellowflag;
        do{
            do{
            cout<<"Give number of yellow characters in row "<<rcount<<": ";
            cin>>yellowflag;
            }while(yellowflag<0||yellowflag>5);

            switch(yellowflag){
                case 0: break;

                case 5:{for(int i=0;i<yellowflag;i++){
                            cout<<"Give yellow character "<<i+1<<": ";
                            char ch;
                            cin>>ch;

                            int p;
                            do{
                            cout<<"Give character position(1-5): ";
                            cin>>p;
                            }while(p!=1&&p!=2&&p!=3&&p!=4&&p!=5);
                            words = yellowwords(words,ch,p);
                            }
                        rcount++;
                        }break;

                default:{for(int i=0;i<yellowflag;i++){
                            cout<<"Give yellow character "<<i+1<<": ";
                            char ch;
                            cin>>ch;
                            int p;
                            do{
                            cout<<"Give character position(1-5): ";
                            cin>>p;
                            }while(p!=1&&p!=2&&p!=3&&p!=4&&p!=5);
                            words = yellowwords(words,ch,p);
                            }
                        }break;
            }
        }while(yellowflag==5);
        return words;
}

vector<string> findwords(vector<string> words){
    words = graycheck(words);
    words = yellowcheck(words);
    words = greencheck(words);
    return words;
}

/*
vector<string> findword(vector<string> words,char c1,int p1,char c2,int p2){
        int j = (int)words.size();
        for(int i=0;i<j;i++){
            if(words[i].at(p1)!=c1||words[i].at(p2)!=c2){
                words.erase(words.begin()+i);
                i-=1;
                j = (int)words.size();
                }
        }
        cout <<endl<<"Words found: "<<words.size()<< endl;
        return words;
}

vector<string> findword(vector<string> words,char c1,int p1,char c2,int p2,char c3,int p3){
        int j = (int)words.size();
        for(int i=0;i<j;i++){
            if(words[i].at(p1)!=c1||words[i].at(p2)!=c2||words[i].at(p3)!=c3){
                words.erase(words.begin()+i);
                i-=1;
                j = (int)words.size();
                }
        }
        cout <<endl<<"Words found: "<<words.size()<< endl;
        return words;
}

vector<string> findword(vector<string> words,char c1,int p1,char c2,int p2,char c3,int p3,char c4,int p4){
        int j = (int)words.size();
        for(int i=0;i<j;i++){
            if(words[i].at(p1)!=c1||words[i].at(p2)!=c2||words[i].at(p3)!=c3||words[i].at(p4)!=c4){
                words.erase(words.begin()+i);
                i-=1;
                j = (int)words.size();
                }
        }
        cout <<endl<<"Words found: "<<words.size()<< endl;
        return words;
}*/
