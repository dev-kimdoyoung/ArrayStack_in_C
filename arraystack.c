#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arraystack.h"
#include "boolean.h"

int main() {
    Stack* stack;

    if(stack = makeStack(stack, 3)) {
        printf("makeStack() test 완료\n");
    }
    else {
        printf("makeStack() test 실패\n");
    }

    if(push(stack, "ㅇㅇㅇ", stack->currentsize)) {
        printf("원소 추가 완료\n");
        printf("원소 내용 : %s\n", stack->element[0].content);
        printf("현재 스택 크기 : %d\n", stack->currentsize);
    }

    if(push(stack, "ㅅㅅㅅ", stack->currentsize)) {
        printf("원소 추가 완료\n");
        printf("원소 내용 : %s\n", stack->element[1].content);
        printf("현재 스택 크기 : %d\n", stack->currentsize);
    }

    if(deleteStack(stack)) {
        printf("deleteStack() test 완료\n");
    }
    else {
        printf("deleteStack() test 실패\n");
    }
    return 0;
}
// size 크기의 스택

Stack* makeStack(Stack* stack, const int maxsize) {
    stack = (Stack*)malloc(sizeof(Stack));

    // stack 크기 초기화
    stack->maxsize = maxsize;
    stack->currentsize = 0;
    printf("스택 크기 초기화 완료\n");

    // 메모리 할당 실패 시
    if(stack == NULL) {
        printf("스택 메모리 할당 실패\n");
        return NULL;
    }

    stack->element = (Data*)calloc(sizeof(Data), stack->maxsize);
    // 메모리 할당 실패 시
    if(stack->element == NULL) {
        printf("스택의 요소 메모리 할당 실패\n");
        memset(stack, 0xFF, sizeof(stack));
        free(stack);
        stack = NULL;
        return NULL;
    }
    return stack;
}

// 최상위에 위치한 원소 추가
_Bool push(Stack *stack, const char* content, const int currentsize) {
    strncpy(stack->element[currentsize].content, content, strlen(content));
    stack->currentsize += 1;
    return stack;
}

// 최상위에 위치한 원소 제거
Stack* pop(Stack *stack);

// 최상위에 위치한 원소 반환
char* peek(const Stack* stack);

// 스택 제거
_Bool deleteStack(Stack* stack) {
    // stack 요소에 할당된 메모리 반환
    memset(stack->element, 0xFF, sizeof(Data));
    free(stack->element);
    stack->element = NULL;
    
    printf("stack의 요소 메모리 반환 완료\n");

    // stack에 할당된 메모리 반환
    memset(stack, 0xFF, sizeof(Stack));
    free(stack);
    stack = NULL;
    printf("stack 메모리 반환 완료\n");
    return TRUE;
}

// 스택의 공백 여부 확인(underflow 발생하는지)
_Bool isEmpty(const Stack* stack) {
    // stack의 현재 크기가 0이면 TRUE 리턴
    if(stack->currentsize == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// 스택의 가용 용량이 없는지 확인(overflow 발생하는지)
_Bool isFull(const Stack* stack) {
    // 만약 stack의 현재 크기와 최대 크기가 같다면 TRUE 리턴
    if(stack->currentsize == stack->maxsize) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}