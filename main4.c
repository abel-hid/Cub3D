#include <stdio.h>
#include <stdlib.h>
// #include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 15
// #define NULL 0
static char *ft_subst(const char *s1, size_t start , size_t end)
{
    char *result = malloc(sizeof(char ) * end +1);
    size_t i = 0;

    while(i < end && s1[start])
    {
        result[i] = s1[start];
        i++;
        start++;
    }
    result[i] = '\0';
    return (result);
}
static size_t ft_strlen(const char *hiba)
{
    size_t index = 0;
    while(hiba[index])
        index++;
    return (index);
}
char *ft_strdup(const char *hh)
{
    int index = 0;
    char *p = malloc(sizeof(char ) *ft_strlen(hh) +1);
    while(hh[index])
    {
        p[index] = hh[index];
        index++;
    }
    p[index] = '\0';
    return (p);
}
char *ft_strjoin(const char *s1, const char *s2)
{
    int index = 0;
    int jndex = 0;
    char *result = malloc(sizeof(char ) *ft_strlen(s1) + ft_strlen(s2) +1);

    while(s1[index])
    {
        result[index ]= s1[index];
        index++;
    }
    while(s2[jndex])
    {
        result[index] = s2[jndex];
        index++;
        jndex++;
    }
    result[index] = '\0';
    return (result);
}

static int check_fornewl(const char *str)
{
    int index =0;
    while(str[index])
    {
        if(str[index] == '\n')
            return (index);
            index++;
    }
    return (1);
}
char *ft_rest(char **f, int nl)
{
    char *rest = ft_subst(*f,nl +1,ft_strlen(*f));
    free(*f);
    *f = NULL;
    return (rest);
}
char *ft_line(char **f,char *line, int nl)
{
    line = ft_subst(*f,0,nl +1);
    *f = ft_subst(*f,nl +1,ft_strlen(*f));
    return (line);
}
char *get_nextLine(int fd)
{
    char *line = NULL;
    char *buffer ;
    static char *f;
    int reader;
    int new_line;

    if(!f)
        f = ft_strdup("");
    buffer = malloc(sizeof(char ) * BUFFER_SIZE +1);
    if(!buffer )
        return(free(f),NULL);
    reader = read(fd,buffer,BUFFER_SIZE);
    while(reader >=  0)
    {
        if(!f[0] && !reader)
            break;
        buffer[reader] = '\0';
        f = ft_strjoin(f,buffer);
        new_line= check_fornewl(f);
        if(new_line != 1)
            return (free(buffer),ft_line(&f,line,new_line));
        if(!reader)
            return (free(buffer),ft_rest(&f,0));
            reader = read(fd,buffer,BUFFER_SIZE);
    }
    return (free(f),free(buffer),f = NULL,NULL);
}
int main()
{
    int fd = open("map.cub",O_RDONLY);
    char *line;
    while((line = get_nextLine(fd)))
    {
        printf("%s",line);
        free(line);
    }
    close(fd);
    return (0);
}