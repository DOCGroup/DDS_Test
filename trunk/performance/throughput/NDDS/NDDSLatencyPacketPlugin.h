
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
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

extern void NDDSLatencyPacketPlugin_delete_sample(
    NDDSLatencyPacket *sample);

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



#ifdef __cplusplus
}
#endif

#endif /* NDDSLatencyPacketPlugin_h */
