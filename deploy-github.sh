#!/bin/bash
# DccX GitHub 部署脚本

# 初始化 Git 仓库
if [ ! -d ".git" ]; then
    echo "初始化 Git 仓库..."
    git init
fi

# 设置 GitHub 仓库信息
GITHUB_USERNAME="dvlo"
REPO_NAME="DccX"

# 检查是否已经连接到远程仓库
if ! git remote | grep -q origin; then
    echo "请先设置远程仓库："
    echo "git remote add origin https://github.com/$GITHUB_USERNAME/$REPO_NAME.git"
    exit 1
fi

# 添加所有文件
echo "添加文件到 Git..."
git add .

# 创建提交
echo "创建提交..."
git commit -m "DccX 项目初始版本"

# 推送到 GitHub
echo "推送到 GitHub..."
git push origin main

# 创建 GitHub Pages（如果需要）
echo "设置 GitHub Pages..."
echo "1. 访问 https://github.com/$GITHUB_USERNAME/$REPO_NAME/settings/pages"
echo "2. 选择分支：main"
echo "3. 选择文件夹：/website"
echo "4. 保存设置"

# 创建 GitHub Actions 自动部署脚本
echo "创建 GitHub Actions 部署脚本..."
mkdir -p .github/workflows

# GitHub Pages 部署配置文件
cat > .github/workflows/deploy.yml << EOF
name: Deploy to GitHub Pages

on:
  push:
    branches: [main]
  workflow_dispatch:

jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - name: Setup Pages
        uses: actions/configure-pages@v3
      - name: Upload artifact
        uses: actions/upload-pages-artifact@v2
        with:
          path: 'website'
      - name: Deploy to GitHub Pages
        id: deployment
        uses: actions/deploy-pages@v2
EOF

# 创建项目 README
cat > README.md << EOF
# DccX Programming Language

DccX is a revolutionary programming language that combines the convenience of Shell scripting with the power of C and the advanced features of C++.

## Features
- Shell command integration
- C language performance
- C++ object-oriented features
- Unique syntax design
- Cross-platform support
- AI-assisted development

## Installation

### Termux (Android)
```bash
pkg update
pkg install git gcc make
git clone https://github.com/$GITHUB_USERNAME/$REPO_NAME
cd $REPO_NAME
make
./dccx examples/test.dvx
```

### Linux
```bash
sudo apt update
sudo apt install git gcc make
git clone https://github.com/$GITHUB_USERNAME/$REPO_NAME
cd $REPO_NAME
make
sudo make install
```

### Windows
Download pre-built binaries or use MinGW to compile from source.

## Quick Start

Create a simple DccX program:

```dvx
#main {
    print "Hello, DccX!"
    shell "ls -la"
    var x = 10
    print x
}
```

Run it with:
```bash
dccx program.dvx
```

## Documentation

Visit our [documentation website](https://$GITHUB_USERNAME.github.io/$REPO_NAME/) for complete guides and tutorials.

## Contributing

We welcome contributions! Please read our [Contributing Guidelines](CONTRIBUTING.md).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
EOF

# 创建许可证文件
cat > LICENSE << EOF
MIT License

Copyright (c) 2024 $GITHUB_USERNAME

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
EOF

# 创建贡献指南
cat > CONTRIBUTING.md << EOF
# Contributing to DccX

We welcome contributions from the community! Here's how you can help:

## How to Contribute

### 1. Reporting Issues
- Use GitHub Issues
- Provide detailed description
- Include code examples if applicable

### 2. Suggesting Features
- Create a feature request issue
- Explain the purpose and benefits
- Suggest implementation ideas

### 3. Submitting Code
- Fork the repository
- Create a feature branch
- Write clean, documented code
- Submit a pull request

## Development Guidelines

### Code Style
- Follow existing coding conventions
- Write clear, commented code
- Use meaningful variable names

### Testing
- Add tests for new features
- Ensure existing tests pass
- Test edge cases and errors

### Documentation
- Update relevant documentation
- Add examples for new features
- Keep README up to date

## Pull Request Process

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Development Setup

### Prerequisites
- Git
- GCC or Clang
- Make

### Building
```bash
make
```

### Testing
```bash
make test
```

## Community

Join our [Discord community](link-to-discord) to discuss ideas and get help.

Thank you for contributing to DccX!
EOF

# 创建更多示例文件
mkdir -p examples
cat > examples/advanced.dvx << EOF
# DccX 高级示例

import sys
import math

class Calculator {
    var value = 0
    
    func add(num) {
        this.value += num
        return this.value
    }
    
    func multiply(num) {
        this.value *= num
        return this.value
    }
    
    func reset() {
        this.value = 0
    }
}

#main {
    # 创建对象
    calc = Calculator()
    
    # 使用对象
    print "初始值: " + calc.value
    calc.add(10)
    print "加法后: " + calc.value
    calc.multiply(2)
    print "乘法后: " + calc.value
    
    # 复杂操作
    files = exec("ls *.dvx")
    
    # 处理文件列表
    for file in files.split("\n") {
        if file != "" {
            # 获取文件信息
            size = exec("stat -c%s " + file)
            print "文件: " + file + ", 大小: " + size
            
            # 文件操作
            if size.to_num() > 1000 {
                sys("mv " + file + " large_files/")
            }
        }
    }
    
    # 内存管理（C 风格）
    buffer = malloc(1024)
    memcpy(buffer, "数据", 4)
    free(buffer)
}
EOF

echo "GitHub 部署脚本完成！"
echo "下一步："
echo "1. 运行 ./deploy-github.sh 初始化仓库"
echo "2. 将仓库推送到 GitHub"
echo "3. 启用 GitHub Pages"
echo "4. 更新仓库中的网站内容"