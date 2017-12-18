#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct word {
	string eng;
	string chi;
	word *next;
};
word *head;
int z = 0;

struct block {
	string max;
	int address;
};
void readtxt()
{
	word *q, *p;
	ifstream file;
	string a, b;
	file.open("dictionary.txt");
	if (!file.is_open())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	while (file.eof() != 1)
	{
		q = new word;
		file >> a >> b;
		q->eng = a;
		q->chi = b;
		q->next = NULL;
		if (z == 0)
		{
			head = q;
			p = q;
		}
		else
		{
			p->next = q;
			p = q;
		}
		z++;
	}
	file.close();
}

void BlockSearch(word *a,block *b,int m,int n)
{
	int i, j, k,l;
	string s;
	k = 0;
	cout << "请输入你想要查找的单词" << endl;
	cin >> s;
	for (i = 0; i < m; i++)
	{
		if (b[i].max >= s)
		{
			j = b[i].address;
			for (l = j; l < j + n; l++)
			{
				if (s == a[l].eng)
				{
					cout << "该单词在字典第" << l + 1 << "位" << endl << s << "      " << a[l].chi << endl;
					return;
				}
			}
			break;
		}
	}
	cout << "你查找的单词并不存在！" << endl;

}
void main()
{
	int  j, k,l,m,x;
	word *p;
	block b[26];
	readtxt();
	word *a = new word[z];
	k =z/26+1;
	p = head;
	j = 0;
	l = 0;
	m = 0;
	while (p != NULL)
	{
		a[j].eng = p->eng;
		a[j].chi = p->chi;
		a[j].next = NULL;
		if (j%k == 0 || j == 0)
		{
			b[l].address = j;
			l++;
		}
		if ((j + 1) % k == 0 || j == z-1)
		{
			b[m].max = a[j].eng;
			m++;
		}
		j++;	
		p = p->next;
	}
	
	while (1)
	{
		BlockSearch(a, b, l, k);
	}
	
}