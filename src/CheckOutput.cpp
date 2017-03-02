///////////////////////////////////////////////////////////////////////
//
//                  (c) 2017 - Hassan Salehe Matar
//
//  Description:
//   * Runs your program multiple times and checks the outputs against
//     the expected output. Then, it prints the correct statistics.
//
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <cstdlib>
#include <stdio.h>


int main(int argc, char * argv[]) {

  if(argc < 4){
    std::cerr << "Number of arguments less than expected" << std::endl;
    std::cerr << "Format: ./Checkoutput <your_program_name> <number_of_runs> <expected_output>" << std::endl;
    exit(1);
  }

  FILE *  res_fd;
  char holder[20];
  std::string program = "./"; program.append( argv[1] );

  int numRuns = atoi( argv[2] );
  int expectedResult = atoi( argv[3] );

  int numCorrect = 0;

  for(int i = 0; i < numRuns; i++) {
    res_fd = popen( program.c_str(), "r" );

    if( !res_fd ) {
      std::cerr << "Something wrong happened while executing your program" << std::endl;
      return 1;

    }

    int bytes = fread( holder, 1, sizeof( holder ), res_fd );
    int result = atoi( holder );

    if( result == expectedResult )
      numCorrect++;
     pclose( res_fd );

    std::cout << "run " << i+1 << "/" << numRuns <<  "\r";

    //std::cout <<"bytes: " << bytes  << " result "<< result << std::endl;
  }
  std::cout << "\r";

  std::cout << "program: "      << program    << std::endl
            << "# of runs: "    << numRuns    << std::endl
            << "correct runs: " << numCorrect << "("
            << ( numCorrect * 100 / numRuns ) << "%)" << std::endl;

  return 0;
}

