#include "common_pthreads.h"
#include <bits/pthreadtypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

volatile int counter = 0;
int loop;

void *worker(void *arg) {
	int i;
	for (i = 0; i < loop; i++) {
		counter++;
	}
	return NULL;
}

int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		fprintf(stderr, "usage: thread <value>\n");
		exit(1);
	}
	
	loop = atoi(argv[1]);
	pthread_t p1, p2;
	printf("Initial value: %d\n", counter);
	
	Pthread_create(&p1, NULL, worker, NULL);
	Pthread_create(&p2, NULL, worker, NULL);
	Pthread_join(p1, NULL);
	Pthread_join(p2, NULL);
	printf("Final value : %d\n", counter);
	
	return 0;
}