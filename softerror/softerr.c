/*
Name: Samuel Villarreal
Email: svill017@ucr.edu
Project: soft-err correction, Research Assistant for Zizhong Chen
Organization: University of California Riverside  
*/

#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "arr.h"

#define NTHREADS 40
#defube SIZE 1000000
/* pointer for calculated matrix */
float *C;

/* prints array for debugging size 1000x1000*/
void printa(float *a)
{
	int i;
	for(i = 0; i < 1000000; i++)
		printf("%f ", a[i]);
}

void mult(void * varg)
{

} 

void run_threads(int* pids)
{
  int i;
  int steps = SIZE / NTHREADS;
  for(i=0; i <= NTHREADS; i++)
  {
		// "serve" array represents the range which a thread will calculate
		int* serve = (int*)malloc(sizeof(int)*2);
		*serve =  j * steps;
		*(serve+1) = (j+1)*steps;
		//creating the thread 
		pthread_create(&pids[i], NULL, mult, serve);
	}
}

int main()
{
	int pids[NTHREADS] = {0};

	/* a Matrix multiplying validity function may be needed depending on
	   how this is being tested A and B are both predetermined and
	   equivalent square matrices 
	*/
	run_threads(pids);

	return 0;
}
