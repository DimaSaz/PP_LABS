#include <iostream>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <omp.h>

using namespace std;

void show(int *ms, int size)
{
	for (int i = 0; i < size; i++)
		cout << ms[i] << ' ';
	cout << endl;
}

void ERROR(int er)
{
	if (er != 0)
	{
		cout << "ERROR" << endl;
		system("pause");
	}
}

int getDigitMax(int mMax)
{
	int dMax(0);
	for (; mMax > 0; dMax++)
		mMax /= 10;
	return dMax;
}

int getDigitMin(int mMin)
{
	int dMin(0);
	for (; mMin > 0; dMin++)
		mMin /= 10;
	return dMin;
}

void show(int num, int* ms_, int sz)
{
	cout << "MS_" << num << " - ";
	for (int i = 0; i < sz; i++)
		cout << ms_[i] << ' ';
	cout << " | i" << num << " = " << sz << endl;
}

void radixSortAlg(int *ms, int *ms_res, int size, int digit)
{
	int i1(0), i2(0), i3(0), i4(0), i5(0), i6(0), i7(0), i8(0), i9(0), i0(0);
	int ppow(1), ms_res_pos(0);
	int *ms_0 = new int[size];
	int *ms_1 = new int[size];
	int *ms_2 = new int[size];
	int *ms_3 = new int[size];
	int *ms_4 = new int[size];
	int *ms_5 = new int[size];
	int *ms_6 = new int[size];
	int *ms_7 = new int[size];
	int *ms_8 = new int[size];
	int *ms_9 = new int[size];

	ppow = pow(10, (digit - 1));

	for (int i = 0; i < size; i++)
		switch (ms[i] / ppow % 10)
		{
		case 0:
			ms_0[i0] = ms[i];
			i0++;
			break;
		case 1:
			ms_1[i1] = ms[i];
			i1++;
			break;
		case 2:
			ms_2[i2] = ms[i];
			i2++;
			break;
		case 3:
			ms_3[i3] = ms[i];
			i3++;
			break;
		case 4:
			ms_4[i4] = ms[i];
			i4++;
			break;
		case 5:
			ms_5[i5] = ms[i];
			i5++;
			break;
		case 6:
			ms_6[i6] = ms[i];
			i6++;
			break;
		case 7:
			ms_7[i7] = ms[i];
			i7++;
			break;
		case 8:
			ms_8[i8] = ms[i];
			i8++;
			break;
		case 9:
			ms_9[i9] = ms[i];
			i9++;
			break;
		}

	//show(0, ms_0, i0);
	//show(1, ms_1, i1);
	//show(2, ms_2, i2);
	//show(3, ms_3, i3);
	//show(4, ms_4, i4);
	//show(5, ms_5, i5);
	//show(6, ms_6, i6);
	//show(7, ms_7, i7);
	//show(8, ms_8, i8);
	//show(9, ms_9, i9);

	for (int i = 0; i < 10; i++)
		switch (i)
		{
		case 0:
			for (int j0 = 0; j0 < i0; j0++)
			{
				ms_res[ms_res_pos] = ms_0[j0];
				ms_res_pos++;
			}
			break;
		case 1:
			for (int j1 = 0; j1 < i1; j1++)
			{
				ms_res[ms_res_pos] = ms_1[j1];
				ms_res_pos++;
			}
			break;
		case 2:
			for (int j2 = 0; j2 < i2; j2++)
			{
				ms_res[ms_res_pos] = ms_2[j2];
				ms_res_pos++;
			}
			break;
		case 3:
			for (int j3 = 0; j3 < i3; j3++)
			{
				ms_res[ms_res_pos] = ms_3[j3];
				ms_res_pos++;
			}
			break;
		case 4:
			for (int j4 = 0; j4 < i4; j4++)
			{
				ms_res[ms_res_pos] = ms_4[j4];
				ms_res_pos++;
			}
			break;
		case 5:
			for (int j5 = 0; j5 < i5; j5++)
			{
				ms_res[ms_res_pos] = ms_5[j5];
				ms_res_pos++;
			}
			break;
		case 6:
			for (int j6 = 0; j6 < i6; j6++)
			{
				ms_res[ms_res_pos] = ms_6[j6];
				ms_res_pos++;
			}
			break;
		case 7:
			for (int j7 = 0; j7 < i7; j7++)
			{
				ms_res[ms_res_pos] = ms_7[j7];
				ms_res_pos++;
			}
			break;
		case 8:
			for (int j8 = 0; j8 < i8; j8++)
			{
				ms_res[ms_res_pos] = ms_8[j8];
				ms_res_pos++;
			}
			break;
		case 9:
			for (int j9 = 0; j9 < i9; j9++)
			{
				ms_res[ms_res_pos] = ms_9[j9];
				ms_res_pos++;
			}
			break;
		}

	delete[] ms_0;
	delete[] ms_1;
	delete[] ms_2;
	delete[] ms_3;
	delete[] ms_4;
	delete[] ms_5;
	delete[] ms_6;
	delete[] ms_7;
	delete[] ms_8;
	delete[] ms_9;

}

