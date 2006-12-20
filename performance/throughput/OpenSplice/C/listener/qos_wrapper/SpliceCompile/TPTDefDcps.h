#ifndef TPTDEFDCPS_H
#define TPTDEFDCPS_H

#include <dds_dcps.h>

#ifndef _TP_Test_QuitMsg_defined
#define _TP_Test_QuitMsg_defined
#ifdef __cplusplus
struct TP_Test_QuitMsg;
#else /* __cplusplus */
typedef struct TP_Test_QuitMsg TP_Test_QuitMsg;
#endif /* __cplusplus */
#endif /* _TP_Test_QuitMsg_defined */
TP_Test_QuitMsg *TP_Test_QuitMsg__alloc (void);

struct TP_Test_QuitMsg {
    DDS_boolean quit;
};

/* Definition for sequence of DDS_octet */
#ifndef _DDS_sequence_octet_defined
#define _DDS_sequence_octet_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    DDS_octet *_buffer;
    DDS_boolean _release;
} DDS_sequence_octet;
DDS_sequence_octet *DDS_sequence_octet__alloc (void);
DDS_octet *DDS_sequence_octet_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_octet_defined */

typedef DDS_sequence_octet TP_Test_Bytes4Seq;
TP_Test_Bytes4Seq *TP_Test_Bytes4Seq__alloc (void);
DDS_octet *TP_Test_Bytes4Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes8Seq;
TP_Test_Bytes8Seq *TP_Test_Bytes8Seq__alloc (void);
DDS_octet *TP_Test_Bytes8Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes16Seq;
TP_Test_Bytes16Seq *TP_Test_Bytes16Seq__alloc (void);
DDS_octet *TP_Test_Bytes16Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes32Seq;
TP_Test_Bytes32Seq *TP_Test_Bytes32Seq__alloc (void);
DDS_octet *TP_Test_Bytes32Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes64Seq;
TP_Test_Bytes64Seq *TP_Test_Bytes64Seq__alloc (void);
DDS_octet *TP_Test_Bytes64Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes128Seq;
TP_Test_Bytes128Seq *TP_Test_Bytes128Seq__alloc (void);
DDS_octet *TP_Test_Bytes128Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes256Seq;
TP_Test_Bytes256Seq *TP_Test_Bytes256Seq__alloc (void);
DDS_octet *TP_Test_Bytes256Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes512Seq;
TP_Test_Bytes512Seq *TP_Test_Bytes512Seq__alloc (void);
DDS_octet *TP_Test_Bytes512Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes1024Seq;
TP_Test_Bytes1024Seq *TP_Test_Bytes1024Seq__alloc (void);
DDS_octet *TP_Test_Bytes1024Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes2048Seq;
TP_Test_Bytes2048Seq *TP_Test_Bytes2048Seq__alloc (void);
DDS_octet *TP_Test_Bytes2048Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes4096Seq;
TP_Test_Bytes4096Seq *TP_Test_Bytes4096Seq__alloc (void);
DDS_octet *TP_Test_Bytes4096Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes8192Seq;
TP_Test_Bytes8192Seq *TP_Test_Bytes8192Seq__alloc (void);
DDS_octet *TP_Test_Bytes8192Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_octet TP_Test_Bytes16384Seq;
TP_Test_Bytes16384Seq *TP_Test_Bytes16384Seq__alloc (void);
DDS_octet *TP_Test_Bytes16384Seq_allocbuf (DDS_unsigned_long len);

#ifndef _TP_Test_Bytes4_defined
#define _TP_Test_Bytes4_defined
#ifdef __cplusplus
struct TP_Test_Bytes4;
#else /* __cplusplus */
typedef struct TP_Test_Bytes4 TP_Test_Bytes4;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes4_defined */
TP_Test_Bytes4 *TP_Test_Bytes4__alloc (void);

struct TP_Test_Bytes4 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes4Seq data;
};

#ifndef _TP_Test_Bytes8_defined
#define _TP_Test_Bytes8_defined
#ifdef __cplusplus
struct TP_Test_Bytes8;
#else /* __cplusplus */
typedef struct TP_Test_Bytes8 TP_Test_Bytes8;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes8_defined */
TP_Test_Bytes8 *TP_Test_Bytes8__alloc (void);

struct TP_Test_Bytes8 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes8Seq data;
};

#ifndef _TP_Test_Bytes16_defined
#define _TP_Test_Bytes16_defined
#ifdef __cplusplus
struct TP_Test_Bytes16;
#else /* __cplusplus */
typedef struct TP_Test_Bytes16 TP_Test_Bytes16;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes16_defined */
TP_Test_Bytes16 *TP_Test_Bytes16__alloc (void);

struct TP_Test_Bytes16 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes16Seq data;
};

