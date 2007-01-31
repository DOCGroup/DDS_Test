#ifndef TEST_H
#define TEST_H

struct gSOAP_byte_array
{
  char* __ptr;
  int __size;
};

typedef struct gSOAP_byte_array ByteArray;

struct gSOAP_inner
{
  char* info;
  int index;
};

typedef struct gSOAP_inner Inner;

struct gSOAP_inner_array
{
  Inner* __ptr;
  int __size;
};

typedef struct gSOAP_inner_array InnerArray;

struct gSOAP_outer
{
  int length;
  InnerArray inner_array;
};

typedef struct gSOAP_outer Outer;

struct gSOAP_outer_array
{
  Outer* __ptr;
  int __size;
};

typedef struct gSOAP_outer_array ComplexType;

//gsoap ns service name: latency
//gsoap ns service style: document
//gsoap ns service encoding: literal
//gsoap ns service port: http://localhost:8080
//gsoap ns service namespace: urn:latency

int ns__latencyByteArray (ByteArray in, unsigned long& seq_num);

int ns__latencyNestedArray (ComplexType in, unsigned long& seq_num);

#endif /* TEST_H */
