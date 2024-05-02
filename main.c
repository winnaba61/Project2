#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(const char *filename);
void filestat2(const char *filename);
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    const char *filename1="text1.txt";
    const char *filename2="text2.txt";
    filestat1(filename1);
    filestat2(filename2);
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
    return 0;
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(const char *filename){
    if(stat(filename,&stat1)==-1)
    {
        perror("stat1");
    }
    printf("파일 1의 정보를 가져옴\n");
    return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(const char *filename){
    if(stat(filename,&stat2)==-1)
    {
        perror("stat2");
    }
    printf("파일 1의 정보를 가져옴\n");
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1=localtime(&stat1.st_mtime);
    if(time1==NULL)
    {
        perror("localtime1");
    }
    printf("파일 1의 마지막 수정 시간: %s", asctime(time1));
    return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2=localtime(&stat2.st_mtime);
    if(time2==NULL)
    {
        perror("localtime2");
    }
    printf("파일 2의 마지막 수정 시간: %s", asctime(time2));
    return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}