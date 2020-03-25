#include "memorysafety.h"

#ifdef MAX_PERFORMANCE

    inline void* check_alloc_fail(void* alloc_ptr) {
        if (alloc_ptr != NULL)
            return alloc_ptr;
        
        fprintf(stderr, "FATAL ERROR: Allocation failure");
        exit(EXIT_FAILURE);
    }

#else

    inline void* check_alloc_fail(void* alloc_ptr, const char* func) {
        if (alloc_ptr != NULL)
            return alloc_ptr;
        
        fprintf(stderr, "FATAL ERROR in function '%s': Allocation failure\n", func);
        exit(EXIT_FAILURE);
    }

#endif