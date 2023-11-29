#include <benchmark/benchmark.h>
#include "templates.h"


int const range_step {2};
int const max_power_of_two {12};

static void WarmUp (benchmark::State& state) {
	[[maybe_unused]] int i {0};
	for (auto _ : state)
		i = warm_up();
}
BENCHMARK(WarmUp);



//-------------------------
// create containter

static void CreateVector(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::vector<T>> (state.range(0));
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(CreateVector)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void CreateDeque(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::deque<T>> (state.range(0));
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(CreateDeque)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void CreateCB(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<boost::circular_buffer<T>> (state.range(0));
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(CreateCB)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);
//-------------------------




//-------------------------
// copy containter

static void CopyVector(benchmark::State& state) {
	auto v = create<std::vector<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = copy<std::vector<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(CopyVector)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void CopyDeque(benchmark::State& state) {
	auto v = create<std::deque<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = copy<std::deque<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(CopyDeque)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void CopyCB(benchmark::State& state) {
	auto v = create<boost::circular_buffer<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = copy<boost::circular_buffer<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(CopyCB)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);
//-------------------------




//-------------------------
// access element using .at()

static void AtVector(benchmark::State& state) {
	auto v = create<std::vector<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = address_at<std::vector<T>> (v, state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(AtVector)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void AtDeque(benchmark::State& state) {
	auto v = create<std::deque<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = address_at<std::deque<T>> (v, state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(AtDeque)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void AtCB(benchmark::State& state) {
	auto v = create<boost::circular_buffer<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = address_at<boost::circular_buffer<T>> (v, state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(AtCB)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);
//-------------------------




//-------------------------
// access element using []

static void BracketsVector(benchmark::State& state) {
	auto v = create<std::vector<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = address_square_brackets<std::vector<T>> (v, state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(BracketsVector)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void BracketsDeque(benchmark::State& state) {
	auto v = create<std::deque<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = address_square_brackets<std::deque<T>> (v, state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(BracketsDeque)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void BracketsCB(benchmark::State& state) {
	auto v = create<boost::circular_buffer<T>> (state.range(0));
	for (auto _ : state){
		auto v_copy = address_square_brackets<boost::circular_buffer<T>> (v, state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(BracketsCB)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);
//-------------------------



//-------------------------
// add element to the end

static void PushBackOnEmptyVector(benchmark::State& state) {
	for (auto _ : state){
		auto v_copy = push_back_on_empty<std::vector<T>> (state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PushBackOnEmptyVector)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void PushBackOnEmptyDeque(benchmark::State& state) {
	for (auto _ : state){
		auto v_copy = push_back_on_empty<std::deque<T>> (state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PushBackOnEmptyDeque)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void PushBackOnEmptyCB(benchmark::State& state) {
	for (auto _ : state){
		auto v_copy = push_back_on_empty<boost::circular_buffer<T>> (state.range(0));
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PushBackOnEmptyCB)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);
//-------------------------




//-------------------------
// pop first elemennt

static void PopFrontVector(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::vector<T>> (state.range(0));
		auto v_copy = pop_front<std::vector<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PopFrontVector)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void PopFrontDeque(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::deque<T>> (state.range(0));
		auto v_copy = pop_front<std::deque<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PopFrontDeque)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);

static void PopFrontCB(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<boost::circular_buffer<T>> (state.range(0));
		auto v_copy = pop_front<boost::circular_buffer<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
	state.SetComplexityN(state.range(0));
}
BENCHMARK(PopFrontCB)->Range(range_step, 1<<max_power_of_two)->Unit(benchmark::kMicrosecond);
//-------------------------




BENCHMARK_MAIN();
