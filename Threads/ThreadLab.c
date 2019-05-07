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
#define should_print 0

void* PosixThreadMainRoutineTestOne(void* data)
{
    //With Mutex, there is not longer intermixing (Maybe a little at begingin because of slowness of prtinging) LMAO im dumb
    thread_comm* tc = (thread_comm*)data;
    
    
    char* message = tc->message;
    int* sharedData = tc->sharedData;
    int* run_counter = tc->counter;
    
    
    for(int i = 0;i< 1000000 ;i++){
        pthread_mutex_lock(tc->mutext_one);
        (*sharedData) += 1;
        pthread_mutex_unlock(tc->mutext_one);
        
        pthread_mutex_lock(tc->mutext_two);
        (*run_counter)++;
        pthread_mutex_unlock(tc->mutext_two);
        
        if(should_print){
            printf("%s: %d\n",message, i);
        }
    }
    
    return NULL;
}

void* PosixThreadMainRoutineTestTwo(void* data)
{
    //With Mutex, there is not longer intermixing (Maybe a little at begingin because of slowness of prtinging) LMAO im dumb
    thread_comm* tc = (thread_comm*)data;
    
    
    char* message = tc->message;
    int* sharedData = tc->sharedData;
    int* run_counter = tc->counter;
    
    
    for(int i = 0;i< 1000000 ;i++){
        pthread_mutex_lock(tc->mutext_one);
        (*sharedData) += 2;
        pthread_mutex_unlock(tc->mutext_one);
        
        pthread_mutex_lock(tc->mutext_two);
        (*run_counter)++;
        pthread_mutex_unlock(tc->mutext_two);
        
        if(should_print){
            printf("%s: %d\n",message, i);
        }
    }
    
    return NULL;
}

void* PosixThreadMainRoutineTestThree(void* data)
{
    //With Mutex, there is not longer intermixing (Maybe a little at begingin because of slowness of prtinging) LMAO im dumb
    thread_comm* tc = (thread_comm*)data;
    
    
    char* message = tc->message;
    int* sharedData = tc->sharedData;
    int* run_counter = tc->counter;
    
    
    for(int i = 0;i< 1000000 ;i++){
        pthread_mutex_lock(tc->mutext_one);
        (*sharedData) += 3;
        pthread_mutex_unlock(tc->mutext_one);
        
        pthread_mutex_lock(tc->mutext_two);
        (*run_counter)++;
        pthread_mutex_unlock(tc->mutext_two);
        
        if(should_print){
            printf("%s: %d\n",message, i);
        }
    }
    
    return NULL;
}

void* PosixThreadMainRoutineTestFour(void* data)
{
    //With Mutex, there is not longer intermixing (Maybe a little at begingin because of slowness of prtinging) LMAO im dumb
    thread_comm* tc = (thread_comm*)data;
    
    
    char* message = tc->message;
    int* sharedData = tc->sharedData;
    int* run_counter = tc->counter;
    
    
    for(int i = 0;i< 1000000 ;i++){
        pthread_mutex_lock(tc->mutext_one);
        (*sharedData) += 4;
        pthread_mutex_unlock(tc->mutext_one);
        
        pthread_mutex_lock(tc->mutext_two);
        (*run_counter)++;
        pthread_mutex_unlock(tc->mutext_two);
        
        if(should_print){
            printf("%s: %d\n",message, i);
        }
    }
    
    return NULL;
}


void RunLab()
{
    // Create the thread using POSIX routines.
    pthread_attr_t  attr,attr2, attr3, attr4;
    pthread_t       posixThreadID,posixThreadID2,posixThreadID3,posixThreadID4;
    int             returnVal, returnVal2, returnVal3, returnVal4;
    int times_ran = 0;
    
    
    returnVal = pthread_attr_init(&attr);
    assert(!returnVal);
    returnVal2 = pthread_attr_init(&attr2);
    assert(!returnVal2);
    returnVal3 = pthread_attr_init(&attr3);
    assert(!returnVal3);
    returnVal4 = pthread_attr_init(&attr4);
    assert(!returnVal4);
    
    
    char* message1 = "I'm thread 1";
    char* message2 = "I'm thread 2";
    char* message3 = "I'm thread 3";
    char* message4 = "I'm thread 4";
    int* sharedData = (int*)malloc(sizeof(int));
    pthread_mutex_t mutex_one = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t mutex_two = PTHREAD_MUTEX_INITIALIZER;
    
    thread_comm tc1;
    thread_comm tc2;
    thread_comm tc3;
    thread_comm tc4;
    tc1.message = message1;
    tc1.mutext_one = &mutex_one;
    tc1.mutext_two = &mutex_two;
    tc1.sharedData = sharedData;
    tc1.counter = &times_ran;
    
    tc2.message = message2;
    tc2.mutext_one = &mutex_one;
    tc2.mutext_two = &mutex_two;
    tc2.sharedData = sharedData;
    tc2.counter = &times_ran;
    
    tc3.message = message3;
    tc3.mutext_one = &mutex_one;
    tc3.mutext_two = &mutex_two;
    tc3.sharedData = sharedData;
    tc3.counter = &times_ran;
    
    tc4.message = message4;
    tc4.mutext_one = &mutex_one;
    tc4.mutext_two = &mutex_two;
    tc4.sharedData = sharedData;
    tc4.counter = &times_ran;
    
    
    clock_t start, end;
    double cpu_time_one, cpu_time_two;
    start = clock();
    
    int threadError = pthread_create(&posixThreadID, &attr, &PosixThreadMainRoutineTestOne, &tc1);
    int threadError2 = pthread_create(&posixThreadID2, &attr, &PosixThreadMainRoutineTestTwo, &tc2);
    int threadError3 = pthread_create(&posixThreadID3, &attr, &PosixThreadMainRoutineTestThree, &tc3);
    int threadError4 = pthread_create(&posixThreadID4, &attr, &PosixThreadMainRoutineTestFour, &tc4);
    
    //Will Wait until thread is done before continuning to execute.
    
    pthread_join(posixThreadID, NULL);
    pthread_join(posixThreadID2, NULL);
    pthread_join(posixThreadID3, NULL);
    pthread_join(posixThreadID4, NULL);

    
    end = clock();
    printf("I'm done!, the shared data value is %d\n", *sharedData);
    printf("And the run counter is %d\n", times_ran);
    cpu_time_one = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time to run in parrell: %f\n", cpu_time_one);
    free(sharedData);
    
    //Kill that thread and get the error message
    returnVal = pthread_attr_destroy(&attr);
    returnVal2 = pthread_attr_destroy(&attr2);
    returnVal3 = pthread_attr_destroy(&attr3);
    returnVal4 = pthread_attr_destroy(&attr4);
    assert(!returnVal);
    if (threadError != 0)
    {
        // Report an error.
    }
    
    
    assert(!returnVal2);
    if (threadError2 != 0)
    {
        // Report an error.
    }
    
    assert(!returnVal3);
    if (threadError3 != 0)
    {
        // Report an error.
    }
    
    assert(!returnVal4);
    if (threadError4 != 0)
    {
        // Report an error.
    }
}

