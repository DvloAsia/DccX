# GitHub 仓库重命名计划

## 当前状态
- **旧仓库名**: `dccx.github.io`
- **旧网址**: https://dvloasia.github.io/dccx.github.io/
- **新仓库名**: `DccX`
- **新网址**: https://dvloasia.github.io/DccX/

## GitHub 仓库重命名步骤
1. **访问 GitHub**: https://github.com/DvloAsia/dccx.github.io
2. **进入 Settings**: 仓库页面右上角 Settings 按钮
3. **重命名仓库**: General 选项卡 -> Repository name
4. **修改为**: DccX
5. **确认**: 会显示 "Will be available at https://github.com/DvloAsia/DccX"

## GitHub Pages 更新步骤
1. **进入 Pages**: Settings -> Pages
2. **修改设置**: 
   - Branch: main
   - Folder: /
   - Save
3. **等待部署**: GitHub Pages 会自动重新部署

## 网站更新步骤
1. **更新网站配置**: 修改 _config.yml 中的 url 和 baseurl
2. **更新 CNAME**: 如果需要自定义域名
3. **更新 README**: 修改所有链接指向新网址
4. **测试访问**: 访问 https://dvloasia.github.io/DccX/

## 注意事项
1. **GitHub Pages 会自动更新网址**
2. **旧链接可能会暂时失效**
3. **建议在新的仓库名生效后，立即更新网站内容**
4. **验证新网址是否可以正常访问**

## 备份
如果不想重命名仓库，也可以考虑：
1. 创建新的 `DccX` 仓库
2. 把内容复制到新仓库
3. 删除旧的 `dccx.github.io` 仓库
4. 设置 GitHub Pages 为新仓库