///////////////////////////////////////////////////////////////////////
//
//                  (c) 2017, 2018 - Hassan Salehe Matar
//
//  Description:
//
//   *  This program creates 4 tasks namely INITIALIZER, COMMISSIONER,
//      DEPOSITOR, and WITHDRAWER.
//
//   *  The expected execution order of these tasks is
//      INITIALIZER -> COMMISSIONER -> DEPOSITOR -> WITHDRAWER.
//      This execution order is ensured by the data flow dependency
//      specified using the depend clause of OpenMP task pragma.
//
//   *  Unfortunately, Archer reports races on this setting.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <omp.h>

// balance
float balance;

// tokens
int token1;
int token2;
int token3;


int main() {

  #pragma omp parallel num_threads(4)
  {
    #pragma omp single
    {
      //std::cout << "There are " << omp_get_num_threads() << " threads"<< std::endl;

      // INITIALISER task
      #pragma omp task depend(out:token1)
      {
        balance  = 1000; // set balance
        token1 = 1; // trigger next task
      }


      // COMMISSIONER task
      #pragma omp task depend(in:token1) depend(out:token2)
      {
        float rate = 0.2; // commission rate
        balance += (balance * rate); // add commission
        token2 = 1; // trigger next task
      }

      // DEPOSITOR task
      #pragma omp task depend(in:token2) depend(out:token3)
      {
        int amount = 200;
        balance += amount;
        token3 = 1; // trigger next task
      }

      // WITHDRAWER task
      #pragma omp task depend(in:token3)
      {
        int amount = 500; // amount to withdraw
        balance -= amount; // deduce amount withdrawn
      }

      // wait all tasks to complete
      #pragma omp taskwait
      //std::cout << "balance: " << balance << std::endl;
      std::cout << balance << std::endl;
    }
  }
  return (int)balance;
}
