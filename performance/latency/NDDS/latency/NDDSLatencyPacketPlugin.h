
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef NDDSLatencyPacketPlugin_h
#define NDDSLatencyPacketPlugin_h

#ifndef NDDSLatencyPacket_h
#include "NDDSLatencyPacket.h"
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
 * PubMessage.
 *
 * By default, this type is struct PubMessage
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct PubMessage)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct PubMessage, the
 * following restriction applies: the key of struct
 * PubMessage must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct PubMessage.
 */
typedef PubMessage PubMessageKeyHolder;


extern RTIBool PubMessagePlugin_serialize(
    struct RTICdrStream *stream, const PubMessage *sample,
    void *serialize_option);

extern RTIBool PubMessagePlugin_deserialize(
    struct RTICdrStream *stream, PubMessage *sample,
    void *deserialize_option);

extern unsigned int PubMessagePlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void PubMessagePlugin_print(
    const PubMessage *sample,
    const char *description, int indent_level);

extern PubMessage *PubMessagePlugin_create_sample();

extern PubMessage *PubMessagePlugin_create_sample_ex(RTIBool allocatePointers);        

extern void PubMessagePlugin_delete_sample(
    PubMessage *sample);        

extern void PubMessagePlugin_delete_sample_ex(
    PubMessage *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind PubMessagePlugin_get_key_kind();

extern struct PRESTypePlugin *PubMessagePlugin_new();

extern void PubMessagePlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern PubMessageKeyHolder *PubMessagePlugin_create_key();

extern void PubMessagePlugin_delete_key(
    PubMessageKeyHolder *key);

extern RTIBool PubMessagePlugin_instance_to_key(
    PubMessageKeyHolder *key, const PubMessage *instance);

extern RTIBool PubMessagePlugin_key_to_instance(
    PubMessage *instance, const PubMessageKeyHolder *key);

extern RTIBool PubMessagePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const PubMessage *instance);




/* The type used to store keys for instances of type struct
 * Nested.
 *
 * By default, this type is struct Nested
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Nested)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Nested, the
 * following restriction applies: the key of struct
 * Nested must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Nested.
 */
typedef Nested NestedKeyHolder;


extern RTIBool NestedPlugin_serialize(
    struct RTICdrStream *stream, const Nested *sample,
    void *serialize_option);

extern RTIBool NestedPlugin_deserialize(
    struct RTICdrStream *stream, Nested *sample,
    void *deserialize_option);

extern unsigned int NestedPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void NestedPlugin_print(
    const Nested *sample,
    const char *description, int indent_level);

extern Nested *NestedPlugin_create_sample();

extern Nested *NestedPlugin_create_sample_ex(RTIBool allocatePointers);        

extern void NestedPlugin_delete_sample(
    Nested *sample);        

extern void NestedPlugin_delete_sample_ex(
    Nested *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind NestedPlugin_get_key_kind();

extern struct PRESTypePlugin *NestedPlugin_new();

extern void NestedPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern NestedKeyHolder *NestedPlugin_create_key();

extern void NestedPlugin_delete_key(
    NestedKeyHolder *key);

extern RTIBool NestedPlugin_instance_to_key(
    NestedKeyHolder *key, const Nested *instance);

extern RTIBool NestedPlugin_key_to_instance(
    Nested *instance, const NestedKeyHolder *key);

extern RTIBool NestedPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Nested *instance);




/* The type used to store keys for instances of type struct
 * Outer.
 *
 * By default, this type is struct Outer
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Outer)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Outer, the
 * following restriction applies: the key of struct
 * Outer must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Outer.
 */
typedef Outer OuterKeyHolder;


extern RTIBool OuterPlugin_serialize(
    struct RTICdrStream *stream, const Outer *sample,
    void *serialize_option);

extern RTIBool OuterPlugin_deserialize(
    struct RTICdrStream *stream, Outer *sample,
    void *deserialize_option);

extern unsigned int OuterPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void OuterPlugin_print(
    const Outer *sample,
    const char *description, int indent_level);

extern Outer *OuterPlugin_create_sample();

extern Outer *OuterPlugin_create_sample_ex(RTIBool allocatePointers);        

extern void OuterPlugin_delete_sample(
    Outer *sample);        

