//
//  ThreadLab.h
//  Threads
//
//  Created by nah on 5/3/19.
//  Copyright © 2019 Austin College. All rights reserved.
//

#ifndef ThreadLab_h
#define ThreadLab_h

#include <stdio.h>

typedef struct thread_comm{
    pthread_mutex_t* mutext_one;
    pthread_mutex_t* mutext_two;
    pthread_mutex_t* mutext_three;
    pthread_mutex_t* mutext_four;
    int* sharedData;
    int* counter;
    int* something_else;
    char* message;
}thread_comm;

void RunLab(void);

#endif /* ThreadLab_h */
