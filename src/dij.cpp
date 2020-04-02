//Author: Nawal Ahmed
//Project Report Dijkstra

#include<iostream>
using namespace std;

int maxD(int dist[], bool check[]) //checks to see if the node with the max distance has been visited yet
{
	int max=9999999,index; //large int is used as a replacement for infinity.
	int node = 0; //starting node has a value of 0
	while (node<13) //there are 13 nodes
	{
		if(check[node]==false && dist[node]<=max) //if the node has not yet been checked and if the current value is infinite
		{
			max=dist[node]; //update
			index=node;
		}
		node++; //check the next node
	}
	return index;
}

void dij(int graph[13][13],int start) //Dijkstra's algorithm
{
	int dist[13];
	bool check[13];
	int d = 0;
	while(d<13) //first steps
	{
		dist[d]=9999999; //value must start at infinity
		check[d]=false; //none have yet been checked
		d++;
	}
	dist[start]=0;

	int c = 0;
	while(c<13) //double loop that performs the primary functionality of the algorithm. O(V^2)
	{
		int univisited=maxD(dist,check);
		check[univisited]=true; //must be unvisited
		int node = 0;
		while(node<13)
		{ //if statements that updates the starting point to every other node
			if(!check[node] &&
                graph[univisited][node] &&
                dist[univisited]!=9999999 &&
                dist[univisited]+graph[univisited][node]<dist[node])
                dist[node]=dist[univisited]+graph[univisited][node];
                node++;
		}
		c++;
	}
	//printing out the results
	cout<<"Node--Dist"<<endl; //title
    d = 0; //reset i to 0, else nothing will display
	while(d<13)
	{
		int num = 0+d; //increments the index
		cout<<num<<"------"<<dist[d]<<endl;
		d++; //next node
	}
}

int main()
{
    //13x13 matrix representation of a weighted graph. Visual representation of the graph is on the report.
	int graph[13][13]={{0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                       {3, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 0, 2},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3},
                       {4, 4, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 5, 0, 0},
                       {0, 0, 0, 5, 0, 0, 0, 3, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0},
                       {0, 1, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 4, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 4, 4, 0},
                       {0, 0, 0, 0, 5, 0, 0, 0, 4, 4, 0, 0, 0},
                       {0, 0, 2, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
                       {7, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};
	dij(graph,0);
}
