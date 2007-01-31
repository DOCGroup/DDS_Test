/* soapStub.h
   Generated by gSOAP 2.7.6c from Test.h
   Copyright (C) 2000-2005, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/
#ifndef soapStub_H
#define soapStub_H
#ifndef TEST_H
#define TEST_H
#endif /* TEST_H */
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_gSOAP_byte_array
#define SOAP_TYPE_gSOAP_byte_array (6)
/* SOAP encoded array of xsd:byte schema type: */
struct gSOAP_byte_array
{
	char *__ptr;
	int __size;
};
#endif

#ifndef SOAP_TYPE_gSOAP_inner
#define SOAP_TYPE_gSOAP_inner (8)
/* gSOAP-inner */
struct gSOAP_inner
{
	char *info;	/* optional element of type xsd:string */
	int index;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_gSOAP_inner_array
#define SOAP_TYPE_gSOAP_inner_array (10)
/* SOAP encoded array of Inner schema type: */
struct gSOAP_inner_array
{
	struct gSOAP_inner *__ptr;
	int __size;
};
#endif

#ifndef SOAP_TYPE_gSOAP_outer
#define SOAP_TYPE_gSOAP_outer (13)
/* gSOAP-outer */
struct gSOAP_outer
{
	int length;	/* required element of type xsd:int */
	struct gSOAP_inner_array inner_array;	/* required element of type InnerArray */
};
#endif

#ifndef SOAP_TYPE_gSOAP_outer_array
#define SOAP_TYPE_gSOAP_outer_array (15)
/* SOAP encoded array of Outer schema type: */
struct gSOAP_outer_array
{
	struct gSOAP_outer *__ptr;
	int __size;
};
#endif

#ifndef SOAP_TYPE_ns__conversionByteArrayResponse
#define SOAP_TYPE_ns__conversionByteArrayResponse (23)
/* ns:conversionByteArrayResponse */
struct ns__conversionByteArrayResponse
{
	unsigned long seq_num;	/* RPC return element */	/* required element of type xsd:unsignedLong */
};
#endif

#ifndef SOAP_TYPE_ns__conversionByteArray
#define SOAP_TYPE_ns__conversionByteArray (24)
/* ns:conversionByteArray */
struct ns__conversionByteArray
{
	struct gSOAP_byte_array in;	/* required element of type ByteArray */
};
#endif

#ifndef SOAP_TYPE_ns__conversionNestedArrayResponse
#define SOAP_TYPE_ns__conversionNestedArrayResponse (26)
/* ns:conversionNestedArrayResponse */
struct ns__conversionNestedArrayResponse
{
	unsigned long seq_num;	/* RPC return element */	/* required element of type xsd:unsignedLong */
};
#endif

#ifndef SOAP_TYPE_ns__conversionNestedArray
#define SOAP_TYPE_ns__conversionNestedArray (27)
/* ns:conversionNestedArray */
struct ns__conversionNestedArray
{
	struct gSOAP_outer_array in;	/* required element of type ComplexType */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (30)
/* SOAP Header: */
struct SOAP_ENV__Header
{
	void *dummy;	/* transient */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (31)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;	/* optional element of type QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (33)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (34)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (35)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;	/* optional element of type QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (4)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE_ByteArray
#define SOAP_TYPE_ByteArray (7)
typedef struct gSOAP_byte_array ByteArray;
#endif

#ifndef SOAP_TYPE_Inner
#define SOAP_TYPE_Inner (9)
typedef struct gSOAP_inner Inner;
#endif

#ifndef SOAP_TYPE_InnerArray
#define SOAP_TYPE_InnerArray (12)
typedef struct gSOAP_inner_array InnerArray;
#endif

#ifndef SOAP_TYPE_Outer
#define SOAP_TYPE_Outer (14)
typedef struct gSOAP_outer Outer;
#endif

#ifndef SOAP_TYPE_ComplexType
#define SOAP_TYPE_ComplexType (17)
typedef struct gSOAP_outer_array ComplexType;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operations                                                         *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 ns__conversionByteArray(struct soap*, struct gSOAP_byte_array in, unsigned long &seq_num);

SOAP_FMAC5 int SOAP_FMAC6 ns__conversionNestedArray(struct soap*, struct gSOAP_outer_array in, unsigned long &seq_num);

/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__conversionByteArray(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct gSOAP_byte_array in, unsigned long &seq_num);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__conversionNestedArray(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct gSOAP_outer_array in, unsigned long &seq_num);

/******************************************************************************\
 *                                                                            *
 * Skeletons                                                                  *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__conversionByteArray(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__conversionNestedArray(struct soap*);

#endif

/* End of soapStub.h */
