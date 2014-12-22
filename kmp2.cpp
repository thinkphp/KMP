#include <cstdio>
#include <cstring>
#include <vector>
#define FIN "strmatch.in"
#define FOUT "strmatch.out"
#define size(x) int((x).size())
#define push push_back
#define MAX 2000007

using namespace std;

char A[ MAX ],
     B[ MAX ];

int N,
    M;

vector<int> sol;

int Prefix[ MAX ];

int min(int a, int b) {

    return (a < b) ? a : b; 
};

void BuildPrefix() {

     int p = 0;

     Prefix[ 1 ] = 0; 

     for(int i = 2; i <= N; i++) {

         while( p > 0 && A[ p + 1] != A[ i ] ) {

                p = Prefix[ p ];
         } 

         if( A[ p + 1 ] == A[ i ] ) p++;

         Prefix[ i ] = p; 
     }  
};

void Matches() {

     int p = 0;

     for(int i = 1; i <= M; i++) {

         while( p > 0 && A[ p + 1 ] != B[ i ] ) {

                p = Prefix[ p ];
         } 

         if( A[ p + 1 ] == B[ i ] ) p++;

         if(p == N) {

            sol.push( i - N );

            p = Prefix[ p ]; 
         }
     }  

};

void readData() {

    freopen(FIN, "r", stdin);

    scanf("%s %s", A + 1, B + 1);

    N = strlen(A + 1);
 
    M = strlen(B + 1);

    fclose( stdin );
};

void writeData() {

     freopen(FOUT, "w", stdout);

     int n = size( sol );

     printf("%d\n", n);   
 
     for(int i = 0; i < min(n, 1000); i++) {

         printf("%d ", sol[ i ]);   
     }

     fclose( stdout );
};

int main() {

    readData(); 
    BuildPrefix();
    Matches();
    writeData(); 

    return(0);
};