#include<stdio.h>
#include<string.h>
#include"util.h"

typedef Subject {
	char num[10];
	char name[30];
	char week[10];
	int start;
	int end;
} Subject;

void timeTable(Subject* sublist);

void loadTable(Subject* sublist);	//txt파일 없으면 생성, 있으면 내용을 배열에 저장, 배열에서 안쓰는 부분 NULL이든 뭐든 초기화 해야될듯

void subjectEdit(Subject* sublist);

int subjectRegister(Subject* sublist);	//성공하면 0, 실패하면 -1

int subjectDelete(Subject* sublist); //성공하면 0, 실패하면 -1

int main()
{
	Subject sublist[50];	//일단 낭낭하게

	timeTable(sublist);
	return 0;
}

void timeTable(Subject* sublist)
{
	loadTable();
	timetable_show();
	timetable_menu();
}

void SubjectEdit(Subject* sublist)
{
	//input 메뉴 따라서
	subjectRegister(sublist);
	subjectDelete(sublist);
	//prev 선택하면 배열 변경사항을 txt 파일에 저장
	//saveSubList(sublist);
	//return;

}

int subjectRegister(Subject* sublist)
{
	Subject newsubject;
	/*
	   input 파트
	*/
	addSubject(sublist, newSubject);	//sublist에 newSubject를 알맞은 위치에 넣음
}

int subjectDelete(Subject* sublist)
{
	/*
	   input 파트
	   등록된 과목 없으면 종료
	   등록된 전체 과목 순서대로 출력
	   과목 번호 입력
	*/
	delSubject(Subject* sublist, delNum);	//과목번호 delNum인 과목 배열에서 삭제
}


