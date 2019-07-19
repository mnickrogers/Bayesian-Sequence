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
                double contingent_probability = 0.5);
    
    ~Observation();
    
    void set_contingent_probability(double probability);
    
    double get_contingent_probability() const;
    
    void set_event(Event * event);
    
    Event * get_event() const;
    
    void set_next(Observation * next);
    
    void set_previous(Observation * previous);
    
    Observation * next() const;
    
    Observation * previous() const;
    
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
