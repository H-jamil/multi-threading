#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
/*
 * compile using :
 * gcc -g -c thread_creation.c -o thread_creation.o
 * gcc -g thread_creation.o -o thread_creatione -lpthread
 * Run : ./thread_creation
 */

static void *
thread_fn_callback(void *arg){
  char *input =(char *)arg;
  while(1){
    printf("input string= %s\n",input);
    sleep(1);
  }
}

void
thread_create(){
  pthread_t pthread1;
  static char *input_thread1="I am thread no 1 which is created by main()";
  int rc= pthread_create(&pthread1,
                        NULL,
                        thread_fn_callback,
                        (void *)input_thread1);
  if(rc!=0){
    printf("Error occurred, thread could not be created, errno = %d\n", rc);
		exit(0);
  }
}

int main(int argc, char **argv){
  thread_create();
  printf("main fn paused\n");
	pause();
  // pthread_exit(0);
	return 0;

}
