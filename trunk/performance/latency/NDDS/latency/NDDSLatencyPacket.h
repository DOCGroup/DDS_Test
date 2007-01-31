
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef NDDSLatencyPacket_h
#define NDDSLatencyPacket_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif

                
#define MAX_MSG_LENGTH (16384)                
        
#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *PubMessageTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct PubMessage
{
    DDS_Long  seqnum;
     DDS_OctetSeq  data;

} PubMessage;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* PubMessage_get_typecode(); /* Type code */
    

DDS_SEQUENCE(PubMessageSeq, PubMessage);
        
NDDSUSERDllExport
RTIBool PubMessage_initialize(
        PubMessage* self);
        
NDDSUSERDllExport
RTIBool PubMessage_initialize_ex(
        PubMessage* self,RTIBool allocatePointers);

NDDSUSERDllExport
void PubMessage_finalize(
        PubMessage* self);
                        
NDDSUSERDllExport
void PubMessage_finalize_ex(
        PubMessage* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool PubMessage_copy(
        PubMessage* dst,
        const PubMessage* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *NestedTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Nested
{
    DDS_Long  n_seqnum;
    char*  n_data; /* maximum length = (20) */

} Nested;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Nested_get_typecode(); /* Type code */
    

DDS_SEQUENCE(NestedSeq, Nested);
        
NDDSUSERDllExport
RTIBool Nested_initialize(
        Nested* self);
        
NDDSUSERDllExport
RTIBool Nested_initialize_ex(
        Nested* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Nested_finalize(
        Nested* self);
                        
NDDSUSERDllExport
void Nested_finalize_ex(
        Nested* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Nested_copy(
        Nested* dst,
        const Nested* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *OuterTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Outer
{
    DDS_Long  o_seqnum;
     NestedSeq  o_data;

} Outer;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Outer_get_typecode(); /* Type code */
    

DDS_SEQUENCE(OuterSeq, Outer);
        
NDDSUSERDllExport
RTIBool Outer_initialize(
        Outer* self);
        
NDDSUSERDllExport
RTIBool Outer_initialize_ex(
        Outer* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Outer_finalize(
        Outer* self);
                        
NDDSUSERDllExport
void Outer_finalize_ex(
        Outer* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Outer_copy(
        Outer* dst,
        const Outer* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *PubMessage_NestTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct PubMessage_Nest
{
    DDS_Long  seqnum;
     OuterSeq  data;

} PubMessage_Nest;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* PubMessage_Nest_get_typecode(); /* Type code */
    

DDS_SEQUENCE(PubMessage_NestSeq, PubMessage_Nest);
        
NDDSUSERDllExport
RTIBool PubMessage_Nest_initialize(
        PubMessage_Nest* self);
        
NDDSUSERDllExport
RTIBool PubMessage_Nest_initialize_ex(
        PubMessage_Nest* self,RTIBool allocatePointers);

NDDSUSERDllExport
void PubMessage_Nest_finalize(
        PubMessage_Nest* self);
                        
NDDSUSERDllExport
void PubMessage_Nest_finalize_ex(
        PubMessage_Nest* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool PubMessage_Nest_copy(
        PubMessage_Nest* dst,
        const PubMessage_Nest* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *AckMessageTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct AckMessage
{
    DDS_Long  seqnum;

} AckMessage;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* AckMessage_get_typecode(); /* Type code */
    

DDS_SEQUENCE(AckMessageSeq, AckMessage);
        
NDDSUSERDllExport
RTIBool AckMessage_initialize(
        AckMessage* self);
        
NDDSUSERDllExport
RTIBool AckMessage_initialize_ex(
        AckMessage* self,RTIBool allocatePointers);

NDDSUSERDllExport
void AckMessage_finalize(
        AckMessage* self);
                        
NDDSUSERDllExport
void AckMessage_finalize_ex(
        AckMessage* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool AckMessage_copy(
        AckMessage* dst,
        const AckMessage* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* NDDSLatencyPacket_h */
