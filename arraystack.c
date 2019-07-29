#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arraystack.h"
#include "boolean.h"

int main() {
    Stack* stack;

    if(stack = makeStack(stack, 10)) {
        printf("makeStack() test 완료\n");
    }
    else {
        printf("makeStack() test 실패\n");
    }

    if(push(stack, "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk", stack->currentsize)) {
        printf("현재 스택 크기 : %d\n", stack->currentsize);
    }

    // for(int i = 0; i < 12; i++) {
    //     if(push(stack, "qrgfdsgf", stack->currentsize)) {
    //         printf("현재 스택 크기 : %d\n", stack->currentsize);
    //     }
    // }

    if(pop(stack)) {
        printf("원소 제거 완료\n");
        printf("현재 스택 크기 : %d\n", stack->currentsize);
    }

    printf("최상위 원소 : %s\n", peek(stack));
    printf("현재 스택 크기 : %d\n", stack->currentsize);

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
    // 만약 추가할 원소 크기가 유효 범위를 넘어서면
    if(strlen(content) > ELEMENT_SIZE) {
        printf("원소의 유효 크기가 초과되었습니다\n");
        return FALSE;
    }

    // 만약 스택 가용 공간이 없으면
    if(isFull(stack)) {
        printf("overflow 발생\n");
        return FALSE;
    }
    // 스택 가용 공간이 존재하면
    else {
        // 스택의 최상위 위치에 원소(content) 추가
        strncpy(stack->element[currentsize].content, content, strlen(content));
        // 스택 현재 크기 update
        stack->currentsize += 1;
        return stack;
    }
}

// 최상위에 위치한 원소 제거
_Bool pop(Stack *stack) {
    // 만약 stack이 비어있으면
    if(isEmpty(stack)) {
        printf("underflow 발생\n");
        return FALSE;
    }
    // 스택에 원소가 존재하면
    else {
        // 스택의 최상위 원소 제거
        strncpy(stack->element[stack->currentsize].content, "", strlen(""));
        // 스택의 현재 크기 update
        stack->currentsize -= 1;
        return TRUE;
    }
}

// 최상위에 위치한 원소 반환
char* peek(const Stack* stack) {
    if(isEmpty(stack)) {
        printf("스택에 원소가 존재하지 않습니다\n");
        return FALSE;
    }
    else {
        return stack->element[stack->currentsize].content;
    }
}

// 스택 제거
_Bool deleteStack(Stack* stack) {
    // stack 요소에 할당된 메모리 반환
    memset(stack->element, 0xFF, sizeof(Data));
    free(stack->element);
    stack->element = NULL;

    // stack에 할당된 메모리 반환
    memset(stack, 0xFF, sizeof(Stack));
    free(stack);
    stack = NULL;

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