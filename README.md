# 2022 사이버 가디언즈 CTF 대비반(포너블)
### Docker Run Command
    docker run -it --security-opt seccomp=unconfined --name=pwn aku34587/cyber_guardians:1.0
    
### Custom Docker image
    docker run -it --name=pwn16 docker.dyhs.kr/pwn/pwn:16.04
    docker run -it --name=pwn18 docker.dyhs.kr/pwn/pwn:18.04
    docker run -it --name=pwn20 docker.dyhs.kr/pwn/pwn:20.04

### Gcc Compile Command
    gcc -fno-stack-protector -no-pie -mpreferred-stack-boundary=2 -m32 file.c
    gcc -fno-stack-protector -no-pie -mpreferred-stack-boundary=2 -m32 -z execstack file.c
