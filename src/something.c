#include "lib.h"

// X is a generic placeholder
// for any macro defined elsewhere
#define X(R_api, Upstream)                                                              \
    SEXP R_api(                                                                         \
        SEXP input,                                                                     \
        SEXP n                                                                          \
    ) {                                                                                 \
        double *input_ptr    = REAL(input);                                             \
        const int input_size = LENGTH(input);                                           \
        const int window     = INTEGER(n)[0];                                           \
                                                                                        \
        vector in = { ._data_ = input_ptr, ._size_ = (size_t) input_size };             \
                                                                                        \
        SEXP output = PROTECT(allocVector(REALSXP, input_size));                        \
        vector out  = { ._data_ = REAL(output), ._size_ = (size_t) input_size };        \
                                                                                        \
        Upstream(in, out, (size_t) window);                                             \
                                                                                        \
        UNPROTECT(1);                                                                   \
        return output;                                                                  \
}
MA_REGISTRY // This allows the generic to be called                                       
#undef X 

// NOTE: #FOO --> "FOO", FOO##BAR --> "FOOBAR"
static const R_CallMethodDef CallEntries[] = {
#define X(R_api, Upstream) { #R_api, (DL_FUNC) &R_api, 2 },
    MA_REGISTRY
#undef X
    { NULL, NULL, 0 }
};

void R_init_pkg(DllInfo *info) {
    R_registerRoutines(info, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(info, FALSE);
}
