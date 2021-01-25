/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "../csapp.h"

int main(void) {
    char *buf, *p1, *p2, *p3;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
    p1 = strchr(buf, '=');
	*p1 = '\0';
	strcpy(arg1, p1+1);
	    
	p2 = strchr(p1+1, '&');
	*p2 = '\0';
	
    p3 = strchr(p2+1, '=');
    *p3 = '\0';
    strcpy(arg2, p3+1);
	
    n1 = atoi(arg1);
	n2 = atoi(arg2);
    }

    /* Make the response body */
    sprintf(content, "Welcoome to add.com: ");
    sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", 
	    content, n1, n2, n1 + n2);
    sprintf(content, "%sThanks for visiting!\r\n", content);
  
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content)+3);
    printf("Content-type: text/html\r\n\r\n");
    printf("%s%s", content, "end"); 
    fflush(stdout); // fflush와 printf, content 작동 방법 고민해보기

    exit(0);
}
/* $end adder */