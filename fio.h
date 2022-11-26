#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readfile(string filename){
    ifstream inputFile(filename);

    if (inputFile.good())
     {
        vector<string> words;
        string current_sring = "";
        while (inputFile >> current_sring)
        	words.push_back(current_sring);

        inputFile.close();

        return words;

        }else
        throw "Error in reading file!";

}

void writetofile(vector<string> words){
    ofstream outputfile;
    outputfile.open ("output.txt");
    for (int count = 0; count <(int)words.size(); count++){
    outputfile << words[count] << " ";
    }
    outputfile.close();
}
