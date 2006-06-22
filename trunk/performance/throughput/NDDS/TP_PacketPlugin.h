
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from TP_Packet.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef TP_PacketPlugin_h
#define TP_PacketPlugin_h

#ifndef TP_Packet_h
#include "TP_Packet.h"
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
 * NDDSLatencyPacket.
 *
 * By default, this type is struct NDDSLatencyPacket
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct NDDSLatencyPacket)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct NDDSLatencyPacket, the
 * following restriction applies: the key of struct
 * NDDSLatencyPacket must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct NDDSLatencyPacket.
 */
typedef NDDSLatencyPacket NDDSLatencyPacketKeyHolder;


extern RTIBool NDDSLatencyPacketPlugin_serialize(
    struct RTICdrStream *stream, const NDDSLatencyPacket *sample,
    void *serialize_option);

extern RTIBool NDDSLatencyPacketPlugin_deserialize(
    struct RTICdrStream *stream, NDDSLatencyPacket *sample,
    void *deserialize_option);

extern unsigned int NDDSLatencyPacketPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void NDDSLatencyPacketPlugin_print(
    const NDDSLatencyPacket *sample,
    const char *description, int indent_level);

extern NDDSLatencyPacket *NDDSLatencyPacketPlugin_create_sample();

extern NDDSLatencyPacket *NDDSLatencyPacketPlugin_create_sample_ex(RTIBool allocatePointers);        

extern void NDDSLatencyPacketPlugin_delete_sample(
    NDDSLatencyPacket *sample);        

extern void NDDSLatencyPacketPlugin_delete_sample_ex(
    NDDSLatencyPacket *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind NDDSLatencyPacketPlugin_get_key_kind();

extern struct PRESTypePlugin *NDDSLatencyPacketPlugin_new();

extern void NDDSLatencyPacketPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern NDDSLatencyPacketKeyHolder *NDDSLatencyPacketPlugin_create_key();

extern void NDDSLatencyPacketPlugin_delete_key(
    NDDSLatencyPacketKeyHolder *key);

extern RTIBool NDDSLatencyPacketPlugin_instance_to_key(
    NDDSLatencyPacketKeyHolder *key, const NDDSLatencyPacket *instance);

extern RTIBool NDDSLatencyPacketPlugin_key_to_instance(
    NDDSLatencyPacket *instance, const NDDSLatencyPacketKeyHolder *key);

extern RTIBool NDDSLatencyPacketPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const NDDSLatencyPacket *instance);




/* The type used to store keys for instances of type struct
 * Bytes4.
 *
 * By default, this type is struct Bytes4
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes4)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes4, the
 * following restriction applies: the key of struct
 * Bytes4 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes4.
 */
typedef Bytes4 Bytes4KeyHolder;


extern RTIBool Bytes4Plugin_serialize(
    struct RTICdrStream *stream, const Bytes4 *sample,
    void *serialize_option);

extern RTIBool Bytes4Plugin_deserialize(
    struct RTICdrStream *stream, Bytes4 *sample,
    void *deserialize_option);

extern unsigned int Bytes4Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes4Plugin_print(
    const Bytes4 *sample,
    const char *description, int indent_level);

extern Bytes4 *Bytes4Plugin_create_sample();

extern Bytes4 *Bytes4Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes4Plugin_delete_sample(
    Bytes4 *sample);        

extern void Bytes4Plugin_delete_sample_ex(
    Bytes4 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes4Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes4Plugin_new();

extern void Bytes4Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes4KeyHolder *Bytes4Plugin_create_key();

extern void Bytes4Plugin_delete_key(
    Bytes4KeyHolder *key);

extern RTIBool Bytes4Plugin_instance_to_key(
    Bytes4KeyHolder *key, const Bytes4 *instance);

extern RTIBool Bytes4Plugin_key_to_instance(
    Bytes4 *instance, const Bytes4KeyHolder *key);

extern RTIBool Bytes4Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes4 *instance);




/* The type used to store keys for instances of type struct
 * Bytes8.
 *
 * By default, this type is struct Bytes8
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes8)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes8, the
 * following restriction applies: the key of struct
 * Bytes8 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes8.
 */
typedef Bytes8 Bytes8KeyHolder;


extern RTIBool Bytes8Plugin_serialize(
    struct RTICdrStream *stream, const Bytes8 *sample,
    void *serialize_option);

extern RTIBool Bytes8Plugin_deserialize(
    struct RTICdrStream *stream, Bytes8 *sample,
    void *deserialize_option);

