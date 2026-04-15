// DccX 词法分析器
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 1024
#define MAX_TOKEN_LIST 10000

typedef struct Token {
    char type[32];      // 类型：keyword, identifier, operator, literal
    char value[MAX_TOKEN_LENGTH]; // 实际值
    int line;           // 行号
    int column;         // 列号
} Token;

enum TokenType {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATION,
    TOKEN_COMMENT,
    TOKEN_SHELL_COMMAND,
    TOKEN_SYSTEM_CALL,
    TOKEN_ERROR
};

// 关键字列表
const char* keywords[] = {
    "func", "class", "if", "else", "while", "for", "return",
    "import", "var", "num", "str", "bool", "list", "dict",
    "file", "proc", "malloc", "free", "memcpy", "assert",
    "throw", "try", "catch", "async", "await", "shell", "sys",
    "exec", "spawn", "this", "super", "extends", "init", "deinit"
};

// 运算符列表
const char* operators[] = {
    "+", "-", "*", "/", "%", "**", "==", "!=", ">", "<", ">=", "<=",
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=",
    "*=", "/=", "%=", "**=", "&=", "|=", "^=", "<<=", ">>="
};

// 标点符号列表
const char* punctuations[] = {
    "{", "}", "(", ")", "[", "]", ";", ",", ":", ".", "@", "#",
    "$", "?", "?", "\\", "\"", "'", "`", "\\", "|"
};

