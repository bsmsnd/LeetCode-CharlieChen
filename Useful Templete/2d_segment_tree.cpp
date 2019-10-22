#include <iostream>
#include <vector>
using namespace std;

// int base[1000][1000] = { 0 };
int seg[1000][1000] = { 0 };

int rect[4][4] = { 
	{ 1, 2, 3, 4 }, 
	{ 5, 6, 7, 8 }, 
	{ 1, 7, 5, 9 }, 
	{ 3, 0, 6, 2 }, 
}; 

int size = 4;
int N, M;

void buildTree(vector< vector<int> >& rect)
{
    N = rect.size();
    M = rect[0].size();
	for (int i = 0;i < N; i++)
	for (int j = 0;j < M; j++)
		seg[N+i][M+j] = rect[i][j];
	
	for (int i = N;i < 2*N; i++)
		for (int j = M-1; j>=1; j--)
			seg[i][j] = seg[i][j<<1] + seg[i][(j<<1)|1];

	for (int i = N-1; i>=1; i--)
		for (int j = 1;j < 2 * M; j++)
			seg[i][j] = seg[i << 1][j] + seg[(i<<1) | 1][j];
		
}

void updateNode(int x, int y, int v)
{
	int i = x + N;
	int j = y + M;

	int diff = v - seg[i][j];

	for (int m = i; m > 0; m >>= 1)	
	for (int n = j; n > 0; j >>= 1)
	{
		seg[m][n] += diff;
	}
}

int queryX(int x, int Ly, int Ry)
{
	int l = Ly, r = Ry, res = 0;
	for (; l < r; l>>=1, r>>=1)
	{
		if (l & 1)
			res += seg[x][l++];
		if (r & 1)
			res += seg[x][--r];
	}	
	return res;
}

int queryY(int Lx, int Rx, int y)
{
	int l = Lx, r = Rx, res = 0;
	for (; l < r; l>>=1, r>>=1)
	{
		if (l & 1)
			res += seg[l++][y];
		if (r & 1)
			res += seg[--r][y];
	}	
	return res;
}

int _query(int Lx, int Rx, int Ly, int Ry)
{
	if (Lx >= Rx || Ly >= Ry)return 0;
	if (Lx & 1)	
		return _query(Lx+1, Rx, Ly, Ry) + queryX(Lx, Ly, Ry);
	if (Rx & 1)
		return _query(Lx, Rx-1, Ly, Ry) + queryX(Rx-1, Ly, Ry);
	if (Ly & 1)
		return _query(Lx, Rx, Ly+1, Ry) + queryY(Lx, Rx, Ly);
	if (Ry & 1)
		return _query(Lx, Rx, Ly, Ry-1) + queryY(Lx, Rx, Ry-1);
	return _query(Lx>>1, Rx>>1, Ly>>1, Ry>>1);

}

int query(int x1, int y1, int x2, int y2)
{
	return _query(x1+N, x2+N+1, y1+M, y2+M+1);
}

void print_seg()
{
	for (int i = 0;i < N * 2; i++)
	{
		for (int j = 0;j < M * 2; j++)
			printf("%d\t", seg[i][j]);
		printf("\n");
	}	
}

void print_matrix(vector< vector<int> > &v)
{
	int n = v.size();
	int m = v[0].size();
	for (int  i = 0;i < n; i++)
	{
		for (int j = 0;j < m; j++)
			printf("%d\t", v[i][j]);
		printf("\n");
	}
}

int main()
{
	vector< vector<int> > rect = {{1,2,3,4},{5,6,7,8},{4,7,2,3},{1,5,9,6}, {4,5,6,7}};
	print_matrix(rect);

	buildTree(rect);
	print_seg();

	updateNode(2,2,4);
	print_seg();

	cout << query(2,2,4,3) << endl;
}