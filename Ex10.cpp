#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sndfile.h>
#include<fstream>
#include<vector>  
#include<tgmath.h> 


using namespace std;

int main(int argc, char** argv){
    SNDFILE* read_file;
    SNDFILE* out_file;

    SF_INFO		sfinfo ;

    read_file = sf_open(argv[1], SFM_READ, &sfinfo);
    short *tmpIn = new short[sfinfo.channels * sfinfo.frames];
    sf_read_short(read_file, tmpIn, sfinfo.channels * sfinfo.frames);
    int frame = sfinfo.frames;
    sf_close(read_file);

    out_file = sf_open(argv[2], SFM_WRITE, &sfinfo);
    sfinfo.frames=frame;

    vector<int> out;

    for( int i=0 ; i < frame* sfinfo.channels ; i++){
        short tp = tmpIn[i];
        short tmp = tmpIn[i] >> 12;
        tmpIn[i] = tmp << 12;
        int res = 0;
        if( tp - tmpIn[i] == 0)  res = tp;
        else res = tp/(tp-tmpIn[i]);
        out.push_back(res);
    }

    int res = 0;
    for( int i = 0 ; i < out.size() ; i++){
        res += out.at(i);
    }
    cout << 10*log10(res) << endl;
    
    sf_write_short(out_file,tmpIn, sfinfo.channels * sfinfo.frames);
    sf_close(out_file);
    return 0;
}