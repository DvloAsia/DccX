# DccX 语法规范

## 文件格式
- 文件扩展名：`.dvx`
- 编码：UTF-8

## 注释
```dvx
# 单行注释（shell风格）
// 单行注释（C风格）
/* 多行注释 */
```

## 变量声明
```dvx
# 基础类型
num x = 10                # 数字类型
str name = "DccX"         # 字符串类型
bool flag = true          # 布尔类型
list arr = [1, 2, 3]      # 列表类型
dict map = {"key": "value"} # 字典类型

# 类型推断（可选）
var y = 20                # 自动推断为数字类型
var text = "hello"        # 自动推断为字符串类型

# 系统类型
file f = open("test.txt") # 文件类型
proc p = spawn("ls")     # 进程类型
```

## 运算符
```dvx
# 算术运算符
a + b    # 加法
a - b    # 减法
a * b    # 乘法
a / b    # 除法
a % b    # 取模
a ** b   # 幂运算

# 比较运算符
a == b   # 等于
a != b   # 不等于
a > b    # 大于
a < b    # 小于
a >= b   # 大于等于
a <= b   # 小于等于

# 逻辑运算符
a && b   # 逻辑与
a || b   # 逻辑或
!a       # 逻辑非

# 位运算符
a & b    # 位与
a | b    # 位或
a ^ b    # 位异或
~a       # 位取反
a << b   # 左移
a >> b   # 右移

# Shell 风格运算符
$(expr)  # 执行命令并获取结果
$[var]   # 变量引用
```

## 函数定义
```dvx
# 简单函数
func add(a, b) {
    return a + b
}

# 带类型的函数
func greet(name: str): str {
    return "Hello, " + name
}

# 匿名函数
var square = func(x) {
    return x * x
}

# Lambda 表达式
var sum = (a, b) => a + b
```

## 控制结构
```dvx
# 条件语句
if condition {
    # 代码块
} elseif condition {
    # 代码块
} else {
    # 代码块
}

# 循环
for item in collection {
    print item
}

for i = 0; i < 10; i++ {
    print i
}

while condition {
    # 循环体
}

# Shell 风格循环
for file in $(ls *.dvx) {
    print "File: " + file
}
```

## 系统命令集成
```dvx
# 直接执行命令
shell "ls -la"

# 获取命令输出
var output = exec("date")
print output

# 管道操作
var result = exec("cat file.txt | grep pattern")

# 后台执行
var proc = spawn("long_process")

# 文件操作
sys("mkdir dir")
sys("rm file.txt")
```

## 类定义（C++风格）
```dvx
class Person {
    # 属性
    var name
    var age
    
    # 构造函数
    init(name, age) {
        this.name = name
        this.age = age
    }
    
    # 方法
    func greet() {
        return "Hello, I'm " + this.name
    }
    
    # 析构函数
    deinit() {
        print "Person destroyed"
    }
}

# 继承
class Student extends Person {
    var grade
    
    init(name, age, grade) {
        super(name, age)
        this.grade = grade
    }
}
```

## 模块和导入
```dvx
# 导入标准库
import sys
import math
import file

# 导入自定义模块
import mymodule
from mymodule import func1, func2

# 别名
import mymodule as mm
```

## 错误处理
```dvx
# try-catch
try {
    var data = open("nonexistent.txt")
} catch error {
    print "Error: " + error.message
}

# 断言
assert condition, "Error message"

# 自定义错误
throw "Something went wrong"
```

## 特殊语法特性
```dvx
# 模板字符串
var path = "${home}/files/${filename}"

# 正则表达式
var pattern = /^[a-z]+$/i

# 异步操作
async func fetch_data() {
    var result = await http.get("https://api.example.com")
    return result
}

# 装饰器
@log
func sensitive_operation() {
    # 自动记录日志
}
```

## 内存管理（C风格）
```dvx
# 内存分配
var buffer = malloc(1024)  # 分配内存

# 内存操作
memcpy(buffer, source, size)

# 指针操作
var ptr = &variable        # 获取指针
var value = *ptr           # 解引用

# 内存释放
free(buffer)               # 释放内存
```

## 示例代码
```dvx
#main {
    # 混合编程示例
    import sys
    import math
    
    # Shell 命令
    files = exec("ls *.dvx")
    
    # C 风格编程
    var total = 0
    for i = 0; i < 10; i++ {
        total += i
    }
    
    # 函数调用
    var result = calculate(total)
    
    # 文件操作
    sys("mkdir output")
    sys("cp source.dvx output/")
    
    # 输出结果
    print "Result: " + result
}

func calculate(n: num): num {
    # 复杂的计算逻辑
    return n * math.pi
}
```

## 扩展语法
```dvx
# 宏定义（C风格）
#define MAX_SIZE 100

# 类型定义
typedef int MyInt
typedef str MyString

# 枚举
enum Color {
    RED,
    GREEN,
    BLUE
}

# 结构体
struct Point {
    x: num
    y: num
}

# 联合体
union Data {
    int_val: num
    str_val: str
}
```

---

这个语法设计融合了：
1. Shell 的简洁性和命令执行能力
2. C 的系统编程和内存管理能力
3. C++ 的面向对象特性
4. 现代语言的便利特性（如类型推断、Lambda）

你可以根据需求调整任何部分！