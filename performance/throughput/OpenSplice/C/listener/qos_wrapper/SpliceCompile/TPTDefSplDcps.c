#if defined (__cplusplus)
extern "C" {
#endif

#include "TPTDefSplDcps.h"
#include "TPTDefDcps.h"

char *
__TP_Test_QuitMsg__name(void)
{
    return "TP_Test::QuitMsg";
}

char *
__TP_Test_QuitMsg__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes4__name(void)
{
    return "TP_Test::Bytes4";
}

char *
__TP_Test_Bytes4__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes8__name(void)
{
    return "TP_Test::Bytes8";
}

char *
__TP_Test_Bytes8__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes16__name(void)
{
    return "TP_Test::Bytes16";
}

char *
__TP_Test_Bytes16__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes32__name(void)
{
    return "TP_Test::Bytes32";
}

char *
__TP_Test_Bytes32__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes64__name(void)
{
    return "TP_Test::Bytes64";
}

char *
__TP_Test_Bytes64__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes128__name(void)
{
    return "TP_Test::Bytes128";
}

char *
__TP_Test_Bytes128__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes256__name(void)
{
    return "TP_Test::Bytes256";
}

char *
__TP_Test_Bytes256__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes512__name(void)
{
    return "TP_Test::Bytes512";
}

char *
__TP_Test_Bytes512__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes1024__name(void)
{
    return "TP_Test::Bytes1024";
}

char *
__TP_Test_Bytes1024__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes2048__name(void)
{
    return "TP_Test::Bytes2048";
}

char *
__TP_Test_Bytes2048__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes4096__name(void)
{
    return "TP_Test::Bytes4096";
}

char *
__TP_Test_Bytes4096__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes8192__name(void)
{
    return "TP_Test::Bytes8192";
}

char *
__TP_Test_Bytes8192__keys(void)
{
    return "";
}

char *
__TP_Test_Bytes16384__name(void)
{
    return "TP_Test::Bytes16384";
}

char *
__TP_Test_Bytes16384__keys(void)
{
    return "";
}

char *
__TP_Test_Nested__name(void)
{
    return "TP_Test::Nested";
}

char *
__TP_Test_Nested__keys(void)
{
    return "";
}

char *
__TP_Test_Outer__name(void)
{
    return "TP_Test::Outer";
}

char *
__TP_Test_Outer__keys(void)
{
    return "";
}

char *
__TP_Test_Complex4__name(void)
{
    return "TP_Test::Complex4";
}

char *
__TP_Test_Complex4__keys(void)
{
    return "";
}

char *
__TP_Test_Complex8__name(void)
{
    return "TP_Test::Complex8";
}

char *
__TP_Test_Complex8__keys(void)
{
    return "";
}

char *
__TP_Test_Complex16__name(void)
{
    return "TP_Test::Complex16";
}

char *
__TP_Test_Complex16__keys(void)
{
    return "";
}

char *
__TP_Test_Complex32__name(void)
{
    return "TP_Test::Complex32";
}

char *
__TP_Test_Complex32__keys(void)
{
    return "";
}

char *
__TP_Test_Complex64__name(void)
{
    return "TP_Test::Complex64";
}

char *
__TP_Test_Complex64__keys(void)
{
    return "";
}

char *
__TP_Test_Complex128__name(void)
{
    return "TP_Test::Complex128";
}

char *
__TP_Test_Complex128__keys(void)
{
    return "";
}

char *
__TP_Test_Complex256__name(void)
{
    return "TP_Test::Complex256";
}

char *
__TP_Test_Complex256__keys(void)
{
    return "";
}

char *
__TP_Test_Complex512__name(void)
{
    return "TP_Test::Complex512";
}

char *
__TP_Test_Complex512__keys(void)
{
    return "";
}

char *
__TP_Test_Complex1024__name(void)
{
    return "TP_Test::Complex1024";
}

char *
__TP_Test_Complex1024__keys(void)
{
    return "";
}

char *
__TP_Test_Complex2048__name(void)
{
    return "TP_Test::Complex2048";
}

char *
__TP_Test_Complex2048__keys(void)
{
    return "";
}

char *
__TP_Test_Complex4096__name(void)
{
    return "TP_Test::Complex4096";
}

char *
__TP_Test_Complex4096__keys(void)
{
    return "";
}

char *
__TP_Test_Complex8192__name(void)
{
    return "TP_Test::Complex8192";
}

char *
__TP_Test_Complex8192__keys(void)
{
    return "";
}

char *
__TP_Test_Complex16384__name(void)
{
    return "TP_Test::Complex16384";
}

char *
__TP_Test_Complex16384__keys(void)
{
    return "";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <strings.h>

void
__TP_Test_QuitMsg__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_QuitMsg *from = (TP_Test_QuitMsg *)_from;
    struct _TP_Test_QuitMsg *to = (struct _TP_Test_QuitMsg *)_to;
    to->quit = (c_bool)from->quit;
}

void
__TP_Test_Bytes4Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes4Seq *from = (TP_Test_Bytes4Seq *)_from;
    _TP_Test_Bytes4Seq *to = (_TP_Test_Bytes4Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes4Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes4Seq)dst0;
}

void
__TP_Test_Bytes8Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes8Seq *from = (TP_Test_Bytes8Seq *)_from;
    _TP_Test_Bytes8Seq *to = (_TP_Test_Bytes8Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes8Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes8Seq)dst0;
}

void
__TP_Test_Bytes16Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes16Seq *from = (TP_Test_Bytes16Seq *)_from;
    _TP_Test_Bytes16Seq *to = (_TP_Test_Bytes16Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes16Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes16Seq)dst0;
}

void
__TP_Test_Bytes32Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes32Seq *from = (TP_Test_Bytes32Seq *)_from;
    _TP_Test_Bytes32Seq *to = (_TP_Test_Bytes32Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes32Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes32Seq)dst0;
}

void
__TP_Test_Bytes64Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes64Seq *from = (TP_Test_Bytes64Seq *)_from;
    _TP_Test_Bytes64Seq *to = (_TP_Test_Bytes64Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes64Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes64Seq)dst0;
}

void
__TP_Test_Bytes128Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes128Seq *from = (TP_Test_Bytes128Seq *)_from;
    _TP_Test_Bytes128Seq *to = (_TP_Test_Bytes128Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes128Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes128Seq)dst0;
}

void
__TP_Test_Bytes256Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes256Seq *from = (TP_Test_Bytes256Seq *)_from;
    _TP_Test_Bytes256Seq *to = (_TP_Test_Bytes256Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes256Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes256Seq)dst0;
}

void
__TP_Test_Bytes512Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes512Seq *from = (TP_Test_Bytes512Seq *)_from;
    _TP_Test_Bytes512Seq *to = (_TP_Test_Bytes512Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes512Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes512Seq)dst0;
}

