# 定义编译器
CXX = g++
# 定义编译选项
CXXFLAGS = -std=c++11

# 定义源文件和目标文件
SOURCES = $(wildcard *.cpp)
EXEC = LMS

# 默认目标
all: $(EXEC)

# 链接所有源文件生成可执行文件
$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SOURCES)

# 清理可执行文件
clean:
	rm -f $(EXEC)
