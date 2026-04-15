// DccX 语言解释器 - 最小框架
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

// 简单的命令解析和执行
void execute_shell_command(const char* cmd) {
    printf("[DccX] Executing shell command: %s\n", cmd);
    system(cmd);
}

// 解析 DccX 代码
void parse_dvx_line(const char* line) {
    // 检测 shell 命令（以 "shell " 开头）
    if (strncmp(line, "shell ", 6) == 0) {
        execute_shell_command(line + 6);
    }
    // 检测 print 语句
    else if (strncmp(line, "print ", 6) == 0) {
        printf("%s\n", line + 6);
    }
    // 检测变量声明
    else if (strstr(line, "int ") || strstr(line, "string ")) {
        printf("[DccX] Variable declaration detected: %s\n", line);
    }
    else {
        printf("[DccX] Unknown statement: %s\n", line);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file.dvx>\n", argv[0]);
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }
    
    char line[MAX_LINE_LENGTH];
    printf("=== DccX Interpreter ===\n");
    
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // 移除换行符
        line[strcspn(line, "\n")] = 0;
        
        // 跳过空行和注释
        if (line[0] == '\0' || line[0] == '#') {
            continue;
        }
        
        parse_dvx_line(line);
    }
    
    fclose(file);
    printf("=== Execution Complete ===\n");
    return 0;
}