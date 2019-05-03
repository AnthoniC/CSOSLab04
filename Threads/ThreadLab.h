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
    pthread_mutex_t* mutext;
    int* sharedData;
    char* message;
}thread_comm;

int Run_Lab(void);

#endif /* ThreadLab_h */
