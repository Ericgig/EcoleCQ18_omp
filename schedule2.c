#include <stdio.h>
#include <omp.h>

int main(void) {
int i;
printf("schedule(static,2)\n");
#pragma omp parallel for schedule(static,2)
  for(i=0;i<10;i++){
      printf("Itération %d, fil %d\n", i, omp_get_thread_num());
  }
printf("schedule(dynamic)\n");
#pragma omp parallel for schedule(dynamic)
  for(i=0;i<10;i++){
      printf("Itération %d, fil %d\n", i, omp_get_thread_num());
  }
printf("schedule(dynamic,2)\n");
#pragma omp parallel for schedule(dynamic,2)
  for(i=0;i<10;i++){
      printf("Itération %d, fil %d\n", i, omp_get_thread_num());
  }
}
