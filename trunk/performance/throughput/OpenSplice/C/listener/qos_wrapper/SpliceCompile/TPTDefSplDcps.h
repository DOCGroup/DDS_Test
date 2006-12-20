#ifndef TPTDEFSPLTYPES_H
#define TPTDEFSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __TPTDef_TP_Test__load (c_base base);

extern c_metaObject __TP_Test_QuitMsg__load (c_base base);
extern char * __TP_Test_QuitMsg__keys (void);
extern char * __TP_Test_QuitMsg__name (void);
struct _TP_Test_QuitMsg {
    c_bool quit;
};

extern c_metaObject __TP_Test_Bytes4Seq__load (c_base base);
typedef c_array _TP_Test_Bytes4Seq;

extern c_metaObject __TP_Test_Bytes8Seq__load (c_base base);
typedef c_array _TP_Test_Bytes8Seq;

extern c_metaObject __TP_Test_Bytes16Seq__load (c_base base);
typedef c_array _TP_Test_Bytes16Seq;

extern c_metaObject __TP_Test_Bytes32Seq__load (c_base base);
typedef c_array _TP_Test_Bytes32Seq;

extern c_metaObject __TP_Test_Bytes64Seq__load (c_base base);
typedef c_array _TP_Test_Bytes64Seq;

extern c_metaObject __TP_Test_Bytes128Seq__load (c_base base);
typedef c_array _TP_Test_Bytes128Seq;

extern c_metaObject __TP_Test_Bytes256Seq__load (c_base base);
typedef c_array _TP_Test_Bytes256Seq;

extern c_metaObject __TP_Test_Bytes512Seq__load (c_base base);
typedef c_array _TP_Test_Bytes512Seq;

extern c_metaObject __TP_Test_Bytes1024Seq__load (c_base base);
typedef c_array _TP_Test_Bytes1024Seq;

extern c_metaObject __TP_Test_Bytes2048Seq__load (c_base base);
typedef c_array _TP_Test_Bytes2048Seq;

extern c_metaObject __TP_Test_Bytes4096Seq__load (c_base base);
typedef c_array _TP_Test_Bytes4096Seq;

extern c_metaObject __TP_Test_Bytes8192Seq__load (c_base base);
typedef c_array _TP_Test_Bytes8192Seq;

extern c_metaObject __TP_Test_Bytes16384Seq__load (c_base base);
typedef c_array _TP_Test_Bytes16384Seq;

extern c_metaObject __TP_Test_Bytes4__load (c_base base);
extern char * __TP_Test_Bytes4__keys (void);
extern char * __TP_Test_Bytes4__name (void);
struct _TP_Test_Bytes4 {
    c_ulong timestamp;
    _TP_Test_Bytes4Seq data;
};

extern c_metaObject __TP_Test_Bytes8__load (c_base base);
extern char * __TP_Test_Bytes8__keys (void);
extern char * __TP_Test_Bytes8__name (void);
struct _TP_Test_Bytes8 {
    c_ulong timestamp;
    _TP_Test_Bytes8Seq data;
};

extern c_metaObject __TP_Test_Bytes16__load (c_base base);
extern char * __TP_Test_Bytes16__keys (void);
extern char * __TP_Test_Bytes16__name (void);
struct _TP_Test_Bytes16 {
    c_ulong timestamp;
    _TP_Test_Bytes16Seq data;
};

extern c_metaObject __TP_Test_Bytes32__load (c_base base);
extern char * __TP_Test_Bytes32__keys (void);
extern char * __TP_Test_Bytes32__name (void);
struct _TP_Test_Bytes32 {
    c_ulong timestamp;
    _TP_Test_Bytes32Seq data;
};

extern c_metaObject __TP_Test_Bytes64__load (c_base base);
extern char * __TP_Test_Bytes64__keys (void);
extern char * __TP_Test_Bytes64__name (void);
struct _TP_Test_Bytes64 {
    c_ulong timestamp;
    _TP_Test_Bytes64Seq data;
};

extern c_metaObject __TP_Test_Bytes128__load (c_base base);
extern char * __TP_Test_Bytes128__keys (void);
extern char * __TP_Test_Bytes128__name (void);
struct _TP_Test_Bytes128 {
    c_ulong timestamp;
    _TP_Test_Bytes128Seq data;
};

