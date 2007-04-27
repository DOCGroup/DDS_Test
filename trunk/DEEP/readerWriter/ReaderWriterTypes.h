#ifndef READERWRITERTYPES_H_
#define READERWRITERTYPES_H_

#if defined (_WINDOWS)
namespace Deep {
  struct timeval {
    time_t tv_sec;
    long tv_usec;
  };
}
#else
# include <sys/time.h>
#endif

namespace Deep {
    
typedef struct timeval duration;


}

#endif /*READERWRITERTYPES_H_*/
