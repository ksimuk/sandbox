#define CONFIG HAVE_MKOSTEMPS64
#define FUNC mkostemps64
#define SFUNC "mkostemps64"
#define FUNC_STR "\"%s\", %i, %#x"
#define FUNC_IMP template, suffixlen, flags
#define ARG_CNT 3
#define ARG_USE "<template> <suffixlen> <flags>"

#define process_args() \
	s = argv[i++]; \
	char *template = s; \
	\
	s = argv[i++]; \
	int suffixlen = 0; \
	sscanf(s, "%i", &suffixlen); \
	\
	s = argv[i++]; \
	int flags = f_get_flags(s);

#include "test-skel-0.c"
