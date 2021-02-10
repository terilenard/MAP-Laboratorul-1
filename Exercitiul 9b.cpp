#include <iostream>
#include <time.h>

using namespace std;

double ** alocare_matrice(int m, int n);
void dealocare_matrice(double **matrice, int m, int n);
void citire_matrice(double **matrice, int m, int n);
void afisare_matrice(double **matrice, int m, int n);
void afisare_max(double **matrice, int m, int n);

int main()
{
    srand(time(NULL));

    int m, n;

    cout << "m = "; //linii
    cin >> m;
    cout << "n = "; //coloana
    cin >> n;

    double **matrice = alocare_matrice(m, n);
    citire_matrice(matrice, m, n);
    afisare_matrice(matrice, m, n);
    afisare_max(matrice, m, n);
    dealocare_matrice(matrice, m, n);
    system("pause");
}

double ** alocare_matrice(int m, int n)
{
    double **matrice;
    matrice = new double*[m];
    for (int i = 0; i < n; i++)
    {
        matrice[i] = new double[n];
    }

    return matrice;
}

void citire_matrice(double **matrice, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrice[i][j] = rand() % 89 + 10;
        }
    }
}

void afisare_matrice(double **matrice, int m, int n)
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

void afisare_max(double **matrice, int m, int n)
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

void dealocare_matrice(double **matrice, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrice[i];
    }
    delete[] matrice;
}