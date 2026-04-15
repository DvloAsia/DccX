# DccX Programming Language

<div align="center">

**DccX** 是一个革命性的编程语言，它将 Shell 脚本的便利性、C 语言的强大性能和 C++ 的高级特性融合在一起。专为现代开发设计，DccX 使系统编程、自动化脚本和快速开发变得更加容易。

**DccX** is a revolutionary programming language that combines the convenience of Shell scripting with the power of C and the advanced features of C++. Designed for modern development, DccX makes system programming, automation, and rapid development accessible to everyone.

</div>

## 🌟 特性 / Features

### Shell 命令集成 / Shell Integration
直接在代码中执行系统命令：
Execute shell commands directly within your code:
```dvx
shell "ls -la"
var output = exec("date")
```

### C 语言性能 / C Language Performance
底层系统编程能力：
Low-level system programming capabilities:
```dvx
var buffer = malloc(1024)
memcpy(buffer, "data", 4)
free(buffer)
```

### C++ 面向对象特性 / C++ Object-Oriented Features
现代编程范式：
Modern programming paradigms:
```dvx
class Person {
    var name
    var age
    
    init(name, age) {
        this.name = name
        this.age = age
    }
    
    func greet() {
        return "Hello, I'm " + this.name
    }
}
```

### AI 辅助开发 / AI-Assisted Development
智能代码分析和建议：
Smart code analysis and suggestions:
```dvx
# AI will analyze your code and provide optimization suggestions
```

### 跨平台支持 / Cross-Platform Support
支持 Termux、Linux、Windows 和 macOS。
Works on Termux, Linux, Windows, and macOS.

## 📦 安装指南 / Installation

### Termux (Android)
```bash
pkg update
pkg install git gcc make
git clone https://github.com/DvloAsia/DccX
cd DccX
make
./dccx examples/test.dvx
```

### Linux
```bash
sudo apt update
sudo apt install git gcc make
git clone https://github.com/DvloAsia/DccX
cd DccX
make
sudo make install
```

### Windows
下载预编译二进制文件，或使用 MinGW 编译源代码。
Download pre-built binaries or use MinGW to compile from source.

## 🚀 快速开始 / Quick Start

### 基础程序 / Basic Program
```dvx
#main {
    print "Hello, DccX!"
    
    # Shell command
    shell "ls -la"
    
    # Variable declaration
    var x = 10
    
    # Condition
    if x > 5 {
        print "x is greater than 5"
    }
    
    # Loop
    for i in range(0, 10) {
        print i
    }
}
```

### 高级示例 / Advanced Example
```dvx
#main {
    import sys
    import math
    
    # File processing with shell integration
    files = exec("find . -name '*.dvx'")
    
    # C-style memory management
    buffer = malloc(1024)
    memcpy(buffer, "Hello", 5)
    
    # Object-oriented programming
    processor = FileProcessor(".")
    results = processor.process_files()
    
    # System operations
    sys("mkdir processed_files")
    sys("mv *.dvx processed_files/")
}
```

## 📚 文档系统 / Documentation

<div align="center">

**双语网站：https://dvloasia.github.io/DccXWeb/**

**Chinese**: https://dvloasia.github.io/DccXWeb/zh/
**English**: https://dvloasia.github.io/DccXWeb/en/

</div>

