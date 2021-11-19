#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream iFile;
    ofstream oFile;

    iFile.open(argv[1]);

    // Gets original image first byte
    char * first_byte = new char [3];
    iFile >> first_byte;

    // Gets original width
    char * width = new char [3];
    iFile >> width;

    // Gets original image height
    char * height = new char [3];
    iFile >> height;

    // Gets original image max
    char * max = new char [3];
    iFile >> max;

    oFile.open("new_image.ppm");
    oFile << first_byte << endl;
    oFile << width << " " << height << endl;
    oFile << max;
    
    char * buffer = new char [3];
    while (iFile.good()) {
        iFile.read(buffer, 3);
        oFile.write(buffer, 3);
    }
}