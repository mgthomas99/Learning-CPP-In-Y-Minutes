
INCLUDES += \
	-I/opt/vc/include/  \
	-Iinclude/

LDFLAGS += \
	-L/opt/vc/lib/  \
	-Llib/          \
	-lm

CFLAGS += \
	$(INCLUDES)     \
	-DRASPBERRY_PI  \
	-Wall

CPPFLAGS += \
	$(CFLAGS)       \
	$(INCLUDES)     \
	-fpermissive

#
main:	person util src/main.cpp
	@mkdir -p "build/"
	$(LINK.cpp)	src/main.cpp    \
			-o	build/main.bin  \
				build/person.o  \
				build/util.o

person:	src/person.cpp
	@mkdir -p "build/"
	$(LINK.cpp) -c	src/person.cpp  \
			-o	build/person.o

util:	src/util.cpp
	@mkdir -p "build/"
	$(LINK.cpp) -c	src/util.cpp  \
			-o	build/util.o
