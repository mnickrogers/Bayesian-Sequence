#include "Observation.hpp"

Observation::Observation(Event * event,
                         Observation * previous,
                         Observation * next,
                         double contingent_probability)
{
    _event = event;
    _previous_observation = previous;
    _next_observation = next;
    _contingent_probability = contingent_probability;
}

Observation::~Observation()
{
    delete _event;
}

void Observation::set_contingent_probability(double probability)
{
    _contingent_probability = probability;
}

double Observation::get_contingent_probability() const
{
    return _contingent_probability;
}

void Observation::set_event(Event * event)
{
    _event = event;
}

Event * Observation::get_event() const
{
    return _event;
}

void Observation::set_next(Observation * next)
{
    _next_observation = next;
}

void Observation::set_previous(Observation * previous)
{
    _previous_observation = previous;
}

Observation * Observation::next() const
{
    return _next_observation;
}

Observation * Observation::previous() const
{
    return _previous_observation;
}
