#ifndef PROJ_H
#define PROJ_H


# include "osqp.h"
# include "types.h"
# include "lin_alg.h"


/**
 * Project z onto \f$C = [l, u]\f$
 * @param z  Vector to project
 * @param l  Lower bound vector
 * @param u  Upper bound vector
 */
void project(OSQPVectorf*       z,
             const OSQPVectorf* l,
             const OSQPVectorf* u);

/**
 * Project y onto the polar of the recession cone of \f$C = [l, u]\f$
 * @param y       Vector to project
 * @param l       Lower bound vector
 * @param u       Upper bound vector
 * @param infval  Positive value treated as infinity
 */
 void project_polar_reccone(OSQPVectorf*       y,
                            const OSQPVectorf* l,
                            const OSQPVectorf* u,
                            OSQPFloat          infval);
/**
 * Test whether y is in the recession cone of \f$C = [l, u]\f$
 * @param y       Vector to project
 * @param l       Lower bound vector
 * @param u       Upper bound vector
 * @param infval  Positive value treated as infinity
 * @param tol     Values in y within tol of zero are treated as zero
 */
OSQPInt test_in_reccone(const OSQPVectorf* y,
                        const OSQPVectorf* l,
                        const OSQPVectorf* u,
                        OSQPFloat          infval,
                        OSQPFloat          tol);

#ifndef OSQP_EMBEDDED_MODE

/**
 * Ensure z is in C = [l,u] and y is in the normal cone of C at z
 * @param z  Primal variable z
 * @param y  Dual variable y
 * @param l  Lower bound vector
 * @param u  Upper bound vector
 */
void project_normalcone(OSQPVectorf*       z,
                        OSQPVectorf*       y,
                        const OSQPVectorf* l,
                        const OSQPVectorf* u);

# endif /* ifndef OSQP_EMBEDDED_MODE */


#endif /* ifndef PROJ_H */