void
__TP_Test_Bytes1024Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes1024Seq *from = (TP_Test_Bytes1024Seq *)_from;
    _TP_Test_Bytes1024Seq *to = (_TP_Test_Bytes1024Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes1024Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes1024Seq)dst0;
}

void
__TP_Test_Bytes2048Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes2048Seq *from = (TP_Test_Bytes2048Seq *)_from;
    _TP_Test_Bytes2048Seq *to = (_TP_Test_Bytes2048Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes2048Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes2048Seq)dst0;
}

void
__TP_Test_Bytes4096Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes4096Seq *from = (TP_Test_Bytes4096Seq *)_from;
    _TP_Test_Bytes4096Seq *to = (_TP_Test_Bytes4096Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes4096Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes4096Seq)dst0;
}

void
__TP_Test_Bytes8192Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes8192Seq *from = (TP_Test_Bytes8192Seq *)_from;
    _TP_Test_Bytes8192Seq *to = (_TP_Test_Bytes8192Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes8192Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes8192Seq)dst0;
}

void
__TP_Test_Bytes16384Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes16384Seq *from = (TP_Test_Bytes16384Seq *)_from;
    _TP_Test_Bytes16384Seq *to = (_TP_Test_Bytes16384Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    c_octet *dst0;
    TP_Test_Bytes16384Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "c_octet"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (c_octet *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        dst0[i0] = (c_octet)(*from0)._buffer[i0];
    }
    *to = (_TP_Test_Bytes16384Seq)dst0;
}

void
__TP_Test_Bytes4__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes4 *from = (TP_Test_Bytes4 *)_from;
    struct _TP_Test_Bytes4 *to = (struct _TP_Test_Bytes4 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes4Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes4Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes8__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes8 *from = (TP_Test_Bytes8 *)_from;
    struct _TP_Test_Bytes8 *to = (struct _TP_Test_Bytes8 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes8Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes8Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes16__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes16 *from = (TP_Test_Bytes16 *)_from;
    struct _TP_Test_Bytes16 *to = (struct _TP_Test_Bytes16 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes16Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes16Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes32__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes32 *from = (TP_Test_Bytes32 *)_from;
    struct _TP_Test_Bytes32 *to = (struct _TP_Test_Bytes32 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes32Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes32Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes64__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes64 *from = (TP_Test_Bytes64 *)_from;
    struct _TP_Test_Bytes64 *to = (struct _TP_Test_Bytes64 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes64Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes64Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes128__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes128 *from = (TP_Test_Bytes128 *)_from;
    struct _TP_Test_Bytes128 *to = (struct _TP_Test_Bytes128 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes128Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes128Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes256__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes256 *from = (TP_Test_Bytes256 *)_from;
    struct _TP_Test_Bytes256 *to = (struct _TP_Test_Bytes256 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes256Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes256Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes512__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes512 *from = (TP_Test_Bytes512 *)_from;
    struct _TP_Test_Bytes512 *to = (struct _TP_Test_Bytes512 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes512Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes512Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes1024__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes1024 *from = (TP_Test_Bytes1024 *)_from;
    struct _TP_Test_Bytes1024 *to = (struct _TP_Test_Bytes1024 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes1024Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes1024Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes2048__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes2048 *from = (TP_Test_Bytes2048 *)_from;
    struct _TP_Test_Bytes2048 *to = (struct _TP_Test_Bytes2048 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes2048Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes2048Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes4096__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes4096 *from = (TP_Test_Bytes4096 *)_from;
    struct _TP_Test_Bytes4096 *to = (struct _TP_Test_Bytes4096 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes4096Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes4096Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes8192__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes8192 *from = (TP_Test_Bytes8192 *)_from;
    struct _TP_Test_Bytes8192 *to = (struct _TP_Test_Bytes8192 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes8192Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes8192Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Bytes16384__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Bytes16384 *from = (TP_Test_Bytes16384 *)_from;
    struct _TP_Test_Bytes16384 *to = (struct _TP_Test_Bytes16384 *)_to;
    to->timestamp = (c_ulong)from->timestamp;
    {
        extern void __TP_Test_Bytes16384Seq__copyIn(c_base, void *, void *);
        __TP_Test_Bytes16384Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Nested__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Nested *from = (TP_Test_Nested *)_from;
    struct _TP_Test_Nested *to = (struct _TP_Test_Nested *)_to;
    to->info = c_stringNew(base, from->info);
    to->index = (c_long)from->index;
}

void
__TP_Test_NestedSeq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_NestedSeq *from = (TP_Test_NestedSeq *)_from;
    _TP_Test_NestedSeq *to = (_TP_Test_NestedSeq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Nested *dst0;
    TP_Test_NestedSeq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Nested"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Nested *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Nested__copyIn(c_base base, void *, void *);
        __TP_Test_Nested__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Nested *)&dst0[i0]);
    }
    *to = (_TP_Test_NestedSeq)dst0;
}

void
__TP_Test_Outer__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Outer *from = (TP_Test_Outer *)_from;
    struct _TP_Test_Outer *to = (struct _TP_Test_Outer *)_to;
    to->length = (c_long)from->length;
    {
        extern void __TP_Test_NestedSeq__copyIn(c_base, void *, void *);
        __TP_Test_NestedSeq__copyIn(base, &from->nested_member, &to->nested_member);
    }
}

void
__TP_Test_Complex4Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex4Seq *from = (TP_Test_Complex4Seq *)_from;
    _TP_Test_Complex4Seq *to = (_TP_Test_Complex4Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex4Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex4Seq)dst0;
}

void
__TP_Test_Complex8Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex8Seq *from = (TP_Test_Complex8Seq *)_from;
    _TP_Test_Complex8Seq *to = (_TP_Test_Complex8Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex8Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex8Seq)dst0;
}

void
__TP_Test_Complex16Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex16Seq *from = (TP_Test_Complex16Seq *)_from;
    _TP_Test_Complex16Seq *to = (_TP_Test_Complex16Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex16Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex16Seq)dst0;
}

void
__TP_Test_Complex32Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex32Seq *from = (TP_Test_Complex32Seq *)_from;
    _TP_Test_Complex32Seq *to = (_TP_Test_Complex32Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex32Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex32Seq)dst0;
}

void
__TP_Test_Complex64Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex64Seq *from = (TP_Test_Complex64Seq *)_from;
    _TP_Test_Complex64Seq *to = (_TP_Test_Complex64Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex64Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex64Seq)dst0;
}

void
__TP_Test_Complex128Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex128Seq *from = (TP_Test_Complex128Seq *)_from;
    _TP_Test_Complex128Seq *to = (_TP_Test_Complex128Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex128Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex128Seq)dst0;
}

void
__TP_Test_Complex256Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex256Seq *from = (TP_Test_Complex256Seq *)_from;
    _TP_Test_Complex256Seq *to = (_TP_Test_Complex256Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex256Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex256Seq)dst0;
}

void
__TP_Test_Complex512Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex512Seq *from = (TP_Test_Complex512Seq *)_from;
    _TP_Test_Complex512Seq *to = (_TP_Test_Complex512Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex512Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex512Seq)dst0;
}

