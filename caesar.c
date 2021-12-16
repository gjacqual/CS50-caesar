#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check_int(string key);
string code_text(string text, int key);

int main(int argc, string argv[])
{
    int key;
    string text;
    string code;

    // If user dont add  any command-line arguments or with more than one argument, program should print an error message
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    // Check argument. If one symbol is no number, print error and exit with return 1;
    if (!(check_int(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }

    // convert string to intager
    key = atoi(argv[1]);

    //Ask user string - text
    text = get_string("plaintext: ");

    code = code_text(text, key);

    printf("ciphertext: %s\n", code);

    return (0);
}

int check_int(string key)
{
    int i = 0;

    // Check all symbols in cycle. If one symbol is no number, we return zero;
    while (key[i] != '\0')
    {
        if (!(isdigit(key[i])))
        {
            return (0);
        }
        i++;
    }

    return (1);
}

string code_text(string text, int key)
{
    int i = 0;


    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            // find uppercase symbols in string
            if (isupper(text[i]))
            {
                //convert to alphabetical numbering
                text[i] = text[i] - 65;
                text[i] = ((text[i] + key) % 26) + 65;
            }
            // find lowercase symbols in string
            else if (islower(text[i]))
            {
                //convert to alphabetical numbering
                text[i] = text[i] - 97;
                text[i] = ((text[i] + key) % 26) + 97;
            }
        }
        i++;
    }
    return (text);
}