/*#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	

	system("pause");
	return 0;
}
*/
#include <fstream>
#include <iostream>
using namespace std;
struct nodetype {

	int peer;

	struct nodetype *parent;

	int position;

	double cw;

	double cv;

	double r;
};

struct nodetype *queues[100000000];

/////////////////////////////////小根堆///////////////////////////////  

void insert(struct nodetype *x, int oldlast) //x是要插入的数

{ //oldlast是目前堆的元素数目                                                

	int last = oldlast + 1;

	queues[last] = x;

		int i = last;

	while ((i > 1) && (queues[i]->r < queues[i / 2]->r)) {

		struct nodetype *temp;

		temp = queues[i];

		queues[i] = queues[i / 2];

		queues[i / 2] = temp;

		i = i / 2;

	}

}     //last是当前堆的元素个数，执行该函数后                                                              

struct nodetype * deletemin(int last, struct nodetype *a[])

{      //返回堆的第一个元素（即最小元素）    

	struct nodetype *temp;

	temp = a[1];

	a[1] = a[last];

	last--;

	int i = 1;

	int j = 0;

	while (i <= last / 2)

	{
		if ((a[2 * i]->r < a[2 * i + 1]->r) || (2 * i == last)) j = 2 * i;

		else j = 2 * i + 1;                                                      if (a[i]->r > a[j]->r) {

			struct nodetype *temp;

			temp = a[i];

			a[i] = a[j];

			a[j] = temp;

			i = j;

		}

		else return(temp);

	}

	return(temp);

}

void main()  /////////////////////////////////小根堆///////////////////////////////  

{

	ifstream indata("input.txt");

	ofstream outdata("output.txt");

	int n, m, c;

	indata >> n; indata >> m; indata >> c;
	//cin >> n >> m >> c;

	double **w = new  double*[n + 1];

	double **cc = new double*[n + 1];

	for (int i = 1; i <= n; i++) {

		w[i] = new double[m + 1];

		cc[i] = new double[m + 1];

	}

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= m; j++)

			indata >> cc[i][j];

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= m; j++)

			indata >> w[i][j];

	double *cmin = new double[n + 1];

	double *wmin = new double[n + 1];

	for (int i = 1; i <= n; i++) {

		cmin[i] = cc[i][1];

		wmin[i] = w[i][1];

		for (int j = 2; j <= m; j++) {

			if (cmin[i]>cc[i][j]) cmin[i] = cc[i][j];

			if (wmin[i]>w[i][j]) wmin[i] = w[i][j];

		}

	}

	double *rc = new double[n + 1];//剩余部件最小价格和  

	double *rw = new double[n + 1];//剩余部件最小重量和  

	rc[n] = 0; rw[n] = 0;

	for (int i = n - 1; i >= 1; i--) {

		rc[i] = rc[i + 1] + cmin[i + 1];

		rw[i] = rw[i + 1] + wmin[i + 1];

	}

	struct nodetype *node = new struct nodetype;

	node->peer = 0;

	node->cv = 0;

	node->cw = 0;

	node->position = 0;

	node->r = rw[1] + wmin[1];

	insert(node, 0);

	int cpeer = 0;

	int q_len = 1;

	bool isend = false;

	while (!isend&&q_len>0)

	{
		node = deletemin(q_len, queues);

		q_len--;

		if (node->peer == n) {

			isend = true;

			outdata << node->cw << endl; 
			int *x = new int[n + 1];

			for (int k = n; k >= 1; k--) {

				x[k] = node->position;

				node = node->parent;

			}

			for (int k = 1; k <= n; k++)   outdata << x[k] << " ";

			outdata << endl; 
			return;
		}

		for (int j = 1; j <= m; j++)

		{
			if (node->cv + cc[node->peer + 1][j] + rc[node->peer + 1] <= c)

			{

				cpeer = node->peer + 1;

				struct nodetype *node_add = new struct nodetype;

				node_add->peer = cpeer;

				node_add->cv = node->cv + cc[cpeer][j];

				node_add->cw = node->cw + w[cpeer][j];

				node_add->r = node_add->cw + rw[cpeer];

				node_add->position = j;

				node_add->parent = node;

				insert(node_add, q_len);

				q_len++;

			}

		}

	}

	if (q_len <= 0) {
		outdata << "No Solution!" << endl;

		return;
	}

}