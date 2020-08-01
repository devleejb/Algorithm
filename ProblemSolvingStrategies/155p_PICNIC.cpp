#include<stdio.h>

using namespace std;

int results[50];
int isFriends[10][10];
int isPair[10];
int numOfStudents;

int countFriends(int isPair[10]) {
    int firstFriend = -1, ret = 0;
    
    // 짝이 모두 이루어졌는지 확인
    for (int i = 0; i < numOfStudents; i++) {
        if (!isPair[i]) {
            firstFriend = i;

            break;
        }
    }

    if (firstFriend == -1) return 1;

    for (int secondFriend = firstFriend + 1; secondFriend < numOfStudents; secondFriend++) {
        if (isFriends[firstFriend][secondFriend] && !isPair[secondFriend]) {
            isPair[firstFriend] = isPair[secondFriend] = 1;
            ret += countFriends(isPair);
            isPair[firstFriend] = isPair[secondFriend] = 0;
        }
    }

    return ret;
}

int main() {
    int numOfPairs, C;

    scanf("%d", &C);

    for (int i = 0; i < C; i++) {

        scanf("%d %d", &numOfStudents, &numOfPairs);

        for (int j = 0; j < numOfPairs; j++) {
            int first, second;

            scanf("%d %d", &first, &second);

            isFriends[first][second] = isFriends[second][first] = 1;
        }

        results[i] = countFriends(isPair);

        for (int row = 0; row < numOfStudents; row++)
            for (int col = 0; i < numOfStudents; col++)
                isFriends[row][col] = 0;       
    }

    for (int i = 0; i < C; i++) printf("%d\n", results[i]);
    
    return 0;
}