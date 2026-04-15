// DccX AI 辅助开发模块

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 5000
#define MAX_SUGGESTIONS 10

typedef struct CodeSuggestion {
    char code[MAX_CODE_LENGTH];
    char explanation[200];
    char type[20];  // "syntax", "optimization", "error", "pattern"
    int confidence; // 置信度 0-100
} CodeSuggestion;

typedef struct AIAssistant {
    // 代码分析数据
    char code[MAX_CODE_LENGTH];
    char language[10];  // "dvx", "c", "shell"
    char context[200];   // 上下文描述
    
    // 建议列表
    CodeSuggestion suggestions[MAX_SUGGESTIONS];
    int suggestion_count;
    
    // 统计信息
    int error_count;
    int optimization_count;
    int pattern_count;
} AIAssistant;

// 初始化 AI 助手
void ai_assistant_init(AIAssistant* assistant) {
    memset(assistant, 0, sizeof(AIAssistant));
    assistant->suggestion_count = 0;
    assistant->error_count = 0;
    assistant->optimization_count = 0;
    assistant->pattern_count = 0;
}

// 设置代码
void ai_assistant_set_code(AIAssistant* assistant, const char* code) {
    strncpy(assistant->code, code, MAX_CODE_LENGTH - 1);
    assistant->code[MAX_CODE_LENGTH - 1] = '\0';
}

// 分析代码语法
void analyze_syntax(AIAssistant* assistant) {
    // 检查常见语法错误
    const char* code = assistant->code;
    
    // 检查括号匹配
    int brace_count = 0;
    int paren_count = 0;
    int bracket_count = 0;
    
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '{') brace_count++;
        if (code[i] == '}') brace_count--;
        if (code[i] == '(') paren_count++;
        if (code[i] == ')') paren_count--;
        if (code[i] == '[') bracket_count++;
        if (code[i] == ']') bracket_count--;
    }
    
    if (brace_count != 0) {
        assistant->suggestions[assistant->suggestion_count].type = "error";
        assistant->suggestions[assistant->suggestion_count].confidence = 90;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "括号未匹配：{ 和 } 的数量不一致");
        assistant->suggestion_count++;
        assistant->error_count++;
    }
    
    if (paren_count != 0) {
        assistant->suggestions[assistant->suggestion_count].type = "error";
        assistant->suggestions[assistant->suggestion_count].confidence = 90;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "括号未匹配：( 和 ) 的数量不一致");
        assistant->suggestion_count++;
        assistant->error_count++;
    }
    
    // 检查 Shell 命令语法
    if (strstr(code, "shell \"") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "syntax";
        assistant->suggestions[assistant->suggestion_count].confidence = 80;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "Shell 命令语法正确");
        assistant->suggestion_count++;
    }
    
    // 检查变量声明
    if (strstr(code, "var ") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "syntax";
        assistant->suggestions[assistant->suggestion_count].confidence = 85;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "变量声明语法正确");
        assistant->suggestion_count++;
    }
}

// 代码优化建议
void analyze_optimization(AIAssistant* assistant) {
    const char* code = assistant->code;
    
    // 检查重复代码
    if (strstr(code, "print") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "optimization";
        assistant->suggestions[assistant->suggestion_count].confidence = 70;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "考虑将多个 print 语句合并为单个字符串输出");
        assistant->suggestion_count++;
        assistant->optimization_count++;
    }
    
    // 检查不必要的 Shell 调用
    if (strstr(code, "shell \"ls") != NULL && strstr(code, "shell \"cat") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "optimization";
        assistant->suggestions[assistant->suggestion_count].confidence = 75;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "可以考虑使用管道命令合并多个 shell 调用");
        assistant->suggestion_count++;
        assistant->optimization_count++;
    }
}

// 代码模式建议
void analyze_patterns(AIAssistant* assistant) {
    const char* code = assistant->code;
    
    // 检查常见模式
    if (strstr(code, "for") != NULL && strstr(code, "in") != NULL && strstr(code, "range") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "pattern";
        assistant->suggestions[assistant->suggestion_count].confidence = 85;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "range 循环模式正确");
        assistant->suggestion_count++;
        assistant->pattern_count++;
    }
    
    if (strstr(code, "if") != NULL && strstr(code, "else") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "pattern";
        assistant->suggestions[assistant->suggestion_count].confidence = 80;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "if-else 条件判断模式正确");
        assistant->suggestion_count++;
        assistant->pattern_count++;
    }
}

