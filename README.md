# Suma Máxima de un Subarreglo

Un análisis comparativo de tres algoritmos para resolver el problema clásico de encontrar la suma máxima de un subarreglo contiguo, con énfasis en complejidad algorítmica y validación experimental.

## Descripción del Problema

Dado un arreglo de enteros que pueden ser positivos o negativos, se requiere encontrar el subarreglo contiguo cuya suma sea máxima. Por ejemplo, en el arreglo [-2, 1, -3, 4, -1, 2, 1, -5, 4], el subarreglo [4, -1, 2, 1] tiene la suma máxima de 6. Este problema presenta un caso de estudio fundamental en el análisis de algoritmos, permitiendo comparar distintos enfoques de resolución con diferentes órdenes de complejidad.

## Objetivo General

El presente trabajo implementa y compara tres soluciones algorítmicas distintas para resolver el problema de la suma máxima de subarreglo, validando su correctitud y analizando su comportamiento en la práctica mediante mediciones empíricas sistemáticas. Se busca demostrar cómo el análisis de complejidad algorítmica se traduce en diferencias significativas de rendimiento real.

## Implementaciones Desarrolladas

Se desarrollaron tres algoritmos con diferentes órdenes de complejidad temporal:

### Algoritmo Cúbico - O(n³)

Esta solución implementa el enfoque más directo: genera todos los subarreglos posibles del arreglo de entrada y calcula la suma de cada uno de ellos de forma independiente. Para un arreglo de tamaño n, existen O(n²) subarreglos diferentes, y calcular la suma de cada subarreglo requiere O(n) operaciones. Aunque esta implementación es conceptualmente simple e intuitiva, su complejidad temporal cúbica la hace impráctica para conjuntos de datos de tamaño moderado o superior.

### Algoritmo Cuadrático - O(n²)

Este algoritmo mejora el enfoque anterior mediante una optimización en el cálculo de sumas. Para cada posición de inicio del subarreglo, calcula incrementalmente la suma de los elementos subsecuentes sin recalcularla desde cero. Esto reduce la complejidad de O(n³) a O(n²), manteniendo un seguimiento de sumas parciales mientras expande el subarreglo hacia la derecha. Si bien representa una mejora sustancial, esta solución aún no es óptima para aplicaciones prácticas con datos de gran escala.

### Algoritmo Lineal - O(n): Algoritmo de Kadane

La tercera implementación utiliza el algoritmo de Kadane, una solución elegante y eficiente que resuelve el problema en tiempo lineal con una única pasada a través del arreglo. El algoritmo mantiene dos variables: la suma máxima encontrada hasta el momento y la suma máxima de subarreglo terminada en la posición actual. En cada iteración, actualiza estas variables basándose en si es mejor continuar con el subarreglo actual o comenzar uno nuevo. Esta aproximación es óptima desde la perspectiva de complejidad temporal.

## Validación de Correctitud

Para asegurar la correctitud de las tres implementaciones, se realizó un proceso de validación comparativa generando cien arreglos aleatorios con las siguientes características:

- Tamaño de arreglos: Entre 1 y 20 elementos
- Rango de valores: Enteros comprendidos entre -10 y 10, incluyendo valores positivos, negativos y cero
- Criterio de validación: Las tres soluciones coincidieron en todas las cien pruebas realizadas

Este proceso confirma que las tres implementaciones resuelven correctamente el problema independientemente de su complejidad algorítmica.

## Entorno Experimental

Las mediciones se realizaron en un entorno con las siguientes características técnicas:

| Componente | Especificación |
|---|---|
| Sistema Operativo | Arch Linux |
| Lenguaje de Programación | C |
| Compilador | GCC con optimizaciones estándar |
| Procesador | AMD A9-9420 RADEON R5 (5 núcleos: 2 Compute + 3 GPU) |
| Memoria RAM | 7.2 GiB |

## Análisis de Resultados Experimentales

Se realizaron mediciones de tiempo de ejecución aumentando el tamaño del arreglo duplicando su valor en cada iteración. Los resultados se presentan en la siguiente tabla:

| n | Cúbica (s) | Razón C³ | Cuadrática (s) | Razón C² | Lineal (s) | Razón L |
|---|---|---|---|---|---|---|
| 1,000 | 0.525292 | — | 0.001570 | — | 0.000005 | — |
| 2,000 | 4.173737 | 7.95 | 0.006256 | 3.98 | 0.000007 | 1.40 |
| 4,000 | 33.387774 | 8.00 | 0.025057 | 4.01 | 0.000014 | 2.00 |
| 8,000 | 291.265705 | 8.72 | 0.096546 | 3.85 | 0.000029 | 2.07 |

