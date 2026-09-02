# Suma Máxima de un Subarreglo

Un análisis comparativo de tres algoritmos para resolver el problema clásico de encontrar la suma máxima de un subarreglo contiguo, con énfasis en complejidad algorítmica y validación experimental.

## 📋 Descripción del Problema

Dado un arreglo de enteros que pueden ser positivos o negativos, encontrar el subarreglo contiguo cuya suma sea máxima. Por ejemplo, en el arreglo `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`, el subarreglo `[4, -1, 2, 1]` tiene la suma máxima de 6.

## 🎯 Objetivo

Implementar y comparar tres soluciones con diferentes complejidades temporales, validar su correctitud y analizar su comportamiento en la práctica mediante mediciones empíricas.

## 🔧 Implementaciones

Se desarrollaron tres algoritmos diferentes:

### 1. **Algoritmo Cúbico - O(n³)**
Genera todos los subarreglos posibles y calcula la suma de cada uno. Proporciona una solución intuitiva pero ineficiente.

### 2. **Algoritmo Cuadrático - O(n²)**
Utiliza un enfoque mejorado donde para cada posición de inicio, calcula la suma de los elementos subsecuentes de forma incremental, reduciendo el trabajo computacional.

### 3. **Algoritmo Lineal - O(n)** ⭐
Implementa el **algoritmo de Kadane**, un algoritmo elegante y eficiente que mantiene un seguimiento de la suma máxima encontrada hasta el momento y la suma máxima terminada en la posición actual, permitiendo resolver el problema en una única pasada.

## ✅ Validación de Correctitud

Se verificó la correctitud de las tres implementaciones generando **100 arreglos aleatorios** con las siguientes características:

- **Tamaño**: Entre 1 y 20 elementos
- **Valores**: Enteros entre -10 y 10 (tanto positivos como negativos)
- **Resultado**: Las 3 soluciones coincidieron en todas las 100 pruebas ✓

## 💻 Entorno de Ejecución

| Característica | Detalles |
|---|---|
| **Sistema Operativo** | Arch Linux |
| **Lenguaje** | C |
| **Compilador** | GCC |
| **Procesador** | AMD A9-9420 RADEON R5 (5 cores, 2C+3G) |
| **Memoria RAM** | 7.2 GiB |

## 📊 Resultados de Medición

Se realizaron mediciones duplicando el tamaño del arreglo en cada iteración:

| n | Cúbica (s) | Razón | Cuadrática (s) | Razón | Lineal (s) | Razón |
|---|---|---|---|---|---|---|
| 1,000 | 0.525292 | — | 0.001570 | — | 0.000005 | — |
| 2,000 | 4.173737 | 7.95 | 0.006256 | 3.98 | 0.000007 | 1.40 |
| 4,000 | 33.387774 | 8.00 | 0.025057 | 4.01 | 0.000014 | 2.00 |
| 8,000 | 291.265705 | 8.72 | 0.096546 | 3.85 | 0.000029 | 2.07 |

### Análisis de Razones

**Algoritmo Cúbico (O(n³))**

Las razones observadas (7.95, 8.00, 8.72) coinciden perfectamente con la predicción teórica de 2³ = 8.

**Algoritmo Cuadrático (O(n²))**

Las razones observadas (3.98, 4.01, 3.85) se ajustan al comportamiento esperado de 2² = 4.

**Algoritmo Lineal (O(n))**

Las razones observadas (1.40, 2.00, 2.07) confirman el crecimiento lineal de 2¹ = 2. La variación en la primera medición se debe a la interferencia del sistema operativo en ejecuciones muy cortas.

## 🔮 Predicción para n = 10⁸

Utilizando la fórmula de extrapolación basada en el orden de crecimiento:


$$T(n_2) \approx T(n_1) \times \left(\frac{n_2}{n_1}\right)^k$$

| Algoritmo | Tiempo Estimado | Interpretación |
|---|---|---|
| **Cúbico** | 568,878,330,078,125 s | ≈ 18 millones de años 🚫 |
| **Cuadrático** | 15,085,312.5 s | ≈ 175 días 🚫 |
| **Lineal** | 0.36 s | ≈ 0.36 segundos ✅ |

Solo la versión lineal es prácticamente viable para n = 10⁸.

## 🏃 Ejecución con n = 10⁸

Se ejecutó el algoritmo lineal con 100 millones de elementos:

| Métrica | Valor |
|---|---|
| **Tiempo Predicho** | 0.36 s |
| **Tiempo Medido** | 0.378766 s |
| **Error de Predicción** | +5.2% |
| **Precisión** | ✅ Excelente |

## 📈 Gráfico Comparativo
Tiempo (s, escala logarítmica)

Copy100  |                    ● Cúbica
     |                   /
 10  |                 /
     |               ●/ Cuadrática
  1  |             /
     |           ●/
0.1  |         /
     |       ●  Lineal
0.01 | / | / 0.001 | / |●──────────────────────── 1000 2000 4000 8000 n


## 🎓 Conclusiones

1. **Validez Teórica Confirmada**: Los resultados experimentales validan perfectamente las complejidades teóricas O(n³), O(n²) y O(n).

2. **Importancia de la Complejidad Algorítmica**: La diferencia de rendimiento es espectacular. La versión lineal completa en 0.36 segundos lo que la versión cúbica tomaría millones de años.

3. **Algoritmo de Kadane - Superior**: Es la única solución prácticamente viable para datos de escala real.

4. **Precisión de Predicciones**: Las estimaciones basadas en complejidad algorítmica son altamente precisas.

## 📚 Referencias

- **Algoritmo de Kadane**: [GeeksforGeeks](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)
- **Análisis de Complejidad**: Cormen, Leiserson, Rivest, Stein - "Introduction to Algorithms"

---

**Autor**: [Tu nombre]  
**Fecha**: Septiembre 2026  
**Licencia**: MIT

