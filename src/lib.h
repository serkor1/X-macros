#ifndef _LIB_H_
#define _LIB_H_

// R Headers
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>

// ext-lib headers
#undef length // undefine the length macro from R's headers because the same macro is defined in the ext-lib
#include "MovingAverage.h"

// This is a generic list
// that corresponds to a lapply
// named MA_REGISTRY --> It
// "loops" through all elements with
// the names with for each iteration
#define MA_REGISTRY  \
    X(impl_SMA, SMA) \
    X(impl_EMA, EMA) \
    X(impl_WMA, WMA)

#endif // _LIB_H_
