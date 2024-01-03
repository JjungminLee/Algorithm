def solution(msg):
    answer = []
    alpha = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
             "V", "W", "X", "Y", "Z"]
    global step
    step = 0
    for i in range(0, len(msg)):
        target = ""
        i=step
        for j in range(i , len(msg)):
            if target + msg[j] in alpha:
                target += msg[j]
            else:
                alpha.append(target + msg[j])
                answer.append(alpha.index(target) + 1)
                step = j
                break

    answer.append(alpha.index(target) + 1)
    return answer


