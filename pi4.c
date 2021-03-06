#include <stdio.h>
#include <omp.h>

int main(void) {
int i, N=1000000000;
double sum;
#pragma omp parallel for reduction(+:sum)
  for(i=0;i<N;i+=2){
    sum += 4./(2.*i+1.);
    sum -= 4./(2.*i+3.);
  }
  printf("pi = %f\n",sum);
}
