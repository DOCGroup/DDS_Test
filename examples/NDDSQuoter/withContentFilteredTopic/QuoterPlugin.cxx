
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Quoter.idl using "nddsgen".
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



#ifndef QuoterPlugin_h
#include "QuoterPlugin.h"
#endif


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool QuoterPlugin_serialize(
    struct RTICdrStream *stream, const Quoter *sample,
    void *serialize_option)
{

    if (!RTICdrStream_serializeDouble(
        stream, &sample->price)) {
        return RTI_FALSE;
    }
            
    if (sample->symbol == NULL) {
        return RTI_FALSE;
    }
    if (!RTICdrStream_serializeString(
        stream, sample->symbol, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (sample->full_name == NULL) {
        return RTI_FALSE;
    }
    if (!RTICdrStream_serializeString(
        stream, sample->full_name, (255) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool QuoterPlugin_deserialize(
    struct RTICdrStream *stream, Quoter *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeDouble(
        stream, &sample->price)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->symbol, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->full_name, (255) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int QuoterPlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;
        

    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (255) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (255) + 1);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void QuoterPlugin_print(
    const Quoter *sample,
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
        

    RTICdrType_printDouble(
        &sample->price, "price", indent_level + 1);
            
    if (&sample->symbol==NULL) {
        RTICdrType_printString(
            NULL, "symbol", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->symbol, "symbol", indent_level + 1);                
    }
            
    if (&sample->full_name==NULL) {
        RTICdrType_printString(
            NULL, "full_name", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->full_name, "full_name", indent_level + 1);                
    }
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


Quoter *QuoterPlugin_create_sample()
{
    return QuoterPlugin_create_sample_ex(RTI_TRUE);
}
        

Quoter *QuoterPlugin_create_sample_ex(RTIBool allocatePointers)
{

    Quoter *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, Quoter);
                
    if (sample != NULL) {
        if (!Quoter_initialize_ex(sample,allocatePointers)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void QuoterPlugin_delete_sample(
    Quoter *sample)
{
    QuoterPlugin_delete_sample_ex(sample,RTI_TRUE);
}
        

void QuoterPlugin_delete_sample_ex(
    Quoter *sample,RTIBool deletePointers)
{
    Quoter_finalize_ex(sample,deletePointers);
    RTIOsapiHeap_freeStructure(sample);
}

 


/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind QuoterPlugin_get_key_kind()
{
        

    return PRES_TYPEPLUGIN_NO_KEY;
    
}


QuoterKeyHolder *QuoterPlugin_create_key()
{
    /* Note: If the definition of QuoterKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return QuoterPlugin_create_sample();
}


void QuoterPlugin_delete_key(
    QuoterKeyHolder *key)
{
    /* Note: If the definition of QuoterKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    QuoterPlugin_delete_sample(key);
}


RTIBool QuoterPlugin_instance_to_key(
    QuoterKeyHolder *dst, const Quoter *src)
{

    return RTI_TRUE;
}


RTIBool QuoterPlugin_key_to_instance(
    Quoter *dst, const QuoterKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool QuoterPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Quoter *instance)
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


struct PRESTypePlugin *QuoterPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        QuoterPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        QuoterPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        Quoter_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        QuoterPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        QuoterPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        QuoterPlugin_get_max_size_serialized;
    plugin->data.createSampleExFnc =
        (PRESTypePluginDataCreateSampleExFunction)
        QuoterPlugin_create_sample_ex;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        QuoterPlugin_create_sample;        
    plugin->data.destroySampleExFnc =
        (PRESTypePluginDataDestroySampleExFunction)
        QuoterPlugin_delete_sample_ex;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        QuoterPlugin_delete_sample;        
    plugin->data.initializeExFnc =
        (PRESTypePluginDataInitializeExFunction)
        Quoter_initialize_ex;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        Quoter_initialize;        
    plugin->data.finalizeExFnc =
        (PRESTypePluginDataFinalizeExFunction)
        Quoter_finalize_ex;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        Quoter_finalize;
        

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        QuoterPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        QuoterPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        QuoterPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        QuoterPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        QuoterPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;

    
    plugin->typeCode = (struct RTICdrTypeCode *)Quoter_get_typecode();
    
    
    return plugin;
}


void QuoterPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}