### Análisis de Comportamiento por Algoritmo

**Algoritmo Cúbico**

Las razones observadas entre mediciones consecutivas (7.95, 8.00, 8.72) son consistentes con la predicción teórica de 2³ = 8 para una complejidad O(n³). La ligera variación en la última razón (8.72) puede atribuirse a efectos de caché y variabilidad en la carga del sistema operativo. Este comportamiento confirma experimentalmente que el tiempo de ejecución crece con la tercera potencia del tamaño de entrada.

**Algoritmo Cuadrático**

Las razones observadas (3.98, 4.01, 3.85) se ajustan al comportamiento esperado de 2² = 4 para una complejidad O(n²), con una desviación máxima del 3.75%. Este excelente ajuste demuestra la validez del análisis asintótico para predecir el comportamiento real del algoritmo.

**Algoritmo Lineal**

Las razones observadas (1.40, 2.00, 2.07) confirman el crecimiento esperado de 2¹ = 2 para una complejidad O(n). La razón de 1.40 en la primera duplicación es menor a la esperada, lo cual se explica por la interferencia del sistema operativo en ejecuciones de muy corta duración donde el tiempo medido es comparable al ruido del sistema.

## Extrapolación para Casos de Gran Escala

Utilizando la relación matemática que caracteriza el crecimiento de cada algoritmo, se estimó el tiempo de ejecución para n = 10⁸ empleando la fórmula de extrapolación:


$$T(n_2) \approx T(n_1) \times \left(\frac{n_2}{n_1}\right)^k$$

donde k es el exponente de complejidad (3 para cúbica, 2 para cuadrática, 1 para lineal).

| Algoritmo | Tiempo Estimado | Equivalencia | Viabilidad |
|---|---|---|---|
| Cúbico | 568,878,330,078,125 segundos | Aproximadamente 18 millones de años | No viable |
| Cuadrático | 15,085,312.5 segundos | Aproximadamente 175 días | No viable |
| Lineal | 0.36 segundos | Fracción de segundo | Viable |

Estos resultados ilustran dramáticamente cómo pequeñas diferencias en la complejidad algorítmica generan diferencias exponenciales en el rendimiento práctico.

## Validación Experimental a Escala

Se ejecutó el algoritmo lineal con entrada de tamaño n = 10⁸ (cien millones de elementos) para contrastar la predicción teórica con el rendimiento real:

| Métrica | Valor |
|---|---|
| Tiempo Predicho | 0.36 segundos |
| Tiempo Medido | 0.378766 segundos |
| Error de Predicción | +5.2% |

La excelente concordancia entre la predicción teórica y la medición real (error menor al 5.2%) valida la utilidad del análisis de complejidad algorítmica para estimar el comportamiento en casos prácticos.

## Visualización Comparativa

La siguiente tabla presenta una comparación relativa de los tiempos de ejecución:

| Tamaño (n) | Cúbica | Cuadrática | Lineal |
|---|---|---|---|
| 1,000 | ████████████████ 0.53s | ███ 0.002s | ▏ 0.000005s |
| 2,000 | ██████████████████████████ 4.17s | ███ 0.006s | ▏ 0.000007s |
| 4,000 | ████████████████████████████████ 33.4s | ████ 0.025s | ▏ 0.000014s |
| 8,000 | ██████████████████████████████████████ 291.3s | █████ 0.097s | ▏ 0.000029s |

## Conclusiones

El presente análisis experimental valida las predicciones teóricas derivadas del análisis de complejidad algorítmica. Las mediciones realizadas demuestran que:

Primero, existe una correspondencia precisa entre la complejidad asintótica teórica y el comportamiento observado en la práctica. Los órdenes de crecimiento O(n³), O(n²) y O(n) se reflejan fielmente en las razones observadas entre mediciones consecutivas.

Segundo, las diferencias en complejidad algorítmica se traducen en diferencias de desempeño de magnitud extraordinaria. La predicción de que la versión cúbica requeriría millones de años para n = 10⁸ frente a 0.36 segundos de la versión lineal subraya la importancia crítica de seleccionar algoritmos eficientes.

Tercero, el algoritmo de Kadane se posiciona como la solución óptima desde la perspectiva de complejidad temporal, siendo la única implementación prácticamente viable para aplicaciones reales que requieren procesamiento de grandes volúmenes de datos.

Finalmente, el análisis de complejidad algorítmica constituye una herramienta predictiva confiable para estimar el comportamiento del software en escenarios que no pueden ser medidos directamente en tiempo razonable.

## Referencias Bibliográficas

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3ª ed.). MIT Press.

GeeksforGeeks. Maximum Subarray Problem. Recuperado de https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
