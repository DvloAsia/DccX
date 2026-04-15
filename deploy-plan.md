# DccX 网站部署计划

## 目标网站结构
```
https://dvloasia.github.io/DccX/
├── zh/ (中文网站)
├── en/ (英文网站)
├── assets/ (共享资源)
├── index.html (语言选择主页)
```

## 步骤
1. **备份原网站**：备份当前 website/ 目录的内容
2. **替换新网站**：用 new-website/ 替换 website/ 目录
3. **修改 GitHub 设置**：
   - 修改仓库名称：从 `dccx.github.io` 改为 `DccX`
   - 更新 GitHub Pages 配置
4. **部署测试**：验证网站可以正常访问

## 关键修改
1. **仓库名称**：从 `dccx.github.io` 改为 `DccX`
2. **网站地址**：从 `https://dvloasia.github.io/dccx.github.io/` 改为 `https://dvloasia.github.io/DccX/`
3. **双语支持**：添加语言切换功能
4. **响应式设计**：优化移动端、平板、电脑显示

## 风险点
1. 原网站链接需要更新
2. GitHub Pages 配置需要修改
3. CNAME 域名配置可能需要调整
4. 测试双语切换功能