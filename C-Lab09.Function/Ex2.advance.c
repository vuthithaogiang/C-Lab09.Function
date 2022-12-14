
/*
* Minigame: casino 
* Người chơi sẽ ting đồng thòi 2 con xúc xắc: mỗi con sẽ có 6 mặt, mỗi mặt có 1, 2, ,3 ,4, 5, 6 lỗ 
* đại diện cho số điểm của từng con xúc xắc
* 
* Sau khi tung xúc xắc tổng số điểm của người chơi: sum = tổng số lỗ trên 2 mặt ngửa lên của hai con xúc xắc
* 
* case1 sum = 7 || 11: lượt chơi đầu tiên người chơi thắng
* case2 sum = 2 || 3 || 12: lượt chơi đầu tiên người chơi thua, nhà cái thăng
* case3 sum = 4 || 5 || 6 || 8 || 9 || 10: sum là điểm của người chơi 
* 
* 
* ở case3 để thắng trò chơi người chơi phải tiếp tục tung xúc xắc đến khi tổng điểm nhận đực bằng số điểm 
* đã nhận được ở lượt đầu tiên
* Người chơi sẽ thua nếu tung được tổng là 7 trước khi tung được tổng bằng số điểm của họ


*/

#include<stdio.h>

#include<time.h>
#include<stdlib.h>

enum Status {CONTINUE, WON, LOST};

int rollDice();

int main() {

	srand(time(NULL));

	int myPoint = 0;

	enum Status gameStatus;

	int sum = rollDice(); // gieo lan dau

	switch (sum) {
	case 7:
	case 11:

		gameStatus = WON;
		break;

	case 3:
	case 2:
	case 12:
		gameStatus = LOST;
		break;
	default:
		gameStatus = CONTINUE;

		myPoint = sum;  // save point
		printf("\nYour point in the first time: %d \n", myPoint);
		break;
	}

	while (CONTINUE == gameStatus) {
		sum = rollDice();

		if (sum == myPoint) {
			gameStatus = WON;
		}
		else {
			if (7 == sum) {
				gameStatus = LOST;
			}
		}
	}

	//display result

	if (WON == gameStatus) {
		puts("You WIN.");
	}
	else {
		puts("You LOSE.");
	}
	return 0;
}

int rollDice() {
	int dice1 = 1 + rand() % 6;
	int dice2 = 1 + rand() % 6;

	printf("\nPlayer rolled: %d %d = %d\n", dice1, dice2, dice1 + dice2);


	return dice1 + dice2;
}
