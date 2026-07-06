#include <R.h>
#include <R_ext/Rdynload.h>
#include "api.h"

#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}

static const R_CallMethodDef CallEntries[] = {
    CALLDEF(impl_SMA, 2),
    {NULL, NULL, 0}
};