extern c_metaObject __TP_Test_Bytes256__load (c_base base);
extern char * __TP_Test_Bytes256__keys (void);
extern char * __TP_Test_Bytes256__name (void);
struct _TP_Test_Bytes256 {
    c_ulong timestamp;
    _TP_Test_Bytes256Seq data;
};

extern c_metaObject __TP_Test_Bytes512__load (c_base base);
extern char * __TP_Test_Bytes512__keys (void);
extern char * __TP_Test_Bytes512__name (void);
struct _TP_Test_Bytes512 {
    c_ulong timestamp;
    _TP_Test_Bytes512Seq data;
};

extern c_metaObject __TP_Test_Bytes1024__load (c_base base);
extern char * __TP_Test_Bytes1024__keys (void);
extern char * __TP_Test_Bytes1024__name (void);
struct _TP_Test_Bytes1024 {
    c_ulong timestamp;
    _TP_Test_Bytes1024Seq data;
};

extern c_metaObject __TP_Test_Bytes2048__load (c_base base);
extern char * __TP_Test_Bytes2048__keys (void);
extern char * __TP_Test_Bytes2048__name (void);
struct _TP_Test_Bytes2048 {
    c_ulong timestamp;
    _TP_Test_Bytes2048Seq data;
};

extern c_metaObject __TP_Test_Bytes4096__load (c_base base);
extern char * __TP_Test_Bytes4096__keys (void);
extern char * __TP_Test_Bytes4096__name (void);
struct _TP_Test_Bytes4096 {
    c_ulong timestamp;
    _TP_Test_Bytes4096Seq data;
};

extern c_metaObject __TP_Test_Bytes8192__load (c_base base);
extern char * __TP_Test_Bytes8192__keys (void);
extern char * __TP_Test_Bytes8192__name (void);
struct _TP_Test_Bytes8192 {
    c_ulong timestamp;
    _TP_Test_Bytes8192Seq data;
};

extern c_metaObject __TP_Test_Bytes16384__load (c_base base);
extern char * __TP_Test_Bytes16384__keys (void);
extern char * __TP_Test_Bytes16384__name (void);
struct _TP_Test_Bytes16384 {
    c_ulong timestamp;
    _TP_Test_Bytes16384Seq data;
};

extern c_metaObject __TP_Test_Nested__load (c_base base);
extern char * __TP_Test_Nested__keys (void);
extern char * __TP_Test_Nested__name (void);
struct _TP_Test_Nested {
    c_string info;
    c_long index;
};

extern c_metaObject __TP_Test_NestedSeq__load (c_base base);
typedef c_array _TP_Test_NestedSeq;

extern c_metaObject __TP_Test_Outer__load (c_base base);
extern char * __TP_Test_Outer__keys (void);
extern char * __TP_Test_Outer__name (void);
struct _TP_Test_Outer {
    c_long length;
    _TP_Test_NestedSeq nested_member;
};

extern c_metaObject __TP_Test_Complex4Seq__load (c_base base);
typedef c_array _TP_Test_Complex4Seq;

extern c_metaObject __TP_Test_Complex8Seq__load (c_base base);
typedef c_array _TP_Test_Complex8Seq;

extern c_metaObject __TP_Test_Complex16Seq__load (c_base base);
typedef c_array _TP_Test_Complex16Seq;

extern c_metaObject __TP_Test_Complex32Seq__load (c_base base);
typedef c_array _TP_Test_Complex32Seq;

extern c_metaObject __TP_Test_Complex64Seq__load (c_base base);
typedef c_array _TP_Test_Complex64Seq;

extern c_metaObject __TP_Test_Complex128Seq__load (c_base base);
typedef c_array _TP_Test_Complex128Seq;

extern c_metaObject __TP_Test_Complex256Seq__load (c_base base);
typedef c_array _TP_Test_Complex256Seq;

extern c_metaObject __TP_Test_Complex512Seq__load (c_base base);
typedef c_array _TP_Test_Complex512Seq;

extern c_metaObject __TP_Test_Complex1024Seq__load (c_base base);
typedef c_array _TP_Test_Complex1024Seq;

