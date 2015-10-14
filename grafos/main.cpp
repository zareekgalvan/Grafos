//
//  main.cpp
//  grafos
//
//  Created by Zareek Galvan on 10/1/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

//=======================================================================================================================
int matriz[100][100];

//=======================================================================================================================
void inicializaMatriz()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 0;
            }
            else
            {
                matriz[i][j] = 100000;
            }
        }
    }
}


void menorDecibel(int s)
{
    for (int k = 0; k < s; k++)
    {
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (i!=j)
                {
                    matriz[i][j] = matriz[j][i]= min(matriz[i][j], max(matriz[i][k], matriz[k][j]));
                }
                
            }
        }
    }
    
}

void decibel(int i, int j)
{
    if (matriz[i-1][j-1] == 100000)
    {
        cout << "no path" << endl;
    }
    else
    {
        cout << matriz[i-1][j-1] << endl;
    }
}

//=======================================================================================================================
void printMatriz(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j]<< "\t";
        }
        cout << endl;
    }
}

//=======================================================================================================================
int main()
{
    int times;
    cin >> times;
    for(int t = 0; t < times; t++)
    {
        inicializaMatriz();
        
        int c, s, q;
        cin >> c >> s >> q;
        
        for (int i = 0; i < s; i++)
        {
            int c1, c2, value;
            cin >> c1 >> c2 >> value;
            matriz[c1-1][c2-1] = value;
            matriz[c2-1][c1-1] = value;
            
        }
        
        menorDecibel(c);
        //printMatriz(c);
        cout << "Case " << t + 1 << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            int c1, c2;
            cin >> c1 >> c2;
            decibel(c1, c2);
        }
        
    }
    
}
