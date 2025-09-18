#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Estudiante {
    string nombre;
    char sexo; // 'M' para mujer, 'H' para hombre
    vector<float> examenes;
};

struct Curso {
    string nombreCurso;
    vector<Estudiante> estudiantes;
};

int main() {
    int numCursos, numEstudiantes, numExamenes;
    cout << "Ingrese el numero de cursos: ";
    cin >> numCursos;
    vector<Curso> cursos(numCursos);

    for (int i = 0; i < numCursos; ++i) {
        cout << "\nNombre del curso #" << (i + 1) << ": ";
        cin.ignore();
        getline(cin, cursos[i].nombreCurso);

        cout << "Numero de estudiantes en " << cursos[i].nombreCurso << ": ";
        cin >> numEstudiantes;

        cout << "Numero de examenes en " << cursos[i].nombreCurso << ": ";
        cin >> numExamenes;

        cursos[i].estudiantes.resize(numEstudiantes);

        for (int j = 0; j < numEstudiantes; ++j) {
            cout << "\nNombre del estudiante #" << (j + 1) << ": ";
            cin.ignore();
            getline(cin, cursos[i].estudiantes[j].nombre);

            cout << "Sexo (M para mujer, H para hombre): ";
            cin >> cursos[i].estudiantes[j].sexo;

            cursos[i].estudiantes[j].examenes.resize(numExamenes);
            for (int k = 0; k < numExamenes; ++k) {
                cout << "Calificacion del examen #" << (k + 1) << ": ";
                cin >> cursos[i].estudiantes[j].examenes[k];
            }
        }
    }

    cout << "\n--- Reporte de Cursos ---\n";
    for (const auto& curso : cursos) {
        int mujeres = 0;
        cout << "\nCurso: " << curso.nombreCurso << endl;
        for (const auto& est : curso.estudiantes) {
            if (est.sexo == 'M' || est.sexo == 'm')
                ++mujeres;
        }
        cout << "Cantidad de estudiantes mujeres: " << mujeres << endl;

        cout << "Promedio final de cada estudiante:\n";
        for (const auto& est : curso.estudiantes) {
            float suma = 0;
            for (float cal : est.examenes)
                suma += cal;
            float promedio = est.examenes.empty() ? 0 : suma / est.examenes.size();
            cout << fixed << setprecision(2);
            cout << "  " << est.nombre << ": " << promedio << endl;
        }
    }

    return 0;
}