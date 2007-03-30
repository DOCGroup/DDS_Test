//******************************************************************
// 
//  Generated by e*ORB IDL to C++ Translator
//  Copyright (c) PrismTech Limited 2006
//  
//  File name: deepTypesDcps.cpp
//  Source: deepTypesDcps.idl
//  Generated: Fri Mar 30 14:15:43 2007
//  OpenFusion eORB C++ V1.5.0
//  
//  All Rights Reserved
//  
//******************************************************************

#include "deepTypesDcps.h"

char * deepTypes::simpleTypeTypeSupportInterface::_local_rep_id_string = "IDL:deepTypes/simpleTypeTypeSupportInterface:1.0";

deepTypes::simpleTypeTypeSupportInterface_ptr deepTypes::simpleTypeTypeSupportInterface::_duplicate (deepTypes::simpleTypeTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::simpleTypeTypeSupportInterface::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::simpleTypeTypeSupportInterface::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::simpleTypeTypeSupportInterface_ptr deepTypes::simpleTypeTypeSupportInterface::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::simpleTypeTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (deepTypes::simpleTypeTypeSupportInterface::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::simpleTypeTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::simpleTypeTypeSupportInterface_ptr deepTypes::simpleTypeTypeSupportInterface::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::simpleTypeTypeSupportInterface_ptr result = NULL;
   result = dynamic_cast<deepTypes::simpleTypeTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::simpleTypeDataWriter::_local_rep_id_string = "IDL:deepTypes/simpleTypeDataWriter:1.0";

deepTypes::simpleTypeDataWriter_ptr deepTypes::simpleTypeDataWriter::_duplicate (deepTypes::simpleTypeDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::simpleTypeDataWriter::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::simpleTypeDataWriter::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::simpleTypeDataWriter_ptr deepTypes::simpleTypeDataWriter::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::simpleTypeDataWriter_ptr result = NULL;
   if (p && p->_is_a (deepTypes::simpleTypeDataWriter::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::simpleTypeDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::simpleTypeDataWriter_ptr deepTypes::simpleTypeDataWriter::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::simpleTypeDataWriter_ptr result = NULL;
   result = dynamic_cast<deepTypes::simpleTypeDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::simpleTypeDataReader::_local_rep_id_string = "IDL:deepTypes/simpleTypeDataReader:1.0";

deepTypes::simpleTypeDataReader_ptr deepTypes::simpleTypeDataReader::_duplicate (deepTypes::simpleTypeDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::simpleTypeDataReader::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::simpleTypeDataReader::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::simpleTypeDataReader_ptr deepTypes::simpleTypeDataReader::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::simpleTypeDataReader_ptr result = NULL;
   if (p && p->_is_a (deepTypes::simpleTypeDataReader::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::simpleTypeDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::simpleTypeDataReader_ptr deepTypes::simpleTypeDataReader::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::simpleTypeDataReader_ptr result = NULL;
   result = dynamic_cast<deepTypes::simpleTypeDataReader_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::nestedTypeTypeSupportInterface::_local_rep_id_string = "IDL:deepTypes/nestedTypeTypeSupportInterface:1.0";

deepTypes::nestedTypeTypeSupportInterface_ptr deepTypes::nestedTypeTypeSupportInterface::_duplicate (deepTypes::nestedTypeTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::nestedTypeTypeSupportInterface::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::nestedTypeTypeSupportInterface::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::nestedTypeTypeSupportInterface_ptr deepTypes::nestedTypeTypeSupportInterface::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::nestedTypeTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (deepTypes::nestedTypeTypeSupportInterface::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::nestedTypeTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::nestedTypeTypeSupportInterface_ptr deepTypes::nestedTypeTypeSupportInterface::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::nestedTypeTypeSupportInterface_ptr result = NULL;
   result = dynamic_cast<deepTypes::nestedTypeTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::nestedTypeDataWriter::_local_rep_id_string = "IDL:deepTypes/nestedTypeDataWriter:1.0";

deepTypes::nestedTypeDataWriter_ptr deepTypes::nestedTypeDataWriter::_duplicate (deepTypes::nestedTypeDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::nestedTypeDataWriter::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::nestedTypeDataWriter::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::nestedTypeDataWriter_ptr deepTypes::nestedTypeDataWriter::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::nestedTypeDataWriter_ptr result = NULL;
   if (p && p->_is_a (deepTypes::nestedTypeDataWriter::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::nestedTypeDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::nestedTypeDataWriter_ptr deepTypes::nestedTypeDataWriter::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::nestedTypeDataWriter_ptr result = NULL;
   result = dynamic_cast<deepTypes::nestedTypeDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::nestedTypeDataReader::_local_rep_id_string = "IDL:deepTypes/nestedTypeDataReader:1.0";

deepTypes::nestedTypeDataReader_ptr deepTypes::nestedTypeDataReader::_duplicate (deepTypes::nestedTypeDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::nestedTypeDataReader::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::nestedTypeDataReader::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::nestedTypeDataReader_ptr deepTypes::nestedTypeDataReader::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::nestedTypeDataReader_ptr result = NULL;
   if (p && p->_is_a (deepTypes::nestedTypeDataReader::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::nestedTypeDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::nestedTypeDataReader_ptr deepTypes::nestedTypeDataReader::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::nestedTypeDataReader_ptr result = NULL;
   result = dynamic_cast<deepTypes::nestedTypeDataReader_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::arrayTypeTypeSupportInterface::_local_rep_id_string = "IDL:deepTypes/arrayTypeTypeSupportInterface:1.0";

deepTypes::arrayTypeTypeSupportInterface_ptr deepTypes::arrayTypeTypeSupportInterface::_duplicate (deepTypes::arrayTypeTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::arrayTypeTypeSupportInterface::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::arrayTypeTypeSupportInterface::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::arrayTypeTypeSupportInterface_ptr deepTypes::arrayTypeTypeSupportInterface::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::arrayTypeTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (deepTypes::arrayTypeTypeSupportInterface::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::arrayTypeTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::arrayTypeTypeSupportInterface_ptr deepTypes::arrayTypeTypeSupportInterface::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::arrayTypeTypeSupportInterface_ptr result = NULL;
   result = dynamic_cast<deepTypes::arrayTypeTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::arrayTypeDataWriter::_local_rep_id_string = "IDL:deepTypes/arrayTypeDataWriter:1.0";

deepTypes::arrayTypeDataWriter_ptr deepTypes::arrayTypeDataWriter::_duplicate (deepTypes::arrayTypeDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::arrayTypeDataWriter::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::arrayTypeDataWriter::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::arrayTypeDataWriter_ptr deepTypes::arrayTypeDataWriter::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::arrayTypeDataWriter_ptr result = NULL;
   if (p && p->_is_a (deepTypes::arrayTypeDataWriter::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::arrayTypeDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::arrayTypeDataWriter_ptr deepTypes::arrayTypeDataWriter::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::arrayTypeDataWriter_ptr result = NULL;
   result = dynamic_cast<deepTypes::arrayTypeDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::arrayTypeDataReader::_local_rep_id_string = "IDL:deepTypes/arrayTypeDataReader:1.0";

deepTypes::arrayTypeDataReader_ptr deepTypes::arrayTypeDataReader::_duplicate (deepTypes::arrayTypeDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::arrayTypeDataReader::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::arrayTypeDataReader::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::arrayTypeDataReader_ptr deepTypes::arrayTypeDataReader::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::arrayTypeDataReader_ptr result = NULL;
   if (p && p->_is_a (deepTypes::arrayTypeDataReader::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::arrayTypeDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::arrayTypeDataReader_ptr deepTypes::arrayTypeDataReader::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::arrayTypeDataReader_ptr result = NULL;
   result = dynamic_cast<deepTypes::arrayTypeDataReader_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::stringTypeTypeSupportInterface::_local_rep_id_string = "IDL:deepTypes/stringTypeTypeSupportInterface:1.0";

deepTypes::stringTypeTypeSupportInterface_ptr deepTypes::stringTypeTypeSupportInterface::_duplicate (deepTypes::stringTypeTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::stringTypeTypeSupportInterface::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::stringTypeTypeSupportInterface::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::stringTypeTypeSupportInterface_ptr deepTypes::stringTypeTypeSupportInterface::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::stringTypeTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (deepTypes::stringTypeTypeSupportInterface::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::stringTypeTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::stringTypeTypeSupportInterface_ptr deepTypes::stringTypeTypeSupportInterface::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::stringTypeTypeSupportInterface_ptr result = NULL;
   result = dynamic_cast<deepTypes::stringTypeTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::stringTypeDataWriter::_local_rep_id_string = "IDL:deepTypes/stringTypeDataWriter:1.0";

deepTypes::stringTypeDataWriter_ptr deepTypes::stringTypeDataWriter::_duplicate (deepTypes::stringTypeDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::stringTypeDataWriter::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::stringTypeDataWriter::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::stringTypeDataWriter_ptr deepTypes::stringTypeDataWriter::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::stringTypeDataWriter_ptr result = NULL;
   if (p && p->_is_a (deepTypes::stringTypeDataWriter::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::stringTypeDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::stringTypeDataWriter_ptr deepTypes::stringTypeDataWriter::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::stringTypeDataWriter_ptr result = NULL;
   result = dynamic_cast<deepTypes::stringTypeDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

char * deepTypes::stringTypeDataReader::_local_rep_id_string = "IDL:deepTypes/stringTypeDataReader:1.0";

deepTypes::stringTypeDataReader_ptr deepTypes::stringTypeDataReader::_duplicate (deepTypes::stringTypeDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

CORBA::Boolean deepTypes::stringTypeDataReader::_local_is_a (const char * _id EORB_ENV_ARGN)
{
   if (strcmp (_id, deepTypes::stringTypeDataReader::_local_rep_id_string) == 0)
   {
      return TRUE;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id EORB_ENV_VARN))
   {
      return TRUE;
   }

   return FALSE;
}

deepTypes::stringTypeDataReader_ptr deepTypes::stringTypeDataReader::_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::stringTypeDataReader_ptr result = NULL;
   if (p && p->_is_a (deepTypes::stringTypeDataReader::_local_rep_id_string EORB_ENV_VARN))
   {
      result = dynamic_cast<deepTypes::stringTypeDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

deepTypes::stringTypeDataReader_ptr deepTypes::stringTypeDataReader::_unchecked_narrow (CORBA::Object_ptr p EORB_ENV_ARGN)
{
   deepTypes::stringTypeDataReader_ptr result = NULL;
   result = dynamic_cast<deepTypes::stringTypeDataReader_ptr> (p);
   result->m_count++;
   return result;
}




