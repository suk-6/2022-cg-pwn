# 1_Handray.c 파일의 바이너리 분석 보고서
## 정의된 Function
```
All defined functions:

Non-debugging symbols:
0x0804830c  _init
0x08048340  printf@plt
0x08048350  puts@plt
0x08048360  __libc_start_main@plt
0x08048370  __isoc99_scanf@plt
0x08048390  _start
0x080483c0  __x86.get_pc_thunk.bx
0x080483d0  deregister_tm_clones
0x08048400  register_tm_clones
0x08048440  __do_global_dtors_aux
0x08048460  frame_dummy
0x0804848b  func_days // 일 계산 함수
0x080484bd  func_hour // 시간 계산 함수
0x08048511  func_minute // 분 계산 함수
0x08048549  main // 메인 함수
0x080485c0  __libc_csu_init
0x08048620  __libc_csu_fini
0x08048624  _fini
```
## main 함수
```
Dump of assembler code for function main:
   0x08048549 <+0>:	push   ebp // 프롤로그 - ebp 레지스터를 stack에 넣는다.
   0x0804854a <+1>:	mov    ebp,esp // 프롤로그 - 레지스터 ebp를 esp에 넣는다.
   0x0804854c <+3>:	push   esi
   0x0804854d <+4>:	push   ebx
   0x0804854e <+5>:	sub    esp,0x4 // 4byte(int, long int, float) 선언 - 지역변수 공간 확보
   0x08048551 <+8>:	push   0x8048640 // "분을 입력하세요." puts 함수를 사용하기 위해 stack에 넣는 것으로 보인다.
   0x08048556 <+13>:	call   0x8048350 <puts@plt> // puts - 문자 출력
   0x0804855b <+18>:	add    esp,0x4 // main+8 줄에서 push 했던 값 정리
   0x0804855e <+21>:	lea    eax,[ebp-0xc] // ebp-0xc의 주소값을 eax로 복사
   0x08048561 <+24>:	push   eax // '0xfffa4a3c' 주소의 0x0 값을 stack에 넣음
   0x08048562 <+25>:	push   0x8048658 // '%d'를 scanf로 입력받기 위해 stack에 넣음
   0x08048567 <+30>:	call   0x8048370 <__isoc99_scanf@plt> // scanf로 '%d'를 입력받고 'ebp-0xc'에 보관
   0x0804856c <+35>:	add    esp,0x8 // scanf에서 입력된 값을 esp 레지스터에 넣음.
   0x0804856f <+38>:	mov    eax,DWORD PTR [ebp-0xc] // 함수에 입력값을 전달하기 위해 ebp-0xc의 값을 eax로 복사
   0x08048572 <+41>:	push   eax // stack에 eax 추가 (함수에 인자를 넘겨주기 위해)
   0x08048573 <+42>:	call   0x8048511 <func_minute> // func_minute 함수 호출
   0x08048578 <+47>:	add    esp,0x4 // stack 정리 (+41줄에서 stack에 push 한 것을 정리)
   0x0804857b <+50>:	mov    esi,eax // func_minute 함수에서 return된 값, 즉 eax 레지스터의 값을 esi 레지스터로 복사
   0x0804857d <+52>:	mov    eax,DWORD PTR [ebp-0xc] // func_hour 함수를 실행하기 위해 eax의 값을 인풋값으로 설정
   0x08048580 <+55>:	push   eax // stack에 eax 추가
   0x08048581 <+56>:	call   0x80484bd <func_hour> // func_hour 함수 호출
   0x08048586 <+61>:	add    esp,0x4 // stack 정리
   0x08048589 <+64>:	mov    ebx,eax // func_hour 함수에서 리턴된 값을 ebx로 복사
   0x0804858b <+66>:	mov    eax,DWORD PTR [ebp-0xc] // func_days 함수를 실행하기 위해 eax의 값을 인풋값으로 설정
   0x0804858e <+69>:	push   eax // stack에 eax 추가
   0x0804858f <+70>:	call   0x804848b <func_days> // func_days 함수 호출
   0x08048594 <+75>:	add    esp,0x4 // stack 정리
   0x08048597 <+78>:	mov    edx,eax // func_days 함수에서 리턴된 값을 ebx로 복사
   0x08048599 <+80>:	mov    eax,DWORD PTR [ebp-0xc] // printf 함수에서 인풋값을 사용하기 위해 eax로 복사하고
   0x0804859c <+83>:	push   esi // func_minute에서 리턴된 값
   0x0804859d <+84>:	push   ebx // func_hour에서 리턴된 값
   0x0804859e <+85>:	push   edx // func_days에서 리턴된 값
   0x0804859f <+86>:	push   eax // scanf에서 입력받은 값 ('분 -> 시 -> 일 -> 인풋'으로 stack에 들어가는 것을 보면 출력 순서가 '인풋 -> 일 -> 시 -> 분' 이라는 것을 알 수 있다.)
   0x080485a0 <+87>:	push   0x804865c // "%d분은 %d일 %d시간 %d분입니다.\n"
   0x080485a5 <+92>:	call   0x8048340 <printf@plt> // printf 함수 호출
   0x080485aa <+97>:	add    esp,0x14 // printf에서 사용하려고 push 됐던 '0x804865c'를 빼낸다.
   0x080485ad <+100>:	mov    eax,0x0 // eax 초기화
   0x080485b2 <+105>:	lea    esp,[ebp-0x8]
   0x080485b5 <+108>:	pop    ebx // push의 반대, stack에 쌓여있던 값들을 빼낸다.
   0x080485b6 <+109>:	pop    esi // push의 반대, stack에 쌓여있던 값들을 빼낸다.
   0x080485b7 <+110>:	pop    ebp // push의 반대, stack에 쌓여있던 값들을 빼낸다.
   0x080485b8 <+111>:	ret // End!
End of assembler dump.
```
## func_minute 함수
```
Dump of assembler code for function func_minute:
   0x08048511 <+0>:	push   ebp // 프롤로그
   0x08048512 <+1>:	mov    ebp,esp // 프롤로그
   0x08048514 <+3>:	mov    ecx,DWORD PTR [ebp+0x8] // main 함수에서 입력받은 값을 ecx 레지스터로 복사 
   0x08048517 <+6>:	mov    edx,0x88888889 // 곱셈 또는 나눗셈 연산을 위해 edx 레지스터 사용
   0x0804851c <+11>:	mov    eax,ecx // ecx의 값(main의 입력값)을 eax 레지스터에 넣어줌.
   0x0804851e <+13>:	imul   edx // edx 곱셈
   0x08048520 <+15>:	lea    eax,[edx+ecx*1] 
   0x08048523 <+18>:	sar    eax,0x5
   0x08048526 <+21>:	mov    edx,eax
   0x08048528 <+23>:	mov    eax,ecx
   0x0804852a <+25>:	sar    eax,0x1f // 0x1f=31, sar=shift 연산(오른쪽, 부호 유지)
   0x0804852d <+28>:	sub    edx,eax
   0x0804852f <+30>:	mov    eax,edx
   0x08048531 <+32>:	mov    edx,eax
   0x08048533 <+34>:	lea    eax,[edx*4+0x0]
   0x0804853a <+41>:	mov    edx,eax
   0x0804853c <+43>:	mov    eax,edx
   0x0804853e <+45>:	shl    eax,0x4
   0x08048541 <+48>:	sub    eax,edx
   0x08048543 <+50>:	sub    ecx,eax
   0x08048545 <+52>:	mov    eax,ecx
   0x08048547 <+54>:	pop    ebp
   0x08048548 <+55>:	ret // main 함수로 return
End of assembler dump.
```