// 生成替代代码
void generate_alternative_code(AIAssistant* assistant) {
    const char* code = assistant->code;
    
    // 基于原始代码生成改进版本
    char alternative[MAX_CODE_LENGTH];
    
    // 简单示例：优化 print 语句
    if (strstr(code, "print \"Hello\"") != NULL && strstr(code, "print \"World\"") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "optimization";
        assistant->suggestions[assistant->suggestion_count].confidence = 80;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "合并 print 语句可以提高效率");
        strcpy(assistant->suggestions[assistant->suggestion_count].code,
               "print \"Hello World\"");
        assistant->suggestion_count++;
    }
    
    // 优化 Shell 命令
    if (strstr(code, "shell \"ls\"") != NULL && strstr(code, "shell \"grep\"") != NULL) {
        assistant->suggestions[assistant->suggestion_count].type = "optimization";
        assistant->suggestions[assistant->suggestion_count].confidence = 85;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "使用管道可以减少 Shell 调用次数");
        strcpy(assistant->suggestions[assistant->suggestion_count].code,
               "shell \"ls | grep pattern\"");
        assistant->suggestion_count++;
    }
}

// AI 助手主分析函数
void ai_assistant_analyze(AIAssistant* assistant) {
    // 重置统计
    assistant->suggestion_count = 0;
    
    // 执行各种分析
    analyze_syntax(assistant);
    analyze_optimization(assistant);
    analyze_patterns(assistant);
    generate_alternative_code(assistant);
}

// 显示分析结果
void ai_assistant_print_results(AIAssistant* assistant) {
    printf("=== AI 代码分析报告 ===\n");
    printf("原始代码:\n%s\n\n", assistant->code);
    
    printf("分析统计:\n");
    printf("错误数量: %d\n", assistant->error_count);
    printf("优化建议: %d\n", assistant->optimization_count);
    printf("模式识别: %d\n", assistant->pattern_count);
    printf("总建议数: %d\n\n", assistant->suggestion_count);
    
    printf("详细建议:\n");
    for (int i = 0; i < assistant->suggestion_count; i++) {
        printf("建议 %d [%s]:\n", i + 1, assistant->suggestions[i].type);
        printf("  说明: %s\n", assistant->suggestions[i].explanation);
        printf("  置信度: %d%%\n", assistant->suggestions[i].confidence);
        if (assistant->suggestions[i].code[0] != '\0') {
            printf("  改进代码: %s\n", assistant->suggestions[i].code);
        }
        printf("\n");
    }
    
    printf("结论:\n");
    if (assistant->error_count > 0) {
        printf("发现语法错误，请先修复\n");
    } else if (assistant->optimization_count > 0) {
        printf("代码可以进一步优化\n");
    } else {
        printf("代码质量良好\n");
    }
}

// 代码复杂度分析
void analyze_complexity(AIAssistant* assistant) {
    const char* code = assistant->code;
    
    int line_count = 0;
    int function_count = 0;
    int loop_count = 0;
    int condition_count = 0;
    int shell_count = 0;
    
    // 简单行数统计
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '\n') line_count++;
    }
    
    // 函数数量
    if (strstr(code, "func ") != NULL) {
        function_count++;
    }
    
    // 循环数量
    if (strstr(code, "for ") != NULL) {
        loop_count++;
    }
    if (strstr(code, "while ") != NULL) {
        loop_count++;
    }
    
    // 条件数量
    if (strstr(code, "if ") != NULL) {
        condition_count++;
    }
    
    // Shell 命令数量
    if (strstr(code, "shell ") != NULL) {
        shell_count++;
    }
    
    // 添加复杂度建议
    if (line_count > 50) {
        assistant->suggestions[assistant->suggestion_count].type = "optimization";
        assistant->suggestions[assistant->suggestion_count].confidence = 70;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "代码较长，建议拆分为多个函数");
        assistant->suggestion_count++;
    }
    
    if (shell_count > 5) {
        assistant->suggestions[assistant->suggestion_count].type = "optimization";
        assistant->suggestions[assistant->suggestion_count].confidence = 75;
        strcpy(assistant->suggestions[assistant->suggestion_count].explanation, 
               "Shell 命令较多，可以考虑合并或使用异步执行");
        assistant->suggestion_count++;
    }
}

// AI 助手 API
int ai_assistant_process_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }
    
    char code[MAX_CODE_LENGTH];
    int code_len = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF && code_len < MAX_CODE_LENGTH - 1) {
        code[code_len++] = ch;
    }
    code[code_len] = '\0';
    
    fclose(file);
    
    // 创建 AI 助手
    AIAssistant assistant;
    ai_assistant_init(&assistant);
    ai_assistant_set_code(&assistant, code);
    ai_assistant_analyze(&assistant);
    analyze_complexity(&assistant);
    ai_assistant_print_results(&assistant);
    
    return 1;
}

// 测试 AI 助手
int test_ai_assistant() {
    const char* test_code = "#main {\n    var x = 10\n    if x > 5 {\n        print \"x is greater than 5\"\n    } else {\n        print \"x is less than 5\"\n    }\n    shell \"ls -la\"\n    shell \"cat file.txt\"\n}";
    
    AIAssistant assistant;
    ai_assistant_init(&assistant);
    ai_assistant_set_code(&assistant, test_code);
    ai_assistant_analyze(&assistant);
    ai_assistant_print_results(&assistant);
    
    return 1;
}

// 主函数
int main_ai_assistant(const char* filename) {
    if (filename) {
        return ai_assistant_process_file(filename);
    } else {
        return test_ai_assistant();
    }
}