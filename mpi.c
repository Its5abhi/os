#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define NUMBERS 100
int main(int argc, char** argv) {
 int rank, size;
 int numbers[NUMBERS];
 int local_sum = 0, global_sum = 0;
 
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 
 // Initialize random seed
 srand(rank);
 // Generate local random numbers
 for (int i = 0; i < NUMBERS; i++) {
 numbers[i] = rand() % 1000;
 local_sum += numbers[i];
 }
 // Sum local sums across processes
 MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
 // Print result from root process
 
 if (rank == 0) {
 printf("Sum of %d random numbers: %d\n", NUMBERS * size, global_sum);
 }
 MPI_Finalize();
 return 0;
}
















#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define NUMBERS 100
int main(int argc, char** argv) {
 int rank, size;
 int numbers[NUMBERS];
 int local_min = INT_MAX, local_max = INT_MIN;
 int global_min, global_max;
 
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 // Initialize random seed
 srand(rank);
 // Generate local random numbers
 for (int i = 0; i < NUMBERS; i++) {
 numbers[i] = rand() % 100;
 if (numbers[i] < local_min) {
 local_min = numbers[i];
 }
 if (numbers[i] > local_max) {
 local_max = numbers[i];
 }
 }
 // Find local minimum and maximum
 MPI_Allreduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
 MPI_Allreduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
 // Print result from all processes
 printf("Process %d: Local min = %d, Local max = %d\n", rank, local_min, local_max);
 // Print global result from root process
 if (rank == 0) {
 printf("Global min = %d, Global max = %d\n", global_min, global_max);
 }
 MPI_Finalize();
 return 0; }

mpicc hello_mpi.c -o hello_mpi
mpiexec -n 4 ./hello_mpi