바이너리를 보았을 때 연산을 위한 명령어들이 있지만,
어셈블리어에서는 나머지를 구하기 위한 명령어가 없기 때문에 연산이 엄청 복잡해보인다.
```
way.mulresult/0xFFFFFFFF(value*multiply/0xFFFFFFFF)>>shift =>; value*original
```
구글에서 찾은 나눗셈 식인데 쉬프트 연산자가 들어가는 걸 보니 대충 이런 방식을 이용한 거 같다.

## func_hour 함수
```
Dump of assembler code for function func_hour:
   0x080484bd <+0>:	push   ebp // 프롤로그
   0x080484be <+1>:	mov    ebp,esp // 프롤로그
   0x080484c0 <+3>:	sub    esp,0x4 // 4byte 지역변수 선언
   0x080484c3 <+6>:	mov    DWORD PTR [ebp-0x4],0x0 // 0으로 초기화
   0x080484ca <+13>:	mov    ecx,DWORD PTR [ebp+0x8] // main 에서 입력받은 값을 연산을 위해 ecx 레지스터에 복사
   0x080484cd <+16>:	mov    edx,0x88888889 // 연산 시작
   0x080484d2 <+21>:	mov    eax,ecx
   0x080484d4 <+23>:	imul   edx
   0x080484d6 <+25>:	lea    eax,[edx+ecx*1]
   0x080484d9 <+28>:	sar    eax,0x5
   0x080484dc <+31>:	mov    edx,eax
   0x080484de <+33>:	mov    eax,ecx
   0x080484e0 <+35>:	sar    eax,0x1f
   0x080484e3 <+38>:	sub    edx,eax
   0x080484e5 <+40>:	mov    eax,edx
   0x080484e7 <+42>:	mov    DWORD PTR [ebp-0x4],eax
   0x080484ea <+45>:	mov    ecx,DWORD PTR [ebp-0x4]
   0x080484ed <+48>:	mov    edx,0x2aaaaaab
   0x080484f2 <+53>:	mov    eax,ecx
   0x080484f4 <+55>:	imul   edx
   0x080484f6 <+57>:	sar    edx,0x2
   0x080484f9 <+60>:	mov    eax,ecx
   0x080484fb <+62>:	sar    eax,0x1f
   0x080484fe <+65>:	sub    edx,eax
   0x08048500 <+67>:	mov    eax,edx
   0x08048502 <+69>:	add    eax,eax
   0x08048504 <+71>:	add    eax,edx
   0x08048506 <+73>:	shl    eax,0x3
   0x08048509 <+76>:	sub    ecx,eax
   0x0804850b <+78>:	mov    edx,ecx
   0x0804850d <+80>:	mov    eax,edx // main으로 리턴하기 위해 eax 레지스터에 결과값을 담는다.
   0x0804850f <+82>:	leave
   0x08048510 <+83>:	ret // main 함수로 return
End of assembler dump.
```
## func_days 함수
```
Dump of assembler code for function func_days:
   0x0804848b <+0>:	push   ebp // 프롤로그
   0x0804848c <+1>:	mov    ebp,esp // 프롤로그
   0x0804848e <+3>:	sub    esp,0x4 // 4byte 지역변수 선언
   0x08048491 <+6>:	mov    DWORD PTR [ebp-0x4],0x0 // 0으로 초기화
   0x08048498 <+13>:	mov    ecx,DWORD PTR [ebp+0x8] // main 에서 입력받은 값을 연산을 위해 ecx 레지스터에 복사
   0x0804849b <+16>:	mov    edx,0xb60b60b7 // 연산 시작
   0x080484a0 <+21>:	mov    eax,ecx
   0x080484a2 <+23>:	imul   edx
   0x080484a4 <+25>:	lea    eax,[edx+ecx*1]
   0x080484a7 <+28>:	sar    eax,0xa // 연산 과정은 모르겠지만 이 Shift 명령어가 작동되면 결과값이 eax 레지스터에 저장된다.
   0x080484aa <+31>:	mov    edx,eax
   0x080484ac <+33>:	mov    eax,ecx
   0x080484ae <+35>:	sar    eax,0x1f
   0x080484b1 <+38>:	sub    edx,eax
   0x080484b3 <+40>:	mov    eax,edx
   0x080484b5 <+42>:	mov    DWORD PTR [ebp-0x4],eax // 결과값을 지역변수에 담고
   0x080484b8 <+45>:	mov    eax,DWORD PTR [ebp-0x4] // 그 지역변수를 main 함수로 리턴하기 위해 eax에 담는다.
   0x080484bb <+48>:	leave
   0x080484bc <+49>:	ret // main 함수로 return
End of assembler dump.
```

