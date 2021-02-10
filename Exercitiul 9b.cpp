#include <iostream>
#include <time.h>

using namespace std;

//void alocare_matrice(int **matrice, int m, int n);
void dealocare_matrice(int **matrice, int m, int n);
void citire_matrice(int **matrice, int m, int n);
void afisare_matrice(int **matrice, int m, int n);
void afisare_max(int **matrice, int m, int n);

int main()
{
    srand(time(NULL));

    int **matrice;
    int m, n;

    cout << "m = "; //linii
    cin >> m;
    cout << "n = "; //coloana
    cin >> n;

    //alocare_matrice(matrice, m, n);
    matrice = new int *[m];
    for (int i = 0; i < n; i++)
    {
        matrice[i] = new int[n];
    }
    citire_matrice(matrice, m, n);
    afisare_matrice(matrice, m, n);
    afisare_max(matrice, m, n);
    dealocare_matrice(matrice, m, n);
    system("pause");
}

/* void alocare_matrice(int **matrice, int m, int n)
{
    matrice = new int*[m];
    for (int i = 0; i < n; i++)
    {
        matrice[i] = new int[n];
    }
} */

void citire_matrice(int **matrice, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrice[i][j] = rand() % 89 + 10;
        }
    }
}

void afisare_matrice(int **matrice, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << "\n";
    }
}

void afisare_max(int **matrice, int m, int n)
{
    int max = 0, pozm, pozn;
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrice[m][n] > max)
            {
                max = matrice[m][n];
                pozm = m;
                pozn = n;
            }
        }
    }
    cout << "Maximul este: " << max << "[" << m << "][" << n << "]";
}

void dealocare_matrice(int **matrice, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrice[i];
    }
    delete[] matrice;
}