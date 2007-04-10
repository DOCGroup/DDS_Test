
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from deepTypes.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef deepTypes_h
#define deepTypes_h

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


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *simpleTypeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct simpleType
{
    DDS_Long  id;
    DDS_Long  payload;

} simpleType;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* simpleType_get_typecode(); /* Type code */
    

DDS_SEQUENCE(simpleTypeSeq, simpleType);
        
NDDSUSERDllExport
RTIBool simpleType_initialize(
        simpleType* self);
        
NDDSUSERDllExport
RTIBool simpleType_initialize_ex(
        simpleType* self,RTIBool allocatePointers);

NDDSUSERDllExport
void simpleType_finalize(
        simpleType* self);
                        
NDDSUSERDllExport
void simpleType_finalize_ex(
        simpleType* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool simpleType_copy(
        simpleType* dst,
        const simpleType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *innerStructTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct innerStruct
{
    DDS_Long  value;

} innerStruct;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* innerStruct_get_typecode(); /* Type code */
    

DDS_SEQUENCE(innerStructSeq, innerStruct);
        
NDDSUSERDllExport
RTIBool innerStruct_initialize(
        innerStruct* self);
        
NDDSUSERDllExport
RTIBool innerStruct_initialize_ex(
        innerStruct* self,RTIBool allocatePointers);

NDDSUSERDllExport
void innerStruct_finalize(
        innerStruct* self);
                        
NDDSUSERDllExport
void innerStruct_finalize_ex(
        innerStruct* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool innerStruct_copy(
        innerStruct* dst,
        const innerStruct* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *nestedTypeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct nestedType
{
    DDS_Long  id;
    innerStruct  payload;

} nestedType;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* nestedType_get_typecode(); /* Type code */
    

DDS_SEQUENCE(nestedTypeSeq, nestedType);
        
NDDSUSERDllExport
RTIBool nestedType_initialize(
        nestedType* self);
        
NDDSUSERDllExport
RTIBool nestedType_initialize_ex(
        nestedType* self,RTIBool allocatePointers);

NDDSUSERDllExport
void nestedType_finalize(
        nestedType* self);
                        
NDDSUSERDllExport
void nestedType_finalize_ex(
        nestedType* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool nestedType_copy(
        nestedType* dst,
        const nestedType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *arrayTypeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct arrayType
{
    DDS_Long  id;
    DDS_Long  payload[10];

} arrayType;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* arrayType_get_typecode(); /* Type code */
    

DDS_SEQUENCE(arrayTypeSeq, arrayType);
        
NDDSUSERDllExport
RTIBool arrayType_initialize(
        arrayType* self);
        
NDDSUSERDllExport
RTIBool arrayType_initialize_ex(
        arrayType* self,RTIBool allocatePointers);

NDDSUSERDllExport
void arrayType_finalize(
        arrayType* self);
                        
NDDSUSERDllExport
void arrayType_finalize_ex(
        arrayType* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool arrayType_copy(
        arrayType* dst,
        const arrayType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *stringTypeTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct stringType
{
    DDS_Long  id;
    char*  payload; /* maximum length = (255) */

} stringType;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* stringType_get_typecode(); /* Type code */
    

DDS_SEQUENCE(stringTypeSeq, stringType);
        
NDDSUSERDllExport
RTIBool stringType_initialize(
        stringType* self);
        
NDDSUSERDllExport
RTIBool stringType_initialize_ex(
        stringType* self,RTIBool allocatePointers);

NDDSUSERDllExport
void stringType_finalize(
        stringType* self);
                        
NDDSUSERDllExport
void stringType_finalize_ex(
        stringType* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool stringType_copy(
        stringType* dst,
        const stringType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* deepTypes_h */
