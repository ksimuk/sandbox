/*
 * generic wrapper.
 *
 * Copyright 1999-2008 Gentoo Foundation
 * Licensed under the GPL-2
 */

#ifndef WRAPPER_ARGS_PROTO
# error WRAPPER_ARGS_PROTO needs to be defined
#endif
#ifndef WRAPPER_ARGS_PROTO_FULL
# define WRAPPER_ARGS_PROTO_FULL WRAPPER_ARGS_PROTO
#endif
#ifndef WRAPPER_ARGS_FULL
# define WRAPPER_ARGS_FULL WRAPPER_ARGS
#endif
#ifndef WRAPPER_RET_TYPE
# define WRAPPER_RET_TYPE int
#endif
#ifndef WRAPPER_RET_DEFAULT
# define WRAPPER_RET_DEFAULT -1
#endif
#ifndef WRAPPER_PRE_CHECKS
# define WRAPPER_PRE_CHECKS() true
#endif
#ifndef WRAPPER_SAFE_POST_EXPAND
# define WRAPPER_SAFE_POST_EXPAND
#endif
#ifndef WRAPPER_POST_EXPAND
# define WRAPPER_POST_EXPAND
#endif

extern WRAPPER_RET_TYPE EXTERN_NAME(WRAPPER_ARGS_PROTO);
static WRAPPER_RET_TYPE (*WRAPPER_TRUE_NAME)(WRAPPER_ARGS_PROTO) = NULL;

#ifndef SB_HIDDEN_FUNC
# define _SB_HIDDEN_FUNC(x) sb_unwrapped_##x
# define SB_HIDDEN_FUNC(x) _SB_HIDDEN_FUNC(x)
#endif
attribute_hidden
WRAPPER_RET_TYPE SB_HIDDEN_FUNC(WRAPPER_NAME)(WRAPPER_ARGS_PROTO_FULL)
{
	check_dlsym(WRAPPER_TRUE_NAME, WRAPPER_SYMNAME, WRAPPER_SYMVER);
	return WRAPPER_TRUE_NAME(WRAPPER_ARGS_FULL);
}

WRAPPER_RET_TYPE WRAPPER_NAME(WRAPPER_ARGS_PROTO)
{
	WRAPPER_RET_TYPE result = WRAPPER_RET_DEFAULT;

	if (WRAPPER_PRE_CHECKS())
		if (WRAPPER_SAFE()) {
			WRAPPER_SAFE_POST_EXPAND
			result = SB_HIDDEN_FUNC(WRAPPER_NAME)(WRAPPER_ARGS_FULL);
			WRAPPER_POST_EXPAND
		}

	return result;
}

#undef WRAPPER_ARGS_FULL
#undef WRAPPER_ARGS_PROTO_FULL
#undef WRAPPER_SAFE_POST_EXPAND
#undef WRAPPER_POST_EXPAND
