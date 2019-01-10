Target := SortTree
LIBS := -lstdc++
SRCS := main.cpp 
SortTree: $(SRCS)
	gcc -o $(Target) $(SRCS) $(LIBS)

