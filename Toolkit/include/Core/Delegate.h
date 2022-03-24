#pragma once

template<typename ...Args>
class Delegate
{
	using DelegateSignature = Delegate<Args...>;

public:

	template <class Obj, void (Obj::* TFunc)(Args...)>
	static void MemberFuncStub(void* objectPtr, Args&&... args)
	{
		Obj* typedPtr = static_cast<Obj*>(objectPtr);
		return (typedPtr->*TFunc)(std::forward<Args>(args)...);
	}

	template <class Obj, void (Obj::* TFunc)(Args...)>
	static DelegateSignature FromMemberFunction(Obj* objectPtr)
	{
		DelegateSignature delegate;
		delegate.Object = objectPtr;
		delegate.Function = &MemberFuncStub<Obj, TFunc>;
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