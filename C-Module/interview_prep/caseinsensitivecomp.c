// case insensitive sorting and comparison

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool compareString(char s1[],char s2[]){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    if(l1 != l2)
    return false;
    
    for(int i=0; i<=l1; i++){
        if((s1[i] | 32) == (s2[i] | 32))
        //if(s1[i] == s2[i] || s1[i]+32 == s2[i] || s1[i] == s2[i]+32)
        continue;
        else
        return false;
    }
    return true;
}

char *sorting(char *s1){
    int l = strlen(s1);
    for(int i=0; i<l-1; i++){
        for(int j=i+1; j<l; j++){
            if( (s1[i] | 32) > (s1[j] | 32)) {
                char temp = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
        }
    }
    return s1;
}

int main()
{
    char str1[] = "NikhIl";
    char str2[] = "nikhil";
    if(compareString(str1,str2))
    printf("Same String\n");
    else
    printf("Different String\n");
    char *str = sorting(str1);
    printf("%s\n",str);

    return 0;
}
