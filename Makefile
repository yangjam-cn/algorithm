input ?= $(obj)
commit = $(msg)
suf = $(suffix $(input))
object = $(basename $(input))
cc = gcc
ifeq ($(suf), .cpp)
	cc = g++
endif
# .c文件在文件夹c下搜索
vpath %.c c
# .ccp文件在cpp、alg、offer文件夹下搜索
vpath %.cpp cpp:alg:offer

$(object): $(input)
	$(cc) $^ -o $@

run:$(object)
	$(object)
# 定义伪目标，防止目录存在与命令同名文件时，目标因不存在依赖项被认定为最新而不执行
.PHONY:clean test
clean:
	del $(addsuffix .exe, $(object)) && cls
test:
	echo $(suf)