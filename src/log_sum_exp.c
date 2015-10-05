/*
 * LogSumExp trick
 *
 * Date: May 07, 2014
 * 
 * Author: Jiarui Ding <jiaruid@cs.ubc.ca>
 *   Department of Computer Science, UBC
 *   Department of Molecular Oncology, BC Cancer Agency  
 */

#include "xseq.h"

SEXP sexp_log_sum_exp(SEXP s_x) {
  double *x = NULL;
  size_t n  = LENGTH(s_x);
  
  PROTECT(s_x = AS_NUMERIC(s_x));
  x = NUMERIC_POINTER(s_x);
  UNPROTECT(1);

  return(Rf_ScalarReal(log_sum_exp(x, n)));
}

double log_sum_exp(const double* x, const size_t n) {  
  double max_exp = x[0], res=0;
  size_t i=0, id_max=0;

  for (i=1; i<n; i++) {
    if (x[i] > max_exp) {
      id_max  = i;
      max_exp = x[i];
    }
  }

  for (i=0; i<n; i++) {
    if (i == id_max) {
      continue;
    }
    res += exp(x[i] - max_exp);
  }
  
  res = log1p(res) + max_exp;
  
  return(res);
}