extern unsigned int Bytes8Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes8Plugin_print(
    const Bytes8 *sample,
    const char *description, int indent_level);

extern Bytes8 *Bytes8Plugin_create_sample();

extern Bytes8 *Bytes8Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes8Plugin_delete_sample(
    Bytes8 *sample);        

extern void Bytes8Plugin_delete_sample_ex(
    Bytes8 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes8Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes8Plugin_new();

extern void Bytes8Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes8KeyHolder *Bytes8Plugin_create_key();

extern void Bytes8Plugin_delete_key(
    Bytes8KeyHolder *key);

extern RTIBool Bytes8Plugin_instance_to_key(
    Bytes8KeyHolder *key, const Bytes8 *instance);

extern RTIBool Bytes8Plugin_key_to_instance(
    Bytes8 *instance, const Bytes8KeyHolder *key);

extern RTIBool Bytes8Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes8 *instance);




/* The type used to store keys for instances of type struct
 * Bytes16.
 *
 * By default, this type is struct Bytes16
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes16)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes16, the
 * following restriction applies: the key of struct
 * Bytes16 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes16.
 */
typedef Bytes16 Bytes16KeyHolder;


extern RTIBool Bytes16Plugin_serialize(
    struct RTICdrStream *stream, const Bytes16 *sample,
    void *serialize_option);

extern RTIBool Bytes16Plugin_deserialize(
    struct RTICdrStream *stream, Bytes16 *sample,
    void *deserialize_option);

extern unsigned int Bytes16Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes16Plugin_print(
    const Bytes16 *sample,
    const char *description, int indent_level);

extern Bytes16 *Bytes16Plugin_create_sample();

extern Bytes16 *Bytes16Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes16Plugin_delete_sample(
    Bytes16 *sample);        

extern void Bytes16Plugin_delete_sample_ex(
    Bytes16 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes16Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes16Plugin_new();

extern void Bytes16Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes16KeyHolder *Bytes16Plugin_create_key();

extern void Bytes16Plugin_delete_key(
    Bytes16KeyHolder *key);

extern RTIBool Bytes16Plugin_instance_to_key(
    Bytes16KeyHolder *key, const Bytes16 *instance);

extern RTIBool Bytes16Plugin_key_to_instance(
    Bytes16 *instance, const Bytes16KeyHolder *key);

extern RTIBool Bytes16Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes16 *instance);




/* The type used to store keys for instances of type struct
 * Bytes32.
 *
 * By default, this type is struct Bytes32
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes32)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes32, the
 * following restriction applies: the key of struct
 * Bytes32 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes32.
 */
typedef Bytes32 Bytes32KeyHolder;


extern RTIBool Bytes32Plugin_serialize(
    struct RTICdrStream *stream, const Bytes32 *sample,
    void *serialize_option);

extern RTIBool Bytes32Plugin_deserialize(
    struct RTICdrStream *stream, Bytes32 *sample,
    void *deserialize_option);

extern unsigned int Bytes32Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes32Plugin_print(
    const Bytes32 *sample,
    const char *description, int indent_level);

extern Bytes32 *Bytes32Plugin_create_sample();

extern Bytes32 *Bytes32Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes32Plugin_delete_sample(
    Bytes32 *sample);        

extern void Bytes32Plugin_delete_sample_ex(
    Bytes32 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes32Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes32Plugin_new();

extern void Bytes32Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes32KeyHolder *Bytes32Plugin_create_key();

extern void Bytes32Plugin_delete_key(
    Bytes32KeyHolder *key);

extern RTIBool Bytes32Plugin_instance_to_key(
    Bytes32KeyHolder *key, const Bytes32 *instance);

extern RTIBool Bytes32Plugin_key_to_instance(
    Bytes32 *instance, const Bytes32KeyHolder *key);

extern RTIBool Bytes32Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes32 *instance);




/* The type used to store keys for instances of type struct
 * Bytes64.
 *
 * By default, this type is struct Bytes64
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes64)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes64, the
 * following restriction applies: the key of struct
 * Bytes64 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes64.
 */
typedef Bytes64 Bytes64KeyHolder;


extern RTIBool Bytes64Plugin_serialize(
    struct RTICdrStream *stream, const Bytes64 *sample,
    void *serialize_option);

extern RTIBool Bytes64Plugin_deserialize(
    struct RTICdrStream *stream, Bytes64 *sample,
    void *deserialize_option);

