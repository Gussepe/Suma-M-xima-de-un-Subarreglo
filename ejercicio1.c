#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max_cubica(const int l[], int n) {
    int max = l[0];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int parcial = 0;

            for (int k = i; k < j; k++) {
                parcial += l[k];
            }

            if (parcial > max) {
                max = parcial;
            }
        }
    }

    return max;
}
int max_cuadratica(const int l[], int n) {
    int max = l[0];

    for (int i = 0; i < n; i++) {
        int parcial = 0;

        for (int j = i; j < n; j++) {
            parcial += l[j];

            if (parcial > max) {
                max = parcial;
            }
        }
    }

    return max;
}
int max_lineal(const int l[], int n) {
    int max = l[0];
    int parcial = l[0];

    for (int i = 1; i < n; i++) {
        if (parcial + l[i] > l[i])
            parcial = parcial + l[i];
        else
            parcial = l[i];

        if (parcial > max)
            max = parcial;
    }

    return max;
}
double tiempo_cubica(const int l[], int n) {
    clock_t inicio = clock();

    volatile int resultado = max_cubica(l, n);

    clock_t fin = clock();

    (void)resultado;

    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

double tiempo_cuadratica(const int l[], int n) {
    clock_t inicio = clock();

    volatile int resultado = max_cuadratica(l, n);

    clock_t fin = clock();

    (void)resultado;

    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

double tiempo_lineal(const int l[], int n) {
    clock_t inicio = clock();

    volatile int resultado = max_lineal(l, n);

    clock_t fin = clock();

    (void)resultado;

    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    for (int prueba = 0; prueba < 100; prueba++) {

        int n = 1 + rand() % 20;
        int l[n];

        for (int i = 0; i < n; i++) {
            l[i] = -10 + rand() % 21;
        }

        int r1 = max_cubica(l, n);
        int r2 = max_cuadratica(l, n);
        int r3 = max_lineal(l, n);

        if (r1 != r2 || r2 != r3) {
            printf("ERROR en la prueba %d\n", prueba + 1);

            printf("Arreglo: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", l[i]);
            }

            printf("\nCubica: %d", r1);
            printf("\nCuadratica: %d", r2);
            printf("\nLineal: %d\n", r3);

            return 1;
        }
    }

    printf("Las 3 soluciones coinciden en las 100 pruebas.\n");
    int tamanos[] = {
        1000,
        2000,
        4000,
        8000
    };

    int cantidad = sizeof(tamanos) / sizeof(tamanos[0]);

    double anterior_cubica = 0.0;
    double anterior_cuadratica = 0.0;
    double anterior_lineal = 0.0;

    printf("\n");
    printf("%8s | %12s | %8s | %12s | %8s | %12s | %8s\n",
           "n",
           "Cubica(s)", "Razon",
           "Cuadratica(s)", "Razon",
           "Lineal(s)", "Razon");

    printf("--------------------------------------------------------------------------------\n");

    /*
       Guardamos el último tiempo para utilizarlo
       posteriormente en la predicción.
    */
    double ultimo_cubica = 0.0;
    double ultimo_cuadratica = 0.0;
    double ultimo_lineal = 0.0;
    int ultimo_n = 0;

    for (int x = 0; x < cantidad; x++) {

        int n = tamanos[x];

        int *l = malloc((size_t)n * sizeof(int));

        if (l == NULL) {
            printf("No se pudo reservar memoria para n=%d\n", n);
            break;
        }

        /* Generamos el arreglo fuera de la medición */
        for (int i = 0; i < n; i++) {
            l[i] = -10 + rand() % 21;
        }

        double tc = tiempo_cubica(l, n);
        double tq = tiempo_cuadratica(l, n);
        double tl = tiempo_lineal(l, n);

        double rc = 0.0;
        double rq = 0.0;
        double rl = 0.0;

        if (x > 0) {
            rc = tc / anterior_cubica;
            rq = tq / anterior_cuadratica;
            rl = tl / anterior_lineal;
        }

        printf("%8d | %12.6f | %8.2f | %12.6f | %8.2f | %12.6f | %8.2f\n",
               n, tc, rc, tq, rq, tl, rl);

        anterior_cubica = tc;
        anterior_cuadratica = tq;
        anterior_lineal = tl;

        ultimo_cubica = tc;
        ultimo_cuadratica = tq;
        ultimo_lineal = tl;
        ultimo_n = n;

        free(l);
    }
    long long n_grande = 100000000LL;

    if (ultimo_n > 0) {

        double factor = (double)n_grande / ultimo_n;

        /*
           O(n^3):
               T(10^8) ~= T(n) * (10^8/n)^3

           O(n^2):
               T(10^8) ~= T(n) * (10^8/n)^2

           O(n):
               T(10^8) ~= T(n) * (10^8/n)
        */

        double pred_cubica =
            ultimo_cubica * factor * factor * factor;

        double pred_cuadratica =
            ultimo_cuadratica * factor * factor;

        double pred_lineal =
            ultimo_lineal * factor;

        printf("Usando como referencia n = %d\n\n", ultimo_n);

        printf("Prediccion cubica:      %.2f segundos\n",
               pred_cubica);

        printf("Prediccion cuadratica:  %.2f segundos\n",
               pred_cuadratica);

        printf("Prediccion lineal:      %.2f segundos\n",
               pred_lineal);

        printf("\n");

        printf("En minutos:\n");

        printf("Cubica:      %.2f minutos\n",
               pred_cubica / 60.0);

        printf("Cuadratica:  %.2f minutos\n",
               pred_cuadratica / 60.0);

        printf("Lineal:      %.2f minutos\n",
               pred_lineal / 60.0);

        printf("\n");

        printf("Versiones que teoricamente tardarian menos de un minuto:\n");

        if (pred_cubica < 60.0)
            printf("- Cubica\n");

        if (pred_cuadratica < 60.0)
            printf("- Cuadratica\n");

        if (pred_lineal < 60.0)
            printf("- Lineal\n");

        if (pred_cubica >= 60.0 &&
            pred_cuadratica >= 60.0 &&
            pred_lineal >= 60.0) {
            printf("Ninguna.\n");
        }
    }

    return 0;
}

