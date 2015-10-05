/*
 *
 * Date: 
 *   Revised: May 08, 2014
 * 
 */

#include <R.h>
#include <Rdefines.h>
#include <Rmath.h>

SEXP sexp_mix_gauss_prob(SEXP s_x, SEXP s_lambda, SEXP s_mu, SEXP s_sigma);
void mix_gauss_prob(double* res, double* post, double* loglik,
  const double* x, const size_t K, const double* lambda, 
  const double* mu, const double* sigma, const size_t N);

SEXP sexp_log_sum_exp(SEXP x);
double log_sum_exp(const double* x, const size_t n);

