# == Default target

.PHONY: all

all:

# == Source files ==

CXX_SOURCES = \
	eztest/Test_Suite.cpp \
	eztest/eztest.cpp \
	eztest/Failure.cpp

CXX_SOURCES += 

OBJS = \
	$(CXX_SOURCES:%.cpp=%.o) \

OBJEXT = o
SOEXT = so

# == Final targets ==

TARGETS = \
  $(OBJS) \
	libezio.$(SOEXT)

all: $(TARGETS)

# == Build flags ==

INCLDIRS += 

CPPFLAGS += $(addprefix -I,$(INCLDIRS))

CFLAGS += -ggdb -fPIC

LDLIBS += 
LIBDIRS +=
LDFLAGS +=
LDFLAGS += $(addprefix -L,$(LIBDIRS))
LDFLAGS += $(addprefix -l,$(LDLIBS))

# == Build rules ==

%.$(OBJEXT): %.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

# == Rules for final targets ==

libezio.$(SOEXT): $(OBJS)
	$(CXX) -shared $(LDFLAGS) $(OBJS) -o $@

# == Dependencies ==

CFLAGS += -MMD -MP

DEP_FILES=$(patsubst %.$(OBJEXT),%.d,$(OBJS))
-include $(DEP_FILES)

# == Clean ==

.PHONY: clean

clean:
	$(RM) $(TARGETS)

# == Documentation ==

.PHONY: docs

all: docs

docs:
	doxygen

docs-ps: docs
	$(MAKE) -C doc/latex
	dvips doc/latex/refman.dvi -o doc/latex/refman.ps

