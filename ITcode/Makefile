obj = src/main.cpp

inc_dir = inc
test: $(obj)
	g++ $^ -I$(inc_dir) -o $@
.PHONY: clean
clean:
	del test.exe && cls