extern unsigned int Bytes64Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes64Plugin_print(
    const Bytes64 *sample,
    const char *description, int indent_level);

extern Bytes64 *Bytes64Plugin_create_sample();

extern Bytes64 *Bytes64Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes64Plugin_delete_sample(
    Bytes64 *sample);        

extern void Bytes64Plugin_delete_sample_ex(
    Bytes64 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes64Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes64Plugin_new();

extern void Bytes64Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes64KeyHolder *Bytes64Plugin_create_key();

extern void Bytes64Plugin_delete_key(
    Bytes64KeyHolder *key);

extern RTIBool Bytes64Plugin_instance_to_key(
    Bytes64KeyHolder *key, const Bytes64 *instance);

extern RTIBool Bytes64Plugin_key_to_instance(
    Bytes64 *instance, const Bytes64KeyHolder *key);

extern RTIBool Bytes64Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes64 *instance);




/* The type used to store keys for instances of type struct
 * Bytes128.
 *
 * By default, this type is struct Bytes128
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes128)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes128, the
 * following restriction applies: the key of struct
 * Bytes128 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes128.
 */
typedef Bytes128 Bytes128KeyHolder;


extern RTIBool Bytes128Plugin_serialize(
    struct RTICdrStream *stream, const Bytes128 *sample,
    void *serialize_option);

extern RTIBool Bytes128Plugin_deserialize(
    struct RTICdrStream *stream, Bytes128 *sample,
    void *deserialize_option);

extern unsigned int Bytes128Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes128Plugin_print(
    const Bytes128 *sample,
    const char *description, int indent_level);

extern Bytes128 *Bytes128Plugin_create_sample();

extern Bytes128 *Bytes128Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes128Plugin_delete_sample(
    Bytes128 *sample);        

extern void Bytes128Plugin_delete_sample_ex(
    Bytes128 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes128Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes128Plugin_new();

extern void Bytes128Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes128KeyHolder *Bytes128Plugin_create_key();

extern void Bytes128Plugin_delete_key(
    Bytes128KeyHolder *key);

extern RTIBool Bytes128Plugin_instance_to_key(
    Bytes128KeyHolder *key, const Bytes128 *instance);

extern RTIBool Bytes128Plugin_key_to_instance(
    Bytes128 *instance, const Bytes128KeyHolder *key);

extern RTIBool Bytes128Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes128 *instance);




/* The type used to store keys for instances of type struct
 * Bytes256.
 *
 * By default, this type is struct Bytes256
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes256)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes256, the
 * following restriction applies: the key of struct
 * Bytes256 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes256.
 */
typedef Bytes256 Bytes256KeyHolder;


extern RTIBool Bytes256Plugin_serialize(
    struct RTICdrStream *stream, const Bytes256 *sample,
    void *serialize_option);

extern RTIBool Bytes256Plugin_deserialize(
    struct RTICdrStream *stream, Bytes256 *sample,
    void *deserialize_option);

extern unsigned int Bytes256Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes256Plugin_print(
    const Bytes256 *sample,
    const char *description, int indent_level);

extern Bytes256 *Bytes256Plugin_create_sample();

extern Bytes256 *Bytes256Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes256Plugin_delete_sample(
    Bytes256 *sample);        

extern void Bytes256Plugin_delete_sample_ex(
    Bytes256 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes256Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes256Plugin_new();

extern void Bytes256Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes256KeyHolder *Bytes256Plugin_create_key();

extern void Bytes256Plugin_delete_key(
    Bytes256KeyHolder *key);

extern RTIBool Bytes256Plugin_instance_to_key(
    Bytes256KeyHolder *key, const Bytes256 *instance);

extern RTIBool Bytes256Plugin_key_to_instance(
    Bytes256 *instance, const Bytes256KeyHolder *key);

extern RTIBool Bytes256Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes256 *instance);




/* The type used to store keys for instances of type struct
 * Bytes512.
 *
 * By default, this type is struct Bytes512
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes512)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes512, the
 * following restriction applies: the key of struct
 * Bytes512 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes512.
 */
typedef Bytes512 Bytes512KeyHolder;


extern RTIBool Bytes512Plugin_serialize(
    struct RTICdrStream *stream, const Bytes512 *sample,
    void *serialize_option);

extern RTIBool Bytes512Plugin_deserialize(
    struct RTICdrStream *stream, Bytes512 *sample,
    void *deserialize_option);

extern unsigned int Bytes512Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes512Plugin_print(
    const Bytes512 *sample,
    const char *description, int indent_level);