// 检查是否为关键字
int is_keyword(const char* token) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 检查是否为运算符
int is_operator(const char* token) {
    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (strcmp(token, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 检查是否为标点符号
int is_punctuation(const char* token) {
    for (int i = 0; i < sizeof(punctuations) / sizeof(punctuations[0]); i++) {
        if (strcmp(token, punctuations[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 检查是否为数字
int is_number(const char* token) {
    for (int i = 0; token[i]; i++) {
        if (!isdigit(token[i]) && token[i] != '.' && token[i] != '-' && token[i] != '+') {
            return 0;
        }
    }
    return 1;
}

// 检查是否为字符串
int is_string(const char* token) {
    if (token[0] == '"' && token[strlen(token) - 1] == '"') {
        return 1;
    }
    if (token[0] == '\'' && token[strlen(token) - 1] == '\'') {
        return 1;
    }
    return 0;
}

// 检查是否为注释
int is_comment(const char* token) {
    if (token[0] == '#') {
        return 1;
    }
    if (strncmp(token, "//", 2) == 0) {
        return 1;
    }
    if (strncmp(token, "/*", 2) == 0) {
        return 1;
    }
    return 0;
}

// 检查是否为 Shell 命令
int is_shell_command(const char* token) {
    if (strncmp(token, "shell", 5) == 0) {
        return 1;
    }
    if (strncmp(token, "exec", 4) == 0) {
        return 1;
    }
    if (strncmp(token, "spawn", 5) == 0) {
        return 1;
    }
    return 0;
}

// 检查是否为系统调用
int is_system_call(const char* token) {
    if (strncmp(token, "sys(", 4) == 0) {
        return 1;
    }
    if (strncmp(token, "malloc(", 7) == 0) {
        return 1;
    }
    if (strncmp(token, "free(", 5) == 0) {
        return 1;
    }
    return 0;
}

// 词法分析器主函数
Token* lexer(const char* code, int* token_count) {
    int len = strlen(code);
    Token* tokens = malloc(sizeof(Token) * MAX_TOKEN_LIST);
    int count = 0;
    int line = 1;
    int column = 1;
    int i = 0;
    
    while (i < len && count < MAX_TOKEN_LIST) {
        // 跳过空格
        if (isspace(code[i])) {
            if (code[i] == '\n') {
                line++;
                column = 1;
            } else {
                column++;
            }
            i++;
            continue;
        }
        
        // 处理注释
        if (code[i] == '#') {
            tokens[count].line = line;
            tokens[count].column = column;
            strcpy(tokens[count].type, "comment");
            
            int start = i;
            while (i < len && code[i] != '\n') {
                i++;
            }
            strncpy(tokens[count].value, code + start, i - start);
            tokens[count].value[i - start] = '\0';
            
            column += i - start;
            count++;
            continue;
        }
        
        // 处理数字
        if (isdigit(code[i]) || code[i] == '.' || code[i] == '-' || code[i] == '+') {
            tokens[count].line = line;
            tokens[count].column = column;
            strcpy(tokens[count].type, "number");
            
            int start = i;
            while (i < len && (isdigit(code[i]) || code[i] == '.' || code[i] == '-' || code[i] == '+')) {
                i++;
            }
            strncpy(tokens[count].value, code + start, i - start);
            tokens[count].value[i - start] = '\0';
            
            column += i - start;
            count++;
            continue;
        }
        
        // 处理字符串
        if (code[i] == '"' || code[i] == '\'') {
            tokens[count].line = line;
            tokens[count].column = column;
            strcpy(tokens[count].type, "string");
            
            char quote = code[i];
            int start = i;
            i++; // 跳过开头的引号
            
            while (i < len && code[i] != quote) {
                if (code[i] == '\n') {
                    line++;
                    column = 1;
                }
                i++;
            }
            
            if (i < len) {
                strncpy(tokens[count].value, code + start + 1, i - start - 1);
                tokens[count].value[i - start - 1] = '\0';
                i++; // 跳过结尾的引号
            } else {
                strcpy(tokens[count].type, "error");
                strcpy(tokens[count].value, "Unclosed string");
            }
            
            column += i - start;
            count++;
            continue;
        }
        
        // 处理标识符
        if (isalpha(code[i]) || code[i] == '_') {
            tokens[count].line = line;
            tokens[count].column = column;
            
            int start = i;
            while (i < len && (isalnum(code[i]) || code[i] == '_')) {
                i++;
            }
            
            char identifier[MAX_TOKEN_LENGTH];
            strncpy(identifier, code + start, i - start);
            identifier[i - start] = '\0';
            
            // 检查类型
            if (is_keyword(identifier)) {
                strcpy(tokens[count].type, "keyword");
            } else if (is_shell_command(identifier)) {
                strcpy(tokens[count].type, "shell_command");
            } else if (is_system_call(identifier)) {
                strcpy(tokens[count].type, "system_call");
            } else {
                strcpy(tokens[count].type, "identifier");
            }
            
            strcpy(tokens[count].value, identifier);
            column += i - start;
            count++;
            continue;
        }
        
        // 处理运算符和标点符号
        char token[MAX_TOKEN_LENGTH] = {0};
        int token_len = 0;
        
        // 收集符号
        while (i < len && !isspace(code[i]) && !isalnum(code[i])) {
            token[token_len++] = code[i];
            i++;
        }
        
        if (token_len > 0) {
            tokens[count].line = line;
            tokens[count].column = column;
            
            token[token_len] = '\0';
            
            if (is_operator(token)) {
                strcpy(tokens[count].type, "operator");
            } else if (is_punctuation(token)) {
                strcpy(tokens[count].type, "punctuation");
            } else {
                strcpy(tokens[count].type, "unknown");
            }
            
            strcpy(tokens[count].value, token);
            column += token_len;
            count++;
            continue;
        }
        
        // 未知字符
        tokens[count].line = line;
        tokens[count].column = column;
        strcpy(tokens[count].type, "error");
        tokens[count].value[0] = code[i];
        tokens[count].value[1] = '\0';
        i++;
        column++;
        count++;
    }
    
    *token_count = count;
    return tokens;
}

// 打印 Token 列表
void print_tokens(Token* tokens, int count) {
    printf("=== Lexer Tokens ===\n");
    for (int i = 0; i < count; i++) {
        printf("Token %d: [%s] '%s' at line %d, column %d\n", 
               i, tokens[i].type, tokens[i].value, tokens[i].line, tokens[i].column);
    }
}

// 测试词法分析器
int test_lexer() {
    const char* test_code = "#main {\n    print \"Hello DccX\"\n    shell \"ls -la\"\n    var x = 10 + 5\n}";
    
    int token_count;
    Token* tokens = lexer(test_code, &token_count);
    
    if (tokens) {
        print_tokens(tokens, token_count);
        free(tokens);
        return 1;
    }
    
    return 0;
}

// 词法分析器主函数（用于测试）
int main_lexer(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }
    
    char code[10000];
    int code_len = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        code[code_len++] = ch;
    }
    code[code_len] = '\0';
    
    fclose(file);
    
    int token_count;
    Token* tokens = lexer(code, &token_count);
    
    if (tokens) {
        printf("=== Lexer Analysis ===\n");
        printf("Total tokens: %d\n", token_count);
        
        // 统计各类 Token
        int keywords = 0;
        int identifiers = 0;
        int numbers = 0;
        int strings = 0;
        int operators = 0;
        int punctuations = 0;
        int comments = 0;
        int shell_commands = 0;
        int system_calls = 0;
        
        for (int i = 0; i < token_count; i++) {
            if (strcmp(tokens[i].type, "keyword") == 0) keywords++;
            else if (strcmp(tokens[i].type, "identifier") == 0) identifiers++;
            else if (strcmp(tokens[i].type, "number") == 0) numbers++;
            else if (strcmp(tokens[i].type, "string") == 0) strings++;
            else if (strcmp(tokens[i].type, "operator") == 0) operators++;
            else if (strcmp(tokens[i].type, "punctuation") == 0) punctuations++;
            else if (strcmp(tokens[i].type, "comment") == 0) comments++;
            else if (strcmp(tokens[i].type, "shell_command") == 0) shell_commands++;
            else if (strcmp(tokens[i].type, "system_call") == 0) system_calls++;
        }
        
        printf("\nToken Statistics:\n");
        printf("Keywords: %d\n", keywords);
        printf("Identifiers: %d\n", identifiers);
        printf("Numbers: %d\n", numbers);
        printf("Strings: %d\n", strings);
        printf("Operators: %d\n", operators);
        printf("Punctuations: %d\n", punctuations);
        printf("Comments: %d\n", comments);
        printf("Shell Commands: %d\n", shell_commands);
        printf("System Calls: %d\n", system_calls);
        
        free(tokens);
        return 1;
    }
    
    return 0;
}