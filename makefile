# change application name here (executable output name)
TARGET=bitmapCreator
# compiler
CC=g++
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall -Wextra -Werror
#src directory
SRCDIR=src
#object directoy
CPPVERSION=-std=c++17
LIBFLAGS=-fPIC
OBJDIR=obj
#Libraries
GTEST = /usr/local/lib/libgtest.a
TOKENIZER=-ltokenizer
XMLPARSER=-lxmlparser
#Folder with header files
INCLUDES=-I include
#target directory

CCFLAGS=$(DEBUG) ${CPPVERSION} $(OPT) $(WARN) -pipe

# linker
LD=g++
LDFLAGS=-lstdc++

OBJS=$(OBJDIR)/main.o\
$(OBJDIR)/BitmapHeader.o \
$(OBJDIR)/BitmapInfoHeader.o \
$(OBJDIR)/Pixel.o \

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)  $(LDFLAGS)

$(OBJDIR)/BitmapHeader.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/BitmapHeader.cpp -o $(OBJDIR)/BitmapHeader.o

$(OBJDIR)/BitmapInfoHeader.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/BitmapInfoHeader.cpp -o $(OBJDIR)/BitmapInfoHeader.o

$(OBJDIR)/Pixel.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Pixel.cpp -o $(OBJDIR)/Pixel.o

$(OBJDIR)/main.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET) $(LIBTARGET) $(ARCHIVELIBTARGET)