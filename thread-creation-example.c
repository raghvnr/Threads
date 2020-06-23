#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void* threadfunc(void* args)
{
    int* p = (int*) args;
    int num = *p;
    printf("Thread Number: %d\n", num);
    return 0;
}

int main()
{
    int i;

    pthread_t tid[NUM_THREADS];
    for(i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, threadfunc, &i);
    }

    for(i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

/*
Outputs recd

Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ gcc -o thread thread-creation-example.c -lpthread
Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ ls -la
total 32
drwxr-xr-x  4 raghavanrajagopalan  staff   128 Jun 23 08:10 .
drwxr-xr-x  9 raghavanrajagopalan  staff   288 Jun 23 07:28 ..
-rwxr-xr-x  1 raghavanrajagopalan  staff  8732 Jun 23 08:10 thread
-rw-r--r--@ 1 raghavanrajagopalan  staff   461 Jun 23 08:10 thread-creation-example.c
Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ ./thread 
Thread Number: 2
Thread Number: 3
Thread Number: 3
Thread Number: 3
Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ ./thread 
Thread Number: 1
Thread Number: 2
Thread Number: 3
Thread Number: 0
Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ ./thread 
Thread Number: 0
Thread Number: 0
Thread Number: 0
Thread Number: 0
Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ ./thread 
Thread Number: 1
Thread Number: 2
Thread Number: 3
Thread Number: 0
Raghavans-MacBook-Pro:Threads raghavanrajagopalan$ ./thread 
Thread Number: 1
Thread Number: 3
Thread Number: 3
Thread Number: 0
*/