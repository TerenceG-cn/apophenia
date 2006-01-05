#include <gsl/gsl_sf_log.h>
#include <gsl/gsl_sf_exp.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>
#include <apophenia/types.h>

gsl_matrix *apop_covariance_matrix(gsl_matrix *in, int normalize);
apop_data * apop_data_covariance_matrix(apop_data *in, int normalize);
apop_data * apop_data_covariance_matrix(apop_data *in, int normalize);
apop_data * apop_data_correlation_matrix(apop_data *in);
double      apop_det_and_inv(gsl_matrix *in, gsl_matrix **out, int calc_det, int calc_inv);
double      apop_x_prime_sigma_x(gsl_vector *x, gsl_matrix *sigma);
void        apop_sv_decomposition(gsl_matrix *data, int dimensions_we_want, gsl_matrix ** pc_space, gsl_vector **eigenvalues);
inline void apop_vector_increment(gsl_vector * v, int i, double amt);
inline void apop_matrix_increment(gsl_matrix * m, int i, int j, double amt);
gsl_matrix *apop_matrix_stack(gsl_matrix *m1, gsl_matrix * m2, char posn);
gsl_matrix *apop_matrix_rm_columns(gsl_matrix *in, int *drop);
