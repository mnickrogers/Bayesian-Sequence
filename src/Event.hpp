#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>

/*
 
 Events represent the occurrence of something. For example, an event might
 be the releae of a quarterly jobs report.
 
 */
class Event
{
public:
    
    Event(double probability = 0.0)
    {
        _random_probability = normalize(probability);
    }
    
    void set_probability(double probability)
    {
        _random_probability = normalize(probability);
    }
    
    double probability() const
    {
        return _random_probability;
    }
    
private:
    
    double          _random_probability;
    
    double normalize(double input)
    {
        return input <= 1 ? input : input / 100.0;
    }
};

#endif /* Event_hpp */
