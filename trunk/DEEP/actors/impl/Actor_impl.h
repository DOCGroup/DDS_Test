#ifndef ACTOR_IMPL_H_
#define ACTOR_IMPL_H_

/* Base class (interface) */
#include "Actor.h"
/* Implementation */
#include "ActorSetting.h"

namespace Deep {

class Actor_impl : public virtual Actor {
    const char *name;
protected:
	Actor_impl(ActorSetting_ptr actorSetting);
	virtual ~Actor_impl();
public:
    const char *getName();
};

typedef Actor_impl *Actor_impl_ptr;

}

#if defined (_WINDOWS)
# include <io.h>
# define mkstemp(s) (void)_mktemp_s (s, strlen (s) + 1)
#endif

#endif /*ACTOR_IMPL_H_*/
