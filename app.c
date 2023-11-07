#include <stdio.h>
#include "test.h"
#include <stdarg.h>

#define LOG_LEVEL   LOG_WARN
#define LOG_OPEN    1
typedef enum{
    LOG_DEBUG=0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERRO,
}ENUM_LOG;
char *GetLogLevel(const int level){
    if(level == LOG_DEBUG) return "LOG_DEBUG";
    if(level == LOG_INFO) return "LOG_INFO";
    if(level == LOG_WARN) return "LOG_WARN";
    if(level == LOG_ERRO) return "LOG_ERRO";
}

void test(const int level,const char* fun,const int line,const char* fmt, ...){
#if LOG_OPEN

    va_list arg;
    va_start(arg,fmt);
    char buf[vsnprintf(NULL,0,fmt,arg)+1];
    vsnprintf(buf,sizeof(buf),fmt,arg);
    va_end(arg);
    if(level>=LOG_LEVEL){
        printf("[%s][%s %d]:%s",GetLogLevel(level),fun,line,buf);
        printf("\n");
    }
    

#endif
}

#define My_Test(LOG_DEBUG,fmt,...) test(LOG_DEBUG,__FUNCTION__,__LINE__,fmt);


int main(){

    // test(LOG_DEBUG,__FUNCTION__,__LINE__,"%s %d","wqwe",1111);
    // test(LOG_INFO,__FUNCTION__,__LINE__,"%s %d","wqwe",1111);
    // test(LOG_WARN,__FUNCTION__,__LINE__,"%s %d","wqwe",1111);
    test(LOG_ERRO,__FUNCTION__,__LINE__,"%s %d","wqwe",1111);
    My_Test(LOG_ERRO,"%s %d","w11we",11223);

}