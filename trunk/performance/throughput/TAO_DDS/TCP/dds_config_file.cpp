// $Id$

#include "dds_config_file.h"
#include <string>
#include <iostream>

using namespace std;

namespace { 

  // replace throughout a string
  // supply 0 to new Char if you want to have the old char deleted
  // sort of like s/oldChar//g in perl

  void strreplace( std::string& target, char oldChar, char newChar )
  {
    string::size_type start = 0;
    string::size_type pos = 0;
    pos = target.find(oldChar,start);

    while( start < target.size() && pos != string::npos ) 
    {
      if( newChar != 0 )
      {
        target.replace(pos,1,&newChar);
        start = pos + 1;
      }
      else
      {
        target.erase(pos,1);
      }
      pos = target.find(oldChar,start);
    }
  }

  void lowercase( std::string& target )
  {
    for( size_t i = 0; i < target.size(); i++ )
    {
      target[i] = tolower(target[i]);
    }
  }

  void cleanup( std::string& line ) {
    std::string copy = line;
    unsigned begin = 0;
    while ( begin != line.size() && isspace( line[ begin ] ) ) ++begin;

    bool inQuote = false;
    unsigned end;
    for ( end = begin; end != line.size(); ++end ) {
      if ( line[ end ] == '\"' ) {
        inQuote = !inQuote;
      } else if ( line[ end ] == '#' && !inQuote ) {
        break;
      }
    }
    while ( end > begin && isspace( line[ end - 1 ] ) ) --end;
    line.assign( line, begin, end - begin );
  }


  string parseValue( string value ) {
    return value;
  }

}

void 
DDS_Config_File::parseLine( string line, unsigned count ) {
  unsigned equals = line.find( '=' );
  if ( equals == string::npos ) {
    std::cerr << "Could not parse line " << count << ", ignoring.\n";
    return;
  }

  string name( line, 0, equals );
  lowercase(name);
  strreplace(name,'_',0);

  parsed_[ name ] = parseValue( string( line, equals + 1, string::npos ) );
}

DDS_Config_File::DDS_Config_File( std::istream& in )
{
  unsigned count = 0;
  string line;

  while ( getline( in, line ) ) {
    ++count;
    cleanup( line );
    if ( line.empty() ) continue;
    parseLine( line, count );
  }
}

const char *
DDS_Config_File::get( std::string name ) const {

  std::map<std::string, std::string>::const_iterator iter
    = parsed_.find( name );
  if ( iter == parsed_.end() ) return "";

  return (iter->second).c_str ();
}
