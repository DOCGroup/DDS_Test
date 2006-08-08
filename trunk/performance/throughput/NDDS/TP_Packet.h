
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from TP_Packet.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef TP_Packet_h
#define TP_Packet_h

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
                        
#define LATENCY_MSG_LENGTH (16384)                
        
#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *NDDSLatencyPacketTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct NDDSLatencyPacket
{
    DDS_Long  sequenceNumber;
     DDS_OctetSeq  data;

} NDDSLatencyPacket;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* NDDSLatencyPacket_get_typecode(); /* Type code */
    

DDS_SEQUENCE(NDDSLatencyPacketSeq, NDDSLatencyPacket);
        
NDDSUSERDllExport
RTIBool NDDSLatencyPacket_initialize(
        NDDSLatencyPacket* self);
        
NDDSUSERDllExport
RTIBool NDDSLatencyPacket_initialize_ex(
        NDDSLatencyPacket* self,RTIBool allocatePointers);

NDDSUSERDllExport
void NDDSLatencyPacket_finalize(
        NDDSLatencyPacket* self);
                        
NDDSUSERDllExport
void NDDSLatencyPacket_finalize_ex(
        NDDSLatencyPacket* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool NDDSLatencyPacket_copy(
        NDDSLatencyPacket* dst,
        const NDDSLatencyPacket* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

                
#define BYTES4_MSG_LENGTH (4)                
                        
#define BYTES8_MSG_LENGTH (8)                
                        
#define BYTES16_MSG_LENGTH (16)                
                        
#define BYTES32_MSG_LENGTH (32)                
                        
#define BYTES64_MSG_LENGTH (64)                
                        
#define BYTES128_MSG_LENGTH (128)                
                        
#define BYTES256_MSG_LENGTH (256)                
                        
#define BYTES512_MSG_LENGTH (512)                
                        
#define BYTES1024_MSG_LENGTH (1024)                
                        
#define BYTES2048_MSG_LENGTH (2048)                
                        
#define BYTES4096_MSG_LENGTH (4096)                
                        
#define BYTES8192_MSG_LENGTH (8192)                
                        
#define BYTES16384_MSG_LENGTH (16384)                
        
#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes4TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes4
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes4;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes4_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes4Seq, Bytes4);
        
NDDSUSERDllExport
RTIBool Bytes4_initialize(
        Bytes4* self);
        
NDDSUSERDllExport
RTIBool Bytes4_initialize_ex(
        Bytes4* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes4_finalize(
        Bytes4* self);
                        
NDDSUSERDllExport
void Bytes4_finalize_ex(
        Bytes4* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes4_copy(
        Bytes4* dst,
        const Bytes4* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes8TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes8
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes8;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes8_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes8Seq, Bytes8);
        
NDDSUSERDllExport
RTIBool Bytes8_initialize(
        Bytes8* self);
        
NDDSUSERDllExport
RTIBool Bytes8_initialize_ex(
        Bytes8* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes8_finalize(
        Bytes8* self);
                        
NDDSUSERDllExport
void Bytes8_finalize_ex(
        Bytes8* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes8_copy(
        Bytes8* dst,
        const Bytes8* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes16TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes16
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes16;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes16_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes16Seq, Bytes16);
        
NDDSUSERDllExport
RTIBool Bytes16_initialize(
        Bytes16* self);
        
NDDSUSERDllExport
RTIBool Bytes16_initialize_ex(
        Bytes16* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes16_finalize(
        Bytes16* self);
                        
NDDSUSERDllExport
void Bytes16_finalize_ex(
        Bytes16* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes16_copy(
        Bytes16* dst,
        const Bytes16* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes32TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes32
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes32;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes32_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes32Seq, Bytes32);
        
NDDSUSERDllExport
RTIBool Bytes32_initialize(
        Bytes32* self);
        
NDDSUSERDllExport
RTIBool Bytes32_initialize_ex(
        Bytes32* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes32_finalize(
        Bytes32* self);
                        
NDDSUSERDllExport
void Bytes32_finalize_ex(
        Bytes32* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes32_copy(
        Bytes32* dst,
        const Bytes32* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes64TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes64
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes64;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes64_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes64Seq, Bytes64);
        
NDDSUSERDllExport
RTIBool Bytes64_initialize(
        Bytes64* self);
        
NDDSUSERDllExport
RTIBool Bytes64_initialize_ex(
        Bytes64* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes64_finalize(
        Bytes64* self);
                        
NDDSUSERDllExport
void Bytes64_finalize_ex(
        Bytes64* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes64_copy(
        Bytes64* dst,
        const Bytes64* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes128TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes128
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes128;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes128_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes128Seq, Bytes128);
        
NDDSUSERDllExport
RTIBool Bytes128_initialize(
        Bytes128* self);
        
NDDSUSERDllExport
RTIBool Bytes128_initialize_ex(
        Bytes128* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes128_finalize(
        Bytes128* self);
                        
NDDSUSERDllExport
void Bytes128_finalize_ex(
        Bytes128* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes128_copy(
        Bytes128* dst,
        const Bytes128* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes256TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes256
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes256;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes256_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes256Seq, Bytes256);
        
NDDSUSERDllExport
RTIBool Bytes256_initialize(
        Bytes256* self);
        
NDDSUSERDllExport
RTIBool Bytes256_initialize_ex(
        Bytes256* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes256_finalize(
        Bytes256* self);
                        
NDDSUSERDllExport
void Bytes256_finalize_ex(
        Bytes256* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes256_copy(
        Bytes256* dst,
        const Bytes256* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes512TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes512
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes512;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes512_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes512Seq, Bytes512);
        
NDDSUSERDllExport
RTIBool Bytes512_initialize(
        Bytes512* self);
        
NDDSUSERDllExport
RTIBool Bytes512_initialize_ex(
        Bytes512* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes512_finalize(
        Bytes512* self);
                        
NDDSUSERDllExport
void Bytes512_finalize_ex(
        Bytes512* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes512_copy(
        Bytes512* dst,
        const Bytes512* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes1024TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes1024
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes1024;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes1024_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes1024Seq, Bytes1024);
        
NDDSUSERDllExport
RTIBool Bytes1024_initialize(
        Bytes1024* self);
        
NDDSUSERDllExport
RTIBool Bytes1024_initialize_ex(
        Bytes1024* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes1024_finalize(
        Bytes1024* self);
                        
NDDSUSERDllExport
void Bytes1024_finalize_ex(
        Bytes1024* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes1024_copy(
        Bytes1024* dst,
        const Bytes1024* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes2048TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes2048
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes2048;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes2048_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes2048Seq, Bytes2048);
        
NDDSUSERDllExport
RTIBool Bytes2048_initialize(
        Bytes2048* self);
        
NDDSUSERDllExport
RTIBool Bytes2048_initialize_ex(
        Bytes2048* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes2048_finalize(
        Bytes2048* self);
                        
NDDSUSERDllExport
void Bytes2048_finalize_ex(
        Bytes2048* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes2048_copy(
        Bytes2048* dst,
        const Bytes2048* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes4096TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes4096
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes4096;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes4096_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes4096Seq, Bytes4096);
        
NDDSUSERDllExport
RTIBool Bytes4096_initialize(
        Bytes4096* self);
        
NDDSUSERDllExport
RTIBool Bytes4096_initialize_ex(
        Bytes4096* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes4096_finalize(
        Bytes4096* self);
                        
NDDSUSERDllExport
void Bytes4096_finalize_ex(
        Bytes4096* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes4096_copy(
        Bytes4096* dst,
        const Bytes4096* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes8192TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes8192
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes8192;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes8192_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes8192Seq, Bytes8192);
        
NDDSUSERDllExport
RTIBool Bytes8192_initialize(
        Bytes8192* self);
        
NDDSUSERDllExport
RTIBool Bytes8192_initialize_ex(
        Bytes8192* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes8192_finalize(
        Bytes8192* self);
                        
NDDSUSERDllExport
void Bytes8192_finalize_ex(
        Bytes8192* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes8192_copy(
        Bytes8192* dst,
        const Bytes8192* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *Bytes16384TYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Bytes16384
{
    DDS_UnsignedLong  timestamp;
     DDS_OctetSeq  data;

} Bytes16384;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Bytes16384_get_typecode(); /* Type code */
    

DDS_SEQUENCE(Bytes16384Seq, Bytes16384);
        
NDDSUSERDllExport
RTIBool Bytes16384_initialize(
        Bytes16384* self);
        
NDDSUSERDllExport
RTIBool Bytes16384_initialize_ex(
        Bytes16384* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Bytes16384_finalize(
        Bytes16384* self);
                        
NDDSUSERDllExport
void Bytes16384_finalize_ex(
        Bytes16384* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Bytes16384_copy(
        Bytes16384* dst,
        const Bytes16384* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* TP_Packet_h */
