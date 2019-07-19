#ifndef BayesianSequence_hpp
#define BayesianSequence_hpp

#include <iostream>
#include "Observation.hpp"

/*
 BayesianSequence represents a sequence of observations of events that are calculated
 to predict the probability of another event.
 */
class BayesianSequence
{
public:
    
    BayesianSequence(double prior = 0.5);

    ~BayesianSequence();
    
    void set_prior(double probability);
    
    double probability() const;
    
    void add_observation(Observation * obs);
    
    double calculate();
    
private:
    
    // The first observation in this sequence.
    Observation             *   _start_observation;
    // The last observation in this sequence.
    Observation             *   _last_observation;
    // The probability of some event given the observations in this sequence.
    double                      _posterior_probability;
    // The prior probability of some event before evaluating this sequence.
    double                      _prior_probability;
    
    // x = prior probability.
    // y = P(a|b) i.e. probability of observation happening given that prediction is happening.
    // z = P(a) probability of observation happening.
    double bayesian(double x, double y, double z) { return (x*y) / ((x*y) + (z*(1.0 - x)));}
};

#endif /* BayesianSequence_hpp */