## 로직
main 함수가 실행되면 4byte 짜리 지역변수를 생성하고 "분을 입력하세요."를 출력한다.
그 후, scanf로 정수 타입을 입력받고 func_minute, func_hour, func_days 함수를 호출해
입력한 분을 일, 시간, 분으로 전환한다. 그리고 Return 된 값을 "%d분은 %d일 %d시간 %d분입니다.\n" 이 문자열에 담아 출력한다.

## 알게 된 내용
### 바이트 저장 순서
바이트가 저장되는 순서에 따라 두개의 방식으로 나눌 수 있습니다.

#### Big Endian
빅 엔디안은 낮은 주소에 MSB부터 저장하는 방식이다.

#### Little Endian
리틀 엔디안은 낮은 주소에 LSB부터 저장하는 방식이다.
그래서 반대로 저장되기 때문에 거꾸로 읽어야 한다.

-----------

### Shift 연산자
#### SHL (Shift Left)
왼쪽으로 쉬프트 연산을 해 높은 비트를 내보내고 Carry Flag로 복사,
낮은 비트쪽에 0을 더하여 채운다.

#### SHR (Shift Right)
오른쪽으로 쉬프트 연산을 해 낮은 비트를 내보내고 Carry Flag로 복사,
높은 비트쪽에 0을 더하여 채운다.

#### SAL (Shift Arithmetic Left)
SHL과 결과적으로 동일하다.

#### SAR (Shift Arithmetic Right)
SHR과 결과적으로 동일하지 않다.
SHR 연산 후, MSB를 유지해야 한다.
