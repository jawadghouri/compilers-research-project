#include <stdio.h>

void myfunction() 
{
    int localvariable = 10; // localvariable's scope begins here
    printf("%d\n", localvariable);
} // localvariable's scope ends here

int main() 
{
    myfunction();
    // printf("%d\n", localvariable); // Error: localvariable is out of scope here
    return 0;
}