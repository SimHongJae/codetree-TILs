dx = [1, 0, -1, 0]  # 상, 우, 하, 좌
dy = [0, 1, 0, -1]

# 왼쪽으로 방향 전환: 상->좌->하->우

cmd_lst = list(input())
x, y = 0, 0
d = 0
for cmd in cmd_lst:
    if cmd == 'L':
        d = (d+3) % 4
    elif cmd == 'R':
        d = (d+1) % 4
    else:
        x += dx[d]
        y += dy[d]
    
print(y, x)