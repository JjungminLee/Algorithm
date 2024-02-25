def solution(m, musicinfos):
    answer = ''
    ans = []
    ansIdx = 0
    # 재생시간, 입력 순서 value에 담기
    for music in musicinfos:
        lst = music.split(',')

        m = m.replace("C#", "H").replace("D#", "I").replace("F#", "J").replace("G#", "K").replace("A#", "L").replace(
            "E#", "Z")
        # 시간 처리
        startTime = lst[0].split(':')
        startHour = int(startTime[0])
        startMinute = int(startTime[1])
        endTime = lst[1].split(':')
        endHour = int(endTime[0])
        endMinute = int(endTime[1])
        time = (endHour - startHour) * 60 + endMinute - startMinute

        # 음악 이름
        musicName = lst[2]
        # 음표 처리
        musicInfo = lst[3]
        musicInfo = musicInfo.replace("C#", "H").replace("D#", "I").replace("F#", "J").replace("G#", "K").replace("A#",
                                                                                                                  "L").replace("E#","Z")
        musicArr = []
        temp = 0

        while (temp != time):
            if (temp < len(musicInfo)):
                musicArr.append(musicInfo[temp])
                temp += 1
            else:
                musicArr.append(musicInfo[temp % len(musicInfo)])
                temp += 1

        musicStr = ''.join(musicArr)

        if(m in musicStr):
            ans.append([time,ansIdx,musicName])
            ansIdx+=1

        ans.sort(key=lambda x: (x[0], -x[1]), reverse=True)

    if (len(ans) == 0):
        answer = "(None)"
    else:
        answer = ans[0][2]
    return answer

#print(solution("ABCDEFG",["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
#print(solution("ABC",["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
