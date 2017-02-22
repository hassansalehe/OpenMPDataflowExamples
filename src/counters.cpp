/* /////////////////////////////////////////////////////////////////////

  This simple code creates two OpenMP dataflow tasks.
  Each of this task increments a shared variable "counter".
  Since the initial value of "counter" is 0, the final value is 2.

  These tasks execute sequentially because there is a
  dependency between them and, therefore, no data race.

  Archer reports a data race between these tasks.
  We consider this as a weakness of Archer in tracking
  a correct ordering of dataflow tasks with dependencies.

/ *//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <omp.h>

int main() {
  int counter = 0;

  #pragma omp parallel num_threads(4) shared(counter)
  {
    #pragma omp master
    {
      #pragma omp task depend(out: counter) shared(counter)
      {
         counter++;
         std::cout << "Counter Thread: " << omp_get_thread_num() << std::endl;
      }

      #pragma omp task depend(in: counter) shared(counter)
      {
         counter++;
         std::cout << "Counter Thread: " << omp_get_thread_num() << std::endl;
      }
     
      #pragma omp taskwait
    }
  }

  std::cout << "counter = " << counter << std::endl;
  return 0;
}
