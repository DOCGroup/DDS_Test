
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
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


RTIBool PubMessagePlugin_serialize(
    struct RTICdrStream *stream, const PubMessage *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->seqnum)) {
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


RTIBool PubMessagePlugin_deserialize(
    struct RTICdrStream *stream, PubMessage *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeLong(
        stream, &sample->seqnum)) {
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


unsigned int PubMessagePlugin_get_max_size_serialized(
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


void PubMessagePlugin_print(
    const PubMessage *sample,
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
        &sample->seqnum, "seqnum", indent_level + 1);
            
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


PubMessage *PubMessagePlugin_create_sample()
{
    return PubMessagePlugin_create_sample_ex(RTI_TRUE);
}
        

PubMessage *PubMessagePlugin_create_sample_ex(RTIBool allocatePointers)
{

    PubMessage *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, PubMessage);
                
    if (sample != NULL) {
        if (!PubMessage_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void PubMessagePlugin_delete_sample(
    PubMessage *sample)
{
    PubMessagePlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void PubMessagePlugin_delete_sample_ex(
    PubMessage *sample,RTIBool deletePointers)
{
    PubMessage_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind PubMessagePlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


PubMessageKeyHolder *PubMessagePlugin_create_key()
{
    /* Note: If the definition of PubMessageKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return PubMessagePlugin_create_sample();
}


void PubMessagePlugin_delete_key(
    PubMessageKeyHolder *key)
{
    /* Note: If the definition of PubMessageKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    PubMessagePlugin_delete_sample(key);
}


RTIBool PubMessagePlugin_instance_to_key(
    PubMessageKeyHolder *dst, const PubMessage *src)
{

    return RTI_TRUE;
}


RTIBool PubMessagePlugin_key_to_instance(
    PubMessage *dst, const PubMessageKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool PubMessagePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const PubMessage *instance)
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


struct PRESTypePlugin *PubMessagePlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        PubMessagePlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        PubMessagePlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        PubMessage_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        PubMessagePlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        PubMessagePlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        PubMessagePlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        PubMessagePlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        PubMessagePlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        PubMessagePlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        PubMessagePlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        PubMessage_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        PubMessage_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        PubMessage_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        PubMessage_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        PubMessagePlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        PubMessagePlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        PubMessagePlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        PubMessagePlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        PubMessagePlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)PubMessage_get_typecode();
    
    
    return plugin;
}


void PubMessagePlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool NestedPlugin_serialize(
    struct RTICdrStream *stream, const Nested *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->n_seqnum)) {
        return RTI_FALSE;
    }
            
    if (sample->n_data == NULL) {
        return RTI_FALSE;
    }
    if (!RTICdrStream_serializeString(
        stream, sample->n_data, (20) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool NestedPlugin_deserialize(
    struct RTICdrStream *stream, Nested *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->n_seqnum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->n_data, (20) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int NestedPlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (20) + 1);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void NestedPlugin_print(
    const Nested *sample,
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
        &sample->n_seqnum, "n_seqnum", indent_level + 1);
            
    if (&sample->n_data==NULL) {
        RTICdrType_printString(
            NULL, "n_data", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->n_data, "n_data", indent_level + 1);                
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Nested *NestedPlugin_create_sample()
{
    return NestedPlugin_create_sample_ex(RTI_TRUE);
}
        

Nested *NestedPlugin_create_sample_ex(RTIBool allocatePointers)
{

    Nested *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Nested);
                
    if (sample != NULL) {
        if (!Nested_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void NestedPlugin_delete_sample(
    Nested *sample)
{
    NestedPlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void NestedPlugin_delete_sample_ex(
    Nested *sample,RTIBool deletePointers)
{
    Nested_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind NestedPlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


NestedKeyHolder *NestedPlugin_create_key()
{
    /* Note: If the definition of NestedKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return NestedPlugin_create_sample();
}


void NestedPlugin_delete_key(
    NestedKeyHolder *key)
{
    /* Note: If the definition of NestedKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    NestedPlugin_delete_sample(key);
}


RTIBool NestedPlugin_instance_to_key(
    NestedKeyHolder *dst, const Nested *src)
{

    return RTI_TRUE;
}


RTIBool NestedPlugin_key_to_instance(
    Nested *dst, const NestedKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool NestedPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Nested *instance)
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


struct PRESTypePlugin *NestedPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        NestedPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        NestedPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Nested_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        NestedPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        NestedPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        NestedPlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        NestedPlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        NestedPlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        NestedPlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        NestedPlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Nested_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Nested_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Nested_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Nested_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        NestedPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        NestedPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        NestedPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        NestedPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        NestedPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Nested_get_typecode();
    
    
    return plugin;
}


void NestedPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool OuterPlugin_serialize(
    struct RTICdrStream *stream, const Outer *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->o_seqnum)) {
        return RTI_FALSE;
    }
            
    if (NestedSeq_get_contiguous_bufferI(&sample->o_data) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            NestedSeq_get_contiguous_bufferI(&sample->o_data),
            NestedSeq_get_length(&sample->o_data),
            (10),
            sizeof(Nested),
            (RTICdrStreamSerializeFunction)NestedPlugin_serialize,
            serialize_option)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)NestedSeq_get_discontiguous_bufferI(&sample->o_data),
            NestedSeq_get_length(&sample->o_data),
            (10),
            (RTICdrStreamSerializeFunction)NestedPlugin_serialize,
            serialize_option)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool OuterPlugin_deserialize(
    struct RTICdrStream *stream, Outer *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeLong(
        stream, &sample->o_seqnum)) {
        return RTI_FALSE;
    }
            
    if (NestedSeq_get_contiguous_bufferI(&sample->o_data) != NULL) {
        if (!RTICdrStream_deserializeNonPrimitiveSequence(
            stream,
            NestedSeq_get_contiguous_bufferI(&sample->o_data),
            &sequence_length,
            NestedSeq_get_maximum(&sample->o_data),
            sizeof(Nested),
            (RTICdrStreamDeserializeFunction)NestedPlugin_deserialize,
            deserialize_option)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
            stream,
            (void **)NestedSeq_get_discontiguous_bufferI(&sample->o_data),
            &sequence_length,
            NestedSeq_get_maximum(&sample->o_data),
            (RTICdrStreamDeserializeFunction)NestedPlugin_deserialize,
            deserialize_option)) {
            return RTI_FALSE;
        }
    }
    if (!NestedSeq_set_length(
        &sample->o_data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int OuterPlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (10),
        NestedPlugin_get_max_size_serialized);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void OuterPlugin_print(
    const Outer *sample,
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
        &sample->o_seqnum, "o_seqnum", indent_level + 1);
            
    if (&sample->o_data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("o_data: NULL\n");    
    } else {
                
        if (NestedSeq_get_contiguous_bufferI(&sample->o_data) != NULL) {
            RTICdrType_printArray(
                NestedSeq_get_contiguous_bufferI(&sample->o_data), 
    	        NestedSeq_get_length(&sample->o_data),
                sizeof(Nested),
                (RTICdrTypePrintFunction)NestedPlugin_print,
                "o_data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                NestedSeq_get_discontiguous_bufferI(&sample->o_data), 
    	        NestedSeq_get_length(&sample->o_data),
                (RTICdrTypePrintFunction)NestedPlugin_print,
                "o_data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Outer *OuterPlugin_create_sample()
{
    return OuterPlugin_create_sample_ex(RTI_TRUE);
}
        

Outer *OuterPlugin_create_sample_ex(RTIBool allocatePointers)
{

    Outer *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Outer);
                
    if (sample != NULL) {
        if (!Outer_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void OuterPlugin_delete_sample(
    Outer *sample)
{
    OuterPlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void OuterPlugin_delete_sample_ex(
    Outer *sample,RTIBool deletePointers)
{
    Outer_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind OuterPlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


OuterKeyHolder *OuterPlugin_create_key()
{
    /* Note: If the definition of OuterKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return OuterPlugin_create_sample();
}


void OuterPlugin_delete_key(
    OuterKeyHolder *key)
{
    /* Note: If the definition of OuterKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    OuterPlugin_delete_sample(key);
}


RTIBool OuterPlugin_instance_to_key(
    OuterKeyHolder *dst, const Outer *src)
{

    return RTI_TRUE;
}


RTIBool OuterPlugin_key_to_instance(
    Outer *dst, const OuterKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool OuterPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Outer *instance)
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


struct PRESTypePlugin *OuterPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        OuterPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        OuterPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Outer_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        OuterPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        OuterPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        OuterPlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        OuterPlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        OuterPlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        OuterPlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        OuterPlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Outer_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Outer_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Outer_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Outer_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        OuterPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        OuterPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        OuterPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        OuterPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        OuterPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Outer_get_typecode();
    
    
    return plugin;
}


void OuterPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool PubMessage_NestPlugin_serialize(
    struct RTICdrStream *stream, const PubMessage_Nest *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->seqnum)) {
        return RTI_FALSE;
    }
            
    if (OuterSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            OuterSeq_get_contiguous_bufferI(&sample->data),
            OuterSeq_get_length(&sample->data),
            ((MAX_MSG_LENGTH)),
            sizeof(Outer),
            (RTICdrStreamSerializeFunction)OuterPlugin_serialize,
            serialize_option)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)OuterSeq_get_discontiguous_bufferI(&sample->data),
            OuterSeq_get_length(&sample->data),
            ((MAX_MSG_LENGTH)),
            (RTICdrStreamSerializeFunction)OuterPlugin_serialize,
            serialize_option)) {
            return RTI_FALSE;
        }
    }
            
    return RTI_TRUE;
}


RTIBool PubMessage_NestPlugin_deserialize(
    struct RTICdrStream *stream, PubMessage_Nest *sample,
    void *deserialize_option)
{

    RTICdrUnsignedLong sequence_length = 0;

    if (!RTICdrStream_deserializeLong(
        stream, &sample->seqnum)) {
        return RTI_FALSE;
    }
            
    if (OuterSeq_get_contiguous_bufferI(&sample->data) != NULL) {
        if (!RTICdrStream_deserializeNonPrimitiveSequence(
            stream,
            OuterSeq_get_contiguous_bufferI(&sample->data),
            &sequence_length,
            OuterSeq_get_maximum(&sample->data),
            sizeof(Outer),
            (RTICdrStreamDeserializeFunction)OuterPlugin_deserialize,
            deserialize_option)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
            stream,
            (void **)OuterSeq_get_discontiguous_bufferI(&sample->data),
            &sequence_length,
            OuterSeq_get_maximum(&sample->data),
            (RTICdrStreamDeserializeFunction)OuterPlugin_deserialize,
            deserialize_option)) {
            return RTI_FALSE;
        }
    }
    if (!OuterSeq_set_length(
        &sample->data, sequence_length)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int PubMessage_NestPlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MAX_MSG_LENGTH)),
        OuterPlugin_get_max_size_serialized);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void PubMessage_NestPlugin_print(
    const PubMessage_Nest *sample,
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
        &sample->seqnum, "seqnum", indent_level + 1);
            
    if (&sample->data == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("data: NULL\n");    
    } else {
                
        if (OuterSeq_get_contiguous_bufferI(&sample->data) != NULL) {
            RTICdrType_printArray(
                OuterSeq_get_contiguous_bufferI(&sample->data), 
    	        OuterSeq_get_length(&sample->data),
                sizeof(Outer),
                (RTICdrTypePrintFunction)OuterPlugin_print,
                "data", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                OuterSeq_get_discontiguous_bufferI(&sample->data), 
    	        OuterSeq_get_length(&sample->data),
                (RTICdrTypePrintFunction)OuterPlugin_print,
                "data", indent_level + 1);
        }
    
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


PubMessage_Nest *PubMessage_NestPlugin_create_sample()
{
    return PubMessage_NestPlugin_create_sample_ex(RTI_TRUE);
}
        

PubMessage_Nest *PubMessage_NestPlugin_create_sample_ex(RTIBool allocatePointers)
{

    PubMessage_Nest *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, PubMessage_Nest);
                
    if (sample != NULL) {
        if (!PubMessage_Nest_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void PubMessage_NestPlugin_delete_sample(
    PubMessage_Nest *sample)
{
    PubMessage_NestPlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void PubMessage_NestPlugin_delete_sample_ex(
    PubMessage_Nest *sample,RTIBool deletePointers)
{
    PubMessage_Nest_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind PubMessage_NestPlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


PubMessage_NestKeyHolder *PubMessage_NestPlugin_create_key()
{
    /* Note: If the definition of PubMessage_NestKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return PubMessage_NestPlugin_create_sample();
}


void PubMessage_NestPlugin_delete_key(
    PubMessage_NestKeyHolder *key)
{
    /* Note: If the definition of PubMessage_NestKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    PubMessage_NestPlugin_delete_sample(key);
}


RTIBool PubMessage_NestPlugin_instance_to_key(
    PubMessage_NestKeyHolder *dst, const PubMessage_Nest *src)
{

    return RTI_TRUE;
}


RTIBool PubMessage_NestPlugin_key_to_instance(
    PubMessage_Nest *dst, const PubMessage_NestKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool PubMessage_NestPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const PubMessage_Nest *instance)
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


struct PRESTypePlugin *PubMessage_NestPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        PubMessage_NestPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        PubMessage_NestPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        PubMessage_Nest_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        PubMessage_NestPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        PubMessage_NestPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        PubMessage_NestPlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        PubMessage_NestPlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        PubMessage_NestPlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        PubMessage_NestPlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        PubMessage_NestPlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        PubMessage_Nest_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        PubMessage_Nest_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        PubMessage_Nest_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        PubMessage_Nest_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        PubMessage_NestPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        PubMessage_NestPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        PubMessage_NestPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        PubMessage_NestPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        PubMessage_NestPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)PubMessage_Nest_get_typecode();
    
    
    return plugin;
}


void PubMessage_NestPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool AckMessagePlugin_serialize(
    struct RTICdrStream *stream, const AckMessage *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->seqnum)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool AckMessagePlugin_deserialize(
    struct RTICdrStream *stream, AckMessage *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->seqnum)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int AckMessagePlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void AckMessagePlugin_print(
    const AckMessage *sample,
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
        &sample->seqnum, "seqnum", indent_level + 1);
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


AckMessage *AckMessagePlugin_create_sample()
{
    return AckMessagePlugin_create_sample_ex(RTI_TRUE);
}
        

AckMessage *AckMessagePlugin_create_sample_ex(RTIBool allocatePointers)
{

    AckMessage *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, AckMessage);
                
    if (sample != NULL) {
        if (!AckMessage_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void AckMessagePlugin_delete_sample(
    AckMessage *sample)
{
    AckMessagePlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void AckMessagePlugin_delete_sample_ex(
    AckMessage *sample,RTIBool deletePointers)
{
    AckMessage_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind AckMessagePlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


AckMessageKeyHolder *AckMessagePlugin_create_key()
{
    /* Note: If the definition of AckMessageKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return AckMessagePlugin_create_sample();
}


void AckMessagePlugin_delete_key(
    AckMessageKeyHolder *key)
{
    /* Note: If the definition of AckMessageKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    AckMessagePlugin_delete_sample(key);
}


RTIBool AckMessagePlugin_instance_to_key(
    AckMessageKeyHolder *dst, const AckMessage *src)
{

    return RTI_TRUE;
}


RTIBool AckMessagePlugin_key_to_instance(
    AckMessage *dst, const AckMessageKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool AckMessagePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const AckMessage *instance)
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


struct PRESTypePlugin *AckMessagePlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        AckMessagePlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        AckMessagePlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        AckMessage_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        AckMessagePlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        AckMessagePlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        AckMessagePlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        AckMessagePlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        AckMessagePlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        AckMessagePlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        AckMessagePlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        AckMessage_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        AckMessage_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        AckMessage_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        AckMessage_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        AckMessagePlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        AckMessagePlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        AckMessagePlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        AckMessagePlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        AckMessagePlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)AckMessage_get_typecode();
    
    
    return plugin;
}


void AckMessagePlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}

