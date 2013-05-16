#ifndef MACROS_H
#define MACROS_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <typeinfo>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

#define COUT std::cout
#define ENDL std::endl
#define STRG std::string
#define TAB  "       "
#define LINE "_________________________________________________" << ENDL

#define INFO( MESSAGE )                                         			\
COUT << STRG( __FILE__ ) << ":[" << ( __LINE__ ) << "]" <<      			\
ENDL << TAB << "* " << STRG( __FUNCTION__ ) << TAB <<          				\
STRG( MESSAGE ) << ENDL;

#endif // MACROS_H
