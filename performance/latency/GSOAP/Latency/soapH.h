/* soapH.h
   Generated by gSOAP 2.7.6c from Test.h
   Copyright (C) 2000-2005, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);
#ifndef WITH_NOIDREF
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 void * SOAP_FMAC4 soap_getelement(struct soap*, int*);
#endif

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (2)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

#ifndef SOAP_TYPE_long
#define SOAP_TYPE_long (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_long(struct soap*, long *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_long(struct soap*, const long *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_long(struct soap*, const char*, int, const long *, const char*);
SOAP_FMAC3 long * SOAP_FMAC4 soap_get_long(struct soap*, long *, const char*, const char*);
SOAP_FMAC3 long * SOAP_FMAC4 soap_in_long(struct soap*, const char*, long *, const char*);

#ifndef SOAP_TYPE_unsignedInt
#define SOAP_TYPE_unsignedInt (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_unsignedInt(struct soap*, unsigned int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_unsignedInt(struct soap*, const unsigned int *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_unsignedInt(struct soap*, const char*, int, const unsigned int *, const char*);
SOAP_FMAC3 unsigned int * SOAP_FMAC4 soap_get_unsignedInt(struct soap*, unsigned int *, const char*, const char*);
SOAP_FMAC3 unsigned int * SOAP_FMAC4 soap_in_unsignedInt(struct soap*, const char*, unsigned int *, const char*);

#ifndef SOAP_TYPE_unsignedLong
#define SOAP_TYPE_unsignedLong (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_unsignedLong(struct soap*, unsigned long *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_unsignedLong(struct soap*, const unsigned long *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_unsignedLong(struct soap*, const char*, int, const unsigned long *, const char*);
SOAP_FMAC3 unsigned long * SOAP_FMAC4 soap_get_unsignedLong(struct soap*, unsigned long *, const char*, const char*);
SOAP_FMAC3 unsigned long * SOAP_FMAC4 soap_in_unsignedLong(struct soap*, const char*, unsigned long *, const char*);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (35)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (34)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (33)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (31)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (30)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

#endif

#ifndef SOAP_TYPE_ns__latencyNestedArray
#define SOAP_TYPE_ns__latencyNestedArray (27)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__latencyNestedArray(struct soap*, const struct ns__latencyNestedArray *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__latencyNestedArray(struct soap*, struct ns__latencyNestedArray *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__latencyNestedArray(struct soap*, const struct ns__latencyNestedArray *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__latencyNestedArray(struct soap*, const char*, int, const struct ns__latencyNestedArray *, const char*);
SOAP_FMAC3 struct ns__latencyNestedArray * SOAP_FMAC4 soap_get_ns__latencyNestedArray(struct soap*, struct ns__latencyNestedArray *, const char*, const char*);
SOAP_FMAC3 struct ns__latencyNestedArray * SOAP_FMAC4 soap_in_ns__latencyNestedArray(struct soap*, const char*, struct ns__latencyNestedArray *, const char*);

#ifndef SOAP_TYPE_ns__latencyNestedArrayResponse
#define SOAP_TYPE_ns__latencyNestedArrayResponse (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__latencyNestedArrayResponse(struct soap*, const struct ns__latencyNestedArrayResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__latencyNestedArrayResponse(struct soap*, struct ns__latencyNestedArrayResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__latencyNestedArrayResponse(struct soap*, const struct ns__latencyNestedArrayResponse *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__latencyNestedArrayResponse(struct soap*, const char*, int, const struct ns__latencyNestedArrayResponse *, const char*);
SOAP_FMAC3 struct ns__latencyNestedArrayResponse * SOAP_FMAC4 soap_get_ns__latencyNestedArrayResponse(struct soap*, struct ns__latencyNestedArrayResponse *, const char*, const char*);
SOAP_FMAC3 struct ns__latencyNestedArrayResponse * SOAP_FMAC4 soap_in_ns__latencyNestedArrayResponse(struct soap*, const char*, struct ns__latencyNestedArrayResponse *, const char*);

#ifndef SOAP_TYPE_ns__latencyByteArray
#define SOAP_TYPE_ns__latencyByteArray (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__latencyByteArray(struct soap*, const struct ns__latencyByteArray *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__latencyByteArray(struct soap*, struct ns__latencyByteArray *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__latencyByteArray(struct soap*, const struct ns__latencyByteArray *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__latencyByteArray(struct soap*, const char*, int, const struct ns__latencyByteArray *, const char*);
SOAP_FMAC3 struct ns__latencyByteArray * SOAP_FMAC4 soap_get_ns__latencyByteArray(struct soap*, struct ns__latencyByteArray *, const char*, const char*);
SOAP_FMAC3 struct ns__latencyByteArray * SOAP_FMAC4 soap_in_ns__latencyByteArray(struct soap*, const char*, struct ns__latencyByteArray *, const char*);

#ifndef SOAP_TYPE_ns__latencyByteArrayResponse
#define SOAP_TYPE_ns__latencyByteArrayResponse (23)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__latencyByteArrayResponse(struct soap*, const struct ns__latencyByteArrayResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__latencyByteArrayResponse(struct soap*, struct ns__latencyByteArrayResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__latencyByteArrayResponse(struct soap*, const struct ns__latencyByteArrayResponse *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__latencyByteArrayResponse(struct soap*, const char*, int, const struct ns__latencyByteArrayResponse *, const char*);
SOAP_FMAC3 struct ns__latencyByteArrayResponse * SOAP_FMAC4 soap_get_ns__latencyByteArrayResponse(struct soap*, struct ns__latencyByteArrayResponse *, const char*, const char*);
SOAP_FMAC3 struct ns__latencyByteArrayResponse * SOAP_FMAC4 soap_in_ns__latencyByteArrayResponse(struct soap*, const char*, struct ns__latencyByteArrayResponse *, const char*);

#ifndef SOAP_TYPE_ComplexType
#define SOAP_TYPE_ComplexType (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ComplexType(struct soap*, struct gSOAP_outer_array const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ComplexType(struct soap*, struct gSOAP_outer_array *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ComplexType(struct soap*, const struct gSOAP_outer_array *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ComplexType(struct soap*, const char*, int, const struct gSOAP_outer_array *, const char*);
SOAP_FMAC3 struct gSOAP_outer_array * SOAP_FMAC4 soap_get_ComplexType(struct soap*, struct gSOAP_outer_array *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_outer_array * SOAP_FMAC4 soap_in_ComplexType(struct soap*, const char*, struct gSOAP_outer_array *, const char*);

#ifndef SOAP_TYPE_gSOAP_outer_array
#define SOAP_TYPE_gSOAP_outer_array (15)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_gSOAP_outer_array(struct soap*, struct gSOAP_outer_array const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_gSOAP_outer_array(struct soap*, struct gSOAP_outer_array *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_gSOAP_outer_array(struct soap*, const struct gSOAP_outer_array *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_gSOAP_outer_array(struct soap*, const char*, int, const struct gSOAP_outer_array *, const char*);
SOAP_FMAC3 struct gSOAP_outer_array * SOAP_FMAC4 soap_get_gSOAP_outer_array(struct soap*, struct gSOAP_outer_array *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_outer_array * SOAP_FMAC4 soap_in_gSOAP_outer_array(struct soap*, const char*, struct gSOAP_outer_array *, const char*);

#ifndef SOAP_TYPE_Outer
#define SOAP_TYPE_Outer (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_Outer(struct soap*, struct gSOAP_outer const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_Outer(struct soap*, struct gSOAP_outer *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_Outer(struct soap*, const struct gSOAP_outer *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_Outer(struct soap*, const char*, int, const struct gSOAP_outer *, const char*);
SOAP_FMAC3 struct gSOAP_outer * SOAP_FMAC4 soap_get_Outer(struct soap*, struct gSOAP_outer *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_outer * SOAP_FMAC4 soap_in_Outer(struct soap*, const char*, struct gSOAP_outer *, const char*);

#ifndef SOAP_TYPE_gSOAP_outer
#define SOAP_TYPE_gSOAP_outer (13)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_gSOAP_outer(struct soap*, const struct gSOAP_outer *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_gSOAP_outer(struct soap*, struct gSOAP_outer *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_gSOAP_outer(struct soap*, const struct gSOAP_outer *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_gSOAP_outer(struct soap*, const char*, int, const struct gSOAP_outer *, const char*);
SOAP_FMAC3 struct gSOAP_outer * SOAP_FMAC4 soap_get_gSOAP_outer(struct soap*, struct gSOAP_outer *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_outer * SOAP_FMAC4 soap_in_gSOAP_outer(struct soap*, const char*, struct gSOAP_outer *, const char*);

#ifndef SOAP_TYPE_InnerArray
#define SOAP_TYPE_InnerArray (12)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_InnerArray(struct soap*, struct gSOAP_inner_array const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_InnerArray(struct soap*, struct gSOAP_inner_array *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_InnerArray(struct soap*, const struct gSOAP_inner_array *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_InnerArray(struct soap*, const char*, int, const struct gSOAP_inner_array *, const char*);
SOAP_FMAC3 struct gSOAP_inner_array * SOAP_FMAC4 soap_get_InnerArray(struct soap*, struct gSOAP_inner_array *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_inner_array * SOAP_FMAC4 soap_in_InnerArray(struct soap*, const char*, struct gSOAP_inner_array *, const char*);

#ifndef SOAP_TYPE_gSOAP_inner_array
#define SOAP_TYPE_gSOAP_inner_array (10)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_gSOAP_inner_array(struct soap*, struct gSOAP_inner_array const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_gSOAP_inner_array(struct soap*, struct gSOAP_inner_array *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_gSOAP_inner_array(struct soap*, const struct gSOAP_inner_array *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_gSOAP_inner_array(struct soap*, const char*, int, const struct gSOAP_inner_array *, const char*);
SOAP_FMAC3 struct gSOAP_inner_array * SOAP_FMAC4 soap_get_gSOAP_inner_array(struct soap*, struct gSOAP_inner_array *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_inner_array * SOAP_FMAC4 soap_in_gSOAP_inner_array(struct soap*, const char*, struct gSOAP_inner_array *, const char*);

#ifndef SOAP_TYPE_Inner
#define SOAP_TYPE_Inner (9)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_Inner(struct soap*, struct gSOAP_inner const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_Inner(struct soap*, struct gSOAP_inner *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_Inner(struct soap*, const struct gSOAP_inner *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_Inner(struct soap*, const char*, int, const struct gSOAP_inner *, const char*);
SOAP_FMAC3 struct gSOAP_inner * SOAP_FMAC4 soap_get_Inner(struct soap*, struct gSOAP_inner *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_inner * SOAP_FMAC4 soap_in_Inner(struct soap*, const char*, struct gSOAP_inner *, const char*);

#ifndef SOAP_TYPE_gSOAP_inner
#define SOAP_TYPE_gSOAP_inner (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_gSOAP_inner(struct soap*, const struct gSOAP_inner *);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_gSOAP_inner(struct soap*, struct gSOAP_inner *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_gSOAP_inner(struct soap*, const struct gSOAP_inner *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_gSOAP_inner(struct soap*, const char*, int, const struct gSOAP_inner *, const char*);
SOAP_FMAC3 struct gSOAP_inner * SOAP_FMAC4 soap_get_gSOAP_inner(struct soap*, struct gSOAP_inner *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_inner * SOAP_FMAC4 soap_in_gSOAP_inner(struct soap*, const char*, struct gSOAP_inner *, const char*);

#ifndef SOAP_TYPE_ByteArray
#define SOAP_TYPE_ByteArray (7)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ByteArray(struct soap*, struct gSOAP_byte_array const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ByteArray(struct soap*, struct gSOAP_byte_array *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ByteArray(struct soap*, const struct gSOAP_byte_array *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ByteArray(struct soap*, const char*, int, const struct gSOAP_byte_array *, const char*);
SOAP_FMAC3 struct gSOAP_byte_array * SOAP_FMAC4 soap_get_ByteArray(struct soap*, struct gSOAP_byte_array *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_byte_array * SOAP_FMAC4 soap_in_ByteArray(struct soap*, const char*, struct gSOAP_byte_array *, const char*);

#ifndef SOAP_TYPE_gSOAP_byte_array
#define SOAP_TYPE_gSOAP_byte_array (6)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_gSOAP_byte_array(struct soap*, struct gSOAP_byte_array const*);
SOAP_FMAC3 void SOAP_FMAC4 soap_default_gSOAP_byte_array(struct soap*, struct gSOAP_byte_array *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_gSOAP_byte_array(struct soap*, const struct gSOAP_byte_array *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_gSOAP_byte_array(struct soap*, const char*, int, const struct gSOAP_byte_array *, const char*);
SOAP_FMAC3 struct gSOAP_byte_array * SOAP_FMAC4 soap_get_gSOAP_byte_array(struct soap*, struct gSOAP_byte_array *, const char*, const char*);
SOAP_FMAC3 struct gSOAP_byte_array * SOAP_FMAC4 soap_in_gSOAP_byte_array(struct soap*, const char*, struct gSOAP_byte_array *, const char*);

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (37)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (36)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (32)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);

#endif

#ifndef SOAP_TYPE_PointerToOuter
#define SOAP_TYPE_PointerToOuter (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToOuter(struct soap*, struct gSOAP_outer *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToOuter(struct soap*, struct gSOAP_outer *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToOuter(struct soap*, const char *, int, struct gSOAP_outer *const*, const char *);
SOAP_FMAC3 struct gSOAP_outer ** SOAP_FMAC4 soap_get_PointerToOuter(struct soap*, struct gSOAP_outer **, const char*, const char*);
SOAP_FMAC3 struct gSOAP_outer ** SOAP_FMAC4 soap_in_PointerToOuter(struct soap*, const char*, struct gSOAP_outer **, const char*);

#ifndef SOAP_TYPE_PointerToInner
#define SOAP_TYPE_PointerToInner (11)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToInner(struct soap*, struct gSOAP_inner *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToInner(struct soap*, struct gSOAP_inner *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToInner(struct soap*, const char *, int, struct gSOAP_inner *const*, const char *);
SOAP_FMAC3 struct gSOAP_inner ** SOAP_FMAC4 soap_get_PointerToInner(struct soap*, struct gSOAP_inner **, const char*, const char*);
SOAP_FMAC3 struct gSOAP_inner ** SOAP_FMAC4 soap_in_PointerToInner(struct soap*, const char*, struct gSOAP_inner **, const char*);

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default__QName(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);

#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);

#endif

/* End of soapH.h */
