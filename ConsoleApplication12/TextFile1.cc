#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
int main()
{
	vector<double> arr;//��vectorΪ����װ��δ֪��С������
	double num;
	int index = 0;
	double *p;
	cout << "�����������ĸ�������������Ϊ������־��" << endl;
	while (cin >> num)
	{
		arr.push_back(num);
		index++;
	}
	if (0 == index)//δ���뾯��
	{
		cout << "���������ݣ�" << endl;
		return -1;
	}
	p = new double[index];//��vector�е������δ���������
	int t = 0;
	for (auto i : arr)
	{
		p[t] = i;
		t++;
	}
	double temp = 0;//ð�����򷨶������������
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
	cout << "�������������飺" << ends;//�������������
	for (int i = 0;i < index;i++)
		cout << p[i] << ends;
	cout << endl;
	double sum = 0;
	double ave = 0;
	for (int i = 0;i < index;i++)//��ѭ���ۼ��������
		sum += p[i];
	ave = sum / index;//ͨ���������ƽ����
	cout << "�������ƽ�����ǣ�" << ends;
	cout << ave << endl;
	cout << "���������λ���ǣ�" << ends;//�������������򣬹���λ���������ҵ������
	if (0 == index % 2)
		cout << (p[index / 2] + p[(index / 2) - 1]) / 2 << endl;
	else
		cout << p[(index + 1) / 2 - 1] << endl;
	double* cnt;
	cnt = new double[index];//cnt�����Ӧԭ�����е������ִ���ͳ��
	cnt[0] = 1;
	for (int i = 0;i < index - 1;i++)
		if (p[i] == p[i + 1])
			cnt[i + 1] = cnt[i] + 1;
		else
			cnt[i+1] = 1;
	cout << "������������ǣ�  " << ends;//cnt�������Ͷ�Ӧԭ���������
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
			cout << p[i] << ends;//���������
	}
	cout << endl;
	system("pause");
	return 0;
}