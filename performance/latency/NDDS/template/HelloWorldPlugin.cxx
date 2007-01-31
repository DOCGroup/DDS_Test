
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from HelloWorld.idl using "nddsgen".
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



#ifndef HelloWorldPlugin_h
#include "HelloWorldPlugin.h"
#endif


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool HelloWorldPlugin_serialize(
    struct RTICdrStream *stream, const HelloWorld *sample,
    void *serialize_option)
{

    if (sample->msg == NULL) {
        return RTI_FALSE;
    }
    if (!RTICdrStream_serializeString(
        stream, sample->msg, (128) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool HelloWorldPlugin_deserialize(
    struct RTICdrStream *stream, HelloWorld *sample,
    void *deserialize_option)
{

    if (!RTICdrStream_deserializeString(
        stream, sample->msg, (128) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


unsigned int HelloWorldPlugin_get_max_size_serialized(
    unsigned int current_alignment)
{
        
    unsigned int initial_alignment = current_alignment;

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (128) + 1);
            
    return current_alignment - initial_alignment;
}


/* ------------------------------------------------------------------------
 * Utility Methods
 * ------------------------------------------------------------------------ */


void HelloWorldPlugin_print(
    const HelloWorld *sample,
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

    RTICdrType_printString(
        sample->msg, "msg", indent_level + 1);                
            
}

/* ------------------------------------------------------------------------
 * Lifecycle Methods
 * ------------------------------------------------------------------------ */


HelloWorld *HelloWorldPlugin_create_sample()
{

    HelloWorld *sample = NULL;

    RTIOsapiHeap_allocateStructure(&sample, HelloWorld);

    if (sample != NULL) {
        if (!HelloWorld_initialize(sample)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }

    return sample;
}


void HelloWorldPlugin_delete_sample(
    HelloWorld *sample)
{
    HelloWorld_finalize(sample);
    RTIOsapiHeap_freeStructure(sample);
}

/* ------------------------------------------------------------------------
 * Key Manipulation Methods
 * ------------------------------------------------------------------------ */


PRESTypePluginKeyKind HelloWorldPlugin_get_key_kind()
{

    return PRES_TYPEPLUGIN_NO_KEY;
    
}




HelloWorldKeyHolder *HelloWorldPlugin_create_key()
{
    /* Note: If the definition of HelloWorldKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    return HelloWorldPlugin_create_sample();
}


void HelloWorldPlugin_delete_key(
    HelloWorldKeyHolder *key)
{
    /* Note: If the definition of HelloWorldKeyHolder
     * changes, the implementation of this method will need to change
     * accordingly.
     */
    HelloWorldPlugin_delete_sample(key);
}


RTIBool HelloWorldPlugin_instance_to_key(
    HelloWorldKeyHolder *dst, const HelloWorld *src)
{

    return RTI_TRUE;
}


RTIBool HelloWorldPlugin_key_to_instance(
    HelloWorld *dst, const HelloWorldKeyHolder *src)
{

    return RTI_TRUE;
}


/* Fill in the fields of the given instance ID based on the key field(s)
 * of the given instance sample.
 *
 * Important: The fields of the instance ID cannot all be set to zero!
 */
RTIBool HelloWorldPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const HelloWorld *instance)
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


struct PRESTypePlugin *HelloWorldPlugin_new()
{
    struct PRESTypePlugin *plugin = NULL;
    
    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    plugin->data.serializeFnc =
        (RTICdrStreamSerializeFunction)
        HelloWorldPlugin_serialize;
    plugin->data.deserializeFnc =
        (RTICdrStreamDeserializeFunction)
        HelloWorldPlugin_deserialize;
    plugin->data.copyFnc =
        (PRESTypePluginDataCopyFunction)
        HelloWorld_copy;
    plugin->data.getKeyKindFnc =
        (PRESTypePluginDataGetKeyKindFunction)
        HelloWorldPlugin_get_key_kind;

    plugin->data.printFnc =
        (RTICdrTypePrintFunction)
        HelloWorldPlugin_print;
    plugin->data.getMaxSizeSerializedFnc =
        (RTICdrTypeGetMaxSizeSerializedFunction)
        HelloWorldPlugin_get_max_size_serialized;
    plugin->data.createSampleFnc =
        (PRESTypePluginDataCreateSampleFunction)
        HelloWorldPlugin_create_sample;
    plugin->data.destroySampleFnc =
        (PRESTypePluginDataDestroySampleFunction)
        HelloWorldPlugin_delete_sample;
    plugin->data.initializeFnc =
        (PRESTypePluginDataInitializeFunction)
        HelloWorld_initialize;
    plugin->data.finalizeFnc =
        (PRESTypePluginDataFinalizeFunction)
        HelloWorld_finalize;

    plugin->data.instanceToKeyFnc =
        (PRESTypePluginDataInstanceToKeyFunction)
        HelloWorldPlugin_instance_to_key;
    plugin->data.keyToInstanceFnc =
        (PRESTypePluginDataKeyToInstanceFunction)
        HelloWorldPlugin_key_to_instance;
    plugin->data.instanceToGuidFnc =
        (PRESTypePluginDataInstanceToGuidFunction)
        HelloWorldPlugin_instance_to_id;

    plugin->data.createKeyFnc =
        (PRESTypePluginDataCreateKeyFunction)
        HelloWorldPlugin_create_key;
    plugin->data.destroyKeyFnc =
        (PRESTypePluginDataDestroyKeyFunction)
        HelloWorldPlugin_delete_key;

    plugin->dataPoolFactory = PRES_TYPEPLUGIN_DEFAULT_DATA_POOL_FACTORY;
    
    
    plugin->typeCode = NULL;    
    
    
    return plugin;
}


void HelloWorldPlugin_delete(struct PRESTypePlugin *self)
{
    RTIOsapiHeap_freeStructure(self);
}

