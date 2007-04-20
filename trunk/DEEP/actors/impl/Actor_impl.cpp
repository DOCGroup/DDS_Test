#include "Actor_impl.h"

namespace Deep
{

Actor_impl::Actor_impl(
    ActorSetting_ptr actorSetting) {
    
    name = actorSetting->getName();
}

Actor_impl::~Actor_impl()
{
}
const char *
Actor_impl::getName() {
    return name;
}

}