#ifndef _TP_Test_Bytes32_defined
#define _TP_Test_Bytes32_defined
#ifdef __cplusplus
struct TP_Test_Bytes32;
#else /* __cplusplus */
typedef struct TP_Test_Bytes32 TP_Test_Bytes32;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes32_defined */
TP_Test_Bytes32 *TP_Test_Bytes32__alloc (void);

struct TP_Test_Bytes32 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes32Seq data;
};

#ifndef _TP_Test_Bytes64_defined
#define _TP_Test_Bytes64_defined
#ifdef __cplusplus
struct TP_Test_Bytes64;
#else /* __cplusplus */
typedef struct TP_Test_Bytes64 TP_Test_Bytes64;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes64_defined */
TP_Test_Bytes64 *TP_Test_Bytes64__alloc (void);

struct TP_Test_Bytes64 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes64Seq data;
};

#ifndef _TP_Test_Bytes128_defined
#define _TP_Test_Bytes128_defined
#ifdef __cplusplus
struct TP_Test_Bytes128;
#else /* __cplusplus */
typedef struct TP_Test_Bytes128 TP_Test_Bytes128;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes128_defined */
TP_Test_Bytes128 *TP_Test_Bytes128__alloc (void);

struct TP_Test_Bytes128 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes128Seq data;
};

#ifndef _TP_Test_Bytes256_defined
#define _TP_Test_Bytes256_defined
#ifdef __cplusplus
struct TP_Test_Bytes256;
#else /* __cplusplus */
typedef struct TP_Test_Bytes256 TP_Test_Bytes256;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes256_defined */
TP_Test_Bytes256 *TP_Test_Bytes256__alloc (void);

struct TP_Test_Bytes256 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes256Seq data;
};

#ifndef _TP_Test_Bytes512_defined
#define _TP_Test_Bytes512_defined
#ifdef __cplusplus
struct TP_Test_Bytes512;
#else /* __cplusplus */
typedef struct TP_Test_Bytes512 TP_Test_Bytes512;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes512_defined */
TP_Test_Bytes512 *TP_Test_Bytes512__alloc (void);

struct TP_Test_Bytes512 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes512Seq data;
};

#ifndef _TP_Test_Bytes1024_defined
#define _TP_Test_Bytes1024_defined
#ifdef __cplusplus
struct TP_Test_Bytes1024;
#else /* __cplusplus */
typedef struct TP_Test_Bytes1024 TP_Test_Bytes1024;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes1024_defined */
TP_Test_Bytes1024 *TP_Test_Bytes1024__alloc (void);

struct TP_Test_Bytes1024 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes1024Seq data;
};

#ifndef _TP_Test_Bytes2048_defined
#define _TP_Test_Bytes2048_defined
#ifdef __cplusplus
struct TP_Test_Bytes2048;
#else /* __cplusplus */
typedef struct TP_Test_Bytes2048 TP_Test_Bytes2048;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes2048_defined */
TP_Test_Bytes2048 *TP_Test_Bytes2048__alloc (void);

struct TP_Test_Bytes2048 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes2048Seq data;
};

#ifndef _TP_Test_Bytes4096_defined
#define _TP_Test_Bytes4096_defined
#ifdef __cplusplus
struct TP_Test_Bytes4096;
#else /* __cplusplus */
typedef struct TP_Test_Bytes4096 TP_Test_Bytes4096;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes4096_defined */
TP_Test_Bytes4096 *TP_Test_Bytes4096__alloc (void);

struct TP_Test_Bytes4096 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes4096Seq data;
};

#ifndef _TP_Test_Bytes8192_defined
#define _TP_Test_Bytes8192_defined
#ifdef __cplusplus
struct TP_Test_Bytes8192;
#else /* __cplusplus */
typedef struct TP_Test_Bytes8192 TP_Test_Bytes8192;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes8192_defined */
TP_Test_Bytes8192 *TP_Test_Bytes8192__alloc (void);

struct TP_Test_Bytes8192 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes8192Seq data;
};

#ifndef _TP_Test_Bytes16384_defined
#define _TP_Test_Bytes16384_defined
#ifdef __cplusplus
struct TP_Test_Bytes16384;
#else /* __cplusplus */
typedef struct TP_Test_Bytes16384 TP_Test_Bytes16384;
#endif /* __cplusplus */
#endif /* _TP_Test_Bytes16384_defined */
TP_Test_Bytes16384 *TP_Test_Bytes16384__alloc (void);

struct TP_Test_Bytes16384 {
    DDS_unsigned_long timestamp;
    TP_Test_Bytes16384Seq data;
};

#ifndef _TP_Test_Nested_defined
#define _TP_Test_Nested_defined
#ifdef __cplusplus
struct TP_Test_Nested;
#else /* __cplusplus */
typedef struct TP_Test_Nested TP_Test_Nested;
#endif /* __cplusplus */
#endif /* _TP_Test_Nested_defined */
TP_Test_Nested *TP_Test_Nested__alloc (void);

