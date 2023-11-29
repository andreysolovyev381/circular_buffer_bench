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
	return container;
}

template<typename  Container, IsContainer<Container> = true>
Container copy (const Container &container) {
	return Container{begin(container), end(container)};
}

template<typename  Container, IsContainer<Container> = true>
Container address_at (Container const &container, size_t size) {
	Container results;
	results.resize(size);
	int j {0};
	for (size_t i = 0; i != size; ++i) {
		j = prm(0, size - 1);
		results.at(i) = container.at(j);
	}
	return results;
}

template<typename  Container, IsContainer<Container> = true>
Container address_square_brackets (Container const &container, size_t size) {
	Container results;
	results.resize(size);
	int j {0};
	for (size_t i = 0; i != size; ++i) {
		j = prm(0, size - 1);
		results[i] = container[j];
	}
	return results;
}

template<typename  Container, IsContainer<Container> = true>
Container push_back_on_empty (size_t new_elem_count) {
	Container container;
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
