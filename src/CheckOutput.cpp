#include <iostream>
#include <map>
#include <cstdlib>
#include <stdio.h>
// #include <>

int main(int argc, char * argv[]) {

  if(argc < 4){
    std::cerr << "Number of arguments less than expected" << std::endl;
    exit(1);
  }

  FILE *  res_fd;
  char holder[20];
  const char * program = argv[1];
  int numRuns = atoi( argv[2] );
  int expectedResult = atoi( argv[3] );

  int numCorrect = 0;

  for(int i = 0; i < numRuns; i++) {
    res_fd = popen(argv[1], "r");

    if( !res_fd ) {
      std::cerr << "Something wrong happened" << std::endl;
      return 1; // something wrong happened

    }

    int bytes = fread(holder, 1, sizeof(holder), res_fd);
    int result = atoi(holder);

    if( result = expectedResult )
      numCorrect++;
     pclose(res_fd);

    std::cout << "run " << i+1 << "/" << numRuns <<  "\r";

    //std::cout <<"bytes: " << bytes  << " result "<< result << std::endl;
  }
  std::cout << "\r";

  std::cout << "program: " << program << std::endl
            << "# of runs: " << numRuns << std::endl
            << "correct runs: " << numCorrect << "(" << (numCorrect*100/numRuns) << "%)" << std::endl;

    std::cout << argv[1] << " " << numRuns << " " << expectedResult  << std::endl;
}