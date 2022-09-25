# 2022 사이버 가디언즈 CTF 대비반(포너블)
### Docker Run Command
    docker run -it --security-opt seccomp=unconfined --name=pwn aku34587/cyber_guardians:1.0
### Gcc Compile Command
    gcc -fno-stack-protector -no-pie -mpreferred-stack-boundary=2 -m32 file.c