AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = sandbox

AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/libsbutil \
	-I$(top_srcdir)/libsbutil/include \
	$(SANDBOX_DEFINES)

sandbox_LDADD = $(top_builddir)/libsbutil/libsbutil.la $(LIBDL)
sandbox_SOURCES = \
	environ.c \
	sandbox.h \
	sandbox.c
