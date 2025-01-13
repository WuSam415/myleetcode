#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s)
{
    int len = strlen(s);
    // Stack to store open parentheses
    char stack[len];
    int stack_index = 0;
    int stack_top = 0;

    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] =='{')
        {
            stack[stack_index] = s[i];
            stack_top = stack_index;
            stack_index++;
        }
        else
        {
            // Empty stack: no open parentheses
            if(stack_index < 1)
            {
                return false;
            }
            else
            {
                if(s[i] == ')')
                {
                    if(stack[stack_top] != '(')
                        return false;
                }
                else if(s[i] == ']')
                {
                    if(stack[stack_top] != '[')
                        return false;
                }
                else if(s[i] == '}')
                {
                    if(stack[stack_top] != '{')
                        return false;
                }
                stack_top--;

            }
        }
        
    }
    return true;
}

/**
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Input: s = "([])"
Output: true
 */

int main()
{
    char* s = "()[]{}";
    char* s_1 = "()";
    char* s_2 = "(]";
    char* s_3 = "([])";

    printf("%s isValid: %s\n", s, (isValid(s)) ? "True" : "False") ;
    printf("%s isValid: %s\n", s_1, (isValid(s_1)) ? "True" : "False");
    printf("%s isValid: %s\n", s_2, (isValid(s_2)) ? "True" : "False");
    printf("%s isValid: %s\n", s_3, (isValid(s_2)) ? "True" : "False");
} 