#include <benchmark/benchmark.h>
#include "templates.h"


[[maybe_unused]] int small_size_test = 3;
[[maybe_unused]] int mid_size_test = 6;
[[maybe_unused]] int big_size_test = 10;

static void WarmUp (benchmark::State& state) {
	[[maybe_unused]] int i {0};
	for (auto _ : state)
		i = warm_up();
}
BENCHMARK(WarmUp);


/*
static void CreateVector(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::vector<T>> (SIZE);
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(CreateVector)->MinTime(big_size_test);

static void CreateDeque(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::deque<T>> (SIZE);
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(CreateDeque)->MinTime(big_size_test);

static void CreateCB(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<boost::circular_buffer<T>> (SIZE);
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(CreateCB)->MinTime(big_size_test);




static void CopyVector(benchmark::State& state) {
	auto v = create<std::vector<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = copy<std::vector<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(CopyVector)->MinTime(big_size_test);

static void CopyDeque(benchmark::State& state) {
	auto v = create<std::deque<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = copy<std::deque<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(CopyDeque)->MinTime(big_size_test);

static void CopyCB(benchmark::State& state) {
	auto v = create<boost::circular_buffer<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = copy<boost::circular_buffer<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(CopyCB)->MinTime(big_size_test);





static void AtVector(benchmark::State& state) {
	auto v = create<std::vector<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = address_at<std::vector<T>> (v, 2);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(AtVector)->MinTime(big_size_test);

static void AtDeque(benchmark::State& state) {
	auto v = create<std::deque<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = address_at<std::deque<T>> (v, 2);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(AtDeque)->MinTime(big_size_test);

static void AtCB(benchmark::State& state) {
	auto v = create<boost::circular_buffer<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = address_at<boost::circular_buffer<T>> (v, 2);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(AtCB)->MinTime(big_size_test)->MinTime(big_size_test);





static void BracketsVector(benchmark::State& state) {
	auto v = create<std::vector<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = address_square_brackets<std::vector<T>> (v, 2);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(BracketsVector)->MinTime(big_size_test);

static void BracketsDeque(benchmark::State& state) {
	auto v = create<std::deque<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = address_square_brackets<std::deque<T>> (v, 2);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(BracketsDeque)->MinTime(big_size_test);

static void BracketsCB(benchmark::State& state) {
	auto v = create<boost::circular_buffer<T>> (SIZE);
	for (auto _ : state){
		auto v_copy = address_square_brackets<boost::circular_buffer<T>> (v, 2);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(BracketsCB)->MinTime(big_size_test);




static void PushBackOnEmptyVector(benchmark::State& state) {
	for (auto _ : state){
		auto v_copy = push_back_on_empty<std::vector<T>> (SIZE);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PushBackOnEmptyVector)->MinTime(big_size_test);

static void PushBackOnEmptyDeque(benchmark::State& state) {
	for (auto _ : state){
		auto v_copy = push_back_on_empty<std::deque<T>> (SIZE);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PushBackOnEmptyDeque)->MinTime(big_size_test);

static void PushBackOnEmptyCB(benchmark::State& state) {
	for (auto _ : state){
		auto v_copy = push_back_on_empty<boost::circular_buffer<T>> (SIZE);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PushBackOnEmptyCB)->MinTime(big_size_test);

*/


static void PopFrontVector(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::vector<T>> (SIZE);
		auto v_copy = pop_front<std::vector<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PopFrontVector)->Range(1, 1<<10);

static void PopFrontDeque(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<std::deque<T>> (SIZE);
		auto v_copy = pop_front<std::deque<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
}
BENCHMARK(PopFrontDeque)->Range(1, 1<<10);

static void PopFrontCB(benchmark::State& state) {
	for (auto _ : state){
		auto v = create<boost::circular_buffer<T>> (SIZE);
		auto v_copy = pop_front<boost::circular_buffer<T>> (v);
		benchmark::DoNotOptimize(v_copy);
	}
	state.SetComplexityN(state.range(0));
}
BENCHMARK(PopFrontCB)->Range(1, 1<<10);

BENCHMARK_MAIN();