void
__TP_Test_Complex1024Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex1024Seq *from = (TP_Test_Complex1024Seq *)_from;
    _TP_Test_Complex1024Seq *to = (_TP_Test_Complex1024Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex1024Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex1024Seq)dst0;
}

void
__TP_Test_Complex2048Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex2048Seq *from = (TP_Test_Complex2048Seq *)_from;
    _TP_Test_Complex2048Seq *to = (_TP_Test_Complex2048Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex2048Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex2048Seq)dst0;
}

void
__TP_Test_Complex4096Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex4096Seq *from = (TP_Test_Complex4096Seq *)_from;
    _TP_Test_Complex4096Seq *to = (_TP_Test_Complex4096Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex4096Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex4096Seq)dst0;
}

void
__TP_Test_Complex8192Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex8192Seq *from = (TP_Test_Complex8192Seq *)_from;
    _TP_Test_Complex8192Seq *to = (_TP_Test_Complex8192Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex8192Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex8192Seq)dst0;
}

void
__TP_Test_Complex16384Seq__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex16384Seq *from = (TP_Test_Complex16384Seq *)_from;
    _TP_Test_Complex16384Seq *to = (_TP_Test_Complex16384Seq *)_to;
    static c_type type0 = NULL;
    unsigned int i0;
    c_long length0;
    struct _TP_Test_Outer *dst0;
    TP_Test_Complex16384Seq *from0 = from;

    if (type0 == NULL) {
        type0 = c_type(c_metaResolve (c_metaObject(base), "TP_Test::Outer"));
    }
    length0 = (c_long)(*from)._length;
    dst0 = (struct _TP_Test_Outer *)c_arrayNew(type0, length0);
    for (i0 = 0; i0 < (unsigned int)length0; i0++) {
        extern void __TP_Test_Outer__copyIn(c_base base, void *, void *);
        __TP_Test_Outer__copyIn(base, &(*from0)._buffer[i0], (struct _TP_Test_Outer *)&dst0[i0]);
    }
    *to = (_TP_Test_Complex16384Seq)dst0;
}

