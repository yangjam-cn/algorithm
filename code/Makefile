object = $(obj)
objects = src/$(object)
includes = inc
test: $(objects) 
	g++ $^ -I $(includes) -o $@

.PHONY: clean
clean:
	del test.exe