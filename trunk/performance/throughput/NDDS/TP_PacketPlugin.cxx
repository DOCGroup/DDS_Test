
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from TP_Packet.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/


#include <string.h>

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
  #include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

#ifndef cdr_stream_h
  #include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
  #include "pres/pres_typePlugin.h"
#endif



#ifndef TP_PacketPlugin_h
#include "TP_PacketPlugin.h"
#endif


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool NDDSLatencyPacketPlugin_serialize(
    struct RTICdrStream *stream, const NDDSLatencyPacket *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->sequenceNumber)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((LATENCY_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((LATENCY_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool NDDSLatencyPacketPlugin_deserialize(
    struct RTICdrStream *stream, NDDSLatencyPacket *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeLong(
        stream, &sample->sequenceNumber)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int NDDSLatencyPacketPlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((LATENCY_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void NDDSLatencyPacketPlugin_print(
    const NDDSLatencyPacket *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printLong(
        &sample->sequenceNumber, "sequenceNumber", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


NDDSLatencyPacket *NDDSLatencyPacketPlugin_create_sample()
{
    return NDDSLatencyPacketPlugin_create_sample_ex(RTI_TRUE);
}
        

NDDSLatencyPacket *NDDSLatencyPacketPlugin_create_sample_ex(RTIBool allocatePointers)
{

    NDDSLatencyPacket *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, NDDSLatencyPacket);
                
    if (sample != NULL) {
        if (!NDDSLatencyPacket_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void NDDSLatencyPacketPlugin_delete_sample(
    NDDSLatencyPacket *sample)
{
    NDDSLatencyPacketPlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void NDDSLatencyPacketPlugin_delete_sample_ex(
    NDDSLatencyPacket *sample,RTIBool deletePointers)
{
    NDDSLatencyPacket_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind NDDSLatencyPacketPlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


NDDSLatencyPacketKeyHolder *NDDSLatencyPacketPlugin_create_key()
{
    /* Note: If the definition of NDDSLatencyPacketKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return NDDSLatencyPacketPlugin_create_sample();
}


void NDDSLatencyPacketPlugin_delete_key(
    NDDSLatencyPacketKeyHolder *key)
{
    /* Note: If the definition of NDDSLatencyPacketKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    NDDSLatencyPacketPlugin_delete_sample(key);
}


RTIBool NDDSLatencyPacketPlugin_instance_to_key(
    NDDSLatencyPacketKeyHolder *dst, const NDDSLatencyPacket *src)
{

    return RTI_TRUE;
}


RTIBool NDDSLatencyPacketPlugin_key_to_instance(
    NDDSLatencyPacket *dst, const NDDSLatencyPacketKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool NDDSLatencyPacketPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const NDDSLatencyPacket *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *NDDSLatencyPacketPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        NDDSLatencyPacketPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        NDDSLatencyPacketPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        NDDSLatencyPacket_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        NDDSLatencyPacketPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        NDDSLatencyPacketPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        NDDSLatencyPacketPlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        NDDSLatencyPacketPlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        NDDSLatencyPacketPlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        NDDSLatencyPacketPlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        NDDSLatencyPacketPlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        NDDSLatencyPacket_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        NDDSLatencyPacket_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        NDDSLatencyPacket_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        NDDSLatencyPacket_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        NDDSLatencyPacketPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        NDDSLatencyPacketPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        NDDSLatencyPacketPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        NDDSLatencyPacketPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        NDDSLatencyPacketPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)NDDSLatencyPacket_get_typecode();
    
    
    return plugin;
}


void NDDSLatencyPacketPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes4Plugin_serialize(
    struct RTICdrStream *stream, const Bytes4 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES4_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES4_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes4Plugin_deserialize(
    struct RTICdrStream *stream, Bytes4 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes4Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES4_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes4Plugin_print(
    const Bytes4 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes4 *Bytes4Plugin_create_sample()
{
    return Bytes4Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes4 *Bytes4Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes4 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes4);
                
    if (sample != NULL) {
        if (!Bytes4_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes4Plugin_delete_sample(
    Bytes4 *sample)
{
    Bytes4Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes4Plugin_delete_sample_ex(
    Bytes4 *sample,RTIBool deletePointers)
{
    Bytes4_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes4Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes4KeyHolder *Bytes4Plugin_create_key()
{
    /* Note: If the definition of Bytes4KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes4Plugin_create_sample();
}


void Bytes4Plugin_delete_key(
    Bytes4KeyHolder *key)
{
    /* Note: If the definition of Bytes4KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes4Plugin_delete_sample(key);
}


RTIBool Bytes4Plugin_instance_to_key(
    Bytes4KeyHolder *dst, const Bytes4 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes4Plugin_key_to_instance(
    Bytes4 *dst, const Bytes4KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes4Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes4 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes4Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes4Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes4Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes4_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes4Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes4Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes4Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes4Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes4Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes4Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes4Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes4_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes4_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes4_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes4_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes4Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes4Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes4Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes4Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes4Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes4_get_typecode();
    
    
    return plugin;
}


void Bytes4Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes8Plugin_serialize(
    struct RTICdrStream *stream, const Bytes8 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES8_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES8_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes8Plugin_deserialize(
    struct RTICdrStream *stream, Bytes8 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes8Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES8_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes8Plugin_print(
    const Bytes8 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes8 *Bytes8Plugin_create_sample()
{
    return Bytes8Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes8 *Bytes8Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes8 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes8);
                
    if (sample != NULL) {
        if (!Bytes8_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes8Plugin_delete_sample(
    Bytes8 *sample)
{
    Bytes8Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes8Plugin_delete_sample_ex(
    Bytes8 *sample,RTIBool deletePointers)
{
    Bytes8_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes8Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes8KeyHolder *Bytes8Plugin_create_key()
{
    /* Note: If the definition of Bytes8KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes8Plugin_create_sample();
}


void Bytes8Plugin_delete_key(
    Bytes8KeyHolder *key)
{
    /* Note: If the definition of Bytes8KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes8Plugin_delete_sample(key);
}


RTIBool Bytes8Plugin_instance_to_key(
    Bytes8KeyHolder *dst, const Bytes8 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes8Plugin_key_to_instance(
    Bytes8 *dst, const Bytes8KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes8Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes8 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes8Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes8Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes8Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes8_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes8Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes8Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes8Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes8Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes8Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes8Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes8Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes8_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes8_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes8_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes8_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes8Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes8Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes8Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes8Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes8Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes8_get_typecode();
    
    
    return plugin;
}


void Bytes8Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes16Plugin_serialize(
    struct RTICdrStream *stream, const Bytes16 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES16_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES16_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes16Plugin_deserialize(
    struct RTICdrStream *stream, Bytes16 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes16Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES16_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes16Plugin_print(
    const Bytes16 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes16 *Bytes16Plugin_create_sample()
{
    return Bytes16Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes16 *Bytes16Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes16 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes16);
                
    if (sample != NULL) {
        if (!Bytes16_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes16Plugin_delete_sample(
    Bytes16 *sample)
{
    Bytes16Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes16Plugin_delete_sample_ex(
    Bytes16 *sample,RTIBool deletePointers)
{
    Bytes16_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes16Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes16KeyHolder *Bytes16Plugin_create_key()
{
    /* Note: If the definition of Bytes16KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes16Plugin_create_sample();
}


void Bytes16Plugin_delete_key(
    Bytes16KeyHolder *key)
{
    /* Note: If the definition of Bytes16KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes16Plugin_delete_sample(key);
}


RTIBool Bytes16Plugin_instance_to_key(
    Bytes16KeyHolder *dst, const Bytes16 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes16Plugin_key_to_instance(
    Bytes16 *dst, const Bytes16KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes16Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes16 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes16Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes16Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes16Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes16_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes16Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes16Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes16Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes16Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes16Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes16Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes16Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes16_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes16_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes16_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes16_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes16Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes16Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes16Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes16Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes16Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes16_get_typecode();
    
    
    return plugin;
}


void Bytes16Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes32Plugin_serialize(
    struct RTICdrStream *stream, const Bytes32 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES32_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES32_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes32Plugin_deserialize(
    struct RTICdrStream *stream, Bytes32 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes32Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES32_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes32Plugin_print(
    const Bytes32 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes32 *Bytes32Plugin_create_sample()
{
    return Bytes32Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes32 *Bytes32Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes32 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes32);
                
    if (sample != NULL) {
        if (!Bytes32_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes32Plugin_delete_sample(
    Bytes32 *sample)
{
    Bytes32Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes32Plugin_delete_sample_ex(
    Bytes32 *sample,RTIBool deletePointers)
{
    Bytes32_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes32Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes32KeyHolder *Bytes32Plugin_create_key()
{
    /* Note: If the definition of Bytes32KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes32Plugin_create_sample();
}


void Bytes32Plugin_delete_key(
    Bytes32KeyHolder *key)
{
    /* Note: If the definition of Bytes32KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes32Plugin_delete_sample(key);
}


RTIBool Bytes32Plugin_instance_to_key(
    Bytes32KeyHolder *dst, const Bytes32 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes32Plugin_key_to_instance(
    Bytes32 *dst, const Bytes32KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes32Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes32 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes32Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes32Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes32Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes32_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes32Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes32Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes32Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes32Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes32Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes32Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes32Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes32_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes32_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes32_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes32_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes32Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes32Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes32Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes32Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes32Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes32_get_typecode();
    
    
    return plugin;
}


void Bytes32Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes64Plugin_serialize(
    struct RTICdrStream *stream, const Bytes64 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES64_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES64_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes64Plugin_deserialize(
    struct RTICdrStream *stream, Bytes64 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes64Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES64_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes64Plugin_print(
    const Bytes64 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes64 *Bytes64Plugin_create_sample()
{
    return Bytes64Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes64 *Bytes64Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes64 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes64);
                
    if (sample != NULL) {
        if (!Bytes64_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes64Plugin_delete_sample(
    Bytes64 *sample)
{
    Bytes64Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes64Plugin_delete_sample_ex(
    Bytes64 *sample,RTIBool deletePointers)
{
    Bytes64_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes64Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes64KeyHolder *Bytes64Plugin_create_key()
{
    /* Note: If the definition of Bytes64KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes64Plugin_create_sample();
}


void Bytes64Plugin_delete_key(
    Bytes64KeyHolder *key)
{
    /* Note: If the definition of Bytes64KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes64Plugin_delete_sample(key);
}


RTIBool Bytes64Plugin_instance_to_key(
    Bytes64KeyHolder *dst, const Bytes64 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes64Plugin_key_to_instance(
    Bytes64 *dst, const Bytes64KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes64Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes64 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes64Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes64Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes64Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes64_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes64Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes64Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes64Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes64Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes64Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes64Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes64Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes64_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes64_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes64_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes64_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes64Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes64Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes64Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes64Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes64Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes64_get_typecode();
    
    
    return plugin;
}


void Bytes64Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes128Plugin_serialize(
    struct RTICdrStream *stream, const Bytes128 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES128_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES128_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes128Plugin_deserialize(
    struct RTICdrStream *stream, Bytes128 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes128Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES128_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes128Plugin_print(
    const Bytes128 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes128 *Bytes128Plugin_create_sample()
{
    return Bytes128Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes128 *Bytes128Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes128 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes128);
                
    if (sample != NULL) {
        if (!Bytes128_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes128Plugin_delete_sample(
    Bytes128 *sample)
{
    Bytes128Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes128Plugin_delete_sample_ex(
    Bytes128 *sample,RTIBool deletePointers)
{
    Bytes128_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes128Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes128KeyHolder *Bytes128Plugin_create_key()
{
    /* Note: If the definition of Bytes128KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes128Plugin_create_sample();
}


void Bytes128Plugin_delete_key(
    Bytes128KeyHolder *key)
{
    /* Note: If the definition of Bytes128KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes128Plugin_delete_sample(key);
}


RTIBool Bytes128Plugin_instance_to_key(
    Bytes128KeyHolder *dst, const Bytes128 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes128Plugin_key_to_instance(
    Bytes128 *dst, const Bytes128KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes128Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes128 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes128Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes128Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes128Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes128_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes128Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes128Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes128Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes128Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes128Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes128Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes128Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes128_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes128_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes128_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes128_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes128Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes128Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes128Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes128Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes128Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes128_get_typecode();
    
    
    return plugin;
}


void Bytes128Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes256Plugin_serialize(
    struct RTICdrStream *stream, const Bytes256 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES256_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES256_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes256Plugin_deserialize(
    struct RTICdrStream *stream, Bytes256 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes256Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES256_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes256Plugin_print(
    const Bytes256 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes256 *Bytes256Plugin_create_sample()
{
    return Bytes256Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes256 *Bytes256Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes256 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes256);
                
    if (sample != NULL) {
        if (!Bytes256_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes256Plugin_delete_sample(
    Bytes256 *sample)
{
    Bytes256Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes256Plugin_delete_sample_ex(
    Bytes256 *sample,RTIBool deletePointers)
{
    Bytes256_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes256Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes256KeyHolder *Bytes256Plugin_create_key()
{
    /* Note: If the definition of Bytes256KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes256Plugin_create_sample();
}


void Bytes256Plugin_delete_key(
    Bytes256KeyHolder *key)
{
    /* Note: If the definition of Bytes256KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes256Plugin_delete_sample(key);
}


RTIBool Bytes256Plugin_instance_to_key(
    Bytes256KeyHolder *dst, const Bytes256 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes256Plugin_key_to_instance(
    Bytes256 *dst, const Bytes256KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes256Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes256 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes256Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes256Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes256Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes256_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes256Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes256Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes256Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes256Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes256Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes256Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes256Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes256_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes256_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes256_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes256_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes256Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes256Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes256Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes256Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes256Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes256_get_typecode();
    
    
    return plugin;
}


void Bytes256Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes512Plugin_serialize(
    struct RTICdrStream *stream, const Bytes512 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES512_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES512_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes512Plugin_deserialize(
    struct RTICdrStream *stream, Bytes512 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes512Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES512_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes512Plugin_print(
    const Bytes512 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes512 *Bytes512Plugin_create_sample()
{
    return Bytes512Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes512 *Bytes512Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes512 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes512);
                
    if (sample != NULL) {
        if (!Bytes512_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes512Plugin_delete_sample(
    Bytes512 *sample)
{
    Bytes512Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes512Plugin_delete_sample_ex(
    Bytes512 *sample,RTIBool deletePointers)
{
    Bytes512_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes512Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes512KeyHolder *Bytes512Plugin_create_key()
{
    /* Note: If the definition of Bytes512KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes512Plugin_create_sample();
}


void Bytes512Plugin_delete_key(
    Bytes512KeyHolder *key)
{
    /* Note: If the definition of Bytes512KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes512Plugin_delete_sample(key);
}


RTIBool Bytes512Plugin_instance_to_key(
    Bytes512KeyHolder *dst, const Bytes512 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes512Plugin_key_to_instance(
    Bytes512 *dst, const Bytes512KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes512Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes512 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes512Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes512Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes512Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes512_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes512Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes512Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes512Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes512Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes512Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes512Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes512Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes512_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes512_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes512_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes512_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes512Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes512Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes512Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes512Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes512Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes512_get_typecode();
    
    
    return plugin;
}


void Bytes512Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes1024Plugin_serialize(
    struct RTICdrStream *stream, const Bytes1024 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES1024_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES1024_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes1024Plugin_deserialize(
    struct RTICdrStream *stream, Bytes1024 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes1024Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES1024_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes1024Plugin_print(
    const Bytes1024 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes1024 *Bytes1024Plugin_create_sample()
{
    return Bytes1024Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes1024 *Bytes1024Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes1024 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes1024);
                
    if (sample != NULL) {
        if (!Bytes1024_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes1024Plugin_delete_sample(
    Bytes1024 *sample)
{
    Bytes1024Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes1024Plugin_delete_sample_ex(
    Bytes1024 *sample,RTIBool deletePointers)
{
    Bytes1024_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes1024Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes1024KeyHolder *Bytes1024Plugin_create_key()
{
    /* Note: If the definition of Bytes1024KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes1024Plugin_create_sample();
}


void Bytes1024Plugin_delete_key(
    Bytes1024KeyHolder *key)
{
    /* Note: If the definition of Bytes1024KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes1024Plugin_delete_sample(key);
}


RTIBool Bytes1024Plugin_instance_to_key(
    Bytes1024KeyHolder *dst, const Bytes1024 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes1024Plugin_key_to_instance(
    Bytes1024 *dst, const Bytes1024KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes1024Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes1024 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes1024Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes1024Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes1024Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes1024_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes1024Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes1024Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes1024Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes1024Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes1024Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes1024Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes1024Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes1024_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes1024_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes1024_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes1024_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes1024Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes1024Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes1024Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes1024Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes1024Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes1024_get_typecode();
    
    
    return plugin;
}


void Bytes1024Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes2048Plugin_serialize(
    struct RTICdrStream *stream, const Bytes2048 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES2048_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES2048_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes2048Plugin_deserialize(
    struct RTICdrStream *stream, Bytes2048 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes2048Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES2048_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes2048Plugin_print(
    const Bytes2048 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes2048 *Bytes2048Plugin_create_sample()
{
    return Bytes2048Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes2048 *Bytes2048Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes2048 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes2048);
                
    if (sample != NULL) {
        if (!Bytes2048_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes2048Plugin_delete_sample(
    Bytes2048 *sample)
{
    Bytes2048Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes2048Plugin_delete_sample_ex(
    Bytes2048 *sample,RTIBool deletePointers)
{
    Bytes2048_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes2048Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes2048KeyHolder *Bytes2048Plugin_create_key()
{
    /* Note: If the definition of Bytes2048KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes2048Plugin_create_sample();
}


void Bytes2048Plugin_delete_key(
    Bytes2048KeyHolder *key)
{
    /* Note: If the definition of Bytes2048KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes2048Plugin_delete_sample(key);
}


RTIBool Bytes2048Plugin_instance_to_key(
    Bytes2048KeyHolder *dst, const Bytes2048 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes2048Plugin_key_to_instance(
    Bytes2048 *dst, const Bytes2048KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes2048Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes2048 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes2048Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes2048Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes2048Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes2048_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes2048Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes2048Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes2048Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes2048Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes2048Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes2048Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes2048Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes2048_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes2048_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes2048_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes2048_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes2048Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes2048Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes2048Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes2048Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes2048Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes2048_get_typecode();
    
    
    return plugin;
}


void Bytes2048Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes4096Plugin_serialize(
    struct RTICdrStream *stream, const Bytes4096 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES4096_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES4096_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes4096Plugin_deserialize(
    struct RTICdrStream *stream, Bytes4096 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes4096Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES4096_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes4096Plugin_print(
    const Bytes4096 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes4096 *Bytes4096Plugin_create_sample()
{
    return Bytes4096Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes4096 *Bytes4096Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes4096 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes4096);
                
    if (sample != NULL) {
        if (!Bytes4096_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes4096Plugin_delete_sample(
    Bytes4096 *sample)
{
    Bytes4096Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes4096Plugin_delete_sample_ex(
    Bytes4096 *sample,RTIBool deletePointers)
{
    Bytes4096_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes4096Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes4096KeyHolder *Bytes4096Plugin_create_key()
{
    /* Note: If the definition of Bytes4096KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes4096Plugin_create_sample();
}


void Bytes4096Plugin_delete_key(
    Bytes4096KeyHolder *key)
{
    /* Note: If the definition of Bytes4096KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes4096Plugin_delete_sample(key);
}


RTIBool Bytes4096Plugin_instance_to_key(
    Bytes4096KeyHolder *dst, const Bytes4096 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes4096Plugin_key_to_instance(
    Bytes4096 *dst, const Bytes4096KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes4096Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes4096 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes4096Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes4096Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes4096Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes4096_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes4096Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes4096Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes4096Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes4096Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes4096Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes4096Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes4096Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes4096_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes4096_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes4096_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes4096_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes4096Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes4096Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes4096Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes4096Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes4096Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes4096_get_typecode();
    
    
    return plugin;
}


void Bytes4096Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes8192Plugin_serialize(
    struct RTICdrStream *stream, const Bytes8192 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES8192_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES8192_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes8192Plugin_deserialize(
    struct RTICdrStream *stream, Bytes8192 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes8192Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES8192_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes8192Plugin_print(
    const Bytes8192 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes8192 *Bytes8192Plugin_create_sample()
{
    return Bytes8192Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes8192 *Bytes8192Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes8192 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes8192);
                
    if (sample != NULL) {
        if (!Bytes8192_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes8192Plugin_delete_sample(
    Bytes8192 *sample)
{
    Bytes8192Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes8192Plugin_delete_sample_ex(
    Bytes8192 *sample,RTIBool deletePointers)
{
    Bytes8192_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes8192Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes8192KeyHolder *Bytes8192Plugin_create_key()
{
    /* Note: If the definition of Bytes8192KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes8192Plugin_create_sample();
}


void Bytes8192Plugin_delete_key(
    Bytes8192KeyHolder *key)
{
    /* Note: If the definition of Bytes8192KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes8192Plugin_delete_sample(key);
}


RTIBool Bytes8192Plugin_instance_to_key(
    Bytes8192KeyHolder *dst, const Bytes8192 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes8192Plugin_key_to_instance(
    Bytes8192 *dst, const Bytes8192KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes8192Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes8192 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes8192Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes8192Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes8192Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes8192_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes8192Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes8192Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes8192Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes8192Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes8192Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes8192Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes8192Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes8192_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes8192_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes8192_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes8192_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes8192Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes8192Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes8192Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes8192Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes8192Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes8192_get_typecode();
    
    
    return plugin;
}


void Bytes8192Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool Bytes16384Plugin_serialize(
    struct RTICdrStream *stream, const Bytes16384 *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES16384_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((BYTES16384_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool Bytes16384Plugin_deserialize(
    struct RTICdrStream *stream, Bytes16384 *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->timestamp)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializePrimitivePointerSequence(
            stream,
            (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            DDS_OctetSeq_get_maximum(&sample->data),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
    if (!DDS_OctetSeq_set_length(&sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int Bytes16384Plugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((BYTES16384_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void Bytes16384Plugin_print(
    const Bytes16384 *sample,
    const char* description, int indent_level)
{

    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level + 1);
        RTILog_debug("NULL\n");
        return;
    }
        

    RTICdrType_printUnsignedLong(
        &sample->timestamp, "timestamp", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
                DDS_OctetSeq_get_length(&sample->data),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Bytes16384 *Bytes16384Plugin_create_sample()
{
    return Bytes16384Plugin_create_sample_ex(RTI_TRUE);
}
        

Bytes16384 *Bytes16384Plugin_create_sample_ex(RTIBool allocatePointers)
{

    Bytes16384 *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Bytes16384);
                
    if (sample != NULL) {
        if (!Bytes16384_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void Bytes16384Plugin_delete_sample(
    Bytes16384 *sample)
{
    Bytes16384Plugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void Bytes16384Plugin_delete_sample_ex(
    Bytes16384 *sample,RTIBool deletePointers)
{
    Bytes16384_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind Bytes16384Plugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


Bytes16384KeyHolder *Bytes16384Plugin_create_key()
{
    /* Note: If the definition of Bytes16384KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return Bytes16384Plugin_create_sample();
}


void Bytes16384Plugin_delete_key(
    Bytes16384KeyHolder *key)
{
    /* Note: If the definition of Bytes16384KeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    Bytes16384Plugin_delete_sample(key);
}


RTIBool Bytes16384Plugin_instance_to_key(
    Bytes16384KeyHolder *dst, const Bytes16384 *src)
{

    return RTI_TRUE;
}


RTIBool Bytes16384Plugin_key_to_instance(
    Bytes16384 *dst, const Bytes16384KeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool Bytes16384Plugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Bytes16384 *instance)
{
    int idIndex = 2;
    idIndex = 2;
    id->value[2] = 0;
    id->value[1] = 0;
    id->value[0] = 0;


    /* By default, NDDSGen assumes that the key specified in the type
     * fully identifies instances of that type. If you would like to
     * further discriminate among instances based on the participant
     * from which they originate, set this out parameter to RTI_FALSE. In
     * that case, only set the value at the last index of the instance ID;
     * the first two values will be set automatically to the RTPS host ID and
     * application ID of the writer's domain participant. (See the
     * documentation for DDS_WireProtocolQosPolicy for a description of
     * the host ID and app ID.)
     */
    *is_unique = RTI_TRUE;
    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */


struct PRESTypePlugin *Bytes16384Plugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        Bytes16384Plugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        Bytes16384Plugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Bytes16384_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        Bytes16384Plugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        Bytes16384Plugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        Bytes16384Plugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        Bytes16384Plugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        Bytes16384Plugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        Bytes16384Plugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        Bytes16384Plugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Bytes16384_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Bytes16384_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Bytes16384_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Bytes16384_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        Bytes16384Plugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        Bytes16384Plugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        Bytes16384Plugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        Bytes16384Plugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        Bytes16384Plugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Bytes16384_get_typecode();
    
    
    return plugin;
}


void Bytes16384Plugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}

