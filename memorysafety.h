#ifndef MEMORYSAFETY_H
#define MEMORYSAFETY_H

#include <stdlib.h>
#include <stdio.h>

#ifdef MAX_PERFORMANCE
    
    void* check_alloc_fail(void* alloc_ptr);

#else

    void* check_alloc_fail(void* alloc_ptr, const char* func);

#endif

#endif