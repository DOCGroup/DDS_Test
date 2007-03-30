#ifndef DEEPTYPESSPLTYPES_H
#define DEEPTYPESSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __deepTypes_deepTypes__load (c_base base);

extern c_metaObject __deepTypes_simpleType__load (c_base base);
extern char * __deepTypes_simpleType__keys (void);
extern char * __deepTypes_simpleType__name (void);
struct _deepTypes_simpleType {
    c_long id;
    c_long payload;
};

extern c_metaObject __deepTypes_innerStruct__load (c_base base);
extern char * __deepTypes_innerStruct__keys (void);
extern char * __deepTypes_innerStruct__name (void);
struct _deepTypes_innerStruct {
    c_long value;
};

extern c_metaObject __deepTypes_nestedType__load (c_base base);
extern char * __deepTypes_nestedType__keys (void);
extern char * __deepTypes_nestedType__name (void);
struct _deepTypes_nestedType {
    c_long id;
    struct _deepTypes_innerStruct payload;
};

extern c_metaObject __deepTypes_arrayType__load (c_base base);
extern char * __deepTypes_arrayType__keys (void);
extern char * __deepTypes_arrayType__name (void);
struct _deepTypes_arrayType {
    c_long id;
    c_long payload[10];
};

extern c_metaObject __deepTypes_stringType__load (c_base base);
extern char * __deepTypes_stringType__keys (void);
extern char * __deepTypes_stringType__name (void);
struct _deepTypes_stringType {
    c_long id;
    c_string payload;
};

#endif
