//Author: Nawal Ahmed
//Project Report Floyd-Warshall

#include<iostream>
using namespace std;

void show(int output[][13]); //shows the output of the solution
void fW (int graph[][13]) //apsp of fW
{
    int output[13][13]; //matrix of 13x13
    int i = 0; //the three variables for fW comparison
    int k = 0;
    int j;

    while (i < 13) { //the matrix starts with the matrix that was inputted already
        j = 0;
        while (j < 13) {
            output[i][j] = graph[i][j];
            j++;
        }
        i++;
    }

    while (k < 13) //triple nested loop that is the bulk of the Floyd-Warshall algorithm
    {
        i = 0;
        while (i < 13) //go through every single node
        {
            j = 0;
            while (j < 13)
            {
                if (output[i][k] + output[k][j] < output[i][j]) //updates the current square
                    output[i][j] = output[i][k] + output[k][j];
                j++;
            }
            i++;
        }
        k++;
    }
    show(output);
}

void show(int output[][13])
{
    int i = 0;
    int j;
    while (i < 13)
    {
        for (int j = 0; j < 13; j++)
        {
                cout<< "\t"; //proper space between elements
                cout << (output[i][j]);
        }
        cout<<("\n"); //new row
        i++;
    }
}

int main()
{
    //use 999 to express infinity. The visual graph for this is in the report
    int graph[13][13] = {{0, 3, 999, 4, 999, 999, 999, 999, 999, 999, 999, 999, 7},
                       {3, 0, 999, 4, 999, 999, 999, 1, 999, 999, 999, 999, 2},
                       {999, 999, 0, 999, 999, 999, 999, 999, 999, 999, 999, 2, 3},
                       {4, 4, 999, 0, 999, 5, 999, 999, 999, 999, 999, 999, 999},
                       {999, 999, 999, 0, 0, 999, 2, 999, 999, 999, 5, 999, 999},
                       {999, 999, 999, 5, 0, 0, 999, 3, 999, 999, 999, 999, 999},
                       {999, 999, 999, 999, 2, 999, 0, 2, 999, 999, 999, 999, 999},
                       {999, 1, 999, 999, 999, 3, 2, 0, 999, 999, 999, 999, 999},
                       {999, 999, 999, 999, 999, 999, 999, 999, 0, 6, 4, 4, 999},
                       {999, 999, 999, 999, 999, 999, 999, 999, 6, 0, 4, 4, 999},
                       {999, 999, 999, 999, 5, 999, 999, 999, 4, 4, 0, 999, 999},
                       {999, 999, 2, 999, 999, 999, 999, 999, 4, 4, 999, 0, 999},
                       {7, 2, 3, 999, 999, 999, 999, 999, 999, 999, 999, 999, 0},
                      };
    fW(graph);
}
