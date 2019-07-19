#include "Event.hpp"

Event::Event(double probability)
{
    _random_probability = normalize(probability);
}

void Event::set_probability(double probability)
{
    _random_probability = normalize(probability);
}

double Event::probability() const
{
    return _random_probability;
}
