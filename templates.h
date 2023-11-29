//
// Created by Andrey Solovyev on 06/11/2021.
//

#pragma once

#include "randomer.h"

#include <vector>
#include <deque>
#include "boost/circular_buffer.hpp"

#include <type_traits>
#include <cassert>


#ifndef CB_VS_OTHERS_BENCH_TEMPLATES_H
#define CB_VS_OTHERS_BENCH_TEMPLATES_H

using T = double;

static const T lower_bound = -1.e5;
static const T upper_bound = 1.e5;
const size_t SIZE = 1e2;

template <typename Container>
using IsContainer = std::enable_if_t<std::disjunction_v<
		std::is_same<Container, std::deque<typename Container::value_type>>,
		std::is_same<Container, std::vector<typename Container::value_type>>,
		std::is_same<Container, boost::circular_buffer<typename Container::value_type>>
>, bool>;

int warm_up () {
	int res {0};
	for (size_t i = 0, j = 1e6; i != j; ++i) {
		res = prm(0, i);
	}
	return res;
}

template<typename  Container, IsContainer<Container> = true>
Container create (size_t size) {
	Container container;
	container.resize(size);
	for (size_t i = 0, j = size; i != j; ++i)
		container[i] = prm(lower_bound, upper_bound);
	return container;
}

template<typename  Container, IsContainer<Container> = true>
Container copy (const Container &container) {
	return Container{begin(container), end(container)};
}

template<typename  Container, IsContainer<Container> = true>
Container address_at (const Container &container, size_t attempts) {
	Container results;
	results.resize(attempts);
	int size = container.size();
	for (size_t i = 0, j = attempts; i != j; ++i)
		results.push_back(container.at(prm(0, size-1)));
	return results;
}

template<typename  Container, IsContainer<Container> = true>
Container address_square_brackets (const Container &container, size_t attempts) {
	Container results;
	results.resize(attempts);
	int size = container.size();
	for (size_t i = 0, j = attempts; i != j; ++i)
		results.push_back(container[prm(0, size)]);
	return results;
}

template<typename  Container, IsContainer<Container> = true>
Container push_back_on_empty (size_t new_elem_count) {
	Container container;
	if constexpr (std::is_same_v<Container, boost::circular_buffer<typename Container::value_type>>){
		container.resize(new_elem_count/(new_elem_count/10));
	}
	for (size_t i = 0, j = new_elem_count; i != j; ++i)
		container.push_back(prm(lower_bound, upper_bound));
	return container;
}


template<typename  Container, IsContainer<Container> = true>
int pop_front (Container &container) {
	int count = 0;
	assert(container.size() > 0);
	if constexpr (not std::is_same_v<Container, std::vector<typename Container::value_type>>){
		while (not container.empty()) {
			container.pop_front();
			++count;
		}
	}
	else{
		while (not container.empty()) {
			container.erase(container.begin());
			++count;
		}
	}
	return count;
}


#endif //CB_VS_OTHERS_BENCH_TEMPLATES_H
