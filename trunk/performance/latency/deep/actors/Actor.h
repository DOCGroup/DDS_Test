#ifndef ACTOR_H_
#define ACTOR_H_

namespace Deep {

class Actor {
public:
    virtual void run() = 0;
    virtual const char *getName() = 0;
};

typedef Actor *Actor_ptr;
}

#endif /*ACTOR_H_*/
