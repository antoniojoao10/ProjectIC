#include<iostream>
#include<fstream>
#include<vector>  
#include<stdio.h>
#include<string.h>
#include<sndfile.h>

using namespace std;

int main(int argc, char** argv){
    SNDFILE* read_file;
    SNDFILE* out_file;
    ofstream ofs(argv[2]);

    SF_INFO		sfinfo ;

    read_file = sf_open(argv[1], SFM_READ, &sfinfo);
    short *tmpIn = new short[sfinfo.channels * sfinfo.frames];
    sf_read_short(read_file, tmpIn, sfinfo.channels * sfinfo.frames);
    int channels = sfinfo.channels;
    int frame = sfinfo.frames;
    sf_close(read_file);

    vector<short> out;
    vector<int> outNumber;
    int add =1;

    for(int a =0; a < frame*channels ; a++){
        ofs << tmpIn[a] << endl;
        for( int i =0 ; i < out.size() ; i++){
            if( out.at(i) == tmpIn[a]) {
                outNumber.at(i)++;
                add =0;
                cout << i << endl;
                break;
            }
        }
        if( add == 1   ){
            out.push_back(tmpIn[a]);
            outNumber.push_back(1);
        }
        add = 1;
    }

    ofstream ofs1(argv[3]);
        
    
    
    for(int i =0 ; i < out.size(); i++){
        ofs1 << out.at(i) << "\t-->\t" << outNumber.at(i) << endl;
    }
    return 0;
}