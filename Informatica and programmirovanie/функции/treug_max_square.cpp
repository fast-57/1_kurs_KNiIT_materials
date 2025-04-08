# include <iostream>
# include <cmath>
using namespace std;
double dlina(double ax, double ay, double bx, double by);
double square(double a, double b, double c){
    double p = (a + b + c)/2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}
int main(){
    int pointx[40], pointy[40];
    int n;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Input koordinats " << i << " point\n";
        cin >> pointx[i] >> pointy[i];
    }
    double  max = 0, S;
    int maxi, maxj, maxk;
        for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++){
                double AB = dlina(pointx[i], pointy[i], pointx[j], pointy[j]);
                double BC = dlina(pointx[j], pointy[j], pointx[k], pointy[k]);
                double AC = dlina(pointx[i], pointy[i], pointx[k], pointy[k]);
                double S = square(AB, BC, AC);
                if (S > max){
                    max = S;
                    maxi = i;
                    maxj = j;
                    maxk = k;
                }
            }
    cout << "Max square = " << S << " in points " << maxi << ", " << maxj << ", " << maxk << endl;
    return 0;
}
double dlina(double ax, double ay, double bx, double by){
    return sqrt((ax-bx) + (ay-by)*(ay-by));
}