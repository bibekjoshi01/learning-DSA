#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int prec(char op)
{
    if (op == '$')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPostFix(char *exp)
{
    int len = strlen(exp);
    char postfix_string[len + 1];
    int trac = 0;
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        char s_c = exp[i];

        if (s_c == '(')
        {
            stack[++top] = s_c;
        }

        else if (s_c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix_string[trac++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
            {
                top--; // Pop the '('
            }
        }

        // In case of operand
        else if (isalnum(s_c))
        {
            postfix_string[trac++] = s_c;
        }

        // In case of operator
        else
        {
            while (top != -1 && prec(s_c) <= prec(stack[top]))
            {
                postfix_string[trac++] = stack[top--];
            }

            stack[++top] = s_c;
        }
    }

    while (top != -1)
    {
        postfix_string[trac++] = stack[top--];
    }

    postfix_string[trac] = '\0'; // Null-terminate the string
    printf("Postfix Expression: %s\n", postfix_string);
}

int main()
{
    char infix_exp[] = "A+(B*C-(D/E$F)*G)*H";

    printf("Infix Expression: %s\n", infix_exp);
    infixToPostFix(infix_exp);

    return 0;
}