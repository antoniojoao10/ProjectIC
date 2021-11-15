#include <iostream>
#include <system_error>

#include "wave/file.h"

using namespace std;
using namespace wave;

int main() {
  // read file's content
  wave::File read_file;
  wave::Error err = read_file.Open("sample01.wav", wave::kIn);
  if (err) {
    std::cout << "Something went wrong in in open" << std::endl;
    return 1;
  }
  std::vector<float> content;
  err = read_file.Read(&content);
  if (err) {
    std::cout << "Something went wrong in read" << std::endl;
    return 2;
  }

  // write that same content to another file
  wave::File write_file;
  err = write_file.Open("copy01.wav", wave::kOut);
  if (err) {
    std::cout << "Something went wrong in out open" << std::endl;
    return 3;
  }
  write_file.set_sample_rate(read_file.sample_rate());
  write_file.set_bits_per_sample(read_file.bits_per_sample());
  write_file.set_channel_number(read_file.channel_number());

  err = write_file.Write(content);
  if (err) {
    std::cout << "Something went wrong in write" << std::endl;
    return 4;
  }

  return 0;
}