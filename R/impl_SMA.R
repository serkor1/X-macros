#' @export
SMA <- function(x, n) {
    .Call(
        C_impl_SMA,
        as.double(x),
        as.integer(n)
    )
}
