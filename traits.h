#pragma once

#include <type_traits>

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
