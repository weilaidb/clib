#include <stdarg.h>
#include <stdio.h>
#include <string.h>
 
int vscnprintf(char *buf, size_t size, const char *fmt, va_list args);
int make_cnprintf(const char *fmt,...);
int make_nprintf(const char *fmt,...);
 
int main()
{
	printf("------------------scnprintf test------------------\n");
	make_cnprintf("%s","123456789ABC");
	make_cnprintf("%s","123456789A");
	make_cnprintf("%s","123456");
	
	printf("------------------snprintf test------------------\n");
	make_nprintf("%s","123456789ABC");
	make_nprintf("%s","123456789A");
	make_nprintf("%s","123456");
 
	return 0;
}
 
int vscnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
	int i;
 
	i = vsnprintf(buf, size, fmt, args);
 
	if (i < size)
		return i;
	if (size != 0)
		return size - 1;
	return 0;
}
 
int make_cnprintf(const char *fmt,...)
{
	int cx = 0;
 
	char buf[10] = {0};
	va_list args;
	va_start(args,fmt);
	cx = vscnprintf(buf,10,fmt,args);
	printf("vscnprintf return cx=%d,buf=%s,buflen:%d\n",cx,buf, strlen(buf));
	printf("fmt:%d\n",strlen(fmt));
	va_end(args);
 
	return 0;
}
 
int make_nprintf(const char *fmt,...)
{
	int cx = 0;
 
	char buf[10] = {0};
	va_list args;
	va_start(args,fmt);
	cx = vsnprintf(buf,10,"%s",args);
	printf("vscprintf return cx=%d,buf=%s\n",cx,buf);
	va_end(args);
 
	return 0;
}

