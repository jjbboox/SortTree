Target := SortTree
LIBS := -lstdc++
SRCS := main.cpp 
SortTree: $(SRCS)
	gcc -o ./output/$(Target) $(SRCS) $(LIBS)

