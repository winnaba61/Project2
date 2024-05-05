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
    const char *filename1="text1";
    const char *filename2="text2";
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
    return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(const char *filename){
    if(stat(filename,&stat2)==-1)
    {
        perror("stat2");
    }
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1=localtime(&stat1.st_mtime);
    if(time1==NULL)
    {
        perror("localtime1");
    }
    return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2=localtime(&stat2.st_mtime);
    if(time2==NULL)
    {
        perror("localtime2");
    }
    return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
	if( ((stat1.st_size) - (stat2.st_size)) > 0 )
		printf("text1 is bigger\n");
	else if( ((stat1.st_size) - (stat2.st_size)) < 0 )
		printf("text2 is bigger\n");
	else if( (stat1.st_size) - (stat2.st_size) == 0 )
		printf("sizes are equal.\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("\nblock compare\n");
    blkcnt_t blkcnt1 = stat1.st_blocks;
    blkcnt_t blkcnt2 = stat2.st_blocks;

    if (blkcnt1 > blkcnt2)
    {
        printf("%s is bigger\n", "text1");
    }
    else if (blkcnt1 < blkcnt2)
    {
        printf("%s is bigger\n", "text2");
    }
    else
    {
        printf("sizes are equal\n");
    }

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("\ndate compare\n");
    //text1
    int day1 = localtime(&stat1.st_mtime)->tm_mday;
    int month1 = localtime(&stat1.st_mtime)->tm_mon;
    int year1 = localtime(&stat1.st_mtime)->tm_year;
    //text2
    int day2 = localtime(&stat2.st_mtime)->tm_mday;
    int month2 = localtime(&stat2.st_mtime)->tm_mon;
    int year2 = localtime(&stat2.st_mtime)->tm_year;

    if (year1 > year2)
        printf("text2 is early\n");
    else if (year1 < year2)
        printf("text1 is early\n");
    else {
        if (month1 > month2)
            printf("text2 is early\n");
        else if (month1 < month2)
            printf("text1 is early\n");
        else {
            if (day1 > day2)
                printf("text2 is early\n");
            else if (day1 < day2)
                printf("text1 is early\n");
            else
                printf("same date\n");
        }
    }
    printf("\n");

}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("time compare\n");
    time_t diff = difftime(stat1.st_mtime, stat2.st_mtime);
    if (diff > 0)
        printf("text2 is early\n");
    else if (diff < 0)
        printf("text1 is early\n");
    else
        printf("same time\n");
    printf("\n");

}