struct TP_Test_Nested {
    DDS_string info;
    DDS_long index;
};

/* Definition for sequence of TP_Test_Nested */
#ifndef _DDS_sequence_TP_Test_Nested_defined
#define _DDS_sequence_TP_Test_Nested_defined
#ifndef _TP_Test_Nested_defined
#define _TP_Test_Nested_defined
typedef struct TP_Test_Nested TP_Test_Nested;
#endif /* _TP_Test_Nested_defined */
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Nested *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Nested;
DDS_sequence_TP_Test_Nested *DDS_sequence_TP_Test_Nested__alloc (void);
TP_Test_Nested *DDS_sequence_TP_Test_Nested_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Nested_defined */

typedef DDS_sequence_TP_Test_Nested TP_Test_NestedSeq;
TP_Test_NestedSeq *TP_Test_NestedSeq__alloc (void);
TP_Test_Nested *TP_Test_NestedSeq_allocbuf (DDS_unsigned_long len);

#ifndef _TP_Test_Outer_defined
#define _TP_Test_Outer_defined
#ifdef __cplusplus
struct TP_Test_Outer;
#else /* __cplusplus */
typedef struct TP_Test_Outer TP_Test_Outer;
#endif /* __cplusplus */
#endif /* _TP_Test_Outer_defined */
TP_Test_Outer *TP_Test_Outer__alloc (void);

struct TP_Test_Outer {
    DDS_long length;
    TP_Test_NestedSeq nested_member;
};

/* Definition for sequence of TP_Test_Outer */
#ifndef _DDS_sequence_TP_Test_Outer_defined
#define _DDS_sequence_TP_Test_Outer_defined
#ifndef _TP_Test_Outer_defined
#define _TP_Test_Outer_defined
typedef struct TP_Test_Outer TP_Test_Outer;
#endif /* _TP_Test_Outer_defined */
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Outer *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Outer;
DDS_sequence_TP_Test_Outer *DDS_sequence_TP_Test_Outer__alloc (void);
TP_Test_Outer *DDS_sequence_TP_Test_Outer_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Outer_defined */

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex4Seq;
TP_Test_Complex4Seq *TP_Test_Complex4Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex4Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex8Seq;
TP_Test_Complex8Seq *TP_Test_Complex8Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex8Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex16Seq;
TP_Test_Complex16Seq *TP_Test_Complex16Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex16Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex32Seq;
TP_Test_Complex32Seq *TP_Test_Complex32Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex32Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex64Seq;
TP_Test_Complex64Seq *TP_Test_Complex64Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex64Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex128Seq;
TP_Test_Complex128Seq *TP_Test_Complex128Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex128Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex256Seq;
TP_Test_Complex256Seq *TP_Test_Complex256Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex256Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex512Seq;
TP_Test_Complex512Seq *TP_Test_Complex512Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex512Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex1024Seq;
TP_Test_Complex1024Seq *TP_Test_Complex1024Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex1024Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex2048Seq;
TP_Test_Complex2048Seq *TP_Test_Complex2048Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex2048Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex4096Seq;
TP_Test_Complex4096Seq *TP_Test_Complex4096Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex4096Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex8192Seq;
TP_Test_Complex8192Seq *TP_Test_Complex8192Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex8192Seq_allocbuf (DDS_unsigned_long len);

typedef DDS_sequence_TP_Test_Outer TP_Test_Complex16384Seq;
TP_Test_Complex16384Seq *TP_Test_Complex16384Seq__alloc (void);
TP_Test_Outer *TP_Test_Complex16384Seq_allocbuf (DDS_unsigned_long len);

#ifndef _TP_Test_Complex4_defined
#define _TP_Test_Complex4_defined
#ifdef __cplusplus
struct TP_Test_Complex4;
#else /* __cplusplus */
typedef struct TP_Test_Complex4 TP_Test_Complex4;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex4_defined */
TP_Test_Complex4 *TP_Test_Complex4__alloc (void);

struct TP_Test_Complex4 {
    TP_Test_Complex4Seq data;
};

#ifndef _TP_Test_Complex8_defined
#define _TP_Test_Complex8_defined
#ifdef __cplusplus
struct TP_Test_Complex8;
#else /* __cplusplus */
typedef struct TP_Test_Complex8 TP_Test_Complex8;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex8_defined */
TP_Test_Complex8 *TP_Test_Complex8__alloc (void);

struct TP_Test_Complex8 {
    TP_Test_Complex8Seq data;
};

#ifndef _TP_Test_Complex16_defined
#define _TP_Test_Complex16_defined
#ifdef __cplusplus
struct TP_Test_Complex16;
#else /* __cplusplus */
typedef struct TP_Test_Complex16 TP_Test_Complex16;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex16_defined */
TP_Test_Complex16 *TP_Test_Complex16__alloc (void);

