#!/bin/bash
# DccX 网站部署脚本

echo "=== DccX 双语网站部署 ==="

# 设置变量
REPO_NAME="DccX"
GITHUB_USERNAME="dvloasia"

echo "1. 添加网站文件..."
git add website/
git add README.md

echo "2. 创建提交..."
git commit -m "更新：双语网站，响应式设计"

echo "3. 推送到 GitHub..."
git push origin main

echo "4. 更新 GitHub Pages 设置..."
echo "   a. 访问 https://github.com/$GITHUB_USERNAME/$REPO_NAME/settings/pages"
echo "   b. 选择分支：main"
echo "   c. 选择文件夹：/ (root)"
echo "   d. 保存设置"

echo "网站部署完成！"
echo "新网址：https://dvloasia.github.io/DccX/"
echo "语言选择页面：https://dvloasia.github.io/DccX/"
echo "中文版：https://dvloasia.github.io/DccX/zh/"
echo "英文版：https://dvloasia.github.io/DccX/en/"