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
    * own implementation of a circular buffer with a fixed size with a basic idea just to move both begin/end pointers to container elements when new data arrives. 

**Benchmark of consequent immediate call of push_back() and pop_front()**

| Performance of preallocated container of 512 elements on 512 operations |      Time |
|:------------------------------------------------------------------------|----------:|
| fixed size circular buffer                                              |    414 ns |
| boost::circular_buffer                                                  |  2'151 ns |
| std::deque                                                              |  2'574 ns |
| std::vector                                                             | 37'145 ns |


- The results are expected, as fixed size container doesn't try to allocate memory while performing operations of storing incoming data.
- Works both for C++17 and C++20.
- See the benchmark result in the dedicated file for the details.
- If you are interested to get full source code for my implementation of fixed size circular buffer then please refer to the [respective repo](https://github.com/andreysolovyev381/circular_buffer_fixed).  

**Feel free to use at your own risk, no guarantees of any kind are given whatsoever.** 