struct TP_Test_Complex16 {
    TP_Test_Complex16Seq data;
};

#ifndef _TP_Test_Complex32_defined
#define _TP_Test_Complex32_defined
#ifdef __cplusplus
struct TP_Test_Complex32;
#else /* __cplusplus */
typedef struct TP_Test_Complex32 TP_Test_Complex32;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex32_defined */
TP_Test_Complex32 *TP_Test_Complex32__alloc (void);

struct TP_Test_Complex32 {
    TP_Test_Complex32Seq data;
};

#ifndef _TP_Test_Complex64_defined
#define _TP_Test_Complex64_defined
#ifdef __cplusplus
struct TP_Test_Complex64;
#else /* __cplusplus */
typedef struct TP_Test_Complex64 TP_Test_Complex64;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex64_defined */
TP_Test_Complex64 *TP_Test_Complex64__alloc (void);

struct TP_Test_Complex64 {
    TP_Test_Complex64Seq data;
};

#ifndef _TP_Test_Complex128_defined
#define _TP_Test_Complex128_defined
#ifdef __cplusplus
struct TP_Test_Complex128;
#else /* __cplusplus */
typedef struct TP_Test_Complex128 TP_Test_Complex128;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex128_defined */
TP_Test_Complex128 *TP_Test_Complex128__alloc (void);

struct TP_Test_Complex128 {
    TP_Test_Complex128Seq data;
};

#ifndef _TP_Test_Complex256_defined
#define _TP_Test_Complex256_defined
#ifdef __cplusplus
struct TP_Test_Complex256;
#else /* __cplusplus */
typedef struct TP_Test_Complex256 TP_Test_Complex256;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex256_defined */
TP_Test_Complex256 *TP_Test_Complex256__alloc (void);

struct TP_Test_Complex256 {
    TP_Test_Complex256Seq data;
};

#ifndef _TP_Test_Complex512_defined
#define _TP_Test_Complex512_defined
#ifdef __cplusplus
struct TP_Test_Complex512;
#else /* __cplusplus */
typedef struct TP_Test_Complex512 TP_Test_Complex512;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex512_defined */
TP_Test_Complex512 *TP_Test_Complex512__alloc (void);

struct TP_Test_Complex512 {
    TP_Test_Complex512Seq data;
};

#ifndef _TP_Test_Complex1024_defined
#define _TP_Test_Complex1024_defined
#ifdef __cplusplus
struct TP_Test_Complex1024;
#else /* __cplusplus */
typedef struct TP_Test_Complex1024 TP_Test_Complex1024;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex1024_defined */
TP_Test_Complex1024 *TP_Test_Complex1024__alloc (void);

struct TP_Test_Complex1024 {
    TP_Test_Complex1024Seq data;
};

#ifndef _TP_Test_Complex2048_defined
#define _TP_Test_Complex2048_defined
#ifdef __cplusplus
struct TP_Test_Complex2048;
#else /* __cplusplus */
typedef struct TP_Test_Complex2048 TP_Test_Complex2048;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex2048_defined */
TP_Test_Complex2048 *TP_Test_Complex2048__alloc (void);

struct TP_Test_Complex2048 {
    TP_Test_Complex2048Seq data;
};

#ifndef _TP_Test_Complex4096_defined
#define _TP_Test_Complex4096_defined
#ifdef __cplusplus
struct TP_Test_Complex4096;
#else /* __cplusplus */
typedef struct TP_Test_Complex4096 TP_Test_Complex4096;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex4096_defined */
TP_Test_Complex4096 *TP_Test_Complex4096__alloc (void);

struct TP_Test_Complex4096 {
    TP_Test_Complex4096Seq data;
};

#ifndef _TP_Test_Complex8192_defined
#define _TP_Test_Complex8192_defined
#ifdef __cplusplus
struct TP_Test_Complex8192;
#else /* __cplusplus */
typedef struct TP_Test_Complex8192 TP_Test_Complex8192;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex8192_defined */
TP_Test_Complex8192 *TP_Test_Complex8192__alloc (void);

struct TP_Test_Complex8192 {
    TP_Test_Complex8192Seq data;
};

#ifndef _TP_Test_Complex16384_defined
#define _TP_Test_Complex16384_defined
#ifdef __cplusplus
struct TP_Test_Complex16384;
#else /* __cplusplus */
typedef struct TP_Test_Complex16384 TP_Test_Complex16384;
#endif /* __cplusplus */
#endif /* _TP_Test_Complex16384_defined */
TP_Test_Complex16384 *TP_Test_Complex16384__alloc (void);

struct TP_Test_Complex16384 {
    TP_Test_Complex16384Seq data;
};

#endif
