#ifndef _LIB_H_
#define _LIB_H_

// R Headers
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>

// ext-lib headers
#undef length // undefine the length macro from R's headers because the same macro is defined in the ext-lib
#include "MovingAverage.h"


#endif // _LIB_H_
