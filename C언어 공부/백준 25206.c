#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student {
	char className[50];
	float pnt;
	char grade[2];
};

int main(void) {
	struct student arr[20] = { 0, };
	float pntSum = 0;
	float pnt_mul_grade_sum = 0;

	for (int i = 0; i < 20; i++) {
		scanf("%s", arr[i].className);
		scanf("%f", &arr[i].grade);
		scanf("%s", arr[i].pnt);

		if ((strcmp(arr[i].grade, "A+") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 4.5;
		}
		else if ((strcmp(arr[i].grade, "A0") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 4.0;
		}
		else if ((strcmp(arr[i].grade, "B+") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 3.5;
		}
		else if ((strcmp(arr[i].grade, "B0") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 3.0;
		}
		else if ((strcmp(arr[i].grade, "C+") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 2.5;
		}
		else if ((strcmp(arr[i].grade, "C0") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 2.0;
		}
		else if ((strcmp(arr[i].grade, "D+") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 1.5;
		}
		else if ((strcmp(arr[i].grade, "D0") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 1.0;
		}
		else if ((strcmp(arr[i].grade, "F") == 0)) {
			pntSum += arr[i].pnt;
			pnt_mul_grade_sum += arr[i].pnt * 0;
		}
		else {
			continue;
		}
	}

	printf("%f", pnt_mul_grade_sum / pntSum);

	return 0;
}