#include "deepTypesSplDcps.h"
#include "ccpp_deepTypes.h"

char *
__deepTypes_simpleType__name(void)
{
    return CORBA::string_dup("deepTypes::simpleType");
}

char *
__deepTypes_simpleType__keys(void)
{
    return CORBA::string_dup("id");
}

char *
__deepTypes_innerStruct__name(void)
{
    return CORBA::string_dup("deepTypes::innerStruct");
}

char *
__deepTypes_innerStruct__keys(void)
{
    return CORBA::string_dup("");
}

char *
__deepTypes_nestedType__name(void)
{
    return CORBA::string_dup("deepTypes::nestedType");
}

char *
__deepTypes_nestedType__keys(void)
{
    return CORBA::string_dup("id");
}

char *
__deepTypes_arrayType__name(void)
{
    return CORBA::string_dup("deepTypes::arrayType");
}

char *
__deepTypes_arrayType__keys(void)
{
    return CORBA::string_dup("id");
}

char *
__deepTypes_stringType__name(void)
{
    return CORBA::string_dup("deepTypes::stringType");
}

char *
__deepTypes_stringType__keys(void)
{
    return CORBA::string_dup("id");
}

#include <v_kernel.h>
#include <v_topic.h>
#include <string.h>

void
__deepTypes_simpleType__copyIn(
    c_base base,
    struct deepTypes::simpleType *from,
    struct _deepTypes_simpleType *to)
{
    to->id = (c_long)from->id;
    to->payload = (c_long)from->payload;
}

void
__deepTypes_innerStruct__copyIn(
    c_base base,
    struct deepTypes::innerStruct *from,
    struct _deepTypes_innerStruct *to)
{
    to->value = (c_long)from->value;
}

void
__deepTypes_nestedType__copyIn(
    c_base base,
    struct deepTypes::nestedType *from,
    struct _deepTypes_nestedType *to)
{
    to->id = (c_long)from->id;
    {
        extern void __deepTypes_innerStruct__copyIn(c_base, deepTypes::innerStruct *, _deepTypes_innerStruct *);
        __deepTypes_innerStruct__copyIn(base, &from->payload, &to->payload);
    }
}

void
__deepTypes_arrayType__copyIn(
    c_base base,
    struct deepTypes::arrayType *from,
    struct _deepTypes_arrayType *to)
{
    to->id = (c_long)from->id;
    {
        c_long (*dst)[10] = &to->payload;
        memcpy (dst, from->payload, sizeof (*dst));
    }
}

void
__deepTypes_stringType__copyIn(
    c_base base,
    struct deepTypes::stringType *from,
    struct _deepTypes_stringType *to)
{
    to->id = (c_long)from->id;
    to->payload = c_stringNew(base, from->payload);
}

void
__deepTypes_simpleType__copyOut(
    void *_from,
    void *_to)
{
    struct _deepTypes_simpleType *from = (struct _deepTypes_simpleType *)_from;
    struct deepTypes::simpleType *to = (struct deepTypes::simpleType *)_to;
    to->id = (CORBA::Long)from->id;
    to->payload = (CORBA::Long)from->payload;
}

void
__deepTypes_innerStruct__copyOut(
    void *_from,
    void *_to)
{
    struct _deepTypes_innerStruct *from = (struct _deepTypes_innerStruct *)_from;
    struct deepTypes::innerStruct *to = (struct deepTypes::innerStruct *)_to;
    to->value = (CORBA::Long)from->value;
}

void
__deepTypes_nestedType__copyOut(
    void *_from,
    void *_to)
{
    struct _deepTypes_nestedType *from = (struct _deepTypes_nestedType *)_from;
    struct deepTypes::nestedType *to = (struct deepTypes::nestedType *)_to;
    to->id = (CORBA::Long)from->id;
    {
        extern void __deepTypes_innerStruct__copyOut(void *, void *);
        __deepTypes_innerStruct__copyOut((void *)&from->payload, (void *)&to->payload);
    }
}

void
__deepTypes_arrayType__copyOut(
    void *_from,
    void *_to)
{
    struct _deepTypes_arrayType *from = (struct _deepTypes_arrayType *)_from;
    struct deepTypes::arrayType *to = (struct deepTypes::arrayType *)_to;
    to->id = (CORBA::Long)from->id;
    {
        c_long (*src)[10] = &from->payload;

        memcpy (to->payload, src, sizeof (*src));
    }
}

void
__deepTypes_stringType__copyOut(
    void *_from,
    void *_to)
{
    struct _deepTypes_stringType *from = (struct _deepTypes_stringType *)_from;
    struct deepTypes::stringType *to = (struct deepTypes::stringType *)_to;
    to->id = (CORBA::Long)from->id;
    to->payload = CORBA::string_dup(from->payload);
}

