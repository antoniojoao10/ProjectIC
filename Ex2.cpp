#include <iostream>
#include <fstream>
using namespace std;
 
int main(int argc, char** argv) {
    string line;
    ifstream iFile;
    ofstream oFile;

    iFile.open(argv[1]);
    oFile.open(argv[2]);
 
    if(iFile && oFile){
        while(getline(iFile,line))
            oFile << line << "\n";

        cout << "Copy Finished \n";
    } else 
        printf("Cannot read File");
 
    iFile.close();
    oFile.close();
 
    return 0;
}