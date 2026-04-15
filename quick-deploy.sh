#!/bin/bash
# DccX 快速部署脚本

echo "=== DccX 项目部署 ==="

# 创建 GitHub 仓库（Web 方式）
echo "1. 请访问 https://github.com 创建新仓库：dccx.github.io"
echo "2. 确保仓库名称格式为：username.github.io（GitHub Pages 要求）"
echo "3. 不要初始化 README.md"

# 获取仓库信息
echo "请输入你的 GitHub 用户名："
read username
echo "请输入你的 GitHub 仓库名（必须是 username.github.io）："
read repo_name

# 检查 SSH 密钥
echo "4. 检查 SSH 密钥..."
if [ ! -f ~/.ssh/id_ed25519 ]; then
    echo "生成 SSH 密钥..."
    ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519 -C "$username@example.com" -N ""
fi

echo "你的 SSH 公钥："
cat ~/.ssh/id_ed25519.pub

echo "5. 将此公钥添加到 GitHub："
echo "   访问 https://github.com/settings/keys"
echo "   点击 'New SSH key'"
echo "   粘贴公钥内容"
echo "   点击 'Add SSH key'"

# 设置 Git 远程仓库
echo "6. 设置 Git 远程仓库..."
git remote remove origin
git remote add origin git@github.com:$username/$repo_name.git

echo "7. 推送代码..."
git push -u origin main

# 备用方案：Web 上传
echo "8. 备用方案：如果 SSH 推送失败，请使用 Web 上传"
echo "   - 访问 https://github.com/$username/$repo_name"
echo "   - 点击 'Upload files'"
echo "   - 上传 dccx.tar.gz 文件"
echo "   - 解压并提交"

# GitHub Pages 配置
echo "9. 启用 GitHub Pages："
echo "   - 进入仓库 Settings"
echo "   - 选择 Pages"
echo "   - 选择 'GitHub Actions'"
echo "   - 等待部署完成"

# 网站 URL
echo "10. 网站 URL：https://$username.github.io/$repo_name"

echo "=== 部署完成 ==="
echo "请按照以上步骤完成部署。"