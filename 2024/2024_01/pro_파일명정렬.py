from functools import cmp_to_key
def compare(x,y):
    # heady body 들어온 순서순
    strX = x[0].upper()
    strY = y[0].upper()
    if(strX<strY):
        return -1
    elif strX>strY:
        return 1 #y를 앞으로
    elif strX==strY:
        if x[1]>y[1]:
            return 1
        elif x[1]<y[1]:
            return -1
        elif x[1]==y[1]:
            if x[2]>y[2]:
                return 1
            else:
                return -1

    return 0
def solution(files):
    answer = []
    headDict = dict()
    bodyDict = dict()
    tailDict = dict()
    # 65 ~ 90 97~122 문자
    # 48 ~ 57 숫자
    # 공백 32
    # 마침표 46
    # 빼기 부호 45
    for item in files:
        head = 0
        # Head찾기
        while True:
            if 48 <= ord(item[head]) <= 57:
                break
            else:
                head += 1
        # Body 찾기
        body = head
        while True:
            if (body == len(item)):
                break

            if ord(item[body]) == 32 or ord(item[body]) == 45 or ord(item[body]) == 46 or 65 <= ord(
                    item[body]) <= 90 or 97 <= ord(item[body]) <= 122:
                break
            else:
                body += 1
        idx = files.index(item)

        # 문자열로 concat하기
        headStr = ""
        for i in range(0, head):
            headStr += item[i]
        bodyStr = ""
        for i in range(head, body):
            bodyStr += item[i]
        tailStr = ""
        for i in range(body, len(item)):
            tailStr += item[i]
        headDict[idx] = headStr
        bodyDict[idx] = int(bodyStr)
        tailDict[idx] = tailStr

    # 딕셔너리보면서 정렬하기
    # Head
    headDict = sorted(headDict.items(), key=lambda item: item[1][0])  # value: [1]

    # body
    bodyDict = sorted(bodyDict.items(), key=lambda item: item[1])


    lst = []
    for i in range(len(headDict)):
        for j in range(len(bodyDict)):
            if(headDict[i][0]==bodyDict[j][0]):

                lst.append((headDict[i][1], bodyDict[j][1], bodyDict[j][0]))

    sorted_list=sorted(lst,key=cmp_to_key(compare))
    for i in range(len(sorted_list)):
        idx = sorted_list[i][2]
        answer.append(files[idx])


    return answer

#solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])
# print(solution(["A500001", "A50000"]))