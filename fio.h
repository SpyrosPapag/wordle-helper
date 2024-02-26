#include <fstream>
#include <string>
#include <list>

using namespace std;


list<string> readfile(string filename){
    ifstream inputFile(filename);

    if (inputFile.good())
     {
        list<string> words;
        string current_sring = "";
        while (inputFile >> current_sring)
        	words.push_back(current_sring);

        inputFile.close();

        return words;

        }else
        throw "Error in reading file!";

}

void writetofile(list<string> words){
    ofstream outputfile;
    outputfile.open ("output.txt");
    for (auto iterator = words.begin(); iterator != words.end(); iterator++){
        outputfile << *iterator << " ";
    }
    outputfile.close();
}
