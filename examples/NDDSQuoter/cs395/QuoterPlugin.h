
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Quoter.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef QuoterPlugin_h
#define QuoterPlugin_h

#ifndef Quoter_h
#include "Quoter.h"
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
 * Quoter.
 *
 * By default, this type is struct Quoter
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct Quoter)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct Quoter, the
 * following restriction applies: the key of struct
 * Quoter must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct Quoter.
 */
typedef Quoter QuoterKeyHolder;


extern RTIBool QuoterPlugin_serialize(
    struct RTICdrStream *stream, const Quoter *sample,
    void *serialize_option);

extern RTIBool QuoterPlugin_deserialize(
    struct RTICdrStream *stream, Quoter *sample,
    void *deserialize_option);

extern unsigned int QuoterPlugin_get_max_size_serialized(
    unsigned int current_alignment);

extern void QuoterPlugin_print(
    const Quoter *sample,
    const char *description, int indent_level);

extern Quoter *QuoterPlugin_create_sample();

extern Quoter *QuoterPlugin_create_sample_ex(RTIBool allocatePointers);        

extern void QuoterPlugin_delete_sample(
    Quoter *sample);        

extern void QuoterPlugin_delete_sample_ex(
    Quoter *sample,RTIBool deletePointers);

extern PRESTypePluginKeyKind QuoterPlugin_get_key_kind();

extern struct PRESTypePlugin *QuoterPlugin_new();

extern void QuoterPlugin_delete(struct PRESTypePlugin *plugin);

/* The following are used if your key kind is USER_KEY */

extern QuoterKeyHolder *QuoterPlugin_create_key();

extern void QuoterPlugin_delete_key(
    QuoterKeyHolder *key);

extern RTIBool QuoterPlugin_instance_to_key(
    QuoterKeyHolder *key, const Quoter *instance);

extern RTIBool QuoterPlugin_key_to_instance(
    Quoter *instance, const QuoterKeyHolder *key);

extern RTIBool QuoterPlugin_instance_to_id(
    DDS_InstanceId_t *id, RTIBool *is_unique,
    const Quoter *instance);



#ifdef __cplusplus
}
#endif
        

#endif /* QuoterPlugin_h */
