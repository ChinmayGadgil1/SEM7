#include <bits/stdc++.h>
using namespace std;

bool isFloat(string s)
{
    bool hasPoint = false;
    for (auto c : s)
    {

        if ((c < '0' || c > '9') && c != '.')
        {
            return false;
        }
        if (c == '.')
        {
            if (hasPoint)
                return false;
            hasPoint = true;
        }
    }
    return hasPoint;
}
bool isOperator(string s)
{
    if (s == "==" || s == "!=" || s == "<=" || s == ">=" || s == "++" || s == "--" || s == "+=" || s == "-=")
    {
        return true;
    }
    if (s.length() > 1)
        return false;
    if (s[0] == '=' || s[0] == '!' || s[0] == '<' || s[0] == '>')
    {
        return true;
    }

    return false;
}
bool isKeyword(string s)
{
    unordered_set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "class", "const_cast", "delete", "dynamic_cast", "explicit", "export", "false", "friend", "inline", "mutable", "namespace", "new", "operator", "private", "protected", "public", "reinterpret_cast", "static_cast", "template", "this", "true", "typeid", "typename", "using", "virtual", "catch", "throw", "try", "alignas", "alignof", "char8_t", "char16_t", "char32_t", "concept", "consteval", "constexpr", "constinit", "co_await", "co_return", "co_yield", "decltype", "noexcept", "nullptr", "requires", "thread_local", "wchar_t", "and", "and_eq", "bitand", "bitor", "compl", "not", "not_eq", "or", "or_eq", "xor", "xor_eq"};

    return keywords.find(s) != keywords.end();
}

int main()
{
    string input;
    while (true)
    {
        cout << "Enter i/p(ESC to exit):";
        getline(cin, input);
        if(input=="ESC") break;
        if (isFloat(input))
        {
            cout << "FLOAT\n";
        }
        else if (isOperator(input))
        {
            cout << "OPERATOR\n";
        }
        else if (isKeyword(input))
        {
            cout << "KEYWORD\n";
        }
    }

    return 0;
}