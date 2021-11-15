#include<iostream>
#include<fstream>
#include<vector>  
using namespace std;

int main(int argc, char** argv){
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);

    string line;
    string allLines;
    vector<char> out;
    vector<int> outNumber;
    while(!ifs.fail()){
        getline(ifs,line);
        allLines.append(line);
    }
    
    out.push_back( allLines[0] );
    outNumber.push_back(1);
    for( int it = 1; it < allLines.size(); ++it) {
        int add = 0;
        for(int i =0 ; i < out.size(); i++){
            if( out.at(i) == allLines[it] ) {
                outNumber.at(i)++;
                add =1;
            }
        }
        if(add==0){
            out.push_back( allLines[it] );
            outNumber.push_back(1);
        }
    }
    for(int i =0 ; i < out.size(); i++){
        ofs << out.at(i) << "\t-->\t" << outNumber.at(i) << endl;
    }
    return 0;
}