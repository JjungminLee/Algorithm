def solution(n, t, m, p):
    answer = ''
    lst = []
    alpha = ["A", "B", "C", "D", "E", "F"]
    # 10진법 이전
    if n <= 10:
        for i in range(0, t*20):
            ans = []

            while True:
                remainder = int(i % n)
                ans.insert(0, remainder)
                i = int(i / n)
                if (i == 0):
                    break

            for num in ans:
                lst.append(num)

    # 10진법 이후
    elif n >= 11:
        for i in range(0, t * m):
            ans = []
            while True:
                remainder = int(i % n)
                if (remainder >= 10):
                    ans.insert(0, alpha[remainder - 10])
                else:
                    ans.insert(0, remainder)
                i = int(i / n)
                if (i == 0):
                    break
            for num in ans:
                lst.append(num)
    
    for i in range(p-1,len(lst),m):
        if(len(answer)==t):
            return answer
        answer+=str(lst[i])
    return answer

print(solution(2,4,2,1))