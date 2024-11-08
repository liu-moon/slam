# Makefile

# 定义目标
.PHONY: clean setup

# 删除build目录
clean:
	rm -rf build

# 创建build目录
setup: clean
	mkdir build

# 默认执行setup
all: setup
