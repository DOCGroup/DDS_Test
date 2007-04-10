#ifndef SETTINGTYPES_H_
#define SETTINGTYPES_H_


typedef char *SettingNameType;

typedef char *TypeNameType;
typedef char *PartitionExpressionType;

typedef enum ActorKind_e {
    ACTOR_UNKNOWN,
    ACTOR_SOURCE,
    ACTOR_REFLECTOR,
    ACTOR_SINK
} ActorKind;

typedef enum ReliabilityKind_e {
    RELIABILITY_UNKNOWN,
    RELIABILITY_BESTEFFORT,
    RELIABILITY_RELIABLE
} ReliabilityKind;

typedef enum DurabilityKind_e {
    DURABILITY_UNKNOWN,
    DURABILITY_VOLATILE,
    DURABILITY_TRANSIENT_LOCAL,
    DURABILITY_TRANSIENT,
    DURABILITY_PERSISTENT
} DurabilityKind;

typedef unsigned int UrgencyType;
typedef unsigned int ImportanceType;

#endif /*SETTINGTYPES_H_*/
