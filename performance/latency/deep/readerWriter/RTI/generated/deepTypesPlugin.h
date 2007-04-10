
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from deepTypes.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef deepTypesPlugin_h
#define deepTypesPlugin_h

#ifndef deepTypes_h
#include "deepTypes.h"
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
 * simpleType.
 *
 * By default, this type is struct simpleType
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct simpleType)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct simpleType, the
 * following restriction applies: the key of struct
 * simpleType must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct simpleType.
 */
typedef simpleType simpleTypeKeyHolder;


extern RTIBool simpleTypePlugin_serialize(
    struct RTICdrStream *stream, const simpleType *sample,
    void *serialize_option);

extern RTIBool simpleTypePlugin_deserialize(
    struct RTICdrStream *stream, simpleType *sample,
    void *deserialize_option);

extern unsigned int simpleTypePlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void simpleTypePlugin_print(
    const simpleType *sample,
    const char *description, int indent_level);

extern simpleType *simpleTypePlugin_create_sample();

extern simpleType *simpleTypePlugin_create_sample_ex(RTIBool allocatePointers);        

extern void simpleTypePlugin_delete_sample(
    simpleType *sample);        

extern void simpleTypePlugin_delete_sample_ex(
    simpleType *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind simpleTypePlugin_get_key_kind();

extern struct PRESTypePlugin *simpleTypePlugin_new();

extern void simpleTypePlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern simpleTypeKeyHolder *simpleTypePlugin_create_key();

extern void simpleTypePlugin_delete_key(
    simpleTypeKeyHolder *key);

extern RTIBool simpleTypePlugin_instance_to_key(
    simpleTypeKeyHolder *key, const simpleType *instance);

extern RTIBool simpleTypePlugin_key_to_instance(
    simpleType *instance, const simpleTypeKeyHolder *key);

extern RTIBool simpleTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const simpleType *instance);




/* The type used to store keys for instances of type struct
 * innerStruct.
 *
 * By default, this type is struct innerStruct
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct innerStruct)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct innerStruct, the
 * following restriction applies: the key of struct
 * innerStruct must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct innerStruct.
 */
typedef innerStruct innerStructKeyHolder;


extern RTIBool innerStructPlugin_serialize(
    struct RTICdrStream *stream, const innerStruct *sample,
    void *serialize_option);

extern RTIBool innerStructPlugin_deserialize(
    struct RTICdrStream *stream, innerStruct *sample,
    void *deserialize_option);

extern unsigned int innerStructPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void innerStructPlugin_print(
    const innerStruct *sample,
    const char *description, int indent_level);

extern innerStruct *innerStructPlugin_create_sample();

extern innerStruct *innerStructPlugin_create_sample_ex(RTIBool allocatePointers);        

extern void innerStructPlugin_delete_sample(
    innerStruct *sample);        

extern void innerStructPlugin_delete_sample_ex(
    innerStruct *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind innerStructPlugin_get_key_kind();

extern struct PRESTypePlugin *innerStructPlugin_new();

extern void innerStructPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern innerStructKeyHolder *innerStructPlugin_create_key();

extern void innerStructPlugin_delete_key(
    innerStructKeyHolder *key);

extern RTIBool innerStructPlugin_instance_to_key(
    innerStructKeyHolder *key, const innerStruct *instance);

extern RTIBool innerStructPlugin_key_to_instance(
    innerStruct *instance, const innerStructKeyHolder *key);

extern RTIBool innerStructPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const innerStruct *instance);




/* The type used to store keys for instances of type struct
 * nestedType.
 *
 * By default, this type is struct nestedType
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct nestedType)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct nestedType, the
 * following restriction applies: the key of struct
 * nestedType must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct nestedType.
 */
typedef nestedType nestedTypeKeyHolder;


extern RTIBool nestedTypePlugin_serialize(
    struct RTICdrStream *stream, const nestedType *sample,
    void *serialize_option);

extern RTIBool nestedTypePlugin_deserialize(
    struct RTICdrStream *stream, nestedType *sample,
    void *deserialize_option);

extern unsigned int nestedTypePlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void nestedTypePlugin_print(
    const nestedType *sample,
    const char *description, int indent_level);

