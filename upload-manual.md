# DccX 项目上传指南

## GitHub 仓库准备

### 1. 创建 GitHub 仓库
首先，在你的 GitHub 账户中创建新仓库：

1. 登录 GitHub：https://github.com
2. 点击右上角的 "+" 图标，选择 "New repository"
3. 输入仓库名称：`dccx.github.io`
4. 描述：DccX Programming Language
5. 选择公开（Public）
6. 不要初始化 README（因为已经有文件）
7. 点击 "Create repository"

### 2. 配置本地项目
在你的计算机上运行以下命令：

```bash
# 克隆项目到你的计算机
git clone https://github.com/dvloasia/dccx.github.io.git
# 或者创建新仓库后，使用以下命令：
git init
git add .
git commit -m "DccX 项目初始版本"
git branch -M main
git remote add origin https://github.com/dvloasia/dccx.github.io.git
git push -u origin main
```

## 项目文件说明

### 核心文件
- **编译器/解释器**：`src/main.c`, `src/lexer.c`, `src/ai_assistant.c`
- **语法规范**：`syntax.md`, `architecture.md`
- **开发计划**：`project-plan.md`, `DEVELOPMENT.md`
- **Makefile**：项目构建配置

### 网站文件
- **主网站**：`website/index.html`
- **文档**：`website/documentation.html`
- **示例**：`website/examples.html`
- **下载页面**：`website/download.html`
- **404页面**：`website/404.html`

### GitHub Pages 配置
- **配置文件**：`website/_config.yml`
- **CNAME**：`website/CNAME`
- **GitHub Actions**：`.github/workflows/pages.yml`
- **GitHub Actions**：`.github/workflows/test.yml`
- **GitHub Actions**：`.github/workflows/deploy.yml`

### 示例和测试
- **示例代码**：`examples/test.dvx`
- **测试代码**：`test/test_lexer.dvx`, `test/test_ai.dvx`

## GitHub Pages 设置

### 1. 启用 GitHub Pages
在你的 GitHub 仓库设置中启用 GitHub Pages：

1. 进入仓库：https://github.com/dvloasia/dccx.github.io
2. 点击 "Settings"
3. 左侧菜单选择 "Pages"
4. 在 "Source" 中选择 "GitHub Actions"
5. GitHub Actions 会自动部署网站

### 2. GitHub Actions 配置
项目已包含以下 GitHub Actions：

- **pages.yml**：部署网站到 GitHub Pages
- **test.yml**：运行自动测试
- **deploy.yml**：完整的部署配置

### 3. 自定义域名
如果你想使用自定义域名：

1. 设置 CNAME 文件：`website/CNAME`
2. 内容为：`dccx.dev`（或你的域名）
3. 在你的 DNS 提供商配置域名指向 GitHub Pages

## 手动上传方法

如果你遇到推送问题，可以使用以下方法：

### 方法 1：使用 GitHub Desktop
1. 下载 GitHub Desktop：https://desktop.github.com/
2. 克隆仓库到本地
3. 将 DccX 项目文件复制到仓库目录
4. 提交并推送

### 方法 2：使用网页上传
1. 访问 GitHub 仓库
2. 点击 "Upload files"
3. 选择所有项目文件
4. 输入提交信息："Initial commit"

### 方法 3：使用 ZIP 上传
```bash
# 压缩项目
tar -czvf dccx.tar.gz DccX/

# 上传到 GitHub
# 使用 GitHub 网页上传功能
```

## GitHub Pages 访问

上传成功后：
1. GitHub Pages 会自动构建网站
2. 访问地址：https://dvloasia.github.io/dccx.github.io/
3. 或自定义域名：https://dccx.dev/

## 项目更新

### 日常更新
```bash
# 添加修改
git add .
git commit -m "更新描述"
git push
```

### GitHub Actions 自动部署
每次推送后，GitHub Actions 会自动：
1. 测试项目
2. 构建网站
3. 部署到 GitHub Pages

## 网站内容

### 主页
- 语言特性介绍
- 快速开始指南
- 下载链接
- 社区链接

### 文档系统
- 完整的语法文档
- API 参考手册
- 示例代码
- 使用指南

### 示例页面
- 基础示例
- Shell 集成示例
- 内存管理示例
- 面向对象示例
- AI 助手示例

## 后续开发

### 持续开发
1. 完善编译器功能
2. 扩展语法特性
3. 增强 AI 助手
4. 丰富示例和文档

### 社区建设
1. GitHub Issues 收集反馈
2. 建立 Discord 社区
3. 编写教程文章
4. 推广项目

### 网站改进
1. 添加更多示例
2. 完善文档内容
3. 添加在线编辑器
4. 添加实时演示

---

这个项目包含了完整的 DccX 语言系统，包括：
- 编译器/解释器框架
- 完整的语法规范
- AI 辅助开发功能
- 完整的网站系统
- GitHub Pages 部署配置

你可以在 GitHub 上查看完整项目，并根据需要进一步开发。