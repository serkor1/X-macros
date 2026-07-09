#' @export
SMA <- function(x, n) {
    .Call(
        C_impl_SMA,
        as.double(x),
        as.integer(n)
    )
}

#' @export
EMA <- function(x, n) {
    .Call(
        C_impl_EMA,
        as.double(x),
        as.integer(n)
    )
}

#' @export
WMA <- function(x, n) {
    .Call(
        C_impl_WMA,
        as.double(x),
        as.integer(n)
    )
}
