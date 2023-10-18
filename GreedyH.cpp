/*
This code to implement Greedy Heuristic Algorithm by c++ to Traveling Salesman Problem
implemented by Mohamed Ali / mohamedn6666@gmail.com
LinkedIN: linkedin.com/in/mohamed-nasr.
github: mohmednasr
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int FindMax(const vector<vector<int>>& myVector, int* r, int* c);
int FindMin(const vector<vector<int>>& myVector, int* r, int* c, vector<int> r_index, vector<int> c_index);
int getIndex(vector<int> v, int K);




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
    vector<int> v_r;   //vector to contain the vertices remaining to our path as out-degree
    //
    vector<int> v_c;   //vector to contain the vertices remaining to our path as in-degree
    //
    vector<int> p;   //vector to contain the vertices for our path

    //first fill vector V by all vertices using for loop
    for(int i = 0; i < n; ++i)
        {v_r.push_back(i);
        v_c.push_back(i);}
    


    int c ; //refer to the column index
    int r ; // refer to the row index
    int min; // min value at the table
    int max; // max value at the table 

    //compute the max value using function FindMax
    max = FindMax(m,& r, & c);


    for(int x: v_r) //for each element remaining in vector v
        {
        //compute the min value using function FindMin
        min = FindMin(m, & r, & c, v_r,v_c);
     
        if (!(find(p.begin(), p.end(), r) != p.end()) && !(find(p.begin(), p.end(), c) != p.end()) )
            //case if r is not in p "path" and c  is not in p "path"
            //easiest case push_back the two elements
            {
            p.push_back(r);
            p.push_back(c);
            auto it_r = find(v_r.begin(), v_r.end(), r);
            auto it_c = find(v_c.begin(), v_c.end(), c);
            v_r.erase(it_r);
            v_c.erase(it_c);

            }
        else if ((find(p.begin(), p.end(), r) != p.end()) && (find(p.begin(), p.end(), c) != p.end()) )
            //case if r is in p "path" and c  is in p "path"
            //it's normal to be at the step before the last one 
            // in this case there is a remaining vertex
            // then we put the value equal the max
            { m[r][c]= max;
            }

       
        else if (find(p.begin(), p.end(), r) != p.end())
            // case if r is in the path
            // then we put the value c at the path after r
            {
                int index_r = getIndex(p, r);
                p.insert(p.begin() + index_r+1, c);
                auto it_c = find(v_c.begin(), v_c.end(), c);
                auto it_r = find(v_r.begin(), v_r.end(), r);
                v_c.erase(it_c);
                v_r.erase(it_r);  

            
            }
        else if (find(p.begin(), p.end(), c) != p.end())
            // case if c is in the path
            // then we put the value r at the path before c
            {
                int index_c = getIndex(p, c);
                p.insert(p.begin() + index_c, r);
                auto it_c = find(v_c.begin(), v_c.end(), c);
                auto it_r = find(v_r.begin(), v_r.end(), r);
                v_c.erase(it_c);
                v_r.erase(it_r); 
                
                }
                
             //print the path on the screen

            cout<< "\n The path with Greedy Heuristic Algorithm : ";
            for(int i:p){
            cout << i+1 << " ";
            cout << endl;
}    

    return 0;
}



//for finding minimum in the table
//we have three variables vector called myVector, int called n represent the row number
int FindMin(const vector<vector<int>>& myVector, int* r, int* c, vector<int> r_index, vector<int> c_index) 
{     
	// Initialize minimum element 
    int min; //min value
    int ri;  // row for initialize min value
    int ci;  // col for initialize min value

    //initialize the minimum value equal to the max value with his indices at the table
    min = FindMax(myVector,& ri, & ci);
    *r = ri;
    *c = ci;
    

	// Traverse vector elements  
	for (int i:r_index) 
        for (int j:c_index)
            {
		    if (myVector[i][j] < min && i != j) 
			    {min = myVector[i][j]; 
                *r = i;
                *c = j;
                }
            }
	return min; 
} 

//Find the maximum value in the table to initialize the min value at FindMin
int FindMax(const vector<vector<int>>& myVector, int* r, int* c) 
{     
	// Initialize minimum element 
    int max;
    
    max = myVector[0][0];

	// Traverse vector elements  
	for (int i = 0; i < myVector.size(); i++) 
        for (int j = 0; j < myVector.size(); j++)
            {
		    if (myVector[i][j] > max && i != j) 
			    {max = myVector[i][j]; 
                *r = i;
                *c = j;
                }
            }
	return max; 
} 


// index of an element inside a vector
int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
  
    // If element was found
    if (it != v.end()) 
    {
      
        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}
