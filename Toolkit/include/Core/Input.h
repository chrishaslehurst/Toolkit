#pragma once

#include <vector>
#include "CoreMinimal.h"

struct GLFWwindow;

namespace toolkit
{
	struct KeyBind
	{
		KeyBind(s32 inKey, s32 inAction, s32 inMods, Delegate<> inBinding)
			:key(inKey)
			,action(inAction)
			,mods(inMods)
			,binding(inBinding)
		{}

		s32 key = 0;
		s32 action = 0;
		s32 mods = 0;

		Delegate<> binding;
	};

	class Input
	{
	public:

		template <class Obj, void (Obj::* TFunc)()>
		void BindKey(s32 key, s32 action, s32 mods, Obj* object)
		{
			keyBinds.push_back(KeyBind(key, action, mods, Delegate<>::FromMemberFunction<Obj, (TFunc)>(object)));
		}

		template <void(*TFunc)()>
		void BindKey(s32 key, s32 action, s32 mods)
		{
			keyBinds.push_back(KeyBind(key, action, mods, Delegate<>::FromFreeFunction<(TFunc)>()));
		}
		
		void ReceiveInput(GLFWwindow* window, s32 key, s32 action, s32 mods);

		void VoidTestCallback();
		void TestCallback(s32 test, s32 test2);

	private:
		std::vector<KeyBind> keyBinds;
	};

	void FreeFuncCallbackTest(s32 test1, s32 test2);
}