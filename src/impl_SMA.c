#include "lib.h"
#include "SMA.h"

SEXP impl_SMA(
    SEXP input,
    SEXP n
)
{
    // values
    double *input_ptr    = REAL(input);
    const int input_size = LENGTH(input);
    const int window     = INTEGER(n)[0];

    vector in = { ._data_ = input_ptr, ._size_ = (size_t) input_size };

    SEXP output = PROTECT(allocVector(REALSXP, input_size));
    vector out  = { ._data_ = REAL(output), ._size_ = (size_t) input_size };

    SMA(in, out, (size_t) window);

    UNPROTECT(1);
    return output;
}

