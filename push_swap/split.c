#include "push_swap.h"

static int  count_words(const char *s, char c)
{
  int count;
  int in_word;

  count = 0;
  in_word = 0;
  while(*s)
  {
    if(*s != c && in_word == 0)
    {
      in_word = 1;
      count ++;
    }
    else if(*s == c)
      in_word = 0;
    s++;
  }
  return (count);
}

static char *create_word(const char *s, int len)
{
  char *word;
  int   i;

  word = (char *)malloc(sizeof(char) * (len + 1));
  if(!word)
    return (NULL);

  i = 0;
  while(i < len)
  {
    word[i] = s[i];
    i++;
  }
  word[i] = '\0';
  return (word);
}

static void free_split(char **res, int count)
{
  while(count > 0)
  {
    count--;
    free(res[count]);
  }
  free(res);
}

static const char *next_word(const char *s, char c, int *len)
{
  *len = 0;
  while(*s && *s == c)
    s++;
  while(s[*len] && s[*len] != c)
    (*len)++;
  return (s);
}

char **ft_split(const char *s, char c)
{
  char **result;
  int words;
  int i;
  int len;

  if(!s)
    return (NULL);
  words = count_words(s, c);
  result = (char **)malloc(sizeof(char *) * (words + 1));
  if (!result)
    return (NULL);
  i = 0;
  while(i < words)
  {
    s = next_word(s, c, &len);
    result[i] = create_word(s, len);
    if(!result[i])
      return (free_split(result, i), NULL);
    s = s + len;
    i++;
  }
  result[i] = NULL;
  return (result);
}