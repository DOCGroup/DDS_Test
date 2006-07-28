
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Quoter.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef Quoter_h
#define Quoter_h

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

        
extern const char *QuoterTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct Quoter
{
    DDS_Double  price;
    char*  symbol; /* maximum length = (255) */
    char*  full_name; /* maximum length = (255) */

} Quoter;
    
                            
#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Quoter_get_typecode(); /* Type code */
    

DDS_SEQUENCE(QuoterSeq, Quoter);
        
NDDSUSERDllExport
RTIBool Quoter_initialize(
        Quoter* self);
        
NDDSUSERDllExport
RTIBool Quoter_initialize_ex(
        Quoter* self,RTIBool allocatePointers);

NDDSUSERDllExport
void Quoter_finalize(
        Quoter* self);
                        
NDDSUSERDllExport
void Quoter_finalize_ex(
        Quoter* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool Quoter_copy(
        Quoter* dst,
        const Quoter* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* Quoter_h */
