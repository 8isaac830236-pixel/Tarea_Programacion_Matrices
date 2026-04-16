#include <stdio.h>
#include <stdlib.h>

int main() {
    float notas[5][3];
    float suma_est, suma_asig;
    int aprobados, reprobados;

    // 1. Ingreso de datos con validación
    for (int i = 0; i < 5; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < 3; j++) {
            do {
                printf(" Asignatura %d (0-10): ", j + 1);
                if (scanf("%f", &notas[i][j]) != 1) {
                    while(getchar() != '\n'); // Limpiar buffer si meten letras
                }
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf(" [Error] Nota invalida. Intente de nuevo.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // 2. Reporte de Promedios por Estudiante
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
        printf("Estudiante %d | Prom: %.2f | Max: %.2f | Min: %.2f\n", 
                i + 1, suma_est / 3, max, min);
    }

    // 3. Estadisticas por Asignatura
    printf("\n============================================\n");
    printf("     ESTADISTICAS DE APROBACION (>= 6)      \n");
    printf("============================================\n");
    for (int j = 0; j < 3; j++) {
        suma_asig = 0; aprobados = 0; reprobados = 0;
        for (int i = 0; i < 5; i++) {
            suma_asig += notas[i][j];
            if (notas[i][j] >= 6.0) aprobados++;
            else reprobados++;
        }
        printf("Asig %d -> Prom: %.2f | Ap: %d | Rep: %d\n", 
                j + 1, suma_asig / 5, aprobados, reprobados);
    }

    // CIERRE DEL SISTEMA (Cambio del 5to Commit)
    printf("\n********************************************\n");
    printf("* PROCESAMIENTO DE DATOS FINALIZADO        *\n");
    printf("* SISTEMA DE GESTION ACADEMICA - FAE No.1  *\n");
    printf("********************************************\n");

    return 0;
}
