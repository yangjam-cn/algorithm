# makefile
# 20200413
#######################
# 编写日志
# 20200413-创建编译指令和清理指令

cfile = linklist.c

check: check.c datatype.c ${cfile} 
	gcc check.c datatype.c ${cfile} -o check


run:
	./check
clean:
	rm check
	clear
