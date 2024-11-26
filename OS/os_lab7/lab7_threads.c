#include <stdio.h>
#include <pthread.h>

void* print_message(void* msg){
    printf("%s\n",(char*)msg);
    return NULL;
}

int main(){
    pthread_t thread1,thread2;
    const char* message1="Hello from Thread 1!";
    const char* message2="Hellow from Thread 2!";

    if(pthread_create(&thread1,NULL,print_message,(void*)message1)){
        fprintf(stderr,"Error creating thread 1\n");
        return 1;
    }
    if (pthread_create(&thread2,NULL,print_message,(void*)message2)){
        fprintf(stderr,"Error creating thread 2\n");
        return 1;
    }
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("Both threrads have finished execution\n");
    return 0;
}