/*
 * Copyright (C) 2024-2025, Alexander Schier
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#ifndef ACC_TRAITS_HEADER
#define ACC_TRAITS_HEADER

#include <type_traits>
#include "defines.h"

ACC_NAMESPACE_BEGIN

template<typename T, typename = void>
struct NormHelper {
	static double squaredNorm(const T&) {
		static_assert(sizeof(T) == 0, "Norm function not implemented for this type");
		return 0.0;
	}
};

// Types with square_norm like math/vector.h
template<typename T>
struct NormHelper<T, std::void_t<decltype(std::declval<T>().square_norm())>> {
	static double squaredNorm(const T& vec) { return vec.square_norm(); }
};

// Types with squaredNorm like Eigen::Vector3d
template<typename T>
struct NormHelper<T, std::void_t<decltype(std::declval<T>().squaredNorm())>> {
	static double squaredNorm(const T& vec) { return vec.squaredNorm(); }
};

// Types with sqrnorm like OpenMesh::Vec3d
template<typename T>
struct NormHelper<T, std::void_t<decltype(std::declval<T>().sqrnorm())>> {
	static double squaredNorm(const T& vec) { return vec.sqrnorm(); }
};

template<typename T>
double squaredNorm(const T &vec) {
	return NormHelper<T>::squaredNorm(vec);
}

ACC_NAMESPACE_END

#endif /* ACC_TRAITS_HEADER */
