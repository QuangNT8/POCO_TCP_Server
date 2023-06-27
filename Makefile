CPP			    = g++
RM			    = rm -f
CPPFLAGS		= -Wall -I. -O2 -std=c++11 -g
LIBS 			:= -lPocoFoundation -lPocoNet
SOURCES			= $(wildcard *.cpp)
TARGETS			= $(SOURCES:%.cpp=%)

all:	${TARGETS}

clean:
	${RM} *.obj *~* ${TARGETS}

${TARGETS}:
	${CPP} ${CPPFLAGS} -o $@ ${@:%=%.cpp} $(LIBS)

