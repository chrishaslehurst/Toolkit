#pragma once

#include <type_traits>
#include <tuple>

template<typename R, typename C, typename... Args>
C function_pointer_class(R(C::*)(Args...));

template<class Signature>
struct signature_trait;

template<class R, class... Args>
struct signature_trait<R(Args...)>
{
	using type = std::tuple<R, Args...>;
};

template<class R, class... Args>
struct signature_trait<R(*)(Args...)>
{
	using type = std::tuple<R, Args...>;
};

template<class R, class U, class... Args>
struct signature_trait<R(U::*)(Args...)>
{
	using type = std::tuple<R, Args...>;
};

template<class Signature>
using signature_trait_t = typename signature_trait<Signature>::type;

template<class Signature1, class Signature2>
using is_same_signature = std::is_same<signature_trait_t<Signature1>,
	signature_trait_t<Signature2>>;

template<class Signature1, class Signature2>
inline constexpr bool is_same_signature_v =
is_same_signature<Signature1, Signature2>::value;