/*
 * Compute the posterior of mixture of univariate Gaussian distributions
 *
 * Date: June 22, 2012
 *   Revised: May 08, 2014
 *
 * Author: Jiarui Ding <jiaruid@cs.ubc.ca>
 *   Department of Computer Science, UBC
 *   Department of Molecular Oncology, BC Cancer Agency 
 */

#include "xseq.h"
#define NUM_RETURN  3

SEXP sexp_mix_gauss_prob(SEXP s_x, SEXP s_lambda, SEXP s_mu, SEXP s_sigma) {
  double* x      = NUMERIC_POINTER(s_x);
  double* lambda = NUMERIC_POINTER(s_lambda);
  double* mu     = NUMERIC_POINTER(s_mu);
  double* sigma  = NUMERIC_POINTER(s_sigma);
  

  PROTECT(s_x      = AS_NUMERIC(s_x));
  PROTECT(s_lambda = AS_NUMERIC(s_lambda));
  PROTECT(s_mu     = AS_NUMERIC(s_mu));
  PROTECT(s_sigma  = AS_NUMERIC(s_sigma));

  size_t K = LENGTH(s_mu), n = LENGTH(s_x);
  
  // return values
  SEXP s_res, s_post, s_loglik;
  PROTECT(s_res    = allocMatrix(REALSXP, n, K));
  PROTECT(s_post   = allocMatrix(REALSXP, n, K));
  PROTECT(s_loglik = NEW_NUMERIC(1));
  
  double* res    = NUMERIC_POINTER(s_res);
  double* post   = NUMERIC_POINTER(s_post);
  double* loglik = NUMERIC_POINTER(s_loglik);
  
  mix_gauss_prob(res, post, loglik, x, K, lambda, mu, sigma, n);
  
  // return a list
  SEXP list, list_name;
  char *name[NUM_RETURN] = {"res", "post", "loglik"};
  
  PROTECT(list_name=allocVector(STRSXP, NUM_RETURN));
  for (size_t i=0; i<NUM_RETURN; i++) {
    SET_STRING_ELT(list_name, i, mkChar(name[i]));
  }
  PROTECT(list=allocVector(VECSXP, NUM_RETURN));
  SET_VECTOR_ELT(list, 0, s_res); 
  SET_VECTOR_ELT(list, 1, s_post);
  SET_VECTOR_ELT(list, 2, s_loglik);
  setAttrib(list, R_NamesSymbol, list_name);
  
  UNPROTECT(9);
  return(list);             
}


void mix_gauss_prob(double* res, double* post, double* loglik, 
  const double* x, const size_t K, const double* lambda, 
  const double* mu, const double* sigma, const size_t N) 
{
  size_t i = 0, j = 0, idx = 0;
  double mu_centered       = 0;
  double max_prob_point    = 0;
  double norm_prob_point   = 0;
	
  double* lambda_sigma = malloc(K * sizeof(double));
  if(NULL == lambda_sigma) {
    return;
  }
	
  double* log_lambda_sigma = malloc(K * sizeof(double));
  if(NULL == log_lambda_sigma) {
    return;
  }
	
  double* post_prob_point = malloc(K * sizeof(double));
  if(NULL == post_prob_point) {
    return;
  }
	
  /* For mixture components */
  for (j=0; j<K; j++){
    log_lambda_sigma[j] = log(lambda[j]) - log(sigma[j]);
    lambda_sigma[j] = exp(log_lambda_sigma[j]);
		/*printf("%lf\n", lambda_sigma[j]);*/
  }
	
  /* For the exact post-probabilities */
  *loglik = -0.5 * N * log(2*M_PI);
	
  /* For each point */
  for (i=0; i<N; i++) {
    for (j=0; j<K; j++) {
      mu_centered = x[i] - mu[j];
      mu_centered = mu_centered * mu_centered;
			
      /* Useful intermedite results for the maximization step */
      res[i + N * j] = mu_centered;
      /* Protect data */
      post_prob_point[j] = mu_centered / (2.0 * sigma[j] * sigma[j]);
      if (j== 0 || max_prob_point > post_prob_point[j]) {
        max_prob_point = post_prob_point[j];
				idx = j;
      }
    }
    
    norm_prob_point = 0;
    for (j=0; j<K; j++) {
      if (idx == j) {
        post_prob_point[j] = 1;
      } else {
        post_prob_point[j] = lambda_sigma[j] / lambda_sigma[idx] *
				exp(max_prob_point - post_prob_point[j]);
      }
      norm_prob_point += post_prob_point[j];
    }
    /*printf("%lf\n", norm_prob_point);*/
		
    for (j=0; j<K; j++) {
      post[i + N * j] = post_prob_point[j] / norm_prob_point;
    }
    /* the loglik and the normalization term: normalization term times the 
		 loglik of the max */
    *loglik += log(norm_prob_point) + log_lambda_sigma[idx] - max_prob_point;
  }
	
  free(lambda_sigma);
  free(log_lambda_sigma);
  free(post_prob_point);
  
  lambda_sigma     = NULL;
  log_lambda_sigma = NULL;
  post_prob_point  = NULL;
	
  return;
}


