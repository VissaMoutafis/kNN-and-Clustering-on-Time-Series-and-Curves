#pragma once

#include "CurveNearestNeighbours.hpp"

class DiscreteLSHSolver: public CurveNearestNeighboursSolver{
private:
    std::vector<DLSHHashingCurve> hs; // use the grid snappers, h's, to transform the curve into a vector 
    std::vector<NearestNeighboursSolver> solvers; // use one different solver for each h to estimate proximity between the grid solvers

public:
    DiscreteLSHSolver(std::list<Curve *> &dataset, uint32_t curve_L, uint32_t curve_delta, uint32_t curve_d);
    ~DiscreteLSHSolver();
    // Find N nearest neighbours of q. Returns list of <Curve *, dist from q>.
    std::list<CurveNeighbour> *kNearestNeighbours(const Curve &q, uint N = 1) final;
    // Find all neighbours in range R. Returns list of <Curve *, dist from q>.
    std::list<CurveNeighbour> *nearestNeighbours_w_rangeSearch(const Curve &q, double R = 10000.0) final;

};


