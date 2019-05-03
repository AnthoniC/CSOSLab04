//
//  ThreadLab.c
//  Threads
//
//  Created by nah on 5/3/19.
//  Copyright © 2019 Austin College. All rights reserved.
//

#include "ThreadLab.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

void* PosixThreadMainRoutine(void* data)
{
    //With Mutex, there is not longer intermixing (Maybe a little at begingin because of slowness of prtinging) LMAO im dumb
    thread_comm* tc = (thread_comm*)data;
    
    
    char* message = tc->message;
    int* sharedData = tc->sharedData;
    pthread_mutex_lock(tc->mutext);
    
    for(int i = 0;i< 10000;i++){
        (*sharedData) += 5;
        printf("%s: %d\n",message, i);
    }
    pthread_mutex_unlock(tc->mutext);
    
    return NULL;
}

int Run_Lab(void){
    
    
    
    return 0;
}

