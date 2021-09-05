#pragma once

#include <map>
#include <vector>
#include "CoreMinimal.h"

enum class Key : u8
{
	/* The unknown key */
	UNKNOWN

	/* Printable keys */
	, SPACE
	, APOSTROPHE           /* ' */
	, COMMA                /* , */
	, MINUS                /* - */
	, PERIOD               /* . */
	, SLASH                /* / */
	, NUM_0
	, NUM_1
	, NUM_2
	, NUM_3
	, NUM_4
	, NUM_5
	, NUM_6
	, NUM_7
	, NUM_8
	, NUM_9
	, SEMICOLON            /* ; */
	, EQUAL                /* = */
	, A
	, B
	, C
	, D
	, E
	, F
	, G
	, H
	, I
	, J
	, K
	, L
	, M
	, N
	, O
	, P
	, Q
	, R
	, S
	, T
	, U
	, V
	, W
	, X
	, Y
	, Z
	, LEFT_BRACKET         /* [ */
	, BACKSLASH            /* \ */
	, RIGHT_BRACKET        /* ] */
	, BACK_TICK         /* ` */
	, WORLD_1             /* non-US #1 */
	, WORLD_2             /* non-US #2 */
	, ESCAPE
	, ENTER
	, TAB
	, BACKSPACE
	, INSERT
	, DELETE
	, RIGHT
	, LEFT
	, DOWN
	, UP
	, PAGE_UP
	, PAGE_DOWN
	, HOME
	, END
	, CAPS_LOCK
	, SCROLL_LOCK
	, NUM_LOCK
	, PRINT_SCREEN
	, PAUSE
	, F1
	, F2
	, F3
	, F4
	, F5
	, F6
	, F7
	, F8
	, F9
	, F10
	, F11
	, F12
	, NP_0
	, NP_1
	, NP_2
	, NP_3
	, NP_4
	, NP_5
	, NP_6
	, NP_7
	, NP_8
	, NP_9
	, NP_DECIMAL
	, NP_DIVIDE
	, NP_MULTIPLY
	, NP_SUBTRACT
	, NP_ADD
	, NP_ENTER
	, NP_EQUAL
	, LEFT_SHIFT
	, LEFT_CONTROL
	, LEFT_ALT
	, LEFT_SUPER
	, RIGHT_SHIFT
	, RIGHT_CONTROL
	, RIGHT_ALT
	, RIGHT_SUPER
	, MENU
	, MAX
};

enum class KeyState : u8
{
	None,
	Pressed,
	Released
};

class Input
{
public:
	virtual ~Input() {}
	virtual void ReceiveInput(s32 key, s32 action, s32 mods) = 0;

protected:
	std::vector<Key> Keys;
	std::vector<KeyState> KeyStates;
};

class InputGL : public Input
{
	std::vector<s32> KeyCodes;

public:
	InputGL();

	void ReceiveInput(s32 key, s32 action, s32 mods) override;

	void VoidTestCallback();
	void TestCallback(s32 test, s32 test2);

private:
	void AddKeyToMap(s32 glKey, Key engineKey);
};

void FreeFuncCallbackTest(s32 test1, s32 test2);