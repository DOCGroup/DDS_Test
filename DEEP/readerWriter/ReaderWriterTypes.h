#ifndef READERWRITERTYPES_H_
#define READERWRITERTYPES_H_

#include <sys/time.h>


// To avoid a clash of typedefs in ACE and OpenSplice
#define pid_t ACE_pid_t_typedef_clash_workaround
#define mode_t ACE_mode_t_typedef_clash_workaround

// #include "ace/Time_Value.h"

#undef pid_t
#undef mode_t

// To avoid a redef error on Windows from OpenSplice header files,
// ACE defines it in config-win32-common.h.
#if defined (ETIMEDOUT)
#undef ETIMEDOUT
#endif

// To avoid a redef error on Windows from OpenSplice header files,
// ACE defines it in config-win32-common.h.
#if defined (FD_SETSIZE)
#undef FD_SETSIZE
#endif


namespace Deep {
    
typedef struct timeval duration;


}

#endif /*READERWRITERTYPES_H_*/
