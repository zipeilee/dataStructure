/* 
 * lectrue 1 demo 
 * 最大子列求和
 * zipei @ 2021/08/11
 */ 
 
#include<stdio.h>
#include<time.h>


/* method 1 暴力求解 三重循环 复杂度为 O(N^3)*/
int MaxSubArray1(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i=0; i<N; i++){
		for(j=i; j<N; j++){
			ThisSum = 0;
			for(k=i; k<j; k++){
				ThisSum += A[k];
			}
			if(ThisSum > MaxSum)
				MaxSum = ThisSum;
		}		
	}
	return MaxSum;
}

/* method 2 二重循环 复杂度为 O(N^2) */
int MaxSubArray2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;

    for(i=0; i<N;i++){
        ThisSum = 0;
        for (j=1; j<N; j++){  /* 针对相同的左端i，不同的右端j，只需向右累加一项即可求得子列和 。 */
            ThisSum += A[j];
        }
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
    }
    return MaxSum;
}

/*  method 3 分而治之 复杂度为 O(NlnN)
 *  将序列从中间分为左右两个子序列，递归求得子序列最大和，
 *  从中间分头向左右两边扫描，求跨过分界线最大子序列和，
 *  输出三个子列和中最大的一个。
 */
int Max3(int A, int B, int C)
{
    return (A > B) ? (A > C ? A : C) : (B > C ? B : C); /* 返回三个整数的最大值 */
}

int DivideAndConquer(int List[], int left, int right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int center, i;

    /* 递归的终止条件，子列只有1个数字 */
    if ( left == right ) {
        if ( List[left] > 0 )
            return List[left];
        else return 0;
    }

    center = ( left + right ) / 2;    /* 找到中分点 */
    MaxLeftSum = DivideAndConquer ( List, left, center );    /* 递归求左子列和 */
    MaxRightSum = DivideAndConquer ( List, center+1, right );    /* 递归求右子列和 */

    /* 求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0;	LeftBorderSum = 0;
    for ( i = center; i >= left; i-- ) {              /* 左边扫描结束 */
        LeftBorderSum += List[i];
        if ( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;	RightBorderSum = 0;
    for ( i = center+1; i <= right; i++ ) {           /* 左边扫描结束 */
        RightBorderSum += List[i];
        if ( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    /* 返回三个结果最大值 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );

}

int MaxSubArray3 ( int List[], int N ) {
    return DivideAndConquer ( List, 0, N-1 );
}

/*
 *  method 4 复杂度最低 为 O(N) 
 *  在线
 */
int MaxSubArray4(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	for(int i=0; i<N; i++){
		ThisSum += A[i];  /* 向右累加 */
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;  /* 若比当前值大 赋新值 */
		else if(ThisSum < 0)   /* 若结果为负数 抛弃之 */
			ThisSum = 0;
	}
	return MaxSum;
}

int main(){

    /* 使用Julia生成一个随机数组进行测试 */
    int n = 100;
    int a[] = {2, 15, 38, 67, 62, 10, 46,  1, 25, 29, 47, 96, 77, 96, 47, 47, 72,
               71, 32, 72, 85, 56, 29, 29, 86, 82, 26, 67, 34, 11, 33, 52, 86, 35,
               31, 36, 37, 48, 26, 61, 85, 20, 76, 80, 63, 49, 62, 25, 57, 33,  0,
               30, 61, 93, 56, 55, 61, 45, 37, 66, 98,  6, 51, 75, 83,  5,  6,  7,
               8, 83, 36, 63, 40, 98, 51, 90, 88, 48, 95, 81, 87, 46, 90, 29, 98,
               3,  9, 75, 44, 20, 95, 40, 80, 70,  4, 44, 98, 96, 25, 47};
    clock_t start, end;
    start = clock();
    MaxSubArray1(a,n);    /*  修改函数名 测试不同函数所花时间 */
    end = clock();
    double delta_t = (double ) (end-start)/10000;
    printf("time=%f\n",delta_t);
    return 0;
}
