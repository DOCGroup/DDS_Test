
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
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



#ifndef NDDSLatencyPacketPlugin_h
#include "NDDSLatencyPacketPlugin.h"
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
            ((MAX_MSG_LENGTH)),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->data),
            DDS_OctetSeq_get_length(&sample->data),
            ((MAX_MSG_LENGTH)),
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
        current_alignment, ((MAX_MSG_LENGTH)), RTI_CDR_OCTET_TYPE);
            
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

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


NDDSLatencyPacket *NDDSLatencyPacketPlugin_create_sample()
{

    NDDSLatencyPacket *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, NDDSLatencyPacket);

    if (sample != NULL) {
        if (!NDDSLatencyPacket_initialize(sample)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void NDDSLatencyPacketPlugin_delete_sample(
    NDDSLatencyPacket *sample)
{
    NDDSLatencyPacket_finalize(sample);
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

        
    /* No key fields to copy */
    
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
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        NDDSLatencyPacketPlugin_create_sample;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        NDDSLatencyPacketPlugin_delete_sample;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        NDDSLatencyPacket_initialize;
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
    
    
    plugin->typeCode = NULL;    
    
    
    return plugin;
}


void NDDSLatencyPacketPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}

