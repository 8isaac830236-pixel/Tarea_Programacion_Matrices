#include <stdio.h>

int main() {
    float notas[5][3];
    float suma_est, suma_asig;
    int aprobados, reprobados;

    printf("--- SISTEMA DE GESTION DE CALIFICACIONES ---\n");

    // 1. Lectura de datos con validacion
    for (int i = 0; i < 5; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            do {
                printf("  Asignatura %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  [Error] La nota debe estar entre 0 y 10. Intente de nuevo.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

 // 2. Resultados detallados por Estudiante
    printf("\n============================================\n");
    printf("        REPORTE DETALLADO: PROMEDIOS        \n");
    printf("============================================\n");
    for (int i = 0; i < 5; i++) {
        suma_est = 0;
        float max = notas[i][0], min = notas[i][0];
        for (int j = 0; j < 3; j++) {
            suma_est += notas[i][j];
            if (notas[i][j] > max) max = notas[i][j];
            if (notas[i][j] < min) min = notas[i][j];
        }
        printf("ID: Estudiante %d | Prom: %.2f | Max: %.2f | Min: %.2f\n", 
                i + 1, suma_est / 3, max, min);
    }

    // 3. Resultados por Asignatura
    printf("\n============================================\n");
    printf("REPORTE POR ASIGNATURA\n");
    printf("============================================\n");
    for (int j = 0; j < 3; j++) {
        suma_asig = 0;
        aprobados = 0;
        reprobados = 0;
        float max_a = notas[0][j], min_a = notas[0][j];

        for (int i = 0; i < 5; i++) {
            suma_asig += notas[i][j];
            if (notas[i][j] >= 6) aprobados++;
            else reprobados++;
            if (notas[i][j] > max_a) max_a = notas[i][j];
            if (notas[i][j] < min_a) min_a = notas[i][j];
        }
        printf("Asig. %d -> Promedio: %.2f | Max: %.2f | Min: %.2f | Ap: %d | Rep: %d\n", 
                j + 1, suma_asig / 5, max_a, min_a, aprobados, reprobados);
    }

    return 0;
}
// Paso numero 2
