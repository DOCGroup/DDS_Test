// -*- C++ -*-
//
// $Id: dds_config_file.h,v 1.1 2006/04/06 21:55:48 mxiong Exp $

#ifndef DDS_CONFIG_FILE_H
#define DDS_CONFIG_FILE_H

#include <string>
#include <iostream>
#include <map>

class DDS_Config_File {

public:

  DDS_Config_File( std::istream& in );

  const char * DDS_Config_File::get( std::string name ) const;

private:

  void parseLine( std::string line, unsigned count );

  std::map<std::string, std::string> parsed_;
};

#endif /* DDS_CONFIG_FILE_H */

