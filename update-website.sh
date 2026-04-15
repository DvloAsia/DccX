#!/bin/bash
# 更新 DccX 网站到 GitHub

echo "=== DccX 网站更新 ==="

echo "1. 检查当前仓库..."
git remote -v

echo "2. 添加网站文件..."
git add website/
git add README.md

echo "3. 提交更改..."
git commit -m "更新：双语网站，优化设计，语言切换功能"

echo "4. 推送到 GitHub..."
git push origin main

echo "5. 等待 GitHub Pages 部署..."
echo "部署完成后，访问："
echo "主网站: https://dvloasia.github.io/DccX/"
echo "中文版: https://dvloasia.github.io/DccX/zh/"
echo "英文版: https://dvloasia.github.io/DccX/en/"
echo ""

echo "如果需要重命名仓库，请访问 GitHub 设置页面："
echo "https://github.com/DvloAsia/dccx.github.io/settings"
echo "将仓库名从 'dccx.github.io' 改为 'DccX'"