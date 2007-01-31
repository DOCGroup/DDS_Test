
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from HelloWorld.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef HelloWorldPlugin_h
#define HelloWorldPlugin_h

#ifndef HelloWorld_h
#include "HelloWorld.h"
#endif




struct RTICdrStream;
struct MIGRtpsGuid;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif



/* The type used to store keys for instances of type struct
 * HelloWorld.
 *
 * By default, this type is struct HelloWorld
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct HelloWorld)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct HelloWorld, the
 * following restriction applies: the key of struct
 * HelloWorld must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct HelloWorld.
 */
typedef HelloWorld HelloWorldKeyHolder;


extern RTIBool HelloWorldPlugin_serialize(
    struct RTICdrStream *stream, const HelloWorld *sample,
    void *serialize_option);

extern RTIBool HelloWorldPlugin_deserialize(
    struct RTICdrStream *stream, HelloWorld *sample,
    void *deserialize_option);

extern unsigned int HelloWorldPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void HelloWorldPlugin_print(
    const HelloWorld *sample,
    const char *description, int indent_level);

extern HelloWorld *HelloWorldPlugin_create_sample();

extern void HelloWorldPlugin_delete_sample(
    HelloWorld *sample);

extern PRESTypePluginKeyKind HelloWorldPlugin_get_key_kind();

extern struct PRESTypePlugin *HelloWorldPlugin_new();

extern void HelloWorldPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern HelloWorldKeyHolder *HelloWorldPlugin_create_key();

extern void HelloWorldPlugin_delete_key(
    HelloWorldKeyHolder *key);

extern RTIBool HelloWorldPlugin_instance_to_key(
    HelloWorldKeyHolder *key, const HelloWorld *instance);

extern RTIBool HelloWorldPlugin_key_to_instance(
    HelloWorld *instance, const HelloWorldKeyHolder *key);

extern RTIBool HelloWorldPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const HelloWorld *instance);



#ifdef __cplusplus
}
#endif

#endif /* HelloWorldPlugin_h */
