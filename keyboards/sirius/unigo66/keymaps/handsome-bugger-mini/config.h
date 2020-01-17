#pragma once

#define TAPPING_TERM 175

// disable old style macro handling: MACRO() & action_get_macro
#define NO_ACTION_MACRO

// disable calling of action_function() from the fn_actions array (deprecated)
#define NO_ACTION_FUNCTION

// trying to improve _T behaviour on the UniGo66 with these two enabled together:
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
