#!/bin/bash
# DccX 双语网站部署脚本

echo "=== DccX 网站部署 ==="

# 检查 Git 配置
if [ ! -d ".git" ]; then
    echo "初始化 Git 仓库..."
    git init
fi

# 添加所有文件
echo "添加文件到 Git..."
git add .

# 创建提交
echo "创建提交..."
git commit -m "更新：双语网站版本"

# 检查远程仓库
if git remote | grep -q origin; then
    echo "连接到远程仓库..."
    git push origin main
else
    echo "请先设置远程仓库："
    echo "git remote add origin https://github.com/DvloAsia/DccX.git"
    echo "然后运行 git push -u origin main"
fi

echo "部署完成！"
echo "网站地址：https://dvloasia.github.io/DccX/"
echo "中文版：https://dvloasia.github.io/DccX/zh/"
echo "英文版：https://dvloasia.github.io/DccX/en/"