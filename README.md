# Stimulating E911 DDOS attacks

# Statement of work
The program simulates the behavior of an E911 system in the presence of a distributed denial of service attack for a duration of one hour. Besides delivering this simulator, use it to generate the equivalent of figure 16 (left) from the Mirsky and Guri paper (except with no distinction between wireless and wireline calls). The program should take the following command line arguments, in the given order: 
1. Number of call takers, c.
2. Average number of legitimate calls per hour (divide this by 3600 to get average calls per second)
3. Average legitimate call service time, ts, in seconds (the reciprocal of this is 𝜆s for the service time exponential distribution).
4. Number of bots.

The program should output (to cout) the average total service time for a legitimate call (the time elapsed from when a legitimate call-placed event is removed from the event queue to the time that the matching service-ended event is dequeued 

Design doc: [Program3_design.pdf](https://github.com/hlongn2469/E911-DDoS-Attacks/files/6200790/Program3_design.pdf)

