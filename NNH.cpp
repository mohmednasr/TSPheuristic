/*
This code to implement Nearest Neighbor Heuristic Algorithm by c++ to Traveling Salesman Problem
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
    

    int k; // to hold the row value from vector p
    int c ; // refer to column with the lowest value at row k
    int min; // refer to the lowest value at row k

    //we assume our path will start by vertix 1 then will be the first element at the path
    p.push_back(0);

    for(int x:v) //for each element remaining in vector v
        {
        k = p.back(); //define the value of the row as the last element of the path
        min = FindMin_row(m,k,& c, v); // find the min value at that row k
        p.push_back(c); // push the value of c to the path
        auto it = find(v.begin(), v.end(), c); //remove c from vector x
        v.erase(it);
        //print the path on the screen
        cout<< "\n The path with Neareast Neighbor Heuristic Algorithm : ";
        for(int x:p)
             cout << x + 1 << " ";
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
        {if (myVector[n][i] < min) 
			{min = myVector[n][i]; 
            *k = i;}
            }    
    return min;
} 
