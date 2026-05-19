#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("SS.txt");

    if (!file)
    {
        cout << "File not found";
        return 0;
    }

    char ch;
    string token = "";

    while (file.get(ch))
    {

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            token += ch;

            while (file.get(ch))
            {
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                {
                    token += ch;
                }
                else
                {
                    file.putback(ch);
                    break;
                }
            }

            if (token == "int" || token == "float" || token == "char" || token == "double" || token == "return")
                cout << token << " -> Keyword\n";
            else
                cout << token << " -> Identifier\n";

            token = "";
        }

        else if (ch >= '0' && ch <= '9')
        {
            token += ch;

            while (file.get(ch))
            {
                if (ch >= '0' && ch <= '9')
                    token += ch;
                else
                {
                    file.putback(ch);
                    break;
                }
            }

            cout << token << " -> Number\n";
            token = "";
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
        {
            cout << ch << " -> Operator\n";
        }

        else if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}')
        {
            cout << ch << " -> Separator\n";
        }
    }

    file.close();
    return 0;
}
