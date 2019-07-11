//
//  main.cpp
//  Bayesian-Sequence
//
//  Created by Nicholas Rogers on 7/10/19.
//  Copyright © 2019 Nicholas Rogers. All rights reserved.
//

#include <iostream>
#include "BayesianSequence.hpp"

int main(int argc, const char * argv[])
{
    BayesianSequence *bs = new BayesianSequence();
    bs->set_prior(0.05);
    
    Event *e1 = new Event(0.1);
    Event *e2 = new Event(0.02);
    
    Observation *o1 = new Observation();
    o1->set_event(e1);
    o1->set_contingent_probability(0.95);
    
    Observation *o2 = new Observation();
    o2->set_event(e2);
    o2->set_contingent_probability(0.85);
    
    bs->add_observation(o1);
    bs->add_observation(o2);
    
    double probability = bs->calculate();
    
    std::cout << probability << std::endl;
    
    delete bs;
    
    return 0;
}
