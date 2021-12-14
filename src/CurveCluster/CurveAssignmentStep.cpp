#include "ClusterSolverCurves.hpp"
#include "GenericLSHSolver.hpp"
#include "ReverseAssignment.hpp"

uint32_t reverse_assignment_lsh_curves(vector<CurveCentroid> &centroids,
                                list<Curve *> &dataset) {

    // query dataset is centroids, input dataset is the points in the cluster
    // TODO: change the defaults
    static  LSHSolver solver(dataset, 5, CLUSTERING_DELTA, dataset.front()->dimensions(), 0);
    
    return __reverse_assignment__<Curve, CurveCentroid, LSHSolver>(centroids, dataset, solver, R_MAX, unassigned_curves);
}