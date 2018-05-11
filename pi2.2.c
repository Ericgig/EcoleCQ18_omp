#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 8

int main(void) {
int i, N=1000000000, fil_n;
double Sum =0., sum[NUM_THREADS];
omp_set_num_threads(NUM_THREADS);

#pragma omp parallel default(none) shared(sum,N) private(fil_n,i)
  {
    fil_n = omp_get_thread_num();
    sum[fil_n] = 0.;
#pragma omp for
    for(i=0;i<N;i+=2){
  sum[fil_n] += 4./(2.*i+1.);
  sum[fil_n] -= 4./(2.*i+3.);
    }
  }
  for(i=0;i<NUM_THREADS;i++){
Sum += sum[i];
  }
  printf("pi = %f\n",Sum);
}
