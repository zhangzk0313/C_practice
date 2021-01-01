/*************************************************************************
	> File Name: ep171.cpp
	> Author: zhang zk
	> Mail: 815028387@qq.com 
	> Created Time: 2020年01月07日 星期二 16时25分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

string num, num1, num2, num3;

int c1() {
	for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
		if (num[i] != num[j]) return 0;
	}
	return 1;
}

int c2() {
	if (num[0] != '1') return 0;
	for (int i = 1; i < num.size(); i++) {
		if (num[i] != 0) return 0;
	}
	return 1;
}

void make1() {
	int mid = (num1.size() + 1) / 2 - 1;
	num1[mid] -= 1;
	for (int )
}

void make1() {
	int mid = (num1.size() + 1) / 2 - 1;
	num1[mid] -= 1;
	for (int i = mid; i >= 0; i--) {
		if (num1[i] < '0') {
			num1[i - 1] -= 1;
			num1[i] += 10;
		}
	}
	for (int i = 0, j = num1.size() - 1; i < j; i++, j--) {
		num1[j] = num1[i];
	}
}
void make3() {
	int mid = (num3.size() + 1) / 2 - 1;
	num3[mid] += 1;
	for (int i = mid; i >= 0; i--) {
		if (num3[i] > '9') {
			num3[i - 1] += 1;
			num3[i] -= 10;
		}
	}
	for (int i = 0, j = num3.size() - 1; i < j; i++, j--) {
		num3[j] = num3[i];
	}
}


void make2() {
	for (int i = 0, j = num2.size() - 1; i < j; i++, j--) {
		num2[j] = num2[i];
	}
}

int main() {
	cin >> num;
	if (c1()) {
		cout << num << endl;
		return 0;
	}
	if (c2()) {
		for (int i = 1; i < num.size(); i++) {
			cout << 9;
		}
		return 0;
	}
	num1 = num2 = num3 = num;
	make2();
	int flag = 0;
	if (num2 < num) {
		make3();
		flag = 1;
	} else {
		make1();
	}
	if (flag == 1) {
		string min_num, max_num;
		min_num = max_num = num;
		for (int i = 0; i < num.size(); i++) {
			mid_num[i] = max_num[i] = '0';
		}
		for (int i = num.size() - 1; i >= 0; i--) {
			min_num[i] = num[i] - num2[i] + '0';
			max_num[i] = num3[i] - num[i] + '0';
		}
		for (int i = num.size() - 1; i >= 0; i--) {
			if (min_num[i] < '0') {
				min_num[i - 1] -= 1;
				min_num[i] += 10;
			}
			if (max_num[i] < '0') {
				max_num[i - 1] -= 1;
				max_num[i] += 10;
			}
		}
		if (max_num < min_num) {
			cout << num3 << endl;
		} else {
			cout << num2 << endl;
		} else 
	}
	return 0;
}
