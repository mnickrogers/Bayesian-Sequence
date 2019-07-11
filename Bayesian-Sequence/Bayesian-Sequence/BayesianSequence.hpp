#ifndef BayesianSequence_hpp
#define BayesianSequence_hpp

#include <iostream>
#include "Observation.hpp"

class BayesianSequence
{
public:
    
    BayesianSequence(double prior = 0.5)
    {
        _prior_probability = _posterior_probability = prior;
        _start_observation = _last_observation = nullptr;
    }
    
    ~BayesianSequence()
    {
        Observation *obs = _start_observation;
        
        while (obs->next() != nullptr)
        {
            Observation *next = obs->next();
            delete obs;
            obs = next;
        }
        
        delete obs;
    }
    
    void set_prior(double probability)
    {
        _posterior_probability = _prior_probability = probability;
    }
    
    double probability() const
    {
        return _posterior_probability;
    }
    
    void add_observation(Observation * obs)
    {
        // Two cases here. Either this is the first object added to this BayesianSequence object or not.
        // We can determine this by checking if the _start_observation is equal to nullptr.
        
        if (_start_observation == nullptr)
        {
            _start_observation = _last_observation = obs;
        }
        else
        {
            obs->set_previous(_last_observation);
            _last_observation->set_next(obs);
            _last_observation = obs;
        }
    }
    
    double calculate()
    {
        Observation *observation = _start_observation;
        
        while (observation != nullptr)
        {
            _posterior_probability = bayesian(_posterior_probability,
                                              observation->get_contingent_probability(),
                                              observation->get_event()->probability());
            observation = observation->next();
        }
        
        return _posterior_probability;
    }
    
private:
    
    Observation             *   _start_observation;
    Observation             *   _last_observation;
    double                      _posterior_probability;
    double                      _prior_probability;
    
    // x = prior probability.
    // y = P(a|b) i.e. probability of observation happening given that prediction is happening.
    // z = P(a) probability of observation happening.
    double bayesian(double x, double y, double z) { return (x*y) / ((x*y) + (z*(1.0 - x)));}
};

#endif /* BayesianSequence_hpp */
