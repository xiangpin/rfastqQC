// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// StatRead_cpp
Rcpp::List StatRead_cpp(std::string sample, std::string readfile, Nullable<StringVector> Type);
RcppExport SEXP _rfastqQC_StatRead_cpp(SEXP sampleSEXP, SEXP readfileSEXP, SEXP TypeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type sample(sampleSEXP);
    Rcpp::traits::input_parameter< std::string >::type readfile(readfileSEXP);
    Rcpp::traits::input_parameter< Nullable<StringVector> >::type Type(TypeSEXP);
    rcpp_result_gen = Rcpp::wrap(StatRead_cpp(sample, readfile, Type));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_rfastqQC_StatRead_cpp", (DL_FUNC) &_rfastqQC_StatRead_cpp, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_rfastqQC(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
