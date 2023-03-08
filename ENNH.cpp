/*
This code to implement Extended Nearest Neighbor Heuristic Algorithm by c++ to Traveling Salesman Problem
implemented by Mohamed Ali / mohamedn6666@gmail.com
LinkedIN: linkedin.com/in/mohamed-nasr.
github: mohmednasr
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;


int FindMin_row(const vector<vector<int>>& myVector, int n , int* k, vector<int> v);
int FindMin_col(const vector<vector<int>>& myVector, int m, int *k, vector<int> v);



int main()
{
    int n;   //number of vertices
    string y;   //take the value of elements from the table 
    
    fstream file;
    file.open("example_instance.txt", ios::in); //define the file

    file >> n;  //get the number of vertices from the file
    vector<vector<int >> m(n); //intialize our 2D vector to keep the elemnts of the table

    /*the next for loop to get the elements value from the file and
     keep them at the vector m if it's at digonal we make if-condition 
     to put 0 instead of "-" else convert it to int */

   for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            file >> y;
            if (i==j) 
                m[i].push_back(0);
            else
                m[i].push_back(stoi(y));
        }
    }

    // implement Nearest Heursitics Algorithm
    vector<int> v;   //vector to contain the vertices remaining to our path
    vector<int> p;   //vector to contain the vertices for our path

    //first fill vector V by all vertices using for loop
    for(int i = 1; i < n; ++i)
        {v.push_back(i);}
    


    int c ; //refer to the column index
    int r ; // refer to the row index
    int min; // min value at the row move from the last vertix at the path
    int min_c; // min value at the column move to the first vertix at the path
    int l; // the index of the last vertix at the path
    int f; // the index of the first vertix at the path

//we assume our path will start by vertix 1 then will be the first element at the path

    p.push_back(0);

    for(int x:v) //for each element remaining in vector v
        {
        l = p.back();
        f = p.front();
        min = FindMin_row( m, l,& c, v);
        min_c = FindMin_col( m, f,& r, v);
        //check the min value
        if (min <= min_c)
            { // if go from the last vertix
            p.push_back(c);
            auto it = find(v.begin(), v.end(), c);
            v.erase(it);
            }
        else
            { // if go to the first vertix
            p.insert(p.begin() + 0, r);
            auto it = find(v.begin(), v.end(), r);
            v.erase(it);
            }
            //print the path on the screen

        cout<< "\n The path with Extended Neareast Neighbor Heuristic Algorithm : ";
        for(int x:p)
            cout << x+1 << " ";
            cout << endl;
        }


    return 0;
}

//for finding minimum in the row
//we have four variables 
//vector called myVector to refer for the main vector, int called n represent the row number
//k refer to the index of the column, vector v the remaining vertices 
int FindMin_row(const vector<vector<int>>& myVector, int n, int* k, vector<int> v) 
{     
	// Initialize minimum element 
    int min;
    *k = *v.begin();
    min = myVector[n][*k];
	// Traverse vector elements  
	for (int i:v)
        {
		if (myVector[n][i] < min) 
			{min = myVector[n][i]; 
            *k = i;}
            }    
    return min;
} 






//for finding minimum in the column
///vector called myVector to refer for the main vector, int called m represent the column number
//k refer to the index of the row, vector v the remaining vertices 
int FindMin_col(const vector<vector<int>>& myVector, int m, int *k, vector<int> v) 
{     
	// Initialize minimum element 
    int min;

    *k = *v.begin();
    min = myVector[*k][m];

	// Traverse vector elements  
	for (int i:v) 
		if (myVector[i][m] < min) 
			{min = myVector[i][m]; 
            *k = i;}

	return min; 
} 
