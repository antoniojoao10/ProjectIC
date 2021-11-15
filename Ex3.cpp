#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sndfile.h>



using namespace std;

int main(int argc, char** argv){
    SNDFILE* read_file;
    SNDFILE* out_file;

    SF_INFO		sfinfo ;

    read_file = sf_open(argv[1], SFM_READ, &sfinfo);
    float *tmpIn = new float[sfinfo.channels * sfinfo.frames];
    sf_read_float(read_file, tmpIn, sfinfo.channels * sfinfo.frames);
    int frame = sfinfo.frames;
    sf_close(read_file);

    out_file = sf_open(argv[2], SFM_WRITE, &sfinfo);
    sfinfo.frames=frame;
    sf_write_float(out_file,tmpIn, sfinfo.channels * sfinfo.frames);
    sf_close(out_file);
    return 0;
}