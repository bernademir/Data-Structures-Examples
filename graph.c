#include<stdio.h>

#define MAX 30

//Kenarlar� tutan yap�m�z
// u source, v destination ve w a��rl�k/maliyet
// Buradaki u ve v d���mleri temsil edecek.
typedef struct edge
{
	int u, v, w;
}edge;

//kenar listesi tutan yap�m�z 
typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgelist;

edgelist elist;

//Kom�uluk matrisi
int G[MAX][MAX], n;
edgelist spanlist;

//Temel fonksiyon tan�mlamalar�
void kruskal();
int find(int belongs[], int vertexno);
void union1(int belongs[], int c1, int c2);
void sort();
void print();

void main()
{
	int i, j, total_cost;

	printf("\nDugum sayisini giriniz... :");

	scanf_s
	("%d", &n);

	printf("\nKomsuluk Matrisini girin:\n");

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf_s("%d", &G[i][j]);

	kruskal();
	print();
}

void kruskal()
{
	int belongs[MAX], i, j, cno1, cno2;
	elist.n = 0;

	//A�a��daki d�ng� source, destination d���mleri ile d���mler aras�ndaki maliyeti de�i�kenlere aktar�yor
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
		{
			if (G[i][j] != 0)
			{
				elist.data[elist.n].u = i;
				elist.data[elist.n].v = j;
				elist.data[elist.n].w = G[i][j];
				elist.n++;
			}
		}

	//Kenarlar� k���kten b�y��e s�ralayan fonksiyonu �a��r�yoruz.
	sort();

	//D���mlerin Parentlar�n� olu�turuyor.
	for (i = 0; i < n; i++)
		belongs[i] = i;

	spanlist.n = 0;

	for (i = 0; i < elist.n; i++)
	{
		cno1 = find(belongs, elist.data[i].u);
		cno2 = find(belongs, elist.data[i].v);

		if (cno1 != cno2)
		{
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n = spanlist.n + 1;
			union1(belongs, cno1, cno2);
		}
	}
}

int find(int belongs[], int vertexno)
{
	return(belongs[vertexno]);
}

void union1(int belongs[], int c1, int c2)
{
	int i;

	for (i = 0; i < n; i++)
		if (belongs[i] == c2)
			belongs[i] = c1;
}

void sort()
{
	int i, j;
	edge temp;

	for (i = 1; i < elist.n; i++)
		for (j = 0; j < elist.n - 1; j++)
			if (elist.data[j].w > elist.data[j + 1].w)
			{
				temp = elist.data[j];
				elist.data[j] = elist.data[j + 1];
				elist.data[j + 1] = temp;
			}
}

void print()
{
	int i, cost = 0;

	for (i = 0; i < spanlist.n; i++)
	{
		printf("\n%d\t%d\t%d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
		cost = cost + spanlist.data[i].w;
	}

	printf("\n\nAsgari Tarama Agacinin Maliyeti=%d", cost);
}