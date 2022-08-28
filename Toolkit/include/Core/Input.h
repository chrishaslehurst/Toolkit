#pragma once

#include <vector>
#include "CoreMinimal.h"

struct GLFWwindow;

namespace tk
{
	struct KeyBind
	{
		KeyBind(s32 inKey, s32 inAction, s32 inMods, Delegate<> inBinding)
			:key(inKey)
			, action(inAction)
			, mods(inMods)
			, binding(inBinding)
		{}

		s32 key = 0;
		s32 action = 0;
		s32 mods = 0;

		Delegate<> binding;
	};

	class Input
	{
	public:

		template <auto Func, std::enable_if_t<std::is_member_function_pointer_v<decltype(Func)>, bool> = true>
		void BindKey(s32 key, s32 action, s32 mods, decltype(function_pointer_class(Func))* object)
		{
			keyBinds.push_back(KeyBind(key, action, mods, Delegate<>::FromMemberFunction<(Func)>(object)));
		}

		template <void(*TFunc)()>
		void BindKey(s32 key, s32 action, s32 mods)
		{
			keyBinds.push_back(KeyBind(key, action, mods, Delegate<>::FromFreeFunction<(TFunc)>()));
		}

		void ReceiveInput(GLFWwindow* window, s32 key, s32 action, s32 mods);

		

	private:
		std::vector<KeyBind> keyBinds;
	};

	
}