### 快速链接 / Quick Links
- [安装指南](https://dvloasia.github.io/DccXWeb/#install) / [Installation Guide](https://dvloasia.github.io/DccXWeb/#install)
- [基础语法](https://dvloasia.github.io/DccXWeb/#basic) / [Basic Syntax](https://dvloasia.github.io/DccXWeb/#basic)
- [变量和类型](https://dvloasia.github.io/DccXWeb/#variables) / [Variables and Types](https://dvloasia.github.io/DccXWeb/#variables)
- [函数定义](https://dvloasia.github.io/DccXWeb/#functions) / [Functions](https://dvloasia.github.io/DccXWeb/#functions)
- [控制结构](https://dvloasia.github.io/DccXWeb/#control) / [Control Structures](https://dvloasia.github.io/DccXWeb/#control)
- [Shell 集成](https://dvloasia.github.io/DccXWeb/#shell) / [Shell Integration](https://dvloasia.github.io/DccXWeb/#shell)
- [内存管理](https://dvloasia.github.io/DccXWeb/#memory) / [Memory Management](https://dvloasia.github.io/DccXWeb/#memory)
- [面向对象编程](https://dvloasia.github.io/DccXWeb/#oop) / [Object-Oriented Programming](https://dvloasia.github.io/DccXWeb/#oop)
- [AI 开发助手](https://dvloasia.github.io/DccXWeb/#ai) / [AI Development Assistant](https://dvloasia.github.io/DccXWeb/#ai)

## 🔧 开发工具 / Development Tools

### 编译器 / Compiler
```bash
dccx -c source.dvx -o output.exe
```

### 解释器 / Interpreter
```bash
dccx source.dvx
```

### AI 助手 / AI Assistant
```bash
dccx -ai source.dvx
```

### 调试器 / Debugger
```bash
dccx -d source.dvx
```

## 📈 发展路线 / Roadmap

### MVP (最小可用产品 / Minimum Viable Product)
- 基础解释器 / Basic interpreter
- Shell 命令执行 / Shell command execution
- 简单语法支持 / Simple syntax support

### Alpha 版本 / Alpha Version
- 完整的词法分析器和解析器 / Complete lexer and parser
- 基础编译器 / Basic compiler
- AI 代码分析 / AI code analysis
- 文档网站 / Documentation website

### Beta 版本 / Beta Version
- 高级特性 / Advanced features
- 性能优化 / Performance optimization
- IDE 集成 / IDE integration
- 社区建设 / Community building

### Release 1.0
- 完整语言特性 / Full language features
- 生产级性能 / Production-ready performance
- 全面文档 / Comprehensive documentation
- 活跃社区 / Active community

## 🤝 贡献指南 / Contributing

<div align="center">

我们欢迎贡献！请在提交前阅读我们的 [贡献指南](CONTRIBUTING.md)。

We welcome contributions! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting.

</div>

### 如何贡献 / How to Contribute
1. Fork 仓库 / Fork the repository
2. 创建特性分支 / Create a feature branch
3. 编写清晰、有文档的代码 / Write clean, documented code
4. 提交 Pull Request / Submit a pull request

### 开发指南 / Development Guidelines
- 遵循现有的编码约定 / Follow existing coding conventions
- 为新增功能编写测试 / Write tests for new features
- 更新文档 / Update documentation
- 保持代码干净模块化 / Keep code clean and modular

## 🌐 社区 / Community

<div align="center">

加入我们的社区讨论想法、获取帮助并分享您的项目：

Join our community to discuss ideas, get help, and share your projects:

</div>

### GitHub
- Issues: 报告问题和提出建议 / Report bugs and suggest features
- Discussions: 一般讨论 / General discussions
- Projects: 项目计划和跟踪 / Project planning and tracking

### Discord
加入我们的 Discord 服务器进行实时聊天和获取支持。
Join our Discord server for real-time chat and support.

### 社交媒体 / Social Media
关注我们的 Twitter 获取更新和公告。
Follow us on Twitter for updates and announcements.

## 📄 许可证 / License

<div align="center">

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件。

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

</div>

## 🙏 致谢 / Acknowledgments

- 灵感源于 Python 的简洁性 / Inspired by Python's simplicity
- 基于 C 语言的性能 / Built on C's performance
- 增强于 Shell 的实用性 / Enhanced by Shell's practicality
- 由现代 AI 技术驱动 / Powered by modern AI technology

---
<div align="center">

**DccX** - 编程语言的未来。在一个强大的语言中融合 Shell、C 和 C++。

**DccX** - The future of programming language. Combining Shell, C, and C++ in one powerful language.

</div>