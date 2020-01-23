#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//ln(x+1) == x-x^2/2+x^3/3-x^4/4+x^5/5-...
//sin(x) == x-x^3/3! + x^5/5!-...
// x nalezy do (-1,1>

double potega(double podstawa,double wykladnik);
double silnia(int n);
double logarytm(double x,int n);
double logarytmOdKonca(double x,int n);
double sinus(double x,int n);
double sinusOdKonca(double x,int n);
double logarytmPoprzedni(double x,int n);
double logarytmPoprzedniOdKonca(double x,int n);
double sinusPoprzedni(double x,int n);
double sinusPoprzedniOdKonca(double x,int n);
double bladBezwzgledny(double x, double xy);
double bladWzgledny(double x, double xy);

int main() {

        double x = -1;
        int n = 100;

	for(int i = 1;i < 10;i++){
	x+=0.02;
	printf(" sinus \n%.30lf\n",sinusPoprzedniOdKonca(x,n));
}

// wpisywanie do plikow
	x=-1;
        // 1 sposob
        FILE *f = fopen("sposob-1.csv", "w");
        if (f == NULL)
        {
                printf("Błąd \n");
                exit(1);
        }
        fprintf(f, "%s,%s,%s,%s,%s\n", "x", "Funkcja wbudowana", "Taylor", "Blad bezwzgledny", "Blad wzgledny");
        for(int i = 1; i <= 100; i++) {
                x+=0.02;
                double wynik = sin(x)*log(x+1);
                double mojWynik = sinus(x,n) * logarytm(x,n);
                fprintf(f,"%0.6lf, %.30lf, %.30lf, %.30lf, %.30lf", x, wynik, mojWynik, bladBezwzgledny(wynik,mojWynik),bladWzgledny(wynik,mojWynik));
                fprintf(f,"\n");
        }
        fclose(f);

        // 2 sposob
        FILE *f2 = fopen("sposob-2.csv", "w");
        if (f2 == NULL)
        {
                printf("Błąd \n");
                exit(1);
        }

        x = -1;
        fprintf(f2, "%s,%s,%s,%s,%s\n", "x", "Funkcja wbudowana", "Taylor", "Blad bezwzgledny", "Blad wzgledny");
        for(int i = 1; i <= 100; i++) {
                x+=0.02;
                double wynik = sin(x)*log(x+1);
                double mojWynik = sinusOdKonca(x,n) * logarytmOdKonca(x,n);
                fprintf(f2,"%0.6lf, %.30lf, %.30lf, %.30lf, %.30lf", x, wynik, mojWynik, bladBezwzgledny(wynik,mojWynik),bladWzgledny(wynik,mojWynik));

                fprintf(f2,"\n");
        }
        fclose(f2);

        // 3 sposob
        FILE *f3 = fopen("sposob-3.csv", "w");
        if (f3 == NULL)
        {
                printf("Błąd \n");
                exit(1);
        }

        x = -1;
        fprintf(f3, "%s,%s,%s,%s,%s\n", "x", "Funkcja wbudowana", "Taylor", "Blad bezwzgledny", "Blad wzgledny");
        for(int i = 1; i <= 100; i++) {
                x+=0.02;
                double wynik = sin(x)*log(x+1);
                double mojWynik = sinusPoprzedni(x,n) * logarytmPoprzedni(x,n);
                fprintf(f3,"%0.6lf, %.30lf, %.30lf, %.30lf, %.30lf", x, wynik, mojWynik, bladBezwzgledny(wynik,mojWynik),bladWzgledny(wynik,mojWynik));
                fprintf(f3,"\n");
        }
        fclose(f3);

        // 4 sposob
        FILE *f4 = fopen("sposob-4.csv", "w");
        if (f4 == NULL)
        {
                printf("Błąd \n");
                exit(1);
        }

        x = -1;
        fprintf(f4, "%s,%s,%s,%s,%s\n", "x", "Funkcja wbudowana", "Taylor", "Blad bezwzgledny", "Blad wzgledny");
        for(int i = 1; i <= 100; i++) {
                x+=0.02;
                double wynik = sin(x) * log(x+1);
                double mojWynik = sinusPoprzedniOdKonca(x,n) * logarytmPoprzedniOdKonca(x,n);
                fprintf(f4,"%0.6lf, %.30lf, %.30lf, %.30lf, %.30lf", x, wynik, mojWynik, bladBezwzgledny(wynik,mojWynik),bladWzgledny(wynik,mojWynik));
                fprintf(f4,"\n");
        }
        fclose(f4);
        printf("Wszystko zostalo zapisano do plikow\n");
        return 0;

}

double potega(double podstawa,double wykladnik) {
        double wynik = 1;
        for(int i = 0; i < wykladnik; i++)
                wynik = wynik * podstawa;

        return wynik;
}

double silnia(int n) {
        double wynik = 1;
        if(n == 0) {
                return wynik;
        } else {
                wynik = n*silnia(n-1);
        }
        return wynik;
}

double logarytm(double x,int n) {
        double wynik = 0;
        double zmienna = 0;
        for(int i = 1;i <= n;i++){
                zmienna = potega(x,i)/i;
                if(i % 2 == 0)
                        zmienna = -zmienna;

                wynik = wynik + zmienna;
        }
        return wynik;
}

double logarytmOdKonca(double x,int n) {
        double wynik = 0;
        double zmienna = 0;
        for(int i = n;i >= 1;i--){
                zmienna = potega(x,i)/i;
                if(i % 2 == 0)
                        zmienna = -zmienna;

                wynik = wynik + zmienna;
        }
        return wynik;
}

double sinus(double x,int n) {
        double wynik = 0;
        double zmienna = 0;
        int znak = 0;
        for(int i = 1;i<=n;i=i+2){
                znak++;
                zmienna = potega(x,i)/silnia(i);

                if(znak%2 == 0)
                        zmienna = -zmienna;
                wynik = wynik + zmienna;
        }
        return wynik;
}

double sinusOdKonca(double x,int n) {
        double wynik = 0;
        double zmienna = 0;
        int znak = 0;
        for(int i = n-1;i>=0;i= i-2) {
                znak++;
                zmienna = potega(x,i)/silnia(i);

                if(znak%2 == 0)
                        zmienna = -zmienna;
                wynik = wynik - zmienna;

        }
        return wynik;
}

double logarytmPoprzedni(double x,int n) {
//	double pierwszy = x;
	double tab[n];
	tab[1] = x;
        double wynik = x;
        for(int i = 2;i <= n; i++) {
                tab[i] = (tab[i-1] * (-1) * (i-1) * x) / i;
                wynik = wynik + tab[i];
        }
        return wynik;
}

double logarytmPoprzedniOdKonca(double x,int n) {
        double tab[n];
	double pierwszy = x;
//	tab[1] = x;
        double wynik = x;
	int iterator = 0;

        for(int i = 2;i <= n;i++) {
                pierwszy = pierwszy * (-1) * (i-1) * x / i;
		tab[iterator] = pierwszy;
		iterator++;
        }

        for(int i = iterator;i >= 0;i--) {
                wynik = wynik + tab[i];
        }
        return wynik;
}

//https://matematyka.pl/viewtopic.php?t=74546
double sinusPoprzedni(double x,int n) {
//	double pierwszy = x;
	double tab[n];
	tab[0] = x;
        double wynik = x;
        for(int i = 1;i < n;i+=2) {
                tab[i] = (tab[i-1] * (-1) * (potega(x,2)))/(2 * i *(2 * i + 1));
                wynik = wynik + tab[i];
        }
        return wynik;
}

double sinusPoprzedniOdKonca(double x,int n) {
        double tab[n];
	double pierwszy = x;
//	tab[0] = x;
	double wynik = x;
	int iterator = 0;

        for(int i = 1; i < n;i+=2) {
	pierwszy = pierwszy * (-1) * (potega(x,2))/(2 * i *(2 * i + 1));
	tab[iterator] = pierwszy;
	iterator++;
        }
        for(int i = iterator;i >= 0;i--) {
                wynik = wynik + tab[i];
        }
        return wynik;
}


double bladBezwzgledny(double x,double xy) {
        return fabs(xy - x);
}

double bladWzgledny(double x,double xy) {
        return bladBezwzgledny(x, xy)/fabs(x);
}


