//
//  Observation.hpp
//  Bayesian-Sequence
//
//  Created by Nicholas Rogers on 7/10/19.
//  Copyright © 2019 Nicholas Rogers. All rights reserved.
//

#ifndef Observation_hpp
#define Observation_hpp

#include <stdio.h>
#include "Event.hpp"

/*
 The observation class handles a single observation of data.
 
 It contains an association of an event with a prediction.
 For example, let's say you were predicting the probability the stock market
 rising tomorrow morning. A successful jobs report would be a good
 indicator. The release of the jobs report is the event and the association
 between the jobs report and the prediction (the stock market rising) would
 be the observation.
 
 */
class Observation
{
public:
    
    Observation(Event * event = nullptr,
                Observation * previous = nullptr,
                Observation * next = nullptr,
                double contingent_probability = 0.5)
    {
        _event = event;
        _previous_observation = previous;
        _next_observation = next;
        _contingent_probability = contingent_probability;
    }
    
    ~Observation()
    {
        delete _event;
    }
    
    void set_contingent_probability(double probability)
    {
        _contingent_probability = probability;
    }
    
    double get_contingent_probability() const
    {
        return _contingent_probability;
    }
    
    void set_event(Event * event)
    {
        _event = event;
    }
    
    Event * get_event() const
    {
        return _event;
    }
    
    void set_next(Observation * next)
    {
        _next_observation = next;
    }
    
    void set_previous(Observation * previous)
    {
        _previous_observation = previous;
    }
    
    Observation * next() const
    {
        return _next_observation;
    }
    
    Observation * previous() const
    {
        return _previous_observation;
    }
    
private:
    
    // An event.
    Event               *   _event;
    // The observation before this observation
    Observation         *   _previous_observation;
    // The observation after this observation
    Observation         *   _next_observation;
    // Probability of this event happening if the conclusion happens.
    double                  _contingent_probability;
    
};

#endif /* Observation_hpp */
