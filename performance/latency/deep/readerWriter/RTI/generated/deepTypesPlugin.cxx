
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from deepTypes.idl using "rtiddsgen".
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



#ifndef deepTypesPlugin_h
#include "deepTypesPlugin.h"
#endif


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool simpleTypePlugin_serialize(
    struct RTICdrStream *stream, const simpleType *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->payload)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool simpleTypePlugin_deserialize(
    struct RTICdrStream *stream, simpleType *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->payload)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int simpleTypePlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void simpleTypePlugin_print(
    const simpleType *sample,
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
        &sample->id, "id", indent_level + 1);
            
    RTICdrType_printLong(
        &sample->payload, "payload", indent_level + 1);
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


simpleType *simpleTypePlugin_create_sample()
{
    return simpleTypePlugin_create_sample_ex(RTI_TRUE);
}
        

simpleType *simpleTypePlugin_create_sample_ex(RTIBool allocatePointers)
{

    simpleType *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, simpleType);
                
    if (sample != NULL) {
        if (!simpleType_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void simpleTypePlugin_delete_sample(
    simpleType *sample)
{
    simpleTypePlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void simpleTypePlugin_delete_sample_ex(
    simpleType *sample,RTIBool deletePointers)
{
    simpleType_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind simpleTypePlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


simpleTypeKeyHolder *simpleTypePlugin_create_key()
{
    /* Note: If the definition of simpleTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return simpleTypePlugin_create_sample();
}


void simpleTypePlugin_delete_key(
    simpleTypeKeyHolder *key)
{
    /* Note: If the definition of simpleTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    simpleTypePlugin_delete_sample(key);
}


RTIBool simpleTypePlugin_instance_to_key(
    simpleTypeKeyHolder *dst, const simpleType *src)
{

    return RTI_TRUE;
}


RTIBool simpleTypePlugin_key_to_instance(
    simpleType *dst, const simpleTypeKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool simpleTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const simpleType *instance)
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


struct PRESTypePlugin *simpleTypePlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        simpleTypePlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        simpleTypePlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        simpleType_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        simpleTypePlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        simpleTypePlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        simpleTypePlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        simpleTypePlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        simpleTypePlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        simpleTypePlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        simpleTypePlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        simpleType_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        simpleType_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        simpleType_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        simpleType_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        simpleTypePlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        simpleTypePlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        simpleTypePlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        simpleTypePlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        simpleTypePlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)simpleType_get_typecode();
    
    
    return plugin;
}


void simpleTypePlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool innerStructPlugin_serialize(
    struct RTICdrStream *stream, const innerStruct *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->value)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool innerStructPlugin_deserialize(
    struct RTICdrStream *stream, innerStruct *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->value)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int innerStructPlugin_get_max_size_serialized(
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


void innerStructPlugin_print(
    const innerStruct *sample,
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
        &sample->value, "value", indent_level + 1);
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


innerStruct *innerStructPlugin_create_sample()
{
    return innerStructPlugin_create_sample_ex(RTI_TRUE);
}
        

innerStruct *innerStructPlugin_create_sample_ex(RTIBool allocatePointers)
{

    innerStruct *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, innerStruct);
                
    if (sample != NULL) {
        if (!innerStruct_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void innerStructPlugin_delete_sample(
    innerStruct *sample)
{
    innerStructPlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void innerStructPlugin_delete_sample_ex(
    innerStruct *sample,RTIBool deletePointers)
{
    innerStruct_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind innerStructPlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


innerStructKeyHolder *innerStructPlugin_create_key()
{
    /* Note: If the definition of innerStructKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return innerStructPlugin_create_sample();
}


void innerStructPlugin_delete_key(
    innerStructKeyHolder *key)
{
    /* Note: If the definition of innerStructKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    innerStructPlugin_delete_sample(key);
}


RTIBool innerStructPlugin_instance_to_key(
    innerStructKeyHolder *dst, const innerStruct *src)
{

    return RTI_TRUE;
}


RTIBool innerStructPlugin_key_to_instance(
    innerStruct *dst, const innerStructKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool innerStructPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const innerStruct *instance)
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


struct PRESTypePlugin *innerStructPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        innerStructPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        innerStructPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        innerStruct_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        innerStructPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        innerStructPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        innerStructPlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        innerStructPlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        innerStructPlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        innerStructPlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        innerStructPlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        innerStruct_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        innerStruct_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        innerStruct_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        innerStruct_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        innerStructPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        innerStructPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        innerStructPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        innerStructPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        innerStructPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)innerStruct_get_typecode();
    
    
    return plugin;
}


void innerStructPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool nestedTypePlugin_serialize(
    struct RTICdrStream *stream, const nestedType *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!innerStructPlugin_serialize(
        stream, &sample->payload, serialize_option)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool nestedTypePlugin_deserialize(
    struct RTICdrStream *stream, nestedType *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!innerStructPlugin_deserialize(
        stream, &sample->payload, deserialize_option)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int nestedTypePlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  innerStructPlugin_get_max_size_serialized(
        current_alignment);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void nestedTypePlugin_print(
    const nestedType *sample,
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
        &sample->id, "id", indent_level + 1);
            
    innerStructPlugin_print(
        &sample->payload, "payload", indent_level + 1);
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


nestedType *nestedTypePlugin_create_sample()
{
    return nestedTypePlugin_create_sample_ex(RTI_TRUE);
}
        

nestedType *nestedTypePlugin_create_sample_ex(RTIBool allocatePointers)
{

    nestedType *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, nestedType);
                
    if (sample != NULL) {
        if (!nestedType_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void nestedTypePlugin_delete_sample(
    nestedType *sample)
{
    nestedTypePlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void nestedTypePlugin_delete_sample_ex(
    nestedType *sample,RTIBool deletePointers)
{
    nestedType_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind nestedTypePlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


nestedTypeKeyHolder *nestedTypePlugin_create_key()
{
    /* Note: If the definition of nestedTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return nestedTypePlugin_create_sample();
}


void nestedTypePlugin_delete_key(
    nestedTypeKeyHolder *key)
{
    /* Note: If the definition of nestedTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    nestedTypePlugin_delete_sample(key);
}


RTIBool nestedTypePlugin_instance_to_key(
    nestedTypeKeyHolder *dst, const nestedType *src)
{

    return RTI_TRUE;
}


RTIBool nestedTypePlugin_key_to_instance(
    nestedType *dst, const nestedTypeKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool nestedTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const nestedType *instance)
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


struct PRESTypePlugin *nestedTypePlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        nestedTypePlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        nestedTypePlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        nestedType_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        nestedTypePlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        nestedTypePlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        nestedTypePlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        nestedTypePlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        nestedTypePlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        nestedTypePlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        nestedTypePlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        nestedType_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        nestedType_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        nestedType_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        nestedType_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        nestedTypePlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        nestedTypePlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        nestedTypePlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        nestedTypePlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        nestedTypePlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)nestedType_get_typecode();
    
    
    return plugin;
}


void nestedTypePlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool arrayTypePlugin_serialize(
    struct RTICdrStream *stream, const arrayType *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->payload, (10), RTI_CDR_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool arrayTypePlugin_deserialize(
    struct RTICdrStream *stream, arrayType *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->payload, (10), RTI_CDR_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int arrayTypePlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (10), RTI_CDR_LONG_TYPE);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void arrayTypePlugin_print(
    const arrayType *sample,
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
        &sample->id, "id", indent_level + 1);
            
    RTICdrType_printArray(
        sample->payload, (10), RTI_CDR_LONG_SIZE,
        (RTICdrTypePrintFunction)RTICdrType_printLong,
        "payload", indent_level + 1);
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


arrayType *arrayTypePlugin_create_sample()
{
    return arrayTypePlugin_create_sample_ex(RTI_TRUE);
}
        

arrayType *arrayTypePlugin_create_sample_ex(RTIBool allocatePointers)
{

    arrayType *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, arrayType);
                
    if (sample != NULL) {
        if (!arrayType_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void arrayTypePlugin_delete_sample(
    arrayType *sample)
{
    arrayTypePlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void arrayTypePlugin_delete_sample_ex(
    arrayType *sample,RTIBool deletePointers)
{
    arrayType_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind arrayTypePlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


arrayTypeKeyHolder *arrayTypePlugin_create_key()
{
    /* Note: If the definition of arrayTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return arrayTypePlugin_create_sample();
}


void arrayTypePlugin_delete_key(
    arrayTypeKeyHolder *key)
{
    /* Note: If the definition of arrayTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    arrayTypePlugin_delete_sample(key);
}


RTIBool arrayTypePlugin_instance_to_key(
    arrayTypeKeyHolder *dst, const arrayType *src)
{

    return RTI_TRUE;
}


RTIBool arrayTypePlugin_key_to_instance(
    arrayType *dst, const arrayTypeKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool arrayTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const arrayType *instance)
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


struct PRESTypePlugin *arrayTypePlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        arrayTypePlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        arrayTypePlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        arrayType_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        arrayTypePlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        arrayTypePlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        arrayTypePlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        arrayTypePlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        arrayTypePlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        arrayTypePlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        arrayTypePlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        arrayType_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        arrayType_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        arrayType_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        arrayType_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        arrayTypePlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        arrayTypePlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        arrayTypePlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        arrayTypePlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        arrayTypePlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)arrayType_get_typecode();
    
    
    return plugin;
}


void arrayTypePlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool stringTypePlugin_serialize(
    struct RTICdrStream *stream, const stringType *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (sample->payload == NULL) {
        return RTI_FALSE;
    }
    if (!RTICdrStream_serializeString(
        stream, sample->payload, (255) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool stringTypePlugin_deserialize(
    struct RTICdrStream *stream, stringType *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeLong(
        stream, &sample->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->payload, (255) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int stringTypePlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (255) + 1);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void stringTypePlugin_print(
    const stringType *sample,
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
        &sample->id, "id", indent_level + 1);
            
    if (&sample->payload==NULL) {
        RTICdrType_printString(
            NULL, "payload", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->payload, "payload", indent_level + 1);                
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


stringType *stringTypePlugin_create_sample()
{
    return stringTypePlugin_create_sample_ex(RTI_TRUE);
}
        

stringType *stringTypePlugin_create_sample_ex(RTIBool allocatePointers)
{

    stringType *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, stringType);
                
    if (sample != NULL) {
        if (!stringType_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void stringTypePlugin_delete_sample(
    stringType *sample)
{
    stringTypePlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void stringTypePlugin_delete_sample_ex(
    stringType *sample,RTIBool deletePointers)
{
    stringType_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind stringTypePlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


stringTypeKeyHolder *stringTypePlugin_create_key()
{
    /* Note: If the definition of stringTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return stringTypePlugin_create_sample();
}


void stringTypePlugin_delete_key(
    stringTypeKeyHolder *key)
{
    /* Note: If the definition of stringTypeKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    stringTypePlugin_delete_sample(key);
}


RTIBool stringTypePlugin_instance_to_key(
    stringTypeKeyHolder *dst, const stringType *src)
{

    return RTI_TRUE;
}


RTIBool stringTypePlugin_key_to_instance(
    stringType *dst, const stringTypeKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool stringTypePlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const stringType *instance)
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


struct PRESTypePlugin *stringTypePlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        stringTypePlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        stringTypePlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        stringType_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        stringTypePlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        stringTypePlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        stringTypePlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        stringTypePlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        stringTypePlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        stringTypePlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        stringTypePlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        stringType_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        stringType_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        stringType_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        stringType_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        stringTypePlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        stringTypePlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        stringTypePlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        stringTypePlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        stringTypePlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)stringType_get_typecode();
    
    
    return plugin;
}


void stringTypePlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}