extern void OuterPlugin_delete_sample_ex(
    Outer *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind OuterPlugin_get_key_kind();

extern struct PRESTypePlugin *OuterPlugin_new();

extern void OuterPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern OuterKeyHolder *OuterPlugin_create_key();

extern void OuterPlugin_delete_key(
    OuterKeyHolder *key);

extern RTIBool OuterPlugin_instance_to_key(
    OuterKeyHolder *key, const Outer *instance);

extern RTIBool OuterPlugin_key_to_instance(
    Outer *instance, const OuterKeyHolder *key);

extern RTIBool OuterPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Outer *instance);




/* The type used to store keys for instances of type struct
 * PubMessage_Nest.
 *
 * By default, this type is struct PubMessage_Nest
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct PubMessage_Nest)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct PubMessage_Nest, the
 * following restriction applies: the key of struct
 * PubMessage_Nest must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct PubMessage_Nest.
 */
typedef PubMessage_Nest PubMessage_NestKeyHolder;


extern RTIBool PubMessage_NestPlugin_serialize(
    struct RTICdrStream *stream, const PubMessage_Nest *sample,
    void *serialize_option);

extern RTIBool PubMessage_NestPlugin_deserialize(
    struct RTICdrStream *stream, PubMessage_Nest *sample,
    void *deserialize_option);

extern unsigned int PubMessage_NestPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void PubMessage_NestPlugin_print(
    const PubMessage_Nest *sample,
    const char *description, int indent_level);

extern PubMessage_Nest *PubMessage_NestPlugin_create_sample();

extern PubMessage_Nest *PubMessage_NestPlugin_create_sample_ex(RTIBool allocatePointers);        

extern void PubMessage_NestPlugin_delete_sample(
    PubMessage_Nest *sample);        

extern void PubMessage_NestPlugin_delete_sample_ex(
    PubMessage_Nest *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind PubMessage_NestPlugin_get_key_kind();

extern struct PRESTypePlugin *PubMessage_NestPlugin_new();

extern void PubMessage_NestPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern PubMessage_NestKeyHolder *PubMessage_NestPlugin_create_key();

extern void PubMessage_NestPlugin_delete_key(
    PubMessage_NestKeyHolder *key);

extern RTIBool PubMessage_NestPlugin_instance_to_key(
    PubMessage_NestKeyHolder *key, const PubMessage_Nest *instance);

extern RTIBool PubMessage_NestPlugin_key_to_instance(
    PubMessage_Nest *instance, const PubMessage_NestKeyHolder *key);

extern RTIBool PubMessage_NestPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const PubMessage_Nest *instance);




/* The type used to store keys for instances of type struct
 * AckMessage.
 *
 * By default, this type is struct AckMessage
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct AckMessage)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct AckMessage, the
 * following restriction applies: the key of struct
 * AckMessage must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct AckMessage.
 */
typedef AckMessage AckMessageKeyHolder;


extern RTIBool AckMessagePlugin_serialize(
    struct RTICdrStream *stream, const AckMessage *sample,
    void *serialize_option);

extern RTIBool AckMessagePlugin_deserialize(
    struct RTICdrStream *stream, AckMessage *sample,
    void *deserialize_option);

extern unsigned int AckMessagePlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void AckMessagePlugin_print(
    const AckMessage *sample,
    const char *description, int indent_level);

extern AckMessage *AckMessagePlugin_create_sample();

extern AckMessage *AckMessagePlugin_create_sample_ex(RTIBool allocatePointers);        

extern void AckMessagePlugin_delete_sample(
    AckMessage *sample);        

extern void AckMessagePlugin_delete_sample_ex(
    AckMessage *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind AckMessagePlugin_get_key_kind();

extern struct PRESTypePlugin *AckMessagePlugin_new();

extern void AckMessagePlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern AckMessageKeyHolder *AckMessagePlugin_create_key();

extern void AckMessagePlugin_delete_key(
    AckMessageKeyHolder *key);

extern RTIBool AckMessagePlugin_instance_to_key(
    AckMessageKeyHolder *key, const AckMessage *instance);

extern RTIBool AckMessagePlugin_key_to_instance(
    AckMessage *instance, const AckMessageKeyHolder *key);

extern RTIBool AckMessagePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const AckMessage *instance);



#ifdef __cplusplus
}
#endif
        

#endif /* NDDSLatencyPacketPlugin_h */
