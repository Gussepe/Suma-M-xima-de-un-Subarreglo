#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max_cubica(const int l[], int n)
{
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

int max_cuadratica(const int l[], int n)
{
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

int max_lineal(const int l[], int n)
{
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

double tiempo_cubica(const int l[], int n)
{
    clock_t inicio = clock();
    volatile int resultado = max_cubica(l, n);
    clock_t fin = clock();

    (void)resultado;

    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

double tiempo_cuadratica(const int l[], int n)
{
    clock_t inicio = clock();
    volatile int resultado = max_cuadratica(l, n);
    clock_t fin = clock();

    (void)resultado;

    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

double tiempo_lineal(const int l[], int n)
{
    clock_t inicio = clock();
    volatile int resultado = max_lineal(l, n);
    clock_t fin = clock();

    (void)resultado;

    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

int main(void)
{
    srand(time(NULL));

    // Validación de correctitud con 100 pruebas
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
            printf("\nCubica: %d\n", r1);
            printf("Cuadratica: %d\n", r2);
            printf("Lineal: %d\n", r3);

            return 1;
        }
    }

    printf("Las 3 soluciones coinciden en las 100 pruebas.\n\n");
    int tamanos[] = {1000, 2000, 4000, 8000};
    int cantidad = sizeof(tamanos) / sizeof(tamanos[0]);

    printf("%8s | %12s | %8s | %12s | %8s | %12s | %8s\n",
           "n", "Cubica(s)", "Razon", "Cuadratica(s)", "Razon",
           "Lineal(s)", "Razon");
    printf("--------------------------------------------------------------------------------\n");

    double anterior_cubica = 0.0;
    double anterior_cuadratica = 0.0;
    double anterior_lineal = 0.0;

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

        for (int i = 0; i < n; i++) {
            l[i] = -10 + rand() % 21;
        }

        double tc = tiempo_cubica(l, n);
        double tq = tiempo_cuadratica(l, n);
        double tl = tiempo_lineal(l, n);

        double rc = (x > 0) ? tc / anterior_cubica : 0.0;
        double rq = (x > 0) ? tq / anterior_cuadratica : 0.0;
        double rl = (x > 0) ? tl / anterior_lineal : 0.0;

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
    printf("\n");
    long long n_grande = 100000000LL;
    int *l_grande = malloc((size_t)n_grande * sizeof(int));

    if (l_grande == NULL) {
        printf("No se pudo reservar memoria para n = %lld\n", n_grande);
        return 1;
    }

    for (long long i = 0; i < n_grande; i++) {
        l_grande[i] = -10 + rand() % 21;
    }

    double tiempo_real = tiempo_lineal(l_grande, n_grande);
    printf("Tiempo real de ejecucion lineal para n = %lld: %.6f segundos\n\n",
           n_grande, tiempo_real);

    free(l_grande);
    if (ultimo_n > 0) {
        double factor = (double)n_grande / ultimo_n;

        double pred_cubica = ultimo_cubica * factor * factor * factor;
        double pred_cuadratica = ultimo_cuadratica * factor * factor;
        double pred_lineal = ultimo_lineal * factor;

        printf("Predicciones usando n = %d como referencia:\n\n", ultimo_n);

        printf("Algoritmo Cubica:\n");
        printf("  Tiempo estimado: %.2f segundos\n", pred_cubica);
        printf("  En minutos:      %.2f minutos\n\n", pred_cubica / 60.0);

        printf("Algoritmo Cuadratica:\n");
        printf("  Tiempo estimado: %.2f segundos\n", pred_cuadratica);
        printf("  En minutos:      %.2f minutos\n\n", pred_cuadratica / 60.0);

        printf("Algoritmo Lineal:\n");
        printf("  Tiempo estimado: %.2f segundos\n", pred_lineal);
        printf("  En minutos:      %.2f minutos\n\n", pred_lineal / 60.0);

        printf("Versiones que tardarian menos de un minuto:\n");

        int hay_alguna = 0;
        if (pred_cubica < 60.0) {
            printf("  - Cubica\n");
            hay_alguna = 1;
        }
        if (pred_cuadratica < 60.0) {
            printf("  - Cuadratica\n");
            hay_alguna = 1;
        }
        if (pred_lineal < 60.0) {
            printf("  - Lineal\n");
            hay_alguna = 1;
        }
        if (!hay_alguna) {
            printf("  Ninguna.\n");
        }
    }

    return 0;
}
