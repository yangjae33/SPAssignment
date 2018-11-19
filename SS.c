#include "SS.h"
#include <string.h>
#include <stdio.h>

struct Subject
{
    int subject_num;
    char* subject_name;
    char* week; //요일 정보 : Sun, Mon, Tue, Wed, Thu, Fri, Sat
    int start;  //시작 교시
    int end;    //종료 교시
};

//A. 시간표 출력
void timetable_show(struct Subject* subject,int* count){}

//A.1.1. 과목 추가
//인자가 있어야 할것같은데 ( 구조체 배열 )
void subject_register(struct Subject* subject,int* count){
    printf("======= 과목 추가 ======\n");
    
    char name[30];
    int num = 0;
    char week[10];
    int start = 0;
    int end = 0;
    
    struct Subject sub;
    printf("과목 번호 : ");
    sub.subject_num = scanf("%d",&num);
    printf("과목명 : ");
    sub.subject_name = scanf("%s",&name);
    printf("시작 시간(교시) : ");
    sub.start = scanf("%d",&start);
    printf("종료 시간(교시) : ");
    sub.end = scanf("%d",&end);
    printf("요일 : ");
    sub.week = scanf("%s",&week);
    
    //추가되는 과목의 적합성 검사
    printf("\n====== 과목이 등록되었습니다 ======\n\n");
}
//A.1.2. 과목 삭제
void subject_delete(struct Subject* subject,int* count){}

//A.1. 과목 편집
void subject_edit(struct Subject* subject,int* count){
    printf("====== 과목 편집 ======\n");
    int menu = 0;
    while(1){
        printf("1. 과목 추가\n2. 과목 삭제\n3. 이전으로\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                subject_register(subject,count);
                continue;
            case 2:
                subject_delete(subject,count);
                continue;
            case 3:
                break;
            default:
                printf("1,2,3 외의 입력입니다.\n");
                continue;
        }
        break;
    }
}
//B.1.1. 강의자료 추가
void add_lecturenote(){}

//B.1.2. 강의자료 삭제
void del_lecturenote(){}

//B.1. 강의자료
void lecturenote(int subject_num){
    printf("====== 강의자료 ======\n");
    int menu = 0;
    while(1){
        printf("1. 강의자료 추가\n2. 강의자료 삭제\n3.이전으로\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                add_lecturenote();
                continue;
            case 2:
                del_lecturenote();
                continue;
            case 3:
                break;
            default:
                printf("1,2,3, 이외의 입력입니다.");
                continue;
        }
        break;
    }
}

//A.4.1. 일정 삭제
void del_schedule(){}

//A.4. 일정 보기
void schedule_show(){
    printf("====== 일정 보기 ======\n");
    int menu = 0;
    while(1){
        printf("1. 일정 삭제\n2. 이전으로\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                del_schedule();
                continue;
            case 2:
                break;
            default:
                printf("1,2 이외의 입력입니다.\n");
                continue;
        }
        break;
    }
}

//B.2.1. 일정 추가
void add_schedule(){}

//B.2. 일정 관리
void schedule_manage(int subject_num){
    printf("====== 일정 관리 ======\n");
    int menu = 0;
    while(1){
        printf("1. 일정 추가\n2. 이전으로\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                add_schedule();
                continue;
            case 2:
                break;
            default:
                printf("1,2 이외의 입력입니다.\n");
                continue;
        }
        break;
    }
}

//A.3. 과목 상세 정보
void subject_detail(){
    int sub_num = 0;
    printf("과목 번호를 입력하세요 : ");
    scanf("%d",&sub_num);
    
    //등록되어있지 않은 과목 번호일때
    printf("등록되어있지 않은 과목입니다.\n");
    //return;
    
    //등록되어있는 과목 번호일때
    printf("====== 과목 상세 정보 ======\n");
    //printf(해당 과목의 정보)
    int menu = 0;
    while(1){
        printf("1. 강의자료\n2. 일정 관리\n3. 이전으로\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                lecturenote(sub_num);
                continue;
            case 2:
                schedule_manage(sub_num);
                continue;
            case 3:
                break;
            default:
                printf("1,2,3 외의 입력입니다.\n");
                continue;
        }
        break;
    }
}

//A.5. 종료
void EXIT(){}

//A. 시간표 메뉴
void timetable_menu(struct Subject* subject,int* count){
    int menu = 0;
    while(1){
        printf("====== 메인 메뉴 ======\n");
        printf("\n1. 과목 편집\n2. 과목 상세정보\n3. 일정 보기\n4. 종료\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                subject_edit(subject,count);
                continue;
            case 2:
                subject_detail();
                continue;
            case 3:
                schedule_show();
                continue;
            case 4:
                EXIT();
                break;
            default:
                printf("1,2,3,4 외의 입력입니다.\n");
                continue;
        }
        break;
    }
}

//A. 시간표
void timetable(){
    int* count = NULL;
    struct Subject subject[10];
    timetable_show(subject,count);
    timetable_menu(subject,count);
}

int main(){
    
    timetable();
    
    return 0;
}