int main()
{
	int threadNum(2);
	int mSize(0);
	int hlp(0), mMax(0), mMin(0), er(0), digitMax(0), digitMin(0);

	srand(time(0));
	cout << "Enter mSize: "; cin >> mSize;
	cout << "Enter mMax: "; cin >> mMax;
	cout << "Enter mMin: "; cin >> mMin;
	cout << "Enter threadNum: "; cin >> threadNum;

	if (mMax < mMin || threadNum <= 0)
		er = 1;
	ERROR(er);

	digitMax = getDigitMax(mMax);
	digitMin = getDigitMin(mMin);

	int *ms = new int[mSize];
	int *ms_test = new int[mSize];
	int *ms_res = new int[mSize];
	for (int i = 0; i < mSize; i++)
		ms[i] = mMin + rand() % ((mMax + 1) - mMin);


	ms_test = ms;



	//show(ms, mSize);

	//cout << "\nSIZE - " << hlp << endl;
	//cout << "MAX - " << mMax << endl;
	//cout << "MIN - " << mMin << endl;
	//cout << "DIGIT_MAX - " << digitMax << endl;
	//cout << "DIGIT_MIN - " << digitMin << "\n\n";

	double time = omp_get_wtime();
#pragma omp parallel num_threads(threadNum)
{
		int delta = mSize / threadNum;
		int rem = mSize % threadNum;
		int rank = omp_get_thread_num();
		int start = rank * delta;
		int end = start + delta;

		//if (rank == 0)
		//{
		//	cout << "DELTA - " << delta << endl;
		//	cout << "REM - " << rem << endl;
		//}
		//cout << "RANK - " << rank << endl;
		//cout << "START - " << start << endl;
		//cout << "END - " << end << endl;

		if (rank == threadNum - 1)
			end += rem;

		int *ms_loc = new int[end - start];

		for (int i = start, j = 0; i < end + 1; i++, j++)
			ms_loc[j] = ms[i];

		for (int i = 1; i < digitMax + 1; i++)
		{
			radixSortAlg(ms_loc, ms_res, mSize, i);
			ms_loc = ms_res;
		}

		for (int i = start, j = 0; i < end + 1; i++, j++)
			ms[i] = ms_loc[j];

		int threadNum_h(threadNum);
		int flag(0);
		int flag_l(-1);

		if (threadNum > 1)
		{
			if (threadNum % 2 != 0) 
				if (rank == (threadNum - 1))
				{
					for (int i = start, j = 0; i < end + 1; i++, j++)
						ms[i] = ms_loc[j];
					threadNum_h++;
					flag++;
				}
			if (rank == 1 || (rank % 2) != 0)
			{
				flag++;
				threadNum++;
				int *ms_hlp = new int[delta * 2];
				int k(0);
				for (int i = start - delta, j = 0; i < end + 1 && j < delta + 1; k++)
				{
					if (ms[i] <= ms_loc[j] && j != end)
					{
						ms_hlp[k] = ms[i];
						i++;
					}
					else
					{
						ms_hlp[k] = ms_loc[j];
						j++;
					}
				}
				for (int i = start - delta, j = 0; i < end; i++, j++)
					ms[i] = ms_hlp[j];
				delete[] ms_hlp;
			}
		}

		flag_l++;
		int count(0);
		int pw(2);
		bool odd(false);

		while (threadNum_h != 1)
		{
			int threadNum_h2(threadNum_h);
			threadNum_h = 0;
			if (threadNum_h2 % 2 != 0)
				odd = true;
			for (int i = 0; i < threadNum; i++)
			{
				if (rank == i && flag > flag_l)
				{
					if (odd && count == threadNum_h2)
					{
						for (int i = start, j = 0; i < end + 1; i++, j++)
							ms[i] = ms_loc[j];
						threadNum_h++;
						flag++;
					}
					else
					{
						count++;
						flag++;
						threadNum_h++;
						int sz = delta * pow(2,pw);
						int *ms_hlp = new int[sz];
						int k(0);
						for (int i = start - sz, j = 0; i < end + 1 && j < delta + 1; k++)
						{
							if (ms[i] <= ms_loc[j] && j != end)
							{
								ms_hlp[k] = ms[i];
								i++;
							}
							else
							{
								ms_hlp[k] = ms_loc[j];
								j++;
							}
						}
						for (int i = start - sz, j = 0; i < end; i++, j++)
							ms[i] = ms_hlp[j];
						delete[] ms_hlp;
					}
				}
			}
			pw++;
		}
delete[] ms_loc;
}
time = omp_get_wtime() - time;

double time2 = omp_get_wtime();
	for (int i = 1; i < digitMax + 1; i++)
	{
		radixSortAlg(ms, ms_res, mSize, i);
		//show(ms_res, mSize);
		ms = ms_res;
	}
	time2 = omp_get_wtime() - time2;

	cout << "TIME_P - " << time << endl;
	cout << "TIME2 - " << time2 << endl;
	cout << endl;
	//show(ms, mSize);
	cout << endl;

	system("pause");
	return 1;
}