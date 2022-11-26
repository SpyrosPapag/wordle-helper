#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void makefile(){
        //Read list of words--------------------------------------------------------------------------
        ifstream inputFile("words.txt");

        vector<string> words;
        string current_sring = "";
        while (inputFile >> current_sring)
        	words.push_back(current_sring);

        inputFile.close();

        //Removes comas-------------------------------------------------------------------------------
        words[0].erase(remove(words[0].begin(), words[0].end(),','), words[0].end());

        //Fills with spaces---------------------------------------------------------------------------
        string temp = " ";
        int j = words[0].size();
        for(int count=7;count<j;){
        words[0].insert(count,temp);
        j = words[0].size()+1;
        count += 8;
        }

        //Save list of words with spaces--------------------------------------------------------------
        ofstream outputfile;
        outputfile.open("gaps.txt");
        for (int count = 0; count <(int)words.size(); count++){
        outputfile << words[count] << " ";
        }
        outputfile.close();
}