extern Bytes512 *Bytes512Plugin_create_sample();

extern Bytes512 *Bytes512Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes512Plugin_delete_sample(
    Bytes512 *sample);        

extern void Bytes512Plugin_delete_sample_ex(
    Bytes512 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes512Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes512Plugin_new();

extern void Bytes512Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes512KeyHolder *Bytes512Plugin_create_key();

extern void Bytes512Plugin_delete_key(
    Bytes512KeyHolder *key);

extern RTIBool Bytes512Plugin_instance_to_key(
    Bytes512KeyHolder *key, const Bytes512 *instance);

extern RTIBool Bytes512Plugin_key_to_instance(
    Bytes512 *instance, const Bytes512KeyHolder *key);

extern RTIBool Bytes512Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes512 *instance);




/* The type used to store keys for instances of type struct
 * Bytes1024.
 *
 * By default, this type is struct Bytes1024
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes1024)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes1024, the
 * following restriction applies: the key of struct
 * Bytes1024 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes1024.
 */
typedef Bytes1024 Bytes1024KeyHolder;


extern RTIBool Bytes1024Plugin_serialize(
    struct RTICdrStream *stream, const Bytes1024 *sample,
    void *serialize_option);

extern RTIBool Bytes1024Plugin_deserialize(
    struct RTICdrStream *stream, Bytes1024 *sample,
    void *deserialize_option);

extern unsigned int Bytes1024Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes1024Plugin_print(
    const Bytes1024 *sample,
    const char *description, int indent_level);

extern Bytes1024 *Bytes1024Plugin_create_sample();

extern Bytes1024 *Bytes1024Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes1024Plugin_delete_sample(
    Bytes1024 *sample);        

extern void Bytes1024Plugin_delete_sample_ex(
    Bytes1024 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes1024Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes1024Plugin_new();

extern void Bytes1024Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes1024KeyHolder *Bytes1024Plugin_create_key();

extern void Bytes1024Plugin_delete_key(
    Bytes1024KeyHolder *key);

extern RTIBool Bytes1024Plugin_instance_to_key(
    Bytes1024KeyHolder *key, const Bytes1024 *instance);

extern RTIBool Bytes1024Plugin_key_to_instance(
    Bytes1024 *instance, const Bytes1024KeyHolder *key);

extern RTIBool Bytes1024Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes1024 *instance);




/* The type used to store keys for instances of type struct
 * Bytes2048.
 *
 * By default, this type is struct Bytes2048
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes2048)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes2048, the
 * following restriction applies: the key of struct
 * Bytes2048 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes2048.
 */
typedef Bytes2048 Bytes2048KeyHolder;


extern RTIBool Bytes2048Plugin_serialize(
    struct RTICdrStream *stream, const Bytes2048 *sample,
    void *serialize_option);

extern RTIBool Bytes2048Plugin_deserialize(
    struct RTICdrStream *stream, Bytes2048 *sample,
    void *deserialize_option);

extern unsigned int Bytes2048Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes2048Plugin_print(
    const Bytes2048 *sample,
    const char *description, int indent_level);

extern Bytes2048 *Bytes2048Plugin_create_sample();

extern Bytes2048 *Bytes2048Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes2048Plugin_delete_sample(
    Bytes2048 *sample);        

extern void Bytes2048Plugin_delete_sample_ex(
    Bytes2048 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes2048Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes2048Plugin_new();

extern void Bytes2048Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes2048KeyHolder *Bytes2048Plugin_create_key();

extern void Bytes2048Plugin_delete_key(
    Bytes2048KeyHolder *key);

extern RTIBool Bytes2048Plugin_instance_to_key(
    Bytes2048KeyHolder *key, const Bytes2048 *instance);

extern RTIBool Bytes2048Plugin_key_to_instance(
    Bytes2048 *instance, const Bytes2048KeyHolder *key);

extern RTIBool Bytes2048Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes2048 *instance);




/* The type used to store keys for instances of type struct
 * Bytes4096.
 *
 * By default, this type is struct Bytes4096
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes4096)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes4096, the
 * following restriction applies: the key of struct
 * Bytes4096 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes4096.
 */
typedef Bytes4096 Bytes4096KeyHolder;


extern RTIBool Bytes4096Plugin_serialize(
    struct RTICdrStream *stream, const Bytes4096 *sample,
    void *serialize_option);

extern RTIBool Bytes4096Plugin_deserialize(
    struct RTICdrStream *stream, Bytes4096 *sample,
    void *deserialize_option);

