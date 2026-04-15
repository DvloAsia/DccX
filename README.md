# DccX Programming Language

**DccX** is a revolutionary programming language that combines the convenience of Shell scripting with the power of C and the advanced features of C++. Designed for modern development, DccX makes system programming, automation, and rapid development accessible to everyone.

## Features

### Shell Integration
Execute shell commands directly within your code:
```dvx
shell "ls -la"
var output = exec("date")
```

### C Language Performance
Low-level system programming capabilities:
```dvx
var buffer = malloc(1024)
memcpy(buffer, "data", 4)
free(buffer)
```

### C++ Object-Oriented Features
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

### AI-Assisted Development
Smart code analysis and suggestions:
```dvx
# AI will analyze your code and provide optimization suggestions
```

### Cross-Platform Support
Works on Termux, Linux, Windows, and macOS.

## Installation

### Termux (Android)
```bash
pkg update
pkg install git gcc make
git clone https://github.com/dvlo/DccX
cd DccX
make
./dccx examples/test.dvx
```

### Linux
```bash
sudo apt update
sudo apt install git gcc make
git clone https://github.com/dvlo/DccX
cd DccX
make
sudo make install
```

### Windows
Download pre-built binaries or use MinGW to compile from source.

## Quick Start

### Basic Program
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

### Advanced Example
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

## Documentation

Complete documentation available at: https://dvlo.github.io/DccX/

### Quick Links
- [Installation Guide](https://dvlo.github.io/DccX/#install)
- [Basic Syntax](https://dvlo.github.io/DccX/#basic)
- [Variables and Types](https://dvlo.github.io/DccX/#variables)
- [Functions](https://dvlo.github.io/DccX/#functions)
- [Control Structures](https://dvlo.github.io/DccX/#control)
- [Shell Integration](https://dvlo.github.io/DccX/#shell)
- [Memory Management](https://dvlo.github.io/DccX/#memory)
- [Object-Oriented Programming](https://dvlo.github.io/DccX/#oop)
- [AI Development Assistant](https://dvlo.github.io/DccX/#ai)

## Development Tools

### Compiler
```bash
dccx -c source.dvx -o output.exe
```

### Interpreter
```bash
dccx source.dvx
```

### AI Assistant
```bash
dccx -ai source.dvx
```

### Debugger
```bash
dccx -d source.dvx
```

## Roadmap

### MVP (Minimum Viable Product)
- Basic interpreter
- Shell command execution
- Simple syntax support

### Alpha Version
- Complete lexer and parser
- Basic compiler
- AI code analysis
- Documentation website

### Beta Version
- Advanced features
- Performance optimization
- IDE integration
- Community building

### Release 1.0
- Full language features
- Production-ready performance
- Comprehensive documentation
- Active community

## Contributing

We welcome contributions! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting.

### How to Contribute
1. Fork the repository
2. Create a feature branch
3. Write clean, documented code
4. Submit a pull request

### Development Guidelines
- Follow existing coding conventions
- Write tests for new features
- Update documentation
- Keep code clean and modular

## Community

Join our community to discuss ideas, get help, and share your projects:

### GitHub
- Issues: Report bugs and suggest features
- Discussions: General discussions
- Projects: Project planning and tracking

### Discord
Join our Discord server for real-time chat and support.

### Social Media
Follow us on Twitter for updates and announcements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by Python's simplicity
- Built on C's performance
- Enhanced by Shell's practicality
- Powered by modern AI technology

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=dvlo/DccX&type=Date)](https://star-history.com/#dvlo/DccX&Date)

---
**DccX** - The future of programming language. Combining Shell, C, and C++ in one powerful language.