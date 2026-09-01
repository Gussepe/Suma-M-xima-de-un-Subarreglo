Ejercicio 1 — Suma máxima de un subarreglo
1. Descripción

El objetivo de este trabajo es resolver el problema de encontrar la suma máxima de un subarreglo contiguo de un arreglo de enteros.

Se implementaron tres algoritmos diferentes:

Una solución cúbica, con complejidad O(n³).
Una solución cuadrática, con complejidad O(n²).
Una solución lineal, con complejidad O(n).

También se verificó que las tres implementaciones entregan el mismo resultado utilizando 100 arreglos pequeños generados aleatoriamente, con números enteros positivos y negativos.

2. Implementación

Las tres funciones implementadas son:

max_cubica()
max_cuadratica()
max_lineal()


La función max_lineal() utiliza el algoritmo conocido como algoritmo de Kadane.

Para verificar que las tres implementaciones son correctas, se generaron 100 arreglos aleatorios de tamaño entre 1 y 20, con valores entre -10 y 10.

El resultado de la verificación fue:

Las 3 soluciones coinciden en las 100 pruebas.


Por lo tanto, las tres soluciones producen el mismo resultado para las pruebas realizadas.

3. Entorno de ejecución

Las mediciones se realizaron en el siguiente equipo:

Característica	Información
Sistema operativo	Arch Linux
Lenguaje	C
Compilador	GCC
Procesador	AMD A9-9420 RADEON R5, 5 COMPUTE CORES 2C+3G
Memoria RAM	7.2 GiB

El programa fue compilado utilizando GCC.

4. Medición de tiempos

Se realizaron mediciones duplicando el tamaño del arreglo:

1000, 2000, 4000, 8000

La razón entre dos mediciones consecutivas se calculó mediante:

Razón = T(2n) / T(n)

Tabla de resultados
n	Cúbica (s)	Razón	Cuadrática (s)	Razón	Lineal (s)	Razón
1000	0.525292	—	0.001570	—	0.000005	—
2000	4.173737	7.95	0.006256	3.98	0.000007	1.40
4000	33.387774	8.00	0.025057	4.01	0.000014	2.00
8000	291.265705	8.72	0.096546	3.85	0.000029	2.07
Análisis de las razones

Para la versión cúbica, al duplicar n, el tiempo aumenta aproximadamente por un factor de 8:

7.95
8.00
8.72


Esto coincide con el crecimiento esperado de O(n³), ya que:

2³ = 8


Para la versión cuadrática, las razones obtenidas son aproximadamente 4:

3.98
4.01
3.85


Esto coincide con O(n²), ya que:

2² = 4


Para la versión lineal, las razones son aproximadamente 2:

1.40
2.00
2.07


La primera razón presenta algo más de variación debido al pequeño tiempo de ejecución, pero las siguientes mediciones muestran claramente el comportamiento lineal.

Por lo tanto, las mediciones son consistentes con los órdenes teóricos:

Algoritmo	Complejidad	Razón esperada al duplicar n
Cúbico	O(n³)	≈ 8
Cuadrático	O(n²)	≈ 4
Lineal	O(n)	≈ 2
5. Predicción para n = 10^8

Para estimar el tiempo de ejecución con n = 10^8, se utilizó como referencia la última medición realizada:

n = 8000


La predicción se realizó utilizando el orden de crecimiento de cada algoritmo.

Para un algoritmo O(n^k) se utilizó:

T(n₂) ≈ T(n₁) × (n₂ / n₁)^k

Resultados de la predicción
Algoritmo	Tiempo estimado (segundos)	Tiempo estimado aproximado
Cúbico	568878330078125.12 s	≈ 18 millones de años
Cuadrático	15085312.50 s	≈ 175 días
Lineal	0.36 s	≈ 0.36 segundos

En minutos, las predicciones fueron:

Algoritmo	Tiempo estimado
Cúbico	9,481,305,501,302.09 minutos
Cuadrático	251,421.88 minutos
Lineal	0.01 minutos

La versión cúbica tendría un tiempo estimado de aproximadamente 18 millones de años, mientras que la versión cuadrática tardaría aproximadamente 175 días.

La versión lineal tendría un tiempo estimado de aproximadamente 0.36 segundos.

Por lo tanto, de acuerdo con la predicción, solamente la versión lineal debería ejecutarse con n = 10^8, ya que es la única cuya estimación está por debajo de un minuto.

6. Ejecución con n = 10^8

Siguiendo la predicción anterior, se ejecutó únicamente la versión lineal para n = 100000000.

Comparación entre predicción y medición
Algoritmo	Tiempo predicho	Tiempo medido
Lineal	0.36 s	[PENDIENTE]

La versión cúbica y la versión cuadrática no se ejecutaron con n = 10^8, debido a que sus tiempos estimados superaban ampliamente el límite de un minuto establecido en el enunciado.

7. Conclusiones

Los resultados experimentales muestran una diferencia significativa entre las tres soluciones.

La versión cúbica presenta un crecimiento muy rápido. Al duplicar el tamaño del arreglo, su tiempo de ejecución aumenta aproximadamente ocho veces, lo cual coincide con una complejidad O(n³).

La versión cuadrática aumenta aproximadamente cuatro veces al duplicar n, comportamiento consistente con una complejidad O(n²).

La versión lineal presenta un crecimiento aproximadamente proporcional al tamaño del arreglo. Al duplicar n, su tiempo aumenta aproximadamente por un factor de dos, lo cual coincide con una complejidad O(n).

La predicción para n = 10^8 muestra claramente la importancia de la complejidad algorítmica. Mientras que las versiones cúbica y cuadrática resultan impracticables para ese tamaño de entrada, la versión lineal es suficientemente rápida como para ser ejecutada.

La predicción de la versión lineal fue de aproximadamente 0.36 segundos. El tiempo real medido se utilizará para comparar la estimación con el comportamiento observado en el equipo.

En conclusión, aunque las tres implementaciones producen el mismo resultado, la versión lineal es la más adecuada para trabajar con arreglos de gran tamaño debido a su menor complejidad temporal.