void
__TP_Test_Complex4__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex4 *from = (TP_Test_Complex4 *)_from;
    struct _TP_Test_Complex4 *to = (struct _TP_Test_Complex4 *)_to;
    {
        extern void __TP_Test_Complex4Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex4Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex8__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex8 *from = (TP_Test_Complex8 *)_from;
    struct _TP_Test_Complex8 *to = (struct _TP_Test_Complex8 *)_to;
    {
        extern void __TP_Test_Complex8Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex8Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex16__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex16 *from = (TP_Test_Complex16 *)_from;
    struct _TP_Test_Complex16 *to = (struct _TP_Test_Complex16 *)_to;
    {
        extern void __TP_Test_Complex16Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex16Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex32__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex32 *from = (TP_Test_Complex32 *)_from;
    struct _TP_Test_Complex32 *to = (struct _TP_Test_Complex32 *)_to;
    {
        extern void __TP_Test_Complex32Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex32Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex64__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex64 *from = (TP_Test_Complex64 *)_from;
    struct _TP_Test_Complex64 *to = (struct _TP_Test_Complex64 *)_to;
    {
        extern void __TP_Test_Complex64Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex64Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex128__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex128 *from = (TP_Test_Complex128 *)_from;
    struct _TP_Test_Complex128 *to = (struct _TP_Test_Complex128 *)_to;
    {
        extern void __TP_Test_Complex128Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex128Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex256__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex256 *from = (TP_Test_Complex256 *)_from;
    struct _TP_Test_Complex256 *to = (struct _TP_Test_Complex256 *)_to;
    {
        extern void __TP_Test_Complex256Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex256Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex512__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex512 *from = (TP_Test_Complex512 *)_from;
    struct _TP_Test_Complex512 *to = (struct _TP_Test_Complex512 *)_to;
    {
        extern void __TP_Test_Complex512Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex512Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex1024__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex1024 *from = (TP_Test_Complex1024 *)_from;
    struct _TP_Test_Complex1024 *to = (struct _TP_Test_Complex1024 *)_to;
    {
        extern void __TP_Test_Complex1024Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex1024Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex2048__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex2048 *from = (TP_Test_Complex2048 *)_from;
    struct _TP_Test_Complex2048 *to = (struct _TP_Test_Complex2048 *)_to;
    {
        extern void __TP_Test_Complex2048Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex2048Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex4096__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex4096 *from = (TP_Test_Complex4096 *)_from;
    struct _TP_Test_Complex4096 *to = (struct _TP_Test_Complex4096 *)_to;
    {
        extern void __TP_Test_Complex4096Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex4096Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex8192__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex8192 *from = (TP_Test_Complex8192 *)_from;
    struct _TP_Test_Complex8192 *to = (struct _TP_Test_Complex8192 *)_to;
    {
        extern void __TP_Test_Complex8192Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex8192Seq__copyIn(base, &from->data, &to->data);
    }
}

void
__TP_Test_Complex16384__copyIn(c_base base, void *_from, void *_to)
{
    TP_Test_Complex16384 *from = (TP_Test_Complex16384 *)_from;
    struct _TP_Test_Complex16384 *to = (struct _TP_Test_Complex16384 *)_to;
    {
        extern void __TP_Test_Complex16384Seq__copyIn(c_base, void *, void *);
        __TP_Test_Complex16384Seq__copyIn(base, &from->data, &to->data);
    }
}

#include <dds_dcps_private.h>

void
__TP_Test_QuitMsg__copyOut(void *_from, void *_to)
{
    struct _TP_Test_QuitMsg *from = (struct _TP_Test_QuitMsg *)_from;
    TP_Test_QuitMsg *to = (TP_Test_QuitMsg *)_to;
    to->quit = (DDS_boolean)from->quit;
}

void
__TP_Test_Bytes4Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes4Seq *from = (_TP_Test_Bytes4Seq *)_from;
    TP_Test_Bytes4Seq *to = (TP_Test_Bytes4Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes4Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 4);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes8Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes8Seq *from = (_TP_Test_Bytes8Seq *)_from;
    TP_Test_Bytes8Seq *to = (TP_Test_Bytes8Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes8Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 8);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes16Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes16Seq *from = (_TP_Test_Bytes16Seq *)_from;
    TP_Test_Bytes16Seq *to = (TP_Test_Bytes16Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes16Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 16);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes32Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes32Seq *from = (_TP_Test_Bytes32Seq *)_from;
    TP_Test_Bytes32Seq *to = (TP_Test_Bytes32Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes32Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 32);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes64Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes64Seq *from = (_TP_Test_Bytes64Seq *)_from;
    TP_Test_Bytes64Seq *to = (TP_Test_Bytes64Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes64Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 64);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes128Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes128Seq *from = (_TP_Test_Bytes128Seq *)_from;
    TP_Test_Bytes128Seq *to = (TP_Test_Bytes128Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes128Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 128);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes256Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes256Seq *from = (_TP_Test_Bytes256Seq *)_from;
    TP_Test_Bytes256Seq *to = (TP_Test_Bytes256Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes256Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 256);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes512Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes512Seq *from = (_TP_Test_Bytes512Seq *)_from;
    TP_Test_Bytes512Seq *to = (TP_Test_Bytes512Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes512Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 512);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes1024Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes1024Seq *from = (_TP_Test_Bytes1024Seq *)_from;
    TP_Test_Bytes1024Seq *to = (TP_Test_Bytes1024Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes1024Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 1024);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes2048Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes2048Seq *from = (_TP_Test_Bytes2048Seq *)_from;
    TP_Test_Bytes2048Seq *to = (TP_Test_Bytes2048Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes2048Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 2048);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes4096Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes4096Seq *from = (_TP_Test_Bytes4096Seq *)_from;
    TP_Test_Bytes4096Seq *to = (TP_Test_Bytes4096Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes4096Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 4096);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes8192Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes8192Seq *from = (_TP_Test_Bytes8192Seq *)_from;
    TP_Test_Bytes8192Seq *to = (TP_Test_Bytes8192Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes8192Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 8192);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes16384Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Bytes16384Seq *from = (_TP_Test_Bytes16384Seq *)_from;
    TP_Test_Bytes16384Seq *to = (TP_Test_Bytes16384Seq *)_to;
    long i0;
    long size0;
    c_octet *src0 = (c_octet *)(*from);
    TP_Test_Bytes16384Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_octet_allocbuf, 16384);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        (*dst0)._buffer[i0] = (DDS_octet)src0[i0];
    }
}

void
__TP_Test_Bytes4__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes4 *from = (struct _TP_Test_Bytes4 *)_from;
    TP_Test_Bytes4 *to = (TP_Test_Bytes4 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes4Seq__copyOut(void *, void *);
        __TP_Test_Bytes4Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes8__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes8 *from = (struct _TP_Test_Bytes8 *)_from;
    TP_Test_Bytes8 *to = (TP_Test_Bytes8 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes8Seq__copyOut(void *, void *);
        __TP_Test_Bytes8Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes16__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes16 *from = (struct _TP_Test_Bytes16 *)_from;
    TP_Test_Bytes16 *to = (TP_Test_Bytes16 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes16Seq__copyOut(void *, void *);
        __TP_Test_Bytes16Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes32__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes32 *from = (struct _TP_Test_Bytes32 *)_from;
    TP_Test_Bytes32 *to = (TP_Test_Bytes32 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes32Seq__copyOut(void *, void *);
        __TP_Test_Bytes32Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes64__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes64 *from = (struct _TP_Test_Bytes64 *)_from;
    TP_Test_Bytes64 *to = (TP_Test_Bytes64 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes64Seq__copyOut(void *, void *);
        __TP_Test_Bytes64Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes128__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes128 *from = (struct _TP_Test_Bytes128 *)_from;
    TP_Test_Bytes128 *to = (TP_Test_Bytes128 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes128Seq__copyOut(void *, void *);
        __TP_Test_Bytes128Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes256__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes256 *from = (struct _TP_Test_Bytes256 *)_from;
    TP_Test_Bytes256 *to = (TP_Test_Bytes256 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes256Seq__copyOut(void *, void *);
        __TP_Test_Bytes256Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes512__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes512 *from = (struct _TP_Test_Bytes512 *)_from;
    TP_Test_Bytes512 *to = (TP_Test_Bytes512 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes512Seq__copyOut(void *, void *);
        __TP_Test_Bytes512Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes1024__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes1024 *from = (struct _TP_Test_Bytes1024 *)_from;
    TP_Test_Bytes1024 *to = (TP_Test_Bytes1024 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes1024Seq__copyOut(void *, void *);
        __TP_Test_Bytes1024Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes2048__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes2048 *from = (struct _TP_Test_Bytes2048 *)_from;
    TP_Test_Bytes2048 *to = (TP_Test_Bytes2048 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes2048Seq__copyOut(void *, void *);
        __TP_Test_Bytes2048Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes4096__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes4096 *from = (struct _TP_Test_Bytes4096 *)_from;
    TP_Test_Bytes4096 *to = (TP_Test_Bytes4096 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes4096Seq__copyOut(void *, void *);
        __TP_Test_Bytes4096Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes8192__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes8192 *from = (struct _TP_Test_Bytes8192 *)_from;
    TP_Test_Bytes8192 *to = (TP_Test_Bytes8192 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes8192Seq__copyOut(void *, void *);
        __TP_Test_Bytes8192Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Bytes16384__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Bytes16384 *from = (struct _TP_Test_Bytes16384 *)_from;
    TP_Test_Bytes16384 *to = (TP_Test_Bytes16384 *)_to;
    to->timestamp = (DDS_unsigned_long)from->timestamp;
    {
        extern void __TP_Test_Bytes16384Seq__copyOut(void *, void *);
        __TP_Test_Bytes16384Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Nested__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Nested *from = (struct _TP_Test_Nested *)_from;
    TP_Test_Nested *to = (TP_Test_Nested *)_to;
    DDS_string_replace (from->info, &to->info);
    to->index = (DDS_long)from->index;
}

void
__TP_Test_NestedSeq__copyOut(void *_from, void *_to)
{
    _TP_Test_NestedSeq *from = (_TP_Test_NestedSeq *)_from;
    TP_Test_NestedSeq *to = (TP_Test_NestedSeq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Nested *src0 = (struct _TP_Test_Nested *)(*from);
    TP_Test_NestedSeq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Nested_allocbuf, size0);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Nested__copyOut(void *, void *);
        __TP_Test_Nested__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Outer__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Outer *from = (struct _TP_Test_Outer *)_from;
    TP_Test_Outer *to = (TP_Test_Outer *)_to;
    to->length = (DDS_long)from->length;
    {
        extern void __TP_Test_NestedSeq__copyOut(void *, void *);
        __TP_Test_NestedSeq__copyOut(&from->nested_member, &to->nested_member);
    }
}

void
__TP_Test_Complex4Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex4Seq *from = (_TP_Test_Complex4Seq *)_from;
    TP_Test_Complex4Seq *to = (TP_Test_Complex4Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex4Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 4);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex8Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex8Seq *from = (_TP_Test_Complex8Seq *)_from;
    TP_Test_Complex8Seq *to = (TP_Test_Complex8Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex8Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 8);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex16Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex16Seq *from = (_TP_Test_Complex16Seq *)_from;
    TP_Test_Complex16Seq *to = (TP_Test_Complex16Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex16Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 16);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex32Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex32Seq *from = (_TP_Test_Complex32Seq *)_from;
    TP_Test_Complex32Seq *to = (TP_Test_Complex32Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex32Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 32);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex64Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex64Seq *from = (_TP_Test_Complex64Seq *)_from;
    TP_Test_Complex64Seq *to = (TP_Test_Complex64Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex64Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 64);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex128Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex128Seq *from = (_TP_Test_Complex128Seq *)_from;
    TP_Test_Complex128Seq *to = (TP_Test_Complex128Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex128Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 128);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex256Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex256Seq *from = (_TP_Test_Complex256Seq *)_from;
    TP_Test_Complex256Seq *to = (TP_Test_Complex256Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex256Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 256);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex512Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex512Seq *from = (_TP_Test_Complex512Seq *)_from;
    TP_Test_Complex512Seq *to = (TP_Test_Complex512Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex512Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 512);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex1024Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex1024Seq *from = (_TP_Test_Complex1024Seq *)_from;
    TP_Test_Complex1024Seq *to = (TP_Test_Complex1024Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex1024Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 1024);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex2048Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex2048Seq *from = (_TP_Test_Complex2048Seq *)_from;
    TP_Test_Complex2048Seq *to = (TP_Test_Complex2048Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex2048Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 2048);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex4096Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex4096Seq *from = (_TP_Test_Complex4096Seq *)_from;
    TP_Test_Complex4096Seq *to = (TP_Test_Complex4096Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex4096Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 4096);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex8192Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex8192Seq *from = (_TP_Test_Complex8192Seq *)_from;
    TP_Test_Complex8192Seq *to = (TP_Test_Complex8192Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex8192Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 8192);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex16384Seq__copyOut(void *_from, void *_to)
{
    _TP_Test_Complex16384Seq *from = (_TP_Test_Complex16384Seq *)_from;
    TP_Test_Complex16384Seq *to = (TP_Test_Complex16384Seq *)_to;
    long i0;
    long size0;
    struct _TP_Test_Outer *src0 = (struct _TP_Test_Outer *)(*from);
    TP_Test_Complex16384Seq *dst0 = to;

    size0 = c_arraySize((c_array)(src0));
    DDS_sequence_replacebuf (dst0, (bufferAllocatorType)DDS_sequence_TP_Test_Outer_allocbuf, 16384);
    dst0->_length = size0;
    for (i0 = 0; i0 < size0; i0++) {
        extern void __TP_Test_Outer__copyOut(void *, void *);
        __TP_Test_Outer__copyOut(&src0[i0], &(*dst0)._buffer[i0]);
    }
}

void
__TP_Test_Complex4__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex4 *from = (struct _TP_Test_Complex4 *)_from;
    TP_Test_Complex4 *to = (TP_Test_Complex4 *)_to;
    {
        extern void __TP_Test_Complex4Seq__copyOut(void *, void *);
        __TP_Test_Complex4Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex8__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex8 *from = (struct _TP_Test_Complex8 *)_from;
    TP_Test_Complex8 *to = (TP_Test_Complex8 *)_to;
    {
        extern void __TP_Test_Complex8Seq__copyOut(void *, void *);
        __TP_Test_Complex8Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex16__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex16 *from = (struct _TP_Test_Complex16 *)_from;
    TP_Test_Complex16 *to = (TP_Test_Complex16 *)_to;
    {
        extern void __TP_Test_Complex16Seq__copyOut(void *, void *);
        __TP_Test_Complex16Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex32__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex32 *from = (struct _TP_Test_Complex32 *)_from;
    TP_Test_Complex32 *to = (TP_Test_Complex32 *)_to;
    {
        extern void __TP_Test_Complex32Seq__copyOut(void *, void *);
        __TP_Test_Complex32Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex64__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex64 *from = (struct _TP_Test_Complex64 *)_from;
    TP_Test_Complex64 *to = (TP_Test_Complex64 *)_to;
    {
        extern void __TP_Test_Complex64Seq__copyOut(void *, void *);
        __TP_Test_Complex64Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex128__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex128 *from = (struct _TP_Test_Complex128 *)_from;
    TP_Test_Complex128 *to = (TP_Test_Complex128 *)_to;
    {
        extern void __TP_Test_Complex128Seq__copyOut(void *, void *);
        __TP_Test_Complex128Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex256__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex256 *from = (struct _TP_Test_Complex256 *)_from;
    TP_Test_Complex256 *to = (TP_Test_Complex256 *)_to;
    {
        extern void __TP_Test_Complex256Seq__copyOut(void *, void *);
        __TP_Test_Complex256Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex512__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex512 *from = (struct _TP_Test_Complex512 *)_from;
    TP_Test_Complex512 *to = (TP_Test_Complex512 *)_to;
    {
        extern void __TP_Test_Complex512Seq__copyOut(void *, void *);
        __TP_Test_Complex512Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex1024__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex1024 *from = (struct _TP_Test_Complex1024 *)_from;
    TP_Test_Complex1024 *to = (TP_Test_Complex1024 *)_to;
    {
        extern void __TP_Test_Complex1024Seq__copyOut(void *, void *);
        __TP_Test_Complex1024Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex2048__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex2048 *from = (struct _TP_Test_Complex2048 *)_from;
    TP_Test_Complex2048 *to = (TP_Test_Complex2048 *)_to;
    {
        extern void __TP_Test_Complex2048Seq__copyOut(void *, void *);
        __TP_Test_Complex2048Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex4096__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex4096 *from = (struct _TP_Test_Complex4096 *)_from;
    TP_Test_Complex4096 *to = (TP_Test_Complex4096 *)_to;
    {
        extern void __TP_Test_Complex4096Seq__copyOut(void *, void *);
        __TP_Test_Complex4096Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex8192__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex8192 *from = (struct _TP_Test_Complex8192 *)_from;
    TP_Test_Complex8192 *to = (TP_Test_Complex8192 *)_to;
    {
        extern void __TP_Test_Complex8192Seq__copyOut(void *, void *);
        __TP_Test_Complex8192Seq__copyOut(&from->data, &to->data);
    }
}

void
__TP_Test_Complex16384__copyOut(void *_from, void *_to)
{
    struct _TP_Test_Complex16384 *from = (struct _TP_Test_Complex16384 *)_from;
    TP_Test_Complex16384 *to = (TP_Test_Complex16384 *)_to;
    {
        extern void __TP_Test_Complex16384Seq__copyOut(void *, void *);
        __TP_Test_Complex16384Seq__copyOut(&from->data, &to->data);
    }
}

#include <dds_dcps_private.h>

TP_Test_QuitMsg *TP_Test_QuitMsg__alloc (void)
{
    return (TP_Test_QuitMsg *)DDS__malloc (NULL, 0, sizeof(TP_Test_QuitMsg));
}

DDS_sequence_octet *DDS_sequence_octet__alloc (void)
{
    return (DDS_sequence_octet *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_octet));
}

DDS_octet *DDS_sequence_octet_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_allocbuf (NULL, sizeof (DDS_octet), len);
}

TP_Test_Bytes4Seq *TP_Test_Bytes4Seq__alloc (void)
{
    return (TP_Test_Bytes4Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes4Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes8Seq *TP_Test_Bytes8Seq__alloc (void)
{
    return (TP_Test_Bytes8Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes8Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes16Seq *TP_Test_Bytes16Seq__alloc (void)
{
    return (TP_Test_Bytes16Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes16Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes32Seq *TP_Test_Bytes32Seq__alloc (void)
{
    return (TP_Test_Bytes32Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes32Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes64Seq *TP_Test_Bytes64Seq__alloc (void)
{
    return (TP_Test_Bytes64Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes64Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes128Seq *TP_Test_Bytes128Seq__alloc (void)
{
    return (TP_Test_Bytes128Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes128Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes256Seq *TP_Test_Bytes256Seq__alloc (void)
{
    return (TP_Test_Bytes256Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes256Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes512Seq *TP_Test_Bytes512Seq__alloc (void)
{
    return (TP_Test_Bytes512Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes512Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes1024Seq *TP_Test_Bytes1024Seq__alloc (void)
{
    return (TP_Test_Bytes1024Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes1024Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes2048Seq *TP_Test_Bytes2048Seq__alloc (void)
{
    return (TP_Test_Bytes2048Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes2048Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes4096Seq *TP_Test_Bytes4096Seq__alloc (void)
{
    return (TP_Test_Bytes4096Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes4096Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes8192Seq *TP_Test_Bytes8192Seq__alloc (void)
{
    return (TP_Test_Bytes8192Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes8192Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes16384Seq *TP_Test_Bytes16384Seq__alloc (void)
{
    return (TP_Test_Bytes16384Seq *)DDS_sequence_octet__alloc ();
}

DDS_octet *TP_Test_Bytes16384Seq_allocbuf (DDS_unsigned_long len)
{
    return (DDS_octet *)DDS_sequence_octet_allocbuf(len);
}

TP_Test_Bytes4 *TP_Test_Bytes4__alloc (void)
{
    void TP_Test_Bytes4__free (void *object);

    return (TP_Test_Bytes4 *)DDS__malloc (TP_Test_Bytes4__free, 0, sizeof(TP_Test_Bytes4));
}

void TP_Test_Bytes4__free (void *object)
{
    TP_Test_Bytes4 *o = (TP_Test_Bytes4 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes8 *TP_Test_Bytes8__alloc (void)
{
    void TP_Test_Bytes8__free (void *object);

    return (TP_Test_Bytes8 *)DDS__malloc (TP_Test_Bytes8__free, 0, sizeof(TP_Test_Bytes8));
}

void TP_Test_Bytes8__free (void *object)
{
    TP_Test_Bytes8 *o = (TP_Test_Bytes8 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes16 *TP_Test_Bytes16__alloc (void)
{
    void TP_Test_Bytes16__free (void *object);

    return (TP_Test_Bytes16 *)DDS__malloc (TP_Test_Bytes16__free, 0, sizeof(TP_Test_Bytes16));
}

void TP_Test_Bytes16__free (void *object)
{
    TP_Test_Bytes16 *o = (TP_Test_Bytes16 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes32 *TP_Test_Bytes32__alloc (void)
{
    void TP_Test_Bytes32__free (void *object);

    return (TP_Test_Bytes32 *)DDS__malloc (TP_Test_Bytes32__free, 0, sizeof(TP_Test_Bytes32));
}

void TP_Test_Bytes32__free (void *object)
{
    TP_Test_Bytes32 *o = (TP_Test_Bytes32 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes64 *TP_Test_Bytes64__alloc (void)
{
    void TP_Test_Bytes64__free (void *object);

    return (TP_Test_Bytes64 *)DDS__malloc (TP_Test_Bytes64__free, 0, sizeof(TP_Test_Bytes64));
}

void TP_Test_Bytes64__free (void *object)
{
    TP_Test_Bytes64 *o = (TP_Test_Bytes64 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes128 *TP_Test_Bytes128__alloc (void)
{
    void TP_Test_Bytes128__free (void *object);

    return (TP_Test_Bytes128 *)DDS__malloc (TP_Test_Bytes128__free, 0, sizeof(TP_Test_Bytes128));
}

void TP_Test_Bytes128__free (void *object)
{
    TP_Test_Bytes128 *o = (TP_Test_Bytes128 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes256 *TP_Test_Bytes256__alloc (void)
{
    void TP_Test_Bytes256__free (void *object);

    return (TP_Test_Bytes256 *)DDS__malloc (TP_Test_Bytes256__free, 0, sizeof(TP_Test_Bytes256));
}

void TP_Test_Bytes256__free (void *object)
{
    TP_Test_Bytes256 *o = (TP_Test_Bytes256 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes512 *TP_Test_Bytes512__alloc (void)
{
    void TP_Test_Bytes512__free (void *object);

    return (TP_Test_Bytes512 *)DDS__malloc (TP_Test_Bytes512__free, 0, sizeof(TP_Test_Bytes512));
}

void TP_Test_Bytes512__free (void *object)
{
    TP_Test_Bytes512 *o = (TP_Test_Bytes512 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes1024 *TP_Test_Bytes1024__alloc (void)
{
    void TP_Test_Bytes1024__free (void *object);

    return (TP_Test_Bytes1024 *)DDS__malloc (TP_Test_Bytes1024__free, 0, sizeof(TP_Test_Bytes1024));
}

void TP_Test_Bytes1024__free (void *object)
{
    TP_Test_Bytes1024 *o = (TP_Test_Bytes1024 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes2048 *TP_Test_Bytes2048__alloc (void)
{
    void TP_Test_Bytes2048__free (void *object);

    return (TP_Test_Bytes2048 *)DDS__malloc (TP_Test_Bytes2048__free, 0, sizeof(TP_Test_Bytes2048));
}

void TP_Test_Bytes2048__free (void *object)
{
    TP_Test_Bytes2048 *o = (TP_Test_Bytes2048 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes4096 *TP_Test_Bytes4096__alloc (void)
{
    void TP_Test_Bytes4096__free (void *object);

    return (TP_Test_Bytes4096 *)DDS__malloc (TP_Test_Bytes4096__free, 0, sizeof(TP_Test_Bytes4096));
}

void TP_Test_Bytes4096__free (void *object)
{
    TP_Test_Bytes4096 *o = (TP_Test_Bytes4096 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes8192 *TP_Test_Bytes8192__alloc (void)
{
    void TP_Test_Bytes8192__free (void *object);

    return (TP_Test_Bytes8192 *)DDS__malloc (TP_Test_Bytes8192__free, 0, sizeof(TP_Test_Bytes8192));
}

void TP_Test_Bytes8192__free (void *object)
{
    TP_Test_Bytes8192 *o = (TP_Test_Bytes8192 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Bytes16384 *TP_Test_Bytes16384__alloc (void)
{
    void TP_Test_Bytes16384__free (void *object);

    return (TP_Test_Bytes16384 *)DDS__malloc (TP_Test_Bytes16384__free, 0, sizeof(TP_Test_Bytes16384));
}

void TP_Test_Bytes16384__free (void *object)
{
    TP_Test_Bytes16384 *o = (TP_Test_Bytes16384 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Nested *TP_Test_Nested__alloc (void)
{
    void TP_Test_Nested__free (void *object);

    return (TP_Test_Nested *)DDS__malloc (TP_Test_Nested__free, 0, sizeof(TP_Test_Nested));
}

void TP_Test_Nested__free (void *object)
{
    TP_Test_Nested *o = (TP_Test_Nested *)object;

    DDS_string_clean (&o->info);
}

DDS_sequence_TP_Test_Nested *DDS_sequence_TP_Test_Nested__alloc (void)
{
    return (DDS_sequence_TP_Test_Nested *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_TP_Test_Nested));
}

TP_Test_Nested *DDS_sequence_TP_Test_Nested_allocbuf (DDS_unsigned_long len)
{
    void DDS_sequence_TP_Test_Nested_freebuf (void *buffer);

    return (TP_Test_Nested *)DDS_sequence_allocbuf (DDS_sequence_TP_Test_Nested_freebuf, sizeof (TP_Test_Nested), len);
}

void DDS_sequence_TP_Test_Nested_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    TP_Test_Nested *b = (TP_Test_Nested *)buffer;
    DDS_unsigned_long i;
    void TP_Test_Nested__free (void *object);

    for (i = 0; i < *count; i++) {
        TP_Test_Nested__free (&b[i]);
    }
}

TP_Test_NestedSeq *TP_Test_NestedSeq__alloc (void)
{
    return (TP_Test_NestedSeq *)DDS_sequence_TP_Test_Nested__alloc ();
}

TP_Test_Nested *TP_Test_NestedSeq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Nested *)DDS_sequence_TP_Test_Nested_allocbuf(len);
}

TP_Test_Outer *TP_Test_Outer__alloc (void)
{
    void TP_Test_Outer__free (void *object);

    return (TP_Test_Outer *)DDS__malloc (TP_Test_Outer__free, 0, sizeof(TP_Test_Outer));
}

void TP_Test_Outer__free (void *object)
{
    TP_Test_Outer *o = (TP_Test_Outer *)object;

    DDS_sequence_clean (&o->nested_member);
}

DDS_sequence_TP_Test_Outer *DDS_sequence_TP_Test_Outer__alloc (void)
{
    return (DDS_sequence_TP_Test_Outer *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_TP_Test_Outer));
}

TP_Test_Outer *DDS_sequence_TP_Test_Outer_allocbuf (DDS_unsigned_long len)
{
    void DDS_sequence_TP_Test_Outer_freebuf (void *buffer);

    return (TP_Test_Outer *)DDS_sequence_allocbuf (DDS_sequence_TP_Test_Outer_freebuf, sizeof (TP_Test_Outer), len);
}

void DDS_sequence_TP_Test_Outer_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    TP_Test_Outer *b = (TP_Test_Outer *)buffer;
    DDS_unsigned_long i;
    void TP_Test_Outer__free (void *object);

    for (i = 0; i < *count; i++) {
        TP_Test_Outer__free (&b[i]);
    }
}

TP_Test_Complex4Seq *TP_Test_Complex4Seq__alloc (void)
{
    return (TP_Test_Complex4Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex4Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex8Seq *TP_Test_Complex8Seq__alloc (void)
{
    return (TP_Test_Complex8Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex8Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex16Seq *TP_Test_Complex16Seq__alloc (void)
{
    return (TP_Test_Complex16Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex16Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex32Seq *TP_Test_Complex32Seq__alloc (void)
{
    return (TP_Test_Complex32Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex32Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex64Seq *TP_Test_Complex64Seq__alloc (void)
{
    return (TP_Test_Complex64Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex64Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex128Seq *TP_Test_Complex128Seq__alloc (void)
{
    return (TP_Test_Complex128Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex128Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex256Seq *TP_Test_Complex256Seq__alloc (void)
{
    return (TP_Test_Complex256Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex256Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex512Seq *TP_Test_Complex512Seq__alloc (void)
{
    return (TP_Test_Complex512Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex512Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex1024Seq *TP_Test_Complex1024Seq__alloc (void)
{
    return (TP_Test_Complex1024Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex1024Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex2048Seq *TP_Test_Complex2048Seq__alloc (void)
{
    return (TP_Test_Complex2048Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex2048Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex4096Seq *TP_Test_Complex4096Seq__alloc (void)
{
    return (TP_Test_Complex4096Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex4096Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex8192Seq *TP_Test_Complex8192Seq__alloc (void)
{
    return (TP_Test_Complex8192Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex8192Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex16384Seq *TP_Test_Complex16384Seq__alloc (void)
{
    return (TP_Test_Complex16384Seq *)DDS_sequence_TP_Test_Outer__alloc ();
}

TP_Test_Outer *TP_Test_Complex16384Seq_allocbuf (DDS_unsigned_long len)
{
    return (TP_Test_Outer *)DDS_sequence_TP_Test_Outer_allocbuf(len);
}

TP_Test_Complex4 *TP_Test_Complex4__alloc (void)
{
    void TP_Test_Complex4__free (void *object);

    return (TP_Test_Complex4 *)DDS__malloc (TP_Test_Complex4__free, 0, sizeof(TP_Test_Complex4));
}

void TP_Test_Complex4__free (void *object)
{
    TP_Test_Complex4 *o = (TP_Test_Complex4 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex8 *TP_Test_Complex8__alloc (void)
{
    void TP_Test_Complex8__free (void *object);

    return (TP_Test_Complex8 *)DDS__malloc (TP_Test_Complex8__free, 0, sizeof(TP_Test_Complex8));
}

void TP_Test_Complex8__free (void *object)
{
    TP_Test_Complex8 *o = (TP_Test_Complex8 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex16 *TP_Test_Complex16__alloc (void)
{
    void TP_Test_Complex16__free (void *object);

    return (TP_Test_Complex16 *)DDS__malloc (TP_Test_Complex16__free, 0, sizeof(TP_Test_Complex16));
}

void TP_Test_Complex16__free (void *object)
{
    TP_Test_Complex16 *o = (TP_Test_Complex16 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex32 *TP_Test_Complex32__alloc (void)
{
    void TP_Test_Complex32__free (void *object);

    return (TP_Test_Complex32 *)DDS__malloc (TP_Test_Complex32__free, 0, sizeof(TP_Test_Complex32));
}

void TP_Test_Complex32__free (void *object)
{
    TP_Test_Complex32 *o = (TP_Test_Complex32 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex64 *TP_Test_Complex64__alloc (void)
{
    void TP_Test_Complex64__free (void *object);

    return (TP_Test_Complex64 *)DDS__malloc (TP_Test_Complex64__free, 0, sizeof(TP_Test_Complex64));
}

void TP_Test_Complex64__free (void *object)
{
    TP_Test_Complex64 *o = (TP_Test_Complex64 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex128 *TP_Test_Complex128__alloc (void)
{
    void TP_Test_Complex128__free (void *object);

    return (TP_Test_Complex128 *)DDS__malloc (TP_Test_Complex128__free, 0, sizeof(TP_Test_Complex128));
}

void TP_Test_Complex128__free (void *object)
{
    TP_Test_Complex128 *o = (TP_Test_Complex128 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex256 *TP_Test_Complex256__alloc (void)
{
    void TP_Test_Complex256__free (void *object);

    return (TP_Test_Complex256 *)DDS__malloc (TP_Test_Complex256__free, 0, sizeof(TP_Test_Complex256));
}

void TP_Test_Complex256__free (void *object)
{
    TP_Test_Complex256 *o = (TP_Test_Complex256 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex512 *TP_Test_Complex512__alloc (void)
{
    void TP_Test_Complex512__free (void *object);

    return (TP_Test_Complex512 *)DDS__malloc (TP_Test_Complex512__free, 0, sizeof(TP_Test_Complex512));
}

void TP_Test_Complex512__free (void *object)
{
    TP_Test_Complex512 *o = (TP_Test_Complex512 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex1024 *TP_Test_Complex1024__alloc (void)
{
    void TP_Test_Complex1024__free (void *object);

    return (TP_Test_Complex1024 *)DDS__malloc (TP_Test_Complex1024__free, 0, sizeof(TP_Test_Complex1024));
}

void TP_Test_Complex1024__free (void *object)
{
    TP_Test_Complex1024 *o = (TP_Test_Complex1024 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex2048 *TP_Test_Complex2048__alloc (void)
{
    void TP_Test_Complex2048__free (void *object);

    return (TP_Test_Complex2048 *)DDS__malloc (TP_Test_Complex2048__free, 0, sizeof(TP_Test_Complex2048));
}

void TP_Test_Complex2048__free (void *object)
{
    TP_Test_Complex2048 *o = (TP_Test_Complex2048 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex4096 *TP_Test_Complex4096__alloc (void)
{
    void TP_Test_Complex4096__free (void *object);

    return (TP_Test_Complex4096 *)DDS__malloc (TP_Test_Complex4096__free, 0, sizeof(TP_Test_Complex4096));
}

void TP_Test_Complex4096__free (void *object)
{
    TP_Test_Complex4096 *o = (TP_Test_Complex4096 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex8192 *TP_Test_Complex8192__alloc (void)
{
    void TP_Test_Complex8192__free (void *object);

    return (TP_Test_Complex8192 *)DDS__malloc (TP_Test_Complex8192__free, 0, sizeof(TP_Test_Complex8192));
}

void TP_Test_Complex8192__free (void *object)
{
    TP_Test_Complex8192 *o = (TP_Test_Complex8192 *)object;

    DDS_sequence_clean (&o->data);
}

TP_Test_Complex16384 *TP_Test_Complex16384__alloc (void)
{
    void TP_Test_Complex16384__free (void *object);

    return (TP_Test_Complex16384 *)DDS__malloc (TP_Test_Complex16384__free, 0, sizeof(TP_Test_Complex16384));
}

void TP_Test_Complex16384__free (void *object)
{
    TP_Test_Complex16384 *o = (TP_Test_Complex16384 *)object;

    DDS_sequence_clean (&o->data);
}

const char * TP_Test_QuitMsg_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"QuitMsg\"><Member name=\"quit\"><Boolean/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes4_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes4Seq\"><Sequence size=\"4\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes4\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes4Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes8_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes8Seq\"><Sequence size=\"8\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes8\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes8Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes16_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes16Seq\"><Sequence size=\"16\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes16\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes16Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes32_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes32Seq\"><Sequence size=\"32\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes32\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes32Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes64_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes64Seq\"><Sequence size=\"64\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes64\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes64Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes128_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes128Seq\"><Sequence size=\"128\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes128\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes128Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes256_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes256Seq\"><Sequence size=\"256\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes256\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes256Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes512_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes512Seq\"><Sequence size=\"512\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes512\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes512Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes1024_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes1024Seq\"><Sequence size=\"1024\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes1024\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes1024Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes2048_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes2048Seq\"><Sequence size=\"2048\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes2048\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes2048Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes4096_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes4096Seq\"><Sequence size=\"4096\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes4096\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes4096Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes8192_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes8192Seq\"><Sequence size=\"8192\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes8192\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes8192Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Bytes16384_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes16384Seq\"><Sequence size=\"16384\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes16384\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes16384Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex4_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex4Seq\"><Sequence size=\"4\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex4\"><Member name=\"data\"><Type name=\"TP_Test::Complex4Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex8_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex8Seq\"><Sequence size=\"8\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex8\"><Member name=\"data\"><Type name=\"TP_Test::Complex8Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex16_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex16Seq\"><Sequence size=\"16\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex16\"><Member name=\"data\"><Type name=\"TP_Test::Complex16Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex32_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex32Seq\"><Sequence size=\"32\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex32\"><Member name=\"data\"><Type name=\"TP_Test::Complex32Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex64_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex64Seq\"><Sequence size=\"64\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex64\"><Member name=\"data\"><Type name=\"TP_Test::Complex64Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex128_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex128Seq\"><Sequence size=\"128\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex128\"><Member name=\"data\"><Type name=\"TP_Test::Complex128Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex256_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex256Seq\"><Sequence size=\"256\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex256\"><Member name=\"data\"><Type name=\"TP_Test::Complex256Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex512_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex512Seq\"><Sequence size=\"512\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex512\"><Member name=\"data\"><Type name=\"TP_Test::Complex512Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex1024_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex1024Seq\"><Sequence size=\"1024\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex1024\"><Member name=\"data\"><Type name=\"TP_Test::Complex1024Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex2048_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex2048Seq\"><Sequence size=\"2048\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex2048\"><Member name=\"data\"><Type name=\"TP_Test::Complex2048Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex4096_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex4096Seq\"><Sequence size=\"4096\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex4096\"><Member name=\"data\"><Type name=\"TP_Test::Complex4096Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex8192_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex8192Seq\"><Sequence size=\"8192\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex8192\"><Member name=\"data\"><Type name=\"TP_Test::Complex8192Seq\"/></Member></Struct></Module></MetaData>";
const char * TP_Test_Complex16384_metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSeq\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSeq\"/></Member></Struct><TypeDef name=\"Complex16384Seq\"><Sequence size=\"16384\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex16384\"><Member name=\"data\"><Type name=\"TP_Test::Complex16384Seq\"/></Member></Struct></Module></MetaData>";
#if defined (__cplusplus)
}
#endif
