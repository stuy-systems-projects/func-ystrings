#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mystrlen(char *s){
  int i = 0;
  while (*s){
    i++;
    s++;
    //   printf("%d\n", i);
  }
  return i;
}

char* mystrcpy(char *dest, char *src){
  char *ret = dest;
  while (*src){
    *dest = *src;
    dest++;
    src++;
  }
  return ret;
}

char* mystrncpy(char *dest, char *src, int n){
  char *ret = dest;
  int count = 0;
  while (*src && count < n){
    *dest = *src;
    dest++;
    src++;
    count++;
  }
  return ret;
}

char* mystrcat(char *dest, char *src){
  char *ret = dest;
  dest += mystrlen(dest); //point to last char of dest
  while (*src){
    *dest = *src;
    dest++;
    src++;
  }
  *dest = 0; //adds null terminating char to end of str
  return ret;
}

char* mystrncat(char *dest, char *src, int n){
  char *ret = dest;
  dest += mystrlen(dest) - 1; //point to last char of dest
  int count = 0;
  while (*src && count < n){
    *dest = *src;
    dest++;
    src++;
  }
  *dest = 0; //adds null terminating char to end of str
  return ret;
}

int mystrcmp(char *s1, char *s2){
  while (*s1){
    if (*s1 == *s2){
      s1++;
      s2++;
    }
    else
      return *s1 - *s2;
  }
  return *s1 - *s2;
}

int mystrchr(char *s, char c){
  while (*s){
    if (*s == c)
      break;
    s++;
  }
  return *s;
}

int main(){
  char s1[10] = "Hello";
  char s2[10] = "";

  printf("Before applying functions:\n");
  printf("s1 = %s, length = %d\n", s1, mystrlen(s1));
  printf("s2 = %s, length = %d\n\n", s2, mystrlen(s2));

  printf("Testing regular functions:\n");
  mystrcpy(s2, s1);
  printf("Copy s1 to s2: s2 = %s, length = %d\n", s2, mystrlen(s2));

  char toCat[5] = "Man";
  mystrcat(s2, toCat);
  printf("Cat \"Man\" to s2: s2 = %s, length = %d\n\n", s2, mystrlen(s2));
 
  char str1[5] = "abc";
  char str2[5] = "bc";
  char str3[5] = "bc";
  char str4[5] = "z";
  printf("Testing strcmp:\n");
  printf("comparing str1 (\"abc\") and str2 (\"bc\"): %d\n", mystrcmp(str1, str2));
  printf("comparing str2 (\"bc\") and str1 (\"abc\"): %d\n", mystrcmp(str2, str1));
  printf("comparing str2 (\"bc\") and str4 (\"z\"): %d\n", mystrcmp(str2, str4));
  printf("comparing str2(\" bc\" and str3 (\"bc\"): %d\n", mystrcmp(str2, str3));
  return 0;
}