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
- It appears that pre-allocated std::deque is very hard to win from, maybe just using architecture-specific optimizations.

**Benchmark of consequent immediate call of push_back() and pop_front()**

| Performance of preallocated container of 64 elements on 64 operations |    Time |
|:----------------------------------------------------------------------|--------:|
| handmade container                                                    | 73.6 ns |
| std::deque                                                            | 86.2 ns |
| boost::circular_buffer                                                |  275 ns |
| std::vector                                                           | 1540 ns |

- **Moral is simple - don't invent a bicycle, use STL in a smart way.**

- See the benchmark result in the dedicated file for the details.

Feel free to use at your own risk, no guarantees of any kind are given whatsoever. 
