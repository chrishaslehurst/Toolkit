#pragma once
#include "TKTypeTraits.h"

template<typename ...Args>
class Delegate
{
	using DelegateSignature = Delegate<Args...>;

public:

	template <auto Func, std::enable_if_t<std::is_member_function_pointer_v<decltype(Func)>, bool> = true>
	static void MemberFuncStub(void* objectPtr, Args&&... args)
	{
		using ObjType = decltype(function_pointer_class(Func));
		ObjType* typedPtr = static_cast<ObjType*>(objectPtr);
		return (typedPtr->*Func)(std::forward<Args>(args)...);
	}

	template <auto Func, std::enable_if_t<std::is_member_function_pointer_v<decltype(Func)>, bool> = true>
	static DelegateSignature FromMemberFunction(decltype(function_pointer_class(Func))* objectPtr)
	{
		static_assert(is_same_signature_v<decltype(Func), void(decltype(function_pointer_class(Func))::*)(Args...)>, "Function signature does not match delegate");
		DelegateSignature delegate;
		delegate.Object = objectPtr;
		delegate.Function = &MemberFuncStub<Func>;
		return delegate;
	}

	template <void(*TFunc)(Args...)>
	static void FreeFuncStub(void*, Args&&... args)
	{
		return (TFunc)(std::forward<Args>(args)...);
	}

	template <void(*TFunc)(Args...)>
	static DelegateSignature FromFreeFunction()
	{
		DelegateSignature d;
		d.Function = &FreeFuncStub<TFunc>;
		return d;
	}

	void Invoke(Args&&... args) const
	{
		return (*Function)(Object, std::forward<Args>(args)...);
	}

private:
	void* Object = nullptr;
	void (*Function)(void*, Args&&...) = nullptr;
};