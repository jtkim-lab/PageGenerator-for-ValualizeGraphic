CC = gcc
OBJS = changeTitle.o
TARGET = changeTitle.out

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -f $(OBJS) $(TARGET)

changeTitle.o : changeTitle.c