extern c_metaObject __TP_Test_Complex2048Seq__load (c_base base);
typedef c_array _TP_Test_Complex2048Seq;

extern c_metaObject __TP_Test_Complex4096Seq__load (c_base base);
typedef c_array _TP_Test_Complex4096Seq;

extern c_metaObject __TP_Test_Complex8192Seq__load (c_base base);
typedef c_array _TP_Test_Complex8192Seq;

extern c_metaObject __TP_Test_Complex16384Seq__load (c_base base);
typedef c_array _TP_Test_Complex16384Seq;

extern c_metaObject __TP_Test_Complex4__load (c_base base);
extern char * __TP_Test_Complex4__keys (void);
extern char * __TP_Test_Complex4__name (void);
struct _TP_Test_Complex4 {
    _TP_Test_Complex4Seq data;
};

extern c_metaObject __TP_Test_Complex8__load (c_base base);
extern char * __TP_Test_Complex8__keys (void);
extern char * __TP_Test_Complex8__name (void);
struct _TP_Test_Complex8 {
    _TP_Test_Complex8Seq data;
};

extern c_metaObject __TP_Test_Complex16__load (c_base base);
extern char * __TP_Test_Complex16__keys (void);
extern char * __TP_Test_Complex16__name (void);
struct _TP_Test_Complex16 {
    _TP_Test_Complex16Seq data;
};

extern c_metaObject __TP_Test_Complex32__load (c_base base);
extern char * __TP_Test_Complex32__keys (void);
extern char * __TP_Test_Complex32__name (void);
struct _TP_Test_Complex32 {
    _TP_Test_Complex32Seq data;
};

extern c_metaObject __TP_Test_Complex64__load (c_base base);
extern char * __TP_Test_Complex64__keys (void);
extern char * __TP_Test_Complex64__name (void);
struct _TP_Test_Complex64 {
    _TP_Test_Complex64Seq data;
};

extern c_metaObject __TP_Test_Complex128__load (c_base base);
extern char * __TP_Test_Complex128__keys (void);
extern char * __TP_Test_Complex128__name (void);
struct _TP_Test_Complex128 {
    _TP_Test_Complex128Seq data;
};

extern c_metaObject __TP_Test_Complex256__load (c_base base);
extern char * __TP_Test_Complex256__keys (void);
extern char * __TP_Test_Complex256__name (void);
struct _TP_Test_Complex256 {
    _TP_Test_Complex256Seq data;
};

extern c_metaObject __TP_Test_Complex512__load (c_base base);
extern char * __TP_Test_Complex512__keys (void);
extern char * __TP_Test_Complex512__name (void);
struct _TP_Test_Complex512 {
    _TP_Test_Complex512Seq data;
};

extern c_metaObject __TP_Test_Complex1024__load (c_base base);
extern char * __TP_Test_Complex1024__keys (void);
extern char * __TP_Test_Complex1024__name (void);
struct _TP_Test_Complex1024 {
    _TP_Test_Complex1024Seq data;
};

extern c_metaObject __TP_Test_Complex2048__load (c_base base);
extern char * __TP_Test_Complex2048__keys (void);
extern char * __TP_Test_Complex2048__name (void);
struct _TP_Test_Complex2048 {
    _TP_Test_Complex2048Seq data;
};

extern c_metaObject __TP_Test_Complex4096__load (c_base base);
extern char * __TP_Test_Complex4096__keys (void);
extern char * __TP_Test_Complex4096__name (void);
struct _TP_Test_Complex4096 {
    _TP_Test_Complex4096Seq data;
};

extern c_metaObject __TP_Test_Complex8192__load (c_base base);
extern char * __TP_Test_Complex8192__keys (void);
extern char * __TP_Test_Complex8192__name (void);
struct _TP_Test_Complex8192 {
    _TP_Test_Complex8192Seq data;
};

extern c_metaObject __TP_Test_Complex16384__load (c_base base);
extern char * __TP_Test_Complex16384__keys (void);
extern char * __TP_Test_Complex16384__name (void);
struct _TP_Test_Complex16384 {
    _TP_Test_Complex16384Seq data;
};

#endif
