# Bayesian Sequence

## Overview

[Bayesian probability](https://en.wikipedia.org/wiki/Bayesian_probability) and more specifically, [Bayesian inference](https://en.wikipedia.org/wiki/Bayesian_inference), allows us to calculate the probability of some event given our prior belief about its probability and other observations. This project is a tool that creates a structure using Bayesian inference to track the likelihood of any arbitrary outcome.

This project contains two types of models. The first is a linear-based model that uses a linked list to represent a sequence of observations that affect the probability of an outcome. The second is a graph-based model that represents events as edges and observations as vertices. Both of these models are implemented as classes.
