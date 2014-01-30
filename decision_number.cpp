/**
 * Finding Decision Numbers For graphs with adjacency list representation of graphs
 * By: Kiana Ehsani
 * Email: kehsani@ce.sharif.edu
 **/


#include<iostream>
#define MXN 30


using namespace std;



int mark[MXN] = {};
int adj_mat[MXN][MXN] = {};
int markNumber = -1;
int MaxN;
char decision_type;

/**
 * Calculates sum of the values of the vertices
**/
int sum_mark()
{
	int sum = 0;
	for(int i = 0;i < MaxN; i++)
	{
		sum += mark[i];
	}
	return sum;
}

/**
 * Checks whether this labeling is the one with the features we want or not
**/
bool isNDG()
{
	for(int i = 0; i < MaxN; i++)
	{
		int sum = 0;
		for(int j = 0; j < MaxN && adj_mat[i][j] != -1; j++)
		{
			sum += mark[adj_mat[i][j]];
		}
		
		
		switch(decision_type){
					case 'b':
					break;
					case 'n':
					sum += mark[i];
					break;
					case 'g':
					break;
					case 'e':
					sum += mark[i];
					break;
				}
		
		
		
		switch(decision_type){
					case 'b':
					if(sum > 1)
						return false;
					break;
					case 'n':
					if(sum > 1)
						return false;
					break;
					case 'g':
					if(sum < 1)
						return false;
					break;
					case 'e':
					if(sum < 1)
						return false;
					break;
				}
	}
	return true;

}


/**
 * Calculates the next function for labeling the vertices
**/
void makeMark()
{
	markNumber++;
	int s = markNumber;
	for(int i = 0;i < MaxN; i++)
	{
		int digit = s % 2;
		s /= 2;
		digit == 1 ? mark[i] = 1 : mark[i] = -1;
	}


}


/**
 * calculates max a and b
 **/
int maxi(int a, int b){
	if (a > b)
		return a;
	return b;
}


/**
 * calculates min a and b
 **/
int mini(int a, int b){
	if (a > b)
		return b;
	return a;
}


/**
Calculates a ^ b
**/
int pow (int a, int b)
{
	int sum = 1;
	for(int i = 0; i< b; i++)
	    sum*=a;
	return sum;
}



/**
 * Read the graph from I/O
 **/
void get_graph()
{
	for(int i = 0;i < MaxN; i++)
	{
		for(int j = 0; j < MaxN; j++)
		{
			adj_mat[i][j] = -1;
		}
	}
	markNumber = -1;
	for(int i =0; i < MaxN; i++)
	{
		int a;
		cin >> a;
		cin >> a;
		int counter = 0;
		while(a != -1)
		{
			adj_mat[i][counter] = a;
			counter ++;
			cin >> a;
		}

	}
}


/**
 * Main function
 **/
int main()
{

    ios::sync_with_stdio(false);
    cout << "Enter type of decision number, order and the adjacency-list representation of the graph. (end list with -1)"<< endl;
    cout << "Type of decision numbers:" << endl << "Bad Decision Number: b" << endl << 
    "Nice Decision Number: n" << endl << "Good Decision Number: g" << endl << "Excellent Decision Number: e" << endl;
    cout << "Enter \'q\' to exit!" << endl; 
    cin >> decision_type;
    while(decision_type != 'q')
    {
        cin >> MaxN;
        get_graph();
		int max = pow(2, MaxN);
		
		
		int maxSum;
		switch(decision_type){
					case 'b':
					maxSum = -MaxN - 10;
					break;
					case 'n':
					maxSum = - MaxN - 10;
					break;
					case 'g':
					maxSum = MaxN + 10;
					break;
					case 'e':
					maxSum = MaxN + 10;
					break;
				}


        /**
        Checks all the labelings to find the decision number
        **/
		for(int i = 0; i < max; i++)
		{
			makeMark();
			if(isNDG())
			{
				int temp = sum_mark();
				switch(decision_type){
					case 'b':
					maxSum = maxi(maxSum, temp);
					break;
					case 'n':
					maxSum = maxi(maxSum, temp);
					break;
					case 'g':
					maxSum = mini(maxSum, temp);
					break;
					case 'e':
					maxSum = mini(maxSum, temp);
					break;
				}
				

			}
		}
		cout << maxSum<<  endl;
		cin >> decision_type;
    }
	return 0;
}
