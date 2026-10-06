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
    if (s[0] == '=' || s[0] == '!' || s[0] == '<' || s[0] == '>' || s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
    {
        return true;
    }
    return false;
}

bool isKeyword(string s)
{
    unordered_set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "class", "const_cast", "delete", "dynamic_cast", "explicit", "export", "false", "friend", "inline", "mutable", "namespace", "new", "operator", "private", "protected", "public", "reinterpret_cast", "static_cast", "template", "this", "true", "typeid", "typename", "using", "virtual", "catch", "throw", "try", "alignas", "alignof", "char8_t", "char16_t", "char32_t", "concept", "consteval", "constexpr", "constinit", "co_await", "co_return", "co_yield", "decltype", "noexcept", "nullptr", "requires", "thread_local", "wchar_t", "and", "and_eq", "bitand", "bitor", "compl", "not", "not_eq", "or", "or_eq", "xor", "xor_eq"
    };
    return keywords.find(s) != keywords.end();
}

int main()
{
    string sentence;
    while (true)
    {
        cout << "Enter sentence (esc to exit): ";
        getline(cin, sentence);
        if (sentence == "esc") break;

        vector<string> floats, operators, keywords_found;
        stringstream ss(sentence);
        string token;

        while (ss >> token)
        {
            if (isFloat(token))
                floats.push_back(token);
            else if (isOperator(token))
                operators.push_back(token);
            else if (isKeyword(token))
                keywords_found.push_back(token);
        }

        cout << "\nFloats: ";
        for (auto f : floats) cout << f << " ";
        cout << "\nOperators: ";
        for (auto op : operators) cout << op << " ";
        cout << "\nKeywords: ";
        for (auto kw : keywords_found) cout << kw << " ";
        cout << "\n\n";
    }

    return 0;
}