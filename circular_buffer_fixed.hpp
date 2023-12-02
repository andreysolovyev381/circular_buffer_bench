//
// Created by Elena Solovyeva on 02.12.2023.
//

#pragma once

#include <vector>
#include <concepts>
#include <type_traits>
#include <cstddef>
#include <stdexcept>
#include <utility>

namespace culib {

	namespace requirements {
		template <typename Numeric>
		concept IsIndex =
		std::convertible_to<Numeric, std::size_t> &&
		std::three_way_comparable<Numeric>;

	}//!namespace

	template <typename T>
	class CircularBufferFixed {
	public:
		using value_type = T;
		template <typename Numeric>
		requires requirements::IsIndex<Numeric>
		explicit CircularBufferFixed (Numeric n, T defaultValue)
				: sz 		{static_cast<std::int32_t>(n)}
				, frontIdx 	{0}
				, backIdx 	{static_cast<std::int32_t>(n) - 1}
		{
			if (n < 1) throw std::invalid_argument ("Can't create a fixed size circular buffer with size 0. Just why?..");
			data.resize(n, defaultValue);
		}

		void push(T t) noexcept {
			updatePush();
			data[backIdx] = std::move(t);
		}

		T& pop() noexcept {
			T& res = data[frontIdx];
			updatePop();
			return res;
		}

		std::size_t size() const noexcept {
			return sz;
		}
	private:
		std::vector<T> data;
		std::int32_t const sz;
		std::int32_t frontIdx, backIdx;

		inline void updatePush() noexcept {
			++backIdx;
			if (backIdx == sz) [[unlikely]] {
				backIdx = 0;
			}
			if (backIdx == frontIdx) [[unlikely]] {
				++frontIdx;
				if (frontIdx == sz) [[unlikely]] {
					frontIdx = 0;
				}
			}
		}

		inline void updatePop() noexcept {
			++frontIdx;
			if (frontIdx == sz) [[unlikely]] {
				frontIdx = 0;
			}
		}
	};
}//!namespace
