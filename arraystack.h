/*
 1) 스택 생성 : 스택의 크기 n 명시해주기
 2) 푸시(push) : 원소 추가 가능 여부 판단(overflow 여부)
 3) 팝(Pop) : 공백 스택인지 여부 판단(underflow 여부)
 4) 피크(Peek)
 5) 스택 삭제
 */
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
typedef struct Data {
    char content[20];      // 스택 내용
}Data;

typedef struct Stack{
    int maxsize;        // 스택의 최대 크기
    int currentsize;    // 스택의 현재 크기
    struct Data* element;      // 스택의 content를 가리킬 포인터
}Stack;

// size 크기의 스택 생성
Stack* makeStack(Stack* stack, const int maxsize);

// 최상위에 위치한 원소 추가
_Bool push(Stack* stack, const char* content, const int currentsize);

// 최상위에 위치한 원소 제거
Stack* pop(Stack* stack);

// 최상위에 위치한 원소 반환
char* peek(const Stack* stack);

// 스택 제거
_Bool deleteStack(Stack* stack);

// 스택의 공백 여부 확인
_Bool isEmpty(const Stack *stack);

// 스택의 가용 용량이 없는지 확인
_Bool isFull(const Stack *stack);
#endif