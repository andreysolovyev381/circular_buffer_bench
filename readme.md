### Benchmarking boost::circular_buffer vs std::vector, std::deque, handmade container 

- I have a specific usage of data window, specifically, my data comes in one at a time, so I am mostly interested in comparing joint usage of the following functionality:  
```cpp 
    push_back();
    pop_front();
```
- Containers tested:
    * std::vector,
    * std::deque,
    * boost::circular_buffer,
    * own implementation of a circular buffer with a fixed size implementing a basic idea just to move both beggining/end pointers to container elements when new data arrives. 

**Benchmark of consequent immediate call of push_back() and pop_front()**

| Performance of preallocated container of 512 elements on 512 operations |     Time |
|:------------------------------------------------------------------------|---------:|
| handmade container                                                      |   547 ns |
| boost::circular_buffer                                                  |  2165 ns |
| std::deque                                                              |  2549 ns |
| std::vector                                                             | 37859 ns |


- See the benchmark result in the dedicated file for the details.

**Feel free to use at your own risk, no guarantees of any kind are given whatsoever.** 
