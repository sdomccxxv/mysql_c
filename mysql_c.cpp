#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;

void menu();

int main()
{
    menu();

}

void Ingresar() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_empresa1", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion exitosa..." << endl;
        string puesto;
        cout << "Ingrese puesto: ";
        cin >> puesto;

        string insert = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar..." << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    //cout << "Hello World!\n";
    system("pause");
    //return 0;
}

void Mostrar() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_empresa1", 3306, NULL, 0);
    if (conectar) {
        string consulta = "SELECT * FROM puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);

        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << " - " << fila[1] << endl;
            }
        }
        else {
            cout << "Error al consultar..." << endl;
        }

    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
}

void menu() {

    int puesto;
    cout << "Si desea ingresar un nuevo puesto presione 1, si desea ver los puestos presione 2: ";
    cin >> puesto;
    switch (puesto)
    {
    case 1: Ingresar();
    case 2: Mostrar();
    default:
        break;
    }
}

