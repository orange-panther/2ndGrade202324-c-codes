#include <stdio.h>
#include <string.h>

char* trim(char* input, char* result)
{
    int startIndex = 0; 
    int endIndex = 0;
    for(int i = 0; input[i] == ' '; i++)
    {
        startIndex = i+1;
    }

    for(int j = strlen(input); input[j] == ' '; j--)
    {
       endIndex = j;
    }

    for(int i = startIndex; i < endIndex; i++)
    {
        result[i] = input[i];
    }
    return result;
}

int isSame(char* first, char* second)
{
    int length = 0;
    if (strlen(first) > strlen(second))
    {
        length = strlen(first);
    }
    else {
        length = strlen(second);
    }

    for (int i = 0; i < length; i++)
    {
        if(!first[i] == second[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char input[256] = "   Here is some text  .   ";
    char result[256] = "Here is some text  .";
    char myResult[256]; 
    trim(input, myResult);
    int res = isSame(myResult, result);
    if (res == 1)
    {
        printf("Sucessfully trimmend the string\n");
    }
    
    // for(int i = 0; i < strlen(result); i++)
    //{
    //     printf("%c", result[i]);
    // }
    // printf("\n");

    return 0;
}
