#include "BayesianSequence.hpp"

BayesianSequence::BayesianSequence(double prior)
{
    _prior_probability = _posterior_probability = prior;
    _start_observation = _last_observation = nullptr;
}

BayesianSequence::~BayesianSequence()
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

void BayesianSequence::set_prior(double probability)
{
    _posterior_probability = _prior_probability = probability;
}

double BayesianSequence::probability() const
{
    return _posterior_probability;
}

void BayesianSequence::add_observation(Observation * obs)
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

double BayesianSequence::calculate()
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