extern nestedType *nestedTypePlugin_create_sample();

extern nestedType *nestedTypePlugin_create_sample_ex(RTIBool allocatePointers);        

extern void nestedTypePlugin_delete_sample(
    nestedType *sample);        

extern void nestedTypePlugin_delete_sample_ex(
    nestedType *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind nestedTypePlugin_get_key_kind();

extern struct PRESTypePlugin *nestedTypePlugin_new();

extern void nestedTypePlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern nestedTypeKeyHolder *nestedTypePlugin_create_key();

extern void nestedTypePlugin_delete_key(
    nestedTypeKeyHolder *key);

extern RTIBool nestedTypePlugin_instance_to_key(
    nestedTypeKeyHolder *key, const nestedType *instance);

extern RTIBool nestedTypePlugin_key_to_instance(
    nestedType *instance, const nestedTypeKeyHolder *key);

extern RTIBool nestedTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const nestedType *instance);




/* The type used to store keys for instances of type struct
 * arrayType.
 *
 * By default, this type is struct arrayType
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct arrayType)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct arrayType, the
 * following restriction applies: the key of struct
 * arrayType must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct arrayType.
 */
typedef arrayType arrayTypeKeyHolder;


extern RTIBool arrayTypePlugin_serialize(
    struct RTICdrStream *stream, const arrayType *sample,
    void *serialize_option);

extern RTIBool arrayTypePlugin_deserialize(
    struct RTICdrStream *stream, arrayType *sample,
    void *deserialize_option);

extern unsigned int arrayTypePlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void arrayTypePlugin_print(
    const arrayType *sample,
    const char *description, int indent_level);

extern arrayType *arrayTypePlugin_create_sample();

extern arrayType *arrayTypePlugin_create_sample_ex(RTIBool allocatePointers);        

extern void arrayTypePlugin_delete_sample(
    arrayType *sample);        

extern void arrayTypePlugin_delete_sample_ex(
    arrayType *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind arrayTypePlugin_get_key_kind();

extern struct PRESTypePlugin *arrayTypePlugin_new();

extern void arrayTypePlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern arrayTypeKeyHolder *arrayTypePlugin_create_key();

extern void arrayTypePlugin_delete_key(
    arrayTypeKeyHolder *key);

extern RTIBool arrayTypePlugin_instance_to_key(
    arrayTypeKeyHolder *key, const arrayType *instance);

extern RTIBool arrayTypePlugin_key_to_instance(
    arrayType *instance, const arrayTypeKeyHolder *key);

extern RTIBool arrayTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const arrayType *instance);




/* The type used to store keys for instances of type struct
 * stringType.
 *
 * By default, this type is struct stringType
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct stringType)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct stringType, the
 * following restriction applies: the key of struct
 * stringType must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct stringType.
 */
typedef stringType stringTypeKeyHolder;


extern RTIBool stringTypePlugin_serialize(
    struct RTICdrStream *stream, const stringType *sample,
    void *serialize_option);

extern RTIBool stringTypePlugin_deserialize(
    struct RTICdrStream *stream, stringType *sample,
    void *deserialize_option);

extern unsigned int stringTypePlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void stringTypePlugin_print(
    const stringType *sample,
    const char *description, int indent_level);

extern stringType *stringTypePlugin_create_sample();

extern stringType *stringTypePlugin_create_sample_ex(RTIBool allocatePointers);        

extern void stringTypePlugin_delete_sample(
    stringType *sample);        

extern void stringTypePlugin_delete_sample_ex(
    stringType *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind stringTypePlugin_get_key_kind();

extern struct PRESTypePlugin *stringTypePlugin_new();

extern void stringTypePlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern stringTypeKeyHolder *stringTypePlugin_create_key();

extern void stringTypePlugin_delete_key(
    stringTypeKeyHolder *key);

extern RTIBool stringTypePlugin_instance_to_key(
    stringTypeKeyHolder *key, const stringType *instance);

extern RTIBool stringTypePlugin_key_to_instance(
    stringType *instance, const stringTypeKeyHolder *key);

extern RTIBool stringTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const stringType *instance);



#ifdef __cplusplus
}
#endif
        

#endif /* deepTypesPlugin_h */
