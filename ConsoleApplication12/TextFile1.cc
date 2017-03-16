#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
int main()
{
	vector<double> arr;//以vector为容器装载未知大小的数组
	double num;
	int index = 0;
	double *p;
	cout << "请输入该数组的各项（以任意非数项为结束标志）" << endl;
	while (cin >> num)
	{
		arr.push_back(num);
		index++;
	}
	if (0 == index)//未输入警告
	{
		cout << "请输入数据！" << endl;
		return -1;
	}
	p = new double[index];//将vector中的数依次传入数组中
	int t = 0;
	for (auto i : arr)
	{
		p[t] = i;
		t++;
	}
	double temp = 0;//冒泡排序法对数组进行排序
	for (int j = 0;j < index - 1;j++)
		for (int i = 0;i < index - 1 - j;i++)
		{
			if (p[i] < p[i + 1])
			{
				temp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = temp;
			}
		}
	cout << "这是排序后的数组：" << ends;//排序后的数组输出
	for (int i = 0;i < index;i++)
		cout << p[i] << ends;
	cout << endl;
	double sum = 0;
	double ave = 0;
	for (int i = 0;i < index;i++)//以循环累加求得总数
		sum += p[i];
	ave = sum / index;//通过总数求得平均数
	cout << "该数组的平均数是：" << ends;
	cout << ave << endl;
	cout << "该数组的中位数是：" << ends;//由于数组已排序，故中位数很容易找到并输出
	if (0 == index % 2)
		cout << (p[index / 2] + p[(index / 2) - 1]) / 2 << endl;
	else
		cout << p[(index + 1) / 2 - 1] << endl;
	double* cnt;
	cnt = new double[index];//cnt数组对应原数组中的数出现次数统计
	cnt[0] = 1;
	for (int i = 0;i < index - 1;i++)
		if (p[i] == p[i + 1])
			cnt[i + 1] = cnt[i] + 1;
		else
			cnt[i+1] = 1;
	cout << "该数组的众数是：  " << ends;//cnt中最大项就对应原数组的众数
	for (int i = 0;i < index;i++)
	{
		int d = 0;
		for (int j = 0;j < index;j++)
			if (cnt[i] >= cnt[j])
				continue;
			else
			{
				d = -1;
				break;
			}
		if (d != -1)
			cout << p[i] << ends;//将众数输出
	}
	cout << endl;
	system("pause");
	return 0;
}