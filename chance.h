#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> mergesort(vector<string>,int,int);
/*
void findchance(vector<string> words,int p){
    int j = (int)words.size();
    int viewcount=1;
    char ch;
    vector<int> counter;



    for(int i=0;i<j-1;i++){
        if(words[i].at(p) == words[i+1].at(p)){
             viewcount++;
        }else{counter.push_back(viewcount);
             ch = words[i].at(p);
             viewcount=1;
        }
    }

    for(int i=0;i<(int)counter.size();i++){
        cout<<"Character '"<<ch<<"' has appeared: "<<counter[i]<<" times."<<i+1<<endl;
    }
}*/

vector<string> mergearrays(vector<string> a,vector<string> b){
    int i=a.size();
    int j=b.size();
    vector<string> mergedarray;

    while(!a.empty()&&!b.empty()){
            int l = a[i-1].compare(b[j-1]);
        if(l<0){
            mergedarray.push_back(a[i-1]);
            a.erase(a.begin()+(i-1));
            i-=1;
            }else{
                mergedarray.push_back(b[j-1]);
                b.erase(b.begin()+(j-1));
                j--;
                }
        }


    if(a.empty()&&!b.empty()){
        while(j>0){
        mergedarray.push_back(b[j-1]);
        j--;
        }
    }else if(!a.empty()&&b.empty()){
        while(i>0){
        mergedarray.push_back(a[i-1]);
        i--;
        }
    }
    return mergedarray;
}

vector<string> mergesort(vector<string> words,int start,int n){
    if(start<n){
    int q = (start + n)/2;
    vector<string> Array1 = mergesort(words,start,q);
    vector<string> Array2 = mergesort(words,q+1,n);
    vector<string> mergedarray = mergearrays(Array1,Array2);
    return mergedarray;
    }else return words;
}