extern unsigned int Bytes4096Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes4096Plugin_print(
    const Bytes4096 *sample,
    const char *description, int indent_level);

extern Bytes4096 *Bytes4096Plugin_create_sample();

extern Bytes4096 *Bytes4096Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes4096Plugin_delete_sample(
    Bytes4096 *sample);        

extern void Bytes4096Plugin_delete_sample_ex(
    Bytes4096 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes4096Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes4096Plugin_new();

extern void Bytes4096Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes4096KeyHolder *Bytes4096Plugin_create_key();

extern void Bytes4096Plugin_delete_key(
    Bytes4096KeyHolder *key);

extern RTIBool Bytes4096Plugin_instance_to_key(
    Bytes4096KeyHolder *key, const Bytes4096 *instance);

extern RTIBool Bytes4096Plugin_key_to_instance(
    Bytes4096 *instance, const Bytes4096KeyHolder *key);

extern RTIBool Bytes4096Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes4096 *instance);




/* The type used to store keys for instances of type struct
 * Bytes8192.
 *
 * By default, this type is struct Bytes8192
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes8192)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes8192, the
 * following restriction applies: the key of struct
 * Bytes8192 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes8192.
 */
typedef Bytes8192 Bytes8192KeyHolder;


extern RTIBool Bytes8192Plugin_serialize(
    struct RTICdrStream *stream, const Bytes8192 *sample,
    void *serialize_option);

extern RTIBool Bytes8192Plugin_deserialize(
    struct RTICdrStream *stream, Bytes8192 *sample,
    void *deserialize_option);

extern unsigned int Bytes8192Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes8192Plugin_print(
    const Bytes8192 *sample,
    const char *description, int indent_level);

extern Bytes8192 *Bytes8192Plugin_create_sample();

extern Bytes8192 *Bytes8192Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes8192Plugin_delete_sample(
    Bytes8192 *sample);        

extern void Bytes8192Plugin_delete_sample_ex(
    Bytes8192 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes8192Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes8192Plugin_new();

extern void Bytes8192Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes8192KeyHolder *Bytes8192Plugin_create_key();

extern void Bytes8192Plugin_delete_key(
    Bytes8192KeyHolder *key);

extern RTIBool Bytes8192Plugin_instance_to_key(
    Bytes8192KeyHolder *key, const Bytes8192 *instance);

extern RTIBool Bytes8192Plugin_key_to_instance(
    Bytes8192 *instance, const Bytes8192KeyHolder *key);

extern RTIBool Bytes8192Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes8192 *instance);




/* The type used to store keys for instances of type struct
 * Bytes16384.
 *
 * By default, this type is struct Bytes16384
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Bytes16384)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Bytes16384, the
 * following restriction applies: the key of struct
 * Bytes16384 must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Bytes16384.
 */
typedef Bytes16384 Bytes16384KeyHolder;


extern RTIBool Bytes16384Plugin_serialize(
    struct RTICdrStream *stream, const Bytes16384 *sample,
    void *serialize_option);

extern RTIBool Bytes16384Plugin_deserialize(
    struct RTICdrStream *stream, Bytes16384 *sample,
    void *deserialize_option);

extern unsigned int Bytes16384Plugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void Bytes16384Plugin_print(
    const Bytes16384 *sample,
    const char *description, int indent_level);

extern Bytes16384 *Bytes16384Plugin_create_sample();

extern Bytes16384 *Bytes16384Plugin_create_sample_ex(RTIBool allocatePointers);        

extern void Bytes16384Plugin_delete_sample(
    Bytes16384 *sample);        

extern void Bytes16384Plugin_delete_sample_ex(
    Bytes16384 *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind Bytes16384Plugin_get_key_kind();

extern struct PRESTypePlugin *Bytes16384Plugin_new();

extern void Bytes16384Plugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern Bytes16384KeyHolder *Bytes16384Plugin_create_key();

extern void Bytes16384Plugin_delete_key(
    Bytes16384KeyHolder *key);

extern RTIBool Bytes16384Plugin_instance_to_key(
    Bytes16384KeyHolder *key, const Bytes16384 *instance);

extern RTIBool Bytes16384Plugin_key_to_instance(
    Bytes16384 *instance, const Bytes16384KeyHolder *key);

extern RTIBool Bytes16384Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes16384 *instance);



#ifdef __cplusplus
}
#endif
        

#endif /* TP_PacketPlugin